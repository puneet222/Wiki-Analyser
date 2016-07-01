<link rel="stylesheet" type="text/css" href="bootstrap/css/bootstrap.min.css">
<!-- <link rel="stylesheet" type="text/css" href="bootstrap/css/bootstrap-responsive.css">
<link rel="stylesheet" type="text/css" href="bootstrap/css/bootstrap-responsive.min.css"> -->
<link rel="stylesheet" type="text/css" href="css/home.css">

<html>
<head>
<title>Wikipedia Analyser</title>
<script src="http://ajax.googleapis.com/ajax/libs/jquery/1.5.1/jquery.js"></script>
<style type="text/css">
  body{
    background-color: #827717 ;
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
<br><br><br><br>

<div class="container" id="preview">

 
    
    <?php

      $link = $_GET['link'] ;

	?>

<script type="text/javascript">
$(document).ready(function() {
    var new_link = "<?php echo $link ; ?>";
    // console.log("search elemet is : " + link) ;

    var arr = new_link.split(" ") ;
    var siz = arr.length ;
    console.log("bcdsjvnc akj cnsdkcjnv" + arr) ;
    for(var i = 0 ; i < siz ; i++)
    {
    	arr[i] = encodeURIComponent(arr[i]) ;
    }

console.log(link);
    
    var link = arr.join("_") ; 





    // link = encodeURIComponent(new_link) ;
    // console.log("after encoding : " + link);
    var extract_data = "" ;
    // alert(link) ;

// /w/api.php?action=query&format=json&prop=extracts&titles=Programming_paradigm&utf8=1&ascii=1&exintro=1&explaintext=1

$.ajax({
        type: "GET",
        url : "https://en.wikipedia.org//w/api.php?action=query&format=json&prop=extracts&titles=" + link + "&utf8=1&ascii=1&exintro=1&explaintext=1&callback=?",
        contentType: "application/json; charset=utf-8",
        async: true,
        dataType : "json" ,
        success: function(data , textStatus, jqXHR){
          console.log(data);
          
          var len = data.length;

          var pageid = Object.keys(data["query"].pages) ;

          extract_data = data["query"].pages[pageid].extract ;
          // console.log("data is : " + extract_data);
         
          var cont = "<br><br><h2 style='color:white'>"+ new_link +"</h2>  \
			<br>"


			$("#head").append(cont);
			var show = "<button class='btn'  id='show'><h4>Click to see the brief introduction of the Article</h4></button>"

			var hide = "<br><button class='btn'  id='hide'><h4>Click to Hide</h4></button>"
			$("#show-btn").append(show);
      

			var para = "<br> <div class='well' style='background-color : #006064;'><p id='brief'>" + extract_data + "</p></div>" ;
			var flag = 0 ;

			$("#show").click(function() {



    			var el = $("<div />").css("display", "none").html(para) ;
    			$("#inner-para").append(el);
    			el.show(1000);

          $("#wiki_btn").animate({right:'150px'}) ;
          $("#analyse-btn").animate({right:'145px'}) ;


    			var el2 = $("<div />").css("display", "none").html(hide) ;
    			$("#t").append(el2);
    			el2.slideDown(1000);
 
    			$("#show").hide(1000) ;

				})

					$('#hide').live('click', function(){ 

 					$("#t").empty() ;
					$("#brief").hide(500 , function(){
						$("#inner-para").empty();
					});
          $("#wiki_btn").animate({right:'10px'}) ;
          $("#analyse-btn").animate({right:'50px'}) ;
					$("#show").show(500);
					
 					})


					var wiki = "<br><a href='https://en.wikipedia.org/wiki/"+ link + "' target='_blank'><button class='btn' id='wiki_btn'><h4>Wikipedia Link of the Article</h4></button></a>" ;

					console.log("value of link is :" + link) ;

					var analyze = "<a href='analyze.php?s=" + link + "' target='_blank'><button class='btn' id='analyse-btn'><i class='fa fa-car fa-lg'></i><h4>Analyze the Article<h4></button></a>" ;


					$("#w").append(wiki) ;
					$("#a").append(analyze) ;
		    
          

        }
        
       
      })


}) ;


</script>


<div class="" id="main">

		<div id="head">
		</div>

		<div id="show-btn">
		</div>


   
		<div id="inner-para">
		</div>

		<div id="wiki-anly">

    <div class="rows">

    <div class="col-xs-3"></div>
    <div class="col-xs-4" id="w"></div>
    <div class="col-xs-1" id="a"></div>
    <div class="col-xs-2" id="t"></div>
    </div>
		</div>

</div>

</div>

<body>

</html>