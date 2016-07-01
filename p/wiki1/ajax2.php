<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<link rel="stylesheet" type="text/css" href="bootstrap/css/bootstrap.css">
<link rel="stylesheet" type="text/css" href="bootstrap/css/bootstrap.min.css">
<!-- <link rel="stylesheet" type="text/css" href="bootstrap/css/bootstrap-responsive.css">
<link rel="stylesheet" type="text/css" href="bootstrap/css/bootstrap-responsive.min.css"> -->
<link rel="stylesheet" type="text/css" href="css/home.css">
<link rel="stylesheet" type="text/css" href="font-awesome-4.6.3/css/font-awesome.min.css">
<link rel="stylesheet" type="text/css" href="font-awesome-4.6.3/css/font-awesome.css">



<html>
<head>
<style type="text/css">
	body{
		background-color: #212121 ;
	}

</style>
<title>Wikipedia Analyser</title>
<script src="http://ajax.googleapis.com/ajax/libs/jquery/1.5.1/jquery.js"></script>
<script src="javaS/first.js"></script>
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
<br>
<br>
<br>
<div class="container">



<?php

$views = $_POST["views"] ;
$year = $_POST["year"] ;
$mon = $_POST["mon"] ;
$dt = $_POST["dt"] ;
$passlink = $_POST["plink2"];

// echo $passlink ;

// echo $views ;
// echo $year ;
// echo $mon ;
// echo $dt ;

$dviews = explode(",", $views) ;
$dyear = explode("," , $year) ;
$dmon = explode("," , $mon) ;
$dt = explode(",", $dt) ;



//database thing

include("dbcon.php") ;

$len  = count($dviews) ;

$delete = "DELETE from user_views" ;

mysqli_select_db($conn, "wiki");


$status = mysqli_query($conn , $delete) ;

if(!$status)
{
	die('Could not '.mysqli_error());
}
else
{
	// echo "query may be executed" ;
}

for ($i=0; $i < $len ; $i++) { 
	
	$query = "insert into user_views values('$dviews[$i]' , '$dyear[$i]' , '$dmon[$i]' , '$dt[$i]') ;" ;

mysqli_select_db($conn, "wiki");


$status = mysqli_query($conn , $query) ;

if(!$status)
{
	die('Could not '.mysqli_error());
}
else
{
	// echo "query may be executed" ;
}
	
} // for loop



 // executing r script 
exec('"D:\SOFTWARE\R-3.2.3\bin\Rscript.exe" "view_analyses.R" 2>&1', $output);

//   // return image tag

//   $nocache = rand();
  // print_r($output) ;

  // echo "<img src='myplot.png?$nocache' /> "; 

?>
<br>
<br>
<script type="text/javascript">

$("#ydaily").hide() ;
		$("#mdaily").hide() ;
		$("#ddaily").hide() ;
		$("#dailyres").hide() ;
		$("#mmonth").hide();
		$("#ymonth").hide();




		function getmonth(){
			var y = $("#syear").val() ;
			// alert(y) ;
			if(y == "")
			{
				alert("Please Specify the Year") ;
				$("#smonth").empty();
				var addop = "<option value='' selected>Month</option>" ;
				$("#smonth").html(addop);
			}
			else
			{
				jQuery.ajax({
					    type: "POST",
					    url: 'month.php',
					    dataType: 'json',
					    data: {year: y},
					    success: function (obj, textstatus) {

					                  if( !('error' in obj) ) {
					                      mons = obj.result;
					                      console.log(mons) ;
					                      var len = mons.length;
					                      console.log(len) ;
					                      $("#smonth").empty();
					                      var addop = "<option value='' selected>Month</option>" ;
					                      for(var i = 0 ; i < len ; i++)
					                      {
					                      	addop += "<option value="+ getletter(mons[i]) + ">" + getletter(mons[i]) + "</option>" ;
					                      }
					                      console.log(addop);
					                      $("#smonth").append(addop);


					                  }
					                  else {
					                      console.log(obj.error);
					                  }
					            }
					});
			}
		}   // function getmonth end 



				function getletter(mon){
			var list = {"01" : "January" , "02" : "February" , "03" : "March" , "04" : "April" , "05" : "May" , "06" : "June" , "07" : "July" , "08" : "August" , "09" : "September" , "10" : "October" , "11" : "November" , "12" : "December"} ;
			return list[mon] ;
		}


	$(document).ready(function(){

		$("#ydaily").hide() ;
		$("#mdaily").hide() ;
		$("#ddaily").hide() ;
		$("#dailyres").hide() ;
		$("#mmonth").hide();
		$("#ymonth").hide();


		$("#daily-views").click(function(){
			$("#daily-views").hide("slow" , function(){
				$("#ydaily").show("slow") ;
			}) ;
		    })  // end of daily view button

		$("#mon-views").click(function(){
			$("#mon-views").hide("slow" , function(){
				$("#ymonth").show("slow");
			// alert("clicked") ;
			})
		})


		$("#mon-next-year").click(function(){
			var y = $("#syear").val() ;
			if(y == "")
			{
				alert("Please specify year") ;
			}
			else
			{

				$("#ymonth").hide("slow") ; 
						jQuery.ajax({
					    type: "POST",
					    url: 'month.php',
					    dataType: 'json',
					    data: {year: y},
					    success: function (obj, textstatus) {

					                  if( !('error' in obj) ) {
					                      mons = obj.result;
					                      console.log(mons) ;
					                      var len = mons.length;
					                      console.log(len) ;
					                      $("#smonth").empty();
					                      var addop = "<option value='' selected>Month</option>" ;
					                      for(var i = 0 ; i < len ; i++)
					                      {
					                      	addop += "<option value="+ getletter(mons[i]) + ">" + getletter(mons[i]) + "</option>" ;
					                      }
					                      console.log(addop);
					                      $("#smonth").append(addop);

					                      $("#mmonth").show("slow") ;

					                  }
					                  else {
					                      console.log(obj.error);
					                  }
					            }
					});
			}
		}) // end of next year button of monthly analysis

		$("#mon-next-month").click(function(){

			var y = $("#syear").val() ;
			var m = $("#smonth").val() ;
			if(m == "")
			{
				alert("Please Specify Month")
			}

			else{

			var imageid = y+m+".png";
			console.log(imageid);
			$("#mmonth").hide("slow" , function(){
				$("#mon-views").show("slow") ;
				$("#dis-img").fadeOut(800 , function(){
				$("#dis-img").html("<img src="+imageid+">") ;
				$("#dis-img").fadeIn(1000);
			})
			})

		 	}
		})



		$("#syear").click(function(){
	// alert("cniuv");

	var addop = "<option value='' selected>Month</option>" ;
	$("#smonth").html(addop);

	var z = $("#syear").val() ;
	if(z != "")
	{
						jQuery.ajax({
					    type: "POST",
					    url: 'month.php',
					    dataType: 'json',
					    data: {year: z},
					    success: function (obj, textstatus) {

					                  if( !('error' in obj) ) {
					                      mons = obj.result;
					                      console.log(mons) ;
					                      var len = mons.length;
					                      console.log(len) ;
					                      $("#smonth").empty();
					                      var addop = "<option value='' selected>Month</option>" ;
					                      for(var i = 0 ; i < len ; i++)
					                      {
					                      	addop += "<option value="+ getletter(mons[i]) + ">" + getletter(mons[i]) + "</option>" ;
					                      }
					                      console.log(addop);
					                      $("#smonth").append(addop);


					                  }
					                  else {
					                      console.log(obj.error);
					                  }
					            }
					});
	}
})   // on click of year drop down list

		$("#mon-btn").click(function(){
			var y = $("#syear").val() ;
			if(y == "")
			{
				alert("Please specify the year") ;
			}
			var m = $("#smonth").val() ;
			if(m == "")
			{
				alert("Please specify the month");
			}
			var pvalue = y+m+".png" ;
			console.log(pvalue);

			$("#dis-img").fadeOut(800 , function(){
				$("#dis-img").html("<img src=" + pvalue + ">") ;
				$("#dis-img").fadeIn(800);
			})
				

		})   // end of monthly analysis button

		$("#next-year").click(function(){
			var y = $("#syeardaily").val() ;
			if(y == "")
			{
				alert("Please specify year") ;
			}
			else
			{

				$("#ydaily").hide("slow") ; 
						jQuery.ajax({
					    type: "POST",
					    url: 'month.php',
					    dataType: 'json',
					    data: {year: y},
					    success: function (obj, textstatus) {

					                  if( !('error' in obj) ) {
					                      mons = obj.result;
					                      console.log(mons) ;
					                      var len = mons.length;
					                      console.log(len) ;
					                      $("#smonthdaily").empty();
					                      var addop = "<option value='' selected>Month</option>" ;
					                      for(var i = 0 ; i < len ; i++)
					                      {
					                      	addop += "<option value="+ getletter(mons[i]) + ">" + getletter(mons[i]) + "</option>" ;
					                      }
					                      console.log(addop);
					                      $("#smonthdaily").append(addop);

					                      $("#mdaily").show("slow") ;

					                  }
					                  else {
					                      console.log(obj.error);
					                  }
					            }
					});
			}
		})   // daily year function end

		$("#next-month").click(function(){
			    var listnum = {"January" : "01" , "February" : "02" , "March" : "03" , "April" : "04" , "May" : "05" , "June" : "06" , "July" : "07" , "August" : "08" , "September" : "09" , "October" : "10" , "November" : "11" , "December" : "12"} ;
			var m = $("#smonthdaily").val() ;
			var y = $("#syeardaily").val() ;
			console.log(m + " " + y) ;
			if(m == "")
			{
				alert("Please Specify Month")
			}
			else
			{
				m = listnum[m] ;
				console.log(m) ;
				$("#mdaily").hide("slow") ;
				jQuery.ajax({

				type:"POST",
				url: 'date.php',
				dataType: 'json',
				data: {year:y , month:m},

				success: function(obj , textstatus) {
					if(!('error' in obj))
					{
						dates = obj.result ;
						console.log(dates);
						var len = dates.length;
						$("#sdatedaily").empty();
					    var addop = "<option value='' selected>Select Date</option>" ;
					    for(var i = 0 ; i < len ; i++)
					    {
					    addop += "<option value="+ dates[i] + ">" + dates[i] + "</option>" ;
					    }
					    console.log(addop);
					    $("#sdatedaily").append(addop);

					    $("#ddaily").show("slow") ;
					}
					else
					{
						console.log(obj.error);
					}
				}
			});
			}
		})   // end of month selection function 

		$("#next-date").click(function(){
			var listnum = {"January" : "01" , "February" : "02" , "March" : "03" , "April" : "04" , "May" : "05" , "June" : "06" , "July" : "07" , "August" : "08" , "September" : "09" , "October" : "10" , "November" : "11" , "December" : "12"} ;
			var m = $("#smonthdaily").val() ;
			var y = $("#syeardaily").val() ;
			var d = $("#sdatedaily").val() ;
			console.log(m + " " + y + " " + d) ;
			if(d == "")
			{
				alert("Please specify date") ;
			}
			else
			{
				var dt = d+"-"+m+"-"+y ;
				m = listnum[m] ;
				$("#ddaily").hide("slow") ;
				jQuery.ajax({

				type:"POST",
				url: 'views.php',
				dataType: 'json',
				data: {year:y , month:m  , date:d},

				success: function(obj , textstatus) {
					if(!('error' in obj))
					{
						views = obj.result ;
						console.log(views);
						$("#daily-cont").empty() ;
						var addon = "<h5 style='color:white'>Page Views on " + dt + " : <b>" + views + "</b></h5>" ;
						$("#daily-cont").html(addon);
						$("#dailyres").show("slow") ;
					}
					else
					{
						console.log("cencvorvnoreivnreoibne") ;
						console.log(obj.error);
					}
				}
			});
			
			} // else

		}) // end of date selection function


		$("#again-views").click(function(){
			$("#dailyres").hide("slow" , function(){
				$("#daily-views").show("slow") ;
			}) ;

		})

		
		$("#last30").click(function(){
			$("#dis-img").fadeOut(800 , function(){
				$("#dis-img").html("<img src='last30.png'>") ;
				$("#dis-img").fadeIn(1000);
			})
			
		})

		$("#last60").click(function(){
			$("#dis-img").fadeOut(800 , function(){
				$("#dis-img").html("<img src='last60.png'>") ;
				$("#dis-img").fadeIn(1000);
			})
		})

		$("#last90").click(function(){
			$("#dis-img").fadeOut(800 , function(){
				$("#dis-img").html("<img src='last90.png'>") ;
				$("#dis-img").fadeIn(1000);
			})
		})

		$("#overall-btn").click(function(){
			$("#dis-img").fadeOut(800 , function(){
				$("#dis-img").html("<img src='overall.png'>") ;
				$("#dis-img").fadeIn(1000);
			})
		}) // end of down button




	})
</script>
<div id="dis-img" style="height:365px">
<img src="overall.png">
</div>

<br><br>
<div class="rows">
<!-- here is the monthly analysis stuff starts .......................................................................... -->

<div class="col-md-5">
<button class="btn" id="mon-views" style="background-color:#607D8B;color:white"><h4>Get Monthly Analysis</h4></button>

<div id="ymonth">
<div class="rows">
<div class="col-md-2">
</div>
<div class="col-md-5">
<select id="syear" class="form-control" style="background:transparent ; width:170px;height:30px">
	<option value="" selected>Select Year</option>
<?php
include("dbcon.php");
$yearquery = "Select distinct(year) from user_views" ;

mysqli_select_db($conn , "wiki") ;
$result = mysqli_query($conn , $yearquery) ;
while($row = mysqli_fetch_assoc($result))
{
	?>
	<option value="<?php  echo $row['year'];?>"><?php echo $row['year'] ?></option>
 	<?php
}
?> 
</select>
</div>
<div class="col-md-3">
<button class="btn" id="mon-next-year" style="background-color:#AFB42B;height:31px">Next</button>
</div>
</div>
</div>


<div id="mmonth">
<div class="rows">
<div class="col-md-2">
</div>
<div class="col-md-5">
<select id="smonth" class="form-control" style="background:transparent ; width:160px;height:30px">
	<option value="" selected>Select Month</option>
</select>
</div>
<div class="col-md-3">
<button class="btn" id="mon-next-month" style="background-color:#304FFE;height:31px;color:white">Analyse</button>
</div>
</div>

</div>
	



</div>

<!-- <div class="col-md-2">
<h4 style="color:white">Monthly Analysis</h4>
</div>

<div class="col-md-1" id="monthly">

<select id="syear" class="form-control" style="background:transparent ; width:80px;height:30px">
	<option value="" selected>Year</option>
<?php
// $yearquery = "Select distinct(year) from user_views" ;
// mysqli_select_db($conn , "wiki") ;
// $result = mysqli_query($conn , $yearquery) ;
// while($row = mysqli_fetch_assoc($result))
// {
// 	?>
	<option value="<?php // echo $row['year'];?>"><?php //echo $row['year'] ?></option>
// 	<?php
// }
?> 
</select>
</div>
<div class="col-md-1">
<select id="smonth" onfocus="getmonth()"  class="form-control" style="background:transparent;width:90px;height:30px" >
	<option value="" selected style="color:black">Month</option>
</select>
<br>
</div>

<div class="col-md-1">
<button class="btn" id="mon-btn" style="background-color:#B71C1C;color:white;height:30px;">Analyse</button>
</div>
 -->

 <?php 
$main = $_GET['s'] ;
 ?>
}
<div class="col-md-2">
<h3 style="color:white"><?php echo $main ?></h3>
</div>

<div class="col-md-4">
<!-- here is get daily user view stuff starts.....................................-->
<button class="btn" id="daily-views" style="background-color:#607D8B;color:white"><h4>Get Daily Page Views</h4></button>


<div id="ydaily">
<div class="rows">
<div class="col-md-6">
<select id="syeardaily" class="form-control" style="background:transparent ; width:160px;height:30px">
	<option value="" selected>Select Year</option>
<?php
$yearquery = "Select distinct(year) from user_views" ;
mysqli_select_db($conn , "wiki") ;
$result = mysqli_query($conn , $yearquery) ;
while($row = mysqli_fetch_assoc($result))
{
	?>
	<option value="<?php echo $row['year'];?>"><?php echo $row['year'] ?></option>
	<?php
}
?> 
</select>
</div>
<div class="col-md-4">
<button class="btn" id="next-year" style="background-color:#00E676;height:31px">Next</button>
</div>
</div>
</div>

<div id="mdaily">
<div class="rows">
<div class="col-md-6">
<select id="smonthdaily" class="form-control" style="background:transparent ; width:160px;height:30px">
	<option value="" selected>Select Month</option>
</select>
</div>
<div class="col-md-4">
<button class="btn" id="next-month" style="background-color:#00E676;height:31px">Next</button>
</div>
</div>

</div>

<div id="ddaily">
<div class="rows">
<div class="col-md-6">
<select id="sdatedaily" class="form-control" style="background:transparent ; width:160px;height:30px">
	<option value="" selected>Select Date</option>
</select>
</div>
<div class="col-md-4">
<button class="btn" id="next-date" style="background-color:#64DD17;height:31px">GO</button>
</div>
</div>
</div>

<div id="dailyres">
<div class="rows">
<div class="col-md-8">
<div id="daily-cont">
<h5>User Views on 15-September-2016 : 4589 </h5>
</div>
</div>
<div class="col-md-4">
<button class="btn" id="again-views" style="background-color:#00BCD4;height:31px">Another</button>
</div>
</div>
</div>



</div>
<br><br><br><br>
<div class="rows">
<div class="col-md-3">  <!-- First down button -->
<button class="btn" style="background-color:#004D40;color:white" id="last30"><h4>Last 30 days Analysis</h4></button> 
</div>
<div class="col-md-3">  <!-- Second down button -->
<button class="btn" style="background-color:#F57F17;color:white" id="last60"><h4>Last 60 days Analysis</h4></button>
</div>
<div class="col-md-3">  <!-- Third down button -->
<button class="btn" style="background-color:#006064;color:white" id="last90"><h4>Last 90 days Analysis</h4></button>
</div>
<div class="col-md-3">  <!-- Fourth down button -->
<button class="btn" style="background-color:#DD2C00;color:white " id="overall-btn"><h4>Overall Analysis</h4></button>
</div>
</div>
</div>
</body>
</html>