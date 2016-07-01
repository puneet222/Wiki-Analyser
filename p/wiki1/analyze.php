<link rel="stylesheet" type="text/css" href="bootstrap/css/bootstrap.min.css">
<!-- <link rel="stylesheet" type="text/css" href="bootstrap/css/bootstrap-responsive.css">
<link rel="stylesheet" type="text/css" href="bootstrap/css/bootstrap-responsive.min.css"> -->
<link rel="stylesheet" type="text/css" href="css/home.css">

<html>
<head>
<title>Wikipedia Analyser</title>
<script src="http://ajax.googleapis.com/ajax/libs/jquery/1.5.1/jquery.js"></script>
<!-- <script src="javaS/first.js"></script> -->
<style type="text/css">
  body{
    background-color: #D7CCC8 ;
  }
</style>
</head>
<body>
<div id="nav">
<ul>
  <li id="wikianly"><a href="#"><h3>Wikipedia Analyser</h3></a></li>
  <li id="help"><a href="help.php"><h4>Help</h4></a></li>
  <li id="contact"><a href="contact.php"><h4>Contact</h4></a></li>
  <li id="about"><a href="about.php"><h4>About</h4></a></li>
</ul>
</div>
<div class="container">

<div id="main-analytics" class="text-center container-fluid-scroll">
<h1>Here's the Analysis Page</h1><br>
<img src="images/analyses3.png" , height="300px" , width="800px">



</div>




  <?php 
  $getvar = $_GET['s'] ;
  echo $getvar ;
  ?>
 
   <script type="text/javascript">

   var new_link = "<?php echo $getvar; ?>";
    // console.log("search elemet is : " + link) ;

    var arr = new_link.split("_") ;
    var siz = arr.length ;
   
    for(var i = 0 ; i < siz ; i++)
    {
    	arr[i] = encodeURIComponent(arr[i]) ;
    }


    
    var link = arr.join("_") ;
    var serlink = link ;
    console.log("new link is : " + serlink) ;
   			

	var v = "" ;


   	 $.ajax({
        type: "GET",
        url : "https://en.wikipedia.org//w/api.php?action=opensearch&format=json&search="+link+"&limit=100&namespace=6%7C10%7C-2%7C-1%7C4%7C8%7C14%7C108%7C101%7C100%7C118%7C446&utf8=1&callback=?",
        contentType: "application/json; charset=utf-8",
        async: true,
        dataType : "json" ,
        success: function(data , textStatus, jqXHR){
          console.log(data);

          var len = data[1].length ;
          console.log("length = " + len) ;
          var type = [] ;
          var name = [] ;
          var link = [] ;

          for(var i = 0 ; i < len ; i++)
          {
          	var arr = data[1][i].split(":");
          	// console.log(arr) ;
          	type.push(arr[0]) ;
          	name.push(arr[1]) ;
          	link.push(data[3][i]);
          	var q = arr[0] ;

          	}


          	var pass_type = type.join(",") ;
          	var pass_name = name.join(",") ;
          	var pass_link = link.join(",") ;

          	console.log(pass_type + " " + pass_link) ;
            console.log("firm1 link is  : " + serlink) ;
          	$("#type").val(pass_type);
          	$("#name").val(pass_name);
          	$("#link").val(pass_link);
            $("#plink").val(serlink);

          	$("#form").append("<button id='click' class='btn' style='background-color:#01579B;color:white'><h4>Basic Data Analysis</h4></button>");


          	$("#click").click(function(){

              $("#form").append("<br><br><img src='images/basic.gif'><h5><b>Analyzing...</b></h5>")
              $("#views_btn")[0].disabled = true ;
          		$("#pass").submit();
          	})


         }


       
      }) // ajax 1

     var d = new Date();
    var nyear = d.getYear() + 1900;
    var nmonth = d.getMonth() + 1 ;
    var ndate = d.getDate() ;

    if(nmonth < 10)
    {
      nmonth = "0" + nmonth ;
    }
    if(ndate < 10)
    {
      ndate = "0" + ndate ;
    }

    var urldate = nyear + nmonth + ndate + "00" ;

    console.log(urldate);
    console.log(nmonth);

   	 $.ajax({
        type: "GET",
        url : "https://wikimedia.org/api/rest_v1/metrics/pageviews/per-article/en.wikipedia/all-access/all-agents/"+ serlink +"/daily/2008100600/" + urldate,
        contentType: "application/json; charset=utf-8",
        async: true,
        dataType : "json" ,
        success: function(data , textStatus, jqXHR){
          console.log(data);
		  var len = (data["items"]).length ;
		  var views = [] ;
		  var date = [] ;
          for(var i = 0 ; i < len ; i++)
          {
          	views.push(data["items"][i]["views"]) ;
          	date.push(data["items"][i]["timestamp"]) ;
          }

          var year = [] ;
          var mon = [] ;
          var dt = [] ;
          console.log(date[2]);
          for(var i = 0 ; i < len ; i++)
          {
          	var snum = (date[i]).toString()
          	var arr = snum.split("") ;
          	
          	var y = arr[0]+arr[1]+arr[2]+arr[3] ;
          	var m = arr[4]+arr[5];
          	var d = arr[6]+arr[7];


          	year.push(y);
          	mon.push(m);
          	dt.push(d);

          }

          var pass_views = views.join(",") ;
          var pass_year = year.join(",");
          var pass_mon = mon.join(",");
          var pass_dt = dt.join(",");


          $("#views").val(pass_views);
          $("#year").val(pass_year);
          $("#mon").val(pass_mon);
          $("#dt").val(pass_dt);
          $("plink2").val(link);


          $("#form2").append("<button id='views_btn' class='btn' style='background-color:#00796B;color:white'><h4>User Views Analysis</h4></button>") ;

          $("#views_btn").click(function(){
          	$("#form2").append("<br><br><img src='images/view.gif'><h5><b>Analysing User Views...</b></h5>")
            $("#click")[0].disabled = true ;

          	$("#pass2").submit() ;
          })




          
      } // success function
  })// ajax

   </script>

<div id="rows">
  
  <div class="col-md-6 text-center">
      <div id="form">
      <form action="ajax.php?s=<?php echo $getvar ;?>" id="pass" method="post">
      <input type="hidden" name="type" id="type">
      <input type="hidden" name="name" id="name">
      <input type="hidden" name="link" id="link">
      <input type="hidden" name="plink" id="plink">
      </form>

      </div>
  </div>    
  
  <div class="col-md-6 text-center">
      <div id="form2">
      <form action="ajax2.php?s=<?php echo $getvar ;?>" id="pass2" method="post">
      <input type="hidden" name="views" id="views">
      <input type="hidden" name="year" id="year">
      <input type="hidden" name="mon" id="mon">
      <input type="hidden" name="dt" id="dt">
      <input type="hidden" name="plink2" id="plink2"> 
      </form>
      </div>
  </div>
</div>
</div>

</body>

</html>