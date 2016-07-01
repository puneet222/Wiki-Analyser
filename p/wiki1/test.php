<!DOCTYPE html>
<link rel="stylesheet" type="text/css" href="bootstrap/css/bootstrap.min.css">
<!-- <link rel="stylesheet" type="text/css" href="bootstrap/css/bootstrap-responsive.css">
<link rel="stylesheet" type="text/css" href="bootstrap/css/bootstrap-responsive.min.css"> -->
<link rel="stylesheet" type="text/css" href="css/home.css">
<link rel="stylesheet" type="text/css" href="font-awesome-4.6.3/css/font-awesome.min.css">
<link rel="stylesheet" type="text/css" href="font-awesome-4.6.3/css/font-awesome.css">
<html>
<head>
<script src="jquery.js"></script>
	<title></title>
<style type="text/css">
	header, .full-width {
  width: 100%;
  background: #ccc;
}
.wrap {
  width: 80%;
  max-width: 24em;
  margin: 0 auto;
  padding: 0.25em 0.625em;
}

html, body {
  overflow-x: hidden;
}
.full-width-bar {
  margin: 0 -9999rem;
  /* add back negative margin value */
  padding: 0.25rem 9999rem;
  background: rgba(0, 0, 0, 0.5);
}
.scroll-pre {
  height: 100px;
  width: 100%;
  background-color: inherit;
  position: fixed;
}

</style>
<script type="text/javascript">

	jQuery.ajax({
    type: "POST",
    url: 'month.php',
    dataType: 'json',
    data: {year: "2015"},
    success: function (obj, textstatus) {

                  if( !('error' in obj) ) {
                      yourVariable = obj.result;
                      console.log(yourVariable) ;
                  }
                  else {
                      console.log(obj.error);
                  }
            }
});
console.log("cencvorvnoreivnreoibne") ;

	jQuery.ajax({

		type:"POST",
		url: 'date.php',
		dataType: 'json',
		data: {year:"2015" , month:"07"},

		success: function(obj , textstatus) {
			if(!('error' in obj))
			{
				dates = obj.result ;
				console.log(dates);
			}
			else
			{
				console.log("cencvorvnoreivnreoibne") ;
				console.log(obj.error);
			}
		}
	});

	jQuery.ajax({

		type:"POST",
		url: 'views.php',
		dataType: 'json',
		data: {year:"2015" , month:"07"  , date:"06"},

		success: function(obj , textstatus) {
			if(!('error' in obj))
			{
				views = obj.result ;
				console.log(views);
			}
			else
			{
				console.log("cencvorvnoreivnreoibne") ;
				console.log(obj.error);
			}
		}
	});
</script>
	<header>
  <div class="wrap">
    <h2>Header</h2>
  </div>
</header>

<h3 class="full-width">
  <div class="wrap">Heading</div>
</h3>
<div class="wrap">
  <p>... text ... </p>
</div>

</head>
<body>
<?php
$year = "2015" ;
$t = array("1" , "2" , "3" , $year);
echo $t[3] ;

$s = array() ;


?>

<nav class="navbar navbar-default navbar-fixed-top my-own-style">
    <ul class="nav navbar-nav">
        <li class="active"><a href="#">Home</a></li>
        <li><a href="#">Link</a></li>
        <li><a href="#">Link</a></li>
        <li class="divider-vertical"></li>
        <li><a href="#">More</a></li>
        <li><a href="#">Options</a></li>
    </ul>
</nav>
<div class="scroll-pre"></div>
<div class="scroll">
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
    <p>Hi World</p>
       Hi World
    <p>Hi World</p>
</div>
</body>
</html>