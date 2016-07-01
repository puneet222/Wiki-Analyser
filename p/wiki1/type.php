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
<title>Wikipedia Analyser</title>
<style type="text/css">
	body{
	background-color: #1B5E20 ;
}

section button {
  margin: 0 auto;
  font-size: 1.4rem;
  padding: 1rem 2.5rem;
  display: block;
  background-color: #1B5E20;
  border: 1px solid transparent;
  color: #ffffff;
  font-weight: 300;
  -webkit-border-radius: 3px;
  border-radius: 3px;
  -webkit-transition: all 0.3s ease-in-out;
  -moz-transition: all 0.3s ease-in-out;
  transition: all 0.3s ease-in-out;
}

section button:hover {
  background-color: #FF6F00;
  color: black;
  border-color: #FF6F00;
}


.scroll-pre {
	background-color: #4DD0E1 ;
  height: 120px;
  width: 100%;
  position: fixed;
}

#test:hover{
	background-color: #4DD0E1 ;
}

.my-own-style{
	height: 0px ;
}


</style>
<script src="http://ajax.googleapis.com/ajax/libs/jquery/1.5.1/jquery.js"></script>
<script src="javaS/first.js"></script>
</head>
<body>

<nav class="navbar navbar-default navbar-fixed-top my-own-style">
<ul class="nav navbar">
  <li id="wikianly"><a href="#" id="test"><h3>Wikipedia Analyser</h3></a></li>
  <li id="help"><a href="help.php" id="test" ><h4>Help</h4></a></li>
  <li id="contact"><a href="contact.php" id="test" ><h4>Contact</h4></a></li>
  <li id="about"><a href="about.php" id="test" ><h4>About</h4></a></li>
</ul>
</nav>
<br>
<br>
<br>
<br>

<div class="container">


<?php
$type = $_GET['t'] ;
// echo $type ;
$search = $_GET['s'] ;
// echo $search ;
?>
<h2 style=color:white>Here are the Available <?php echo $type?>s of Topic <?php echo $search?> </h2>
<?php
include("dbcon.php") ;

$query = "SELECT name , link from table1 where type='$type'" ;
// echo $query ;
mysqli_select_db($conn , "wiki") ;
$result = mysqli_query($conn , $query);
$i = 0 ;

	while($row = mysqli_fetch_assoc($result)){
		$i++ ;
		if($i % 2 != 0)
		{
		?>
		<br><br>
		<div class="rows">
		<div class="col-md-6">
		<section>
		<a href="<?php echo $row['link']?>" target="_blank"><button type="button" class="down"><h4><?php echo $row['name']?></h4></button></a>
		</section>
		</div>
		</div>
		<?php

	}// enf if

	else{
		?>
		<div class="col-md-6">
		<section>
		<a href="<?php echo $row['link']?>" target="_blank"><button type="button"><h4><?php echo $row['name']?></h4></button></a>
		</section>
		</div>
		<?php
	}

		
	}

?>
</body>
</html>