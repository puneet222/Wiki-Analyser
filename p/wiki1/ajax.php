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
		background-color: #00695C ;
	}
	section button {
  margin: 0 auto;
  font-size: 2rem;
  padding: 1rem 2.5rem;
  display: block;
  background-color: #00695C;
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
  background-color: #00E676;
  color: white;
  border-color: white;
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
$main = $_GET['s'] ;
?>
<br>
<h2 style="color:#ECEFF1">Basic Analysis of <?php echo $main ;?></h2>



<div class="rows">

<div class="col-md-6">

<?php
$passlink = $_POST['plink'];

// echo $passlink ;

$nocache = rand();
echo "<img src='myplot.png?$nocache' /> "; 
?>
</div>

<div class="col-md-6">
<br><br><br><br><br>
<div class="rows">  <!--- First row -->

<div class=col-md-6>
<section>
<a href="type.php?t=File&s=<?php echo $passlink?>" target="_blank"><button id="File"  type="button" ">Files</button></a>
</section>
</div>
<div class=col-md-6>
<section>
<a href="type.php?t=Template&s=<?php echo $passlink?>" target="_blank"><button id="Template" type="button">Template</button></a>
</section>
</div>
<br>
<div class="rows">  <!--- Second -->
<div class=col-md-6>
<section>
<a href="type.php?t=Media&s=<?php echo $passlink?>" target="_blank"><button id="Media" type="button">Media</button></a>
</section>
</div>
<div class=col-md-6>
<section>
<a href="type.php?t=Special&s=<?php echo $passlink?>" target="_blank"><button id="Special" type="button">Special</button></a>
</section>
</div>
</div>

<br>
<div class="rows">   <!--- third row -->

<div class="col-md-6">
<section>
<a href="type.php?t=Wikipedia&s=<?php echo $passlink?>" target="_blank" ><button id="Wikipedia" type="button">Wikipedia</button></a>
</section>
</div>
<br>
<div class="col-md-6"> <!-- fourth -->
<section>
<a href="type.php?t=MediaWiki&s=<?php echo $passlink?>" target="_blank"><button id="MediaWiki" type="button">MediaWiki</button></a>
</section>
</div>


</div>
<br>
<div class="rows">  <!--- fifth row -->

<div class=col-md-6>
<section>
<a href="type.php?t=Category&s=<?php echo $passlink?>" target="_blank"><button id="Category" type="button">Category</button></a>
</section>
</div>
<div class=col-md-6>
<section>
<a href="type.php?t=Book&s=<?php echo $passlink?>" target="_blank"><button id="Book" type="button">Book</button></a>
</section>
</div>
</div>
<br>
<div class="rows">   <!-- sixth row -->
<div class=col-md-6>
<section>
<a href="type.php?t=Portal&s=<?php echo $passlink?>" target="_blank"><button id="Portal" type="button">Portal</button></a>
</section>
</div>
<div class=col-md-6>
<section>
<a href="type.php?t=Draft&s=<?php echo $passlink?>" target="_blank"><button id="Draft" type="button">Draft</button></a>
</section>
</div>

</div>

<br><br><br><br><br><br><br><br><br><br>
<div class="rows">
<div class="col-md-12">

	<a href="analyze.php?s=<?php echo $passlink?>"><button class="btn" style="background-color:#FF3D00 ; padding : 10px ; color:white"><h4>Go to Analyze Page</h4></button>

</div>
</div>

</div>

</div>
</div>


<?php

$type = $_POST["type"] ;
$name = $_POST["name"] ;
$link = $_POST["link"] ;


// echo $type ;
// echo $name ;
// echo $link ;



$dtype = explode(",", $type) ;
$dname = explode(",", $name) ;
$dlink = explode(",", $link) ;


// // database thing

include("dbcon.php") ;

$len  = count($dtype) ;

$delete = "DELETE from table1" ;
$deltype = "Drop table typecount" ;
$drop = "DROP TABLE sum" ;
mysqli_select_db($conn, "wiki");

mysqli_query($conn , $drop) ;
$status2 = mysqli_query($conn , $delete) ;

if(!$status2)
{
	die('Could not '.mysqli_error());
}
else
{
	// echo "query may be executed" ;
}

$status3 = mysqli_query($conn , $deltype) ;

if(!$status3)
{
	die('Could not '.mysqli_error());
}
else
{
	// echo "query may be executed" ;
}

for ($i=0; $i < $len ; $i++) { 
	
	$query = "insert into table1 values('$dtype[$i]' , '$dname[$i]' , '$dlink[$i]') ;" ;

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
exec('"D:\SOFTWARE\R-3.2.3\bin\Rscript.exe" "Rscript.R" 2>&1', $output);

// print_r($output);

  // return image tag

?>















<?php

//   for file
	$filequery = "Select * from typecount" ;
	mysqli_select_db($conn , "wiki");

	$result = mysqli_query($conn , $filequery);

	while($row = mysqli_fetch_assoc($result)){

		
		if($row["count"] > 0)
		{
			//here comes the javascript
		}
		else
		{
			?>
			<script type="text/javascript">

			var id = "#" + '<?php echo $row["type"] ?>' ;

			// alert(id) ;
			$(id)[0].disabled = true;

			</script>
 
			<?php
		}
	}

	?>




</div>

</body>
</html>
