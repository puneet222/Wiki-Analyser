library(RMySQL)
library(ggplot2)
library(Cairo)

Corner_text <- function(text, location="topright"){
  legend(location,legend=text, bty ="n", pch=NA , col = "white" , text.col = "white") 
}

get_date <- function(year , month , date){
  mylist <- list() ;
  mylist$'01' <- "January" ;
  mylist$'02' <- "February" ;
  mylist$'03' <- "March" ;
  mylist$'04' <- "April" ;
  mylist$'05' <- "May" ;
  mylist$'06' <- "June" ;
  mylist$'07' <- "July" ;
  mylist$'08' <- "August" ;
  mylist$'09' <- "September" ;
  mylist$'10' <- "October" ;
  mylist$'11' <- "November" ;
  mylist$'12' <- "December" ;
  
  refdate <- paste0(date ,"-" ,  mylist[[month]] ,"-" , year ) ;
  refdate ;
  
}

get_month <- function(month){
  mylist2 <- list() ;
  mylist2$'01' <- "January" ;
  mylist2$'02' <- "February" ;
  mylist2$'03' <- "March" ;
  mylist2$'04' <- "April" ;
  mylist2$'05' <- "May" ;
  mylist2$'06' <- "June" ;
  mylist2$'07' <- "July" ;
  mylist2$'08' <- "August" ;
  mylist2$'09' <- "September" ;
  mylist2$'10' <- "October" ;
  mylist2$'11' <- "November" ;
  mylist2$'12' <- "December" ;
  
  month <- mylist2[[month]] ;
  month
}

conn <- dbConnect(MySQL(), host="127.0.0.1", port= 3306, user="root",
                  password = "", dbname="wiki")

year <- dbGetQuery(conn , "Select distinct(year) from user_views") ;

year <- year[,"year"]

t.year <- length(year) ;

month <- c() ;

for(i in 1 : t.year)
{
  #monthly analysis
  query <- paste0("select distinct(month) from user_views where year=" , "'" , year[i] , "'")
  smonth <- dbGetQuery(conn , query) 
  month <- c(month , smonth) 
  
  #now month is a list so we have to convert into any other data structure for ease of accessibilty
  month <- rapply(month, c)
  t.month <- length(month)
  date <- c() ;
  for(j in 1 : t.month)
  {
    query <- paste0("Select distinct(date) from user_views where year=" , "'" , year[i] , "'" , "AND month=" , "'" , month[[j]] , "'")
    temp <- dbGetQuery(conn , query) ;
    #now we have all the dates of that month
    date <- temp[,"date"] #converting data frame into character vector
    t.date <- length(date) ;
    
    views <- c() ;
    for(k in 1 : t.date)
    {
      query <- paste0("Select views from user_views where year=" , "'" , year[i] , "'" , " and month=" , "'" , month[[j]] , "'" , " and date="  , "'" , date[k] , "'")
      temp2 <- dbGetQuery(conn , query) ;
      views <- c(views , temp2[,"views"]) ; 
      monmean <- paste0("Select avg(views) as monavg from user_views where year=" , "'" , year[i] , "'" , "AND month=" , "'" , month[[j]] , "'" ) ;
      monmeantemp <- dbGetQuery(conn , monmean) ;
      meanmonth <- monmeantemp[,"monavg"] ;
      meanmonth <- round(meanmonth) ;
      
      monmax <- paste0("select max(views) as monmaxi from user_views where year=" , "'" , year[i] , "'" , "and month=" , "'" , month[[j]] , "'" ) ;
      monmaxtemp <- dbGetQuery(conn , monmax);
      maximum.month <- monmaxtemp[,"monmaxi"];
      
      maxdateq <- paste0("Select date from user_views where views=" , maximum.month , " and year=" , "'" , year[i] , "'" , " and month=" , "'" , month[[j]] , "'") ; 
      maxdatetemp <- dbGetQuery(conn , maxdateq) ;
      maxdate <- get_date(year[1] , month[[j]] , maxdatetemp[,"date"])
}      
    
    
    
    #now we have date vector having all the dates of month[[j]] and year[i]
    #and we also have vector of views of the corrresponding date
    
    #now we create graph plot
    
    #now i am making the main label
    main_l = paste0(get_month(month[[j]]) , " " , year[i]) ;
    
    #now making the name of the plot
    name = paste0(year[i] , get_month(month[[j]]) , ".png")
    Cairo(file=name, 
          type="png",
          units="in", 
          width=15, 
          height=5, 
          pointsize=12, 
          dpi=72)
    plot(views , type = "o" , col="turquoise1" , lwd = 2 , bty = 'n' , main = main_l , sub="Monthly Analysis of user views " , ylab = "User views" , xlab = "Date"  , col.axis="white" , col.main = "White" , col.lab = "white"  , col.sub = "white")
    axis(1 , at=date, labels = date , col = "white" , col.ticks = "white")
    Corner_text(text=paste0("Average page views = " , meanmonth)) ;
    Corner_text(text=paste0("\nMaximum page views = " , maximum.month)) ;
    Corner_text(text=paste0("\n\nDate = " , maxdate)) ;
    dev.off()
    
    date <- c() ;
  }
  month <-c() ;
}

#overall analyses

total_views <- dbGetQuery(conn , "Select views from user_views") ;
total_views <- total_views[,"views"]
total_year <- dbGetQuery(conn , "Select year from user_views") ;
total_year <- total_year[,"year"]
total_month <- dbGetQuery(conn , "Select month from user_views") ;
total_month <- total_month[,"month"]
total_date <- dbGetQuery(conn , "Select date from user_views") ;
total_date <- total_date[,"date"]

omean <- "Select avg(views) as oavg from user_views"
omeantemp <- dbGetQuery(conn , omean) ;
meanover <- omeantemp[,"oavg"] ;
meanover <- round(meanover) ;

omax <- "select max(views) as omaxi from user_views"
omaxtemp <- dbGetQuery(conn , omax);
maximum.over <- omaxtemp[,"omaxi"];

omaxdateq <- paste0("Select date , month , year from user_views where views=" , maximum.over) ;
omaxdatetemp <- dbGetQuery(conn , omaxdateq) ;
omaxdate <- get_date(omaxdatetemp[,"year"] , omaxdatetemp[,"month"] , omaxdatetemp[,"date"])
omaxdate

olen <- length(total_views) ;

odate <- c() ;

for(i in 1:olen)
{
  temp2 <- paste0(total_date[i] , "-" , get_month(total_month[i]) , "-" , total_year[i]);
  odate <- c(odate , temp2);
}
start <- get_date(total_year[1] , total_month[1] , total_date[1])
end <- get_date(total_year[olen] , total_month[olen] , total_date[olen])

omain <- paste0("Analysis of User views from " , start , " - " , end)
Cairo(file="overall.png", 
      type="png",
      units="in", 
      width=15, 
      height=5, 
      pointsize=12, 
      dpi=72)
plot(total_views , type = "l" , col="turquoise1" , lwd = 1 , bty = 'n' , main = omain , sub="OverAll Analysis of user views" , ylab = "User views" , xlab = "Timeline" , xaxt = 'n' ,col.axis="white" , col.main = "White" , col.lab = "white"  , col.sub = "white" )
axis(1 , at=1:olen , labels = odate  , col = "white" , col.ticks = "white")
Corner_text(text=paste0("Average page views = " , meanover)) ;
Corner_text(text=paste0("\nMaximum page views = " , maximum.over)) ;
Corner_text(text=paste0("\n\nDate = " , omaxdate)) ;
dev.off()

#last 30 days
query30v <- "Select views from user_views order by year desc , month desc , date desc limit 30"
last30v <- dbGetQuery(conn , query30v) ;
last30v <- last30v[,"views"]

query30y <- "Select year from user_views order by year desc , month desc , date desc limit 30"
last30y <- dbGetQuery(conn , query30y) ;
last30y <- last30y[,"year"]

query30m <- "Select month from user_views order by year desc , month desc , date desc limit 30"
last30m <- dbGetQuery(conn , query30m) ;
last30m <- last30m[,"month"]

query30d <- "Select date from user_views order by year desc , month desc , date desc limit 30"
last30d <- dbGetQuery(conn , query30d) ;
last30d <- last30d[,"date"]

# finding avg max for displaying on graph last30
mean30 <- round(mean(last30v)) ;
max30 <- max(last30v);
index30 <- last30v == max30
y30 <- last30y[index30]
m30 <- last30m[index30]
d30 <- last30d[index30]
date30 <- get_date(y30,m30,d30)


last30dates <- c() ;
views30  <- c() ;
for(i in 0:29)
{
  tempdates <- get_date(last30y[30-i] , last30m[30-i] , last30d[30-i])
  last30dates <- c(last30dates , tempdates)
  tempviews <- last30v[30-i] ;
  views30 <- c(views30 , tempviews)
}

#now we have last  30 days views and dates
Cairo(file="last30.png", 
      type="png",
      units="in", 
      width=15, 
      height=5, 
      pointsize=12, 
      dpi=72)
plot(views30 , type = "o" , col="turquoise1" , lwd = 1 , bty = 'n' , main = "Last 30 days Analysis" , ylab = "User views" , xlab = "Timeline" , xaxt='n' ,col.axis="white" , col.main = "White" , col.lab = "white"  , col.sub = "white")
axis(1 , at=1:30 , labels = last30dates , col = "white" , col.ticks = "white")
Corner_text(text=paste0("Average page views = " , mean30)) ;
Corner_text(text=paste0("\nMaximum page views = " , max30)) ;
Corner_text(text=paste0("\n\nDate = " , date30)) ;
par(las=2)
dev.off()

# last 60 days analysis

query60v <- "Select views from user_views order by year desc , month desc , date desc limit 60"
last60v <- dbGetQuery(conn , query60v) ;
last60v <- last60v[,"views"]

query60y <- "Select year from user_views order by year desc , month desc , date desc limit 60"
last60y <- dbGetQuery(conn , query60y) ;
last60y <- last60y[,"year"]

query60m <- "Select month from user_views order by year desc , month desc , date desc limit 60"
last60m <- dbGetQuery(conn , query60m) ;
last60m <- last60m[,"month"]

query60d <- "Select date from user_views order by year desc , month desc , date desc limit 60"
last60d <- dbGetQuery(conn , query60d) ;
last60d <- last60d[,"date"]

# finding avg max for displaying on graph last60
mean60 <- round(mean(last60v)) ;
max60 <- max(last60v);
index60 <- last60v == max60
y60 <- last60y[index60]
m60 <- last60m[index60]
d60 <- last60d[index60]
date60 <- get_date(y60,m60,d60)

last60dates <- c() ;
views60  <- c() ;
for(i in 0:59)
{
  tempdates <- get_date(last60y[60-i] , last60m[60-i] , last60d[60-i])
  last60dates <- c(last60dates , tempdates)
  tempviews <- last60v[60-i] ;
  views60 <- c(views60 , tempviews)
}

#now we have last  60 days views and dates
Cairo(file="last60.png", 
      type="png",
      units="in", 
      width=15, 
      height=5, 
      pointsize=12, 
      dpi=72)
plot(views60 , type = "o" , col="turquoise1" , lwd = 1 , bty = 'n' , main = "Last 60 days Analysis" , ylab = "User views" , xlab = "Timeline" , xaxt='n' ,col.axis="white" , col.main = "White" , col.lab = "white"  , col.sub = "white" )
axis(1 , at=1:60 , labels = last60dates , col = "white" , col.ticks = "white")
Corner_text(text=paste0("Average page views = " , mean60)) ;
Corner_text(text=paste0("\nMaximum page views = " , max60)) ;
Corner_text(text=paste0("\n\nDate = " , date60)) ;
par(las=2)
dev.off()

#last 90 days Analysis

query90v <- "Select views from user_views order by year desc , month desc , date desc limit 90"
last90v <- dbGetQuery(conn , query90v) ;
last90v <- last90v[,"views"]

query90y <- "Select year from user_views order by year desc , month desc , date desc limit 90"
last90y <- dbGetQuery(conn , query90y) ;
last90y <- last90y[,"year"]

query90m <- "Select month from user_views order by year desc , month desc , date desc limit 90"
last90m <- dbGetQuery(conn , query90m) ;
last90m <- last90m[,"month"]

query90d <- "Select date from user_views order by year desc , month desc , date desc limit 90"
last90d <- dbGetQuery(conn , query90d) ;
last90d <- last90d[,"date"]

mean90 <- round(mean(last90v)) ;
max90 <- max(last90v);
index90 <- last90v == max90
y90 <- last90y[index90]
m90 <- last90m[index90]
d90 <- last90d[index90]
date90 <- get_date(y90,m90,d60)

last90dates <- c() ;
views90  <- c() ;
for(i in 0:89)
{
  tempdates <- get_date(last90y[90-i] , last90m[90-i] , last90d[90-i])
  last90dates <- c(last90dates , tempdates)
  tempviews <- last90v[90-i] ;
  views90 <- c(views90 , tempviews)
}

#now we have last  90 days views and dates
Cairo(file="last90.png", 
      type="png",
      units="in", 
      width=15, 
      height=5, 
      pointsize=12, 
      dpi=72)
plot(views90 , type = "o" , col="turquoise1" , lwd = 1 , bty = 'n' ,  main = "Last 90 days Analysis" , ylab = "User views" , xlab = "Timeline" , xaxt='n' ,col.axis="white" , col.main = "White" , col.lab = "white"  , col.sub = "white")
axis(1 , at=1:90 , labels = last90dates , col = "white" , col.lab="white")
Corner_text(text=paste0("Average page views = " , mean90)) ;
Corner_text(text=paste0("\nMaximum page views = " , max90)) ;
Corner_text(text=paste0("\n\nDate = " , date90)) ;
par(las=2)
dev.off()



