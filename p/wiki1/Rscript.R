library(RMySQL)

con <- dbConnect(MySQL(), host="127.0.0.1", port= 3306, user="root",
                 password = "", dbname="wiki")

#dbGetQuery(con, "show tables ;")

type_vec <- c("File" , "Template" , "Media" , "Special" , "Wikipedia" , "MediaWiki" , "Category" , "Book" , "Portal" , "Draft")
num_vec <- c() ;

for(i in 1 : 10)
{
  query <- paste0("Select count(*) from table1 where type =","'",type_vec[i],"'" )  
  result <- dbGetQuery(con , query) ; 
  num_vec <- c(num_vec , result[,"count(*)"] )
}

num_vec

typecount <- data.frame(type = type_vec , count=num_vec)

dbWriteTable(con , name="typecount" , value = typecount)

index <- num_vec != 0
index
new_num <- num_vec[index] ;
new_type <- type_vec[index]

plot_data <- data.frame(types = new_type , number = new_num)
colr <- c("brown1" , "aquamarine" , "darkorange" , "darkorchid1" , "gold" , "hotpink" , "lightcoral" , "lightslateblue" , "purple1" , "seagreen")

total <- dbGetQuery(con , "Select count(*) from table1")
total <- total[,"count(*)"]

total.df <- data.frame(sum=total)

dbWriteTable(con, name='sum', value=total.df)

miny <- min(new_num) ;
maxy <- max(new_num)

if(maxy == 0)
{
  maxy <- 1 
}
library(Cairo)
Cairo(file="myplot.png", 
      type="png",
      units="in", 
      width=7, 
      height=7, 
      pointsize=12, 
      dpi=72)
xx <- barplot(plot_data$number, main="Analysis of your wiki Topic",  
              ylab="Number", names.arg=new_type, 
               col= colr , col.axis="white" , col.main = "White" , col.lab = "white" , border = "white")
text(x = xx, y = plot_data$number, label = plot_data$number, pos = 3, cex = 0.8, col = "white" , font.lab = 2 , cex.lab=1 , cex.main=1.5)
par(las=2)
dev.off()
