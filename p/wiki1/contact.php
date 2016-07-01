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
<script src="http://ajax.googleapis.com/ajax/libs/jquery/1.5.1/jquery.js"></script>
<script src="javaS/first.js"></script>
<style type="text/css">
	body{
		background-color: #757575;
	}
</style>
</head>
<body>

<div id="nav">
<ul>
  <li id="wikianly"><a href="#"><h3>Wikipedia Analyser</h3></a></li>
  <li id="help"><a href="help.php"><h4>Help</h4></a></li>
  <li id="contact"><a href="contact.php" class="active"><h4>Contact</h4></a></li>
  <li id="about"><a href="about.php"><h4>About</h4></a></li>
</ul>
</div>
<br>
<br>
<br>
<div class="container">
<script type="text/javascript">
$(document).ready(function(){
	$("#dismail").hide() ;
	$("#discon").hide() ;

		$("#email").click(function(){
			$("#email").hide("slow" , function(){
				$("#dismail").show("slow") ;
			})
	})

		$("#contacti").click(function(){
			$("#contacti").hide("slow" , function(){
				$("#discon").show("slow");
			})
			// alert("cjkvnoi") ;
		})
})
</script>

<div class="text-center">
<br><br><br>
<button class="btn" style="background:transparent;border-color:#64FFDA"><h1 style="color:white">Puneet Aggarwal</h1></button>
<br><br><br><br>
<div id="em">
<button class="btn" id="email" style="background-color:orange;color:white"><h2>Contact via E-MAIL<h2></button>
<h1 id="dismail" style="color:white">E-mail: aggarwal.puneet222@gmail.com</h1>
</div>
<br><br>
<div id="con">
<button id="contacti" class="btn" style="background-color:orange;color:white"><h2>Contact via Phone<h2></button>
<h1 id="discon" style="color:white">Contact: +91 9988182547</h1>
</div>
<br><br><br><br>
<div class="rows">
<div class="col-md-4">
</div>
<div class="col-md-2">
<button class="btn btn-primary" style="width:150px"><h4>facebook</h4></button>
</div>

<div class="col-md-2">
<button class="btn" style="color:white;background-color:black;width:150px"><h4>github</h4></button>
</div>
</div>
</div>

</div>
</body>
</html>