<?php
function getMonth($year) 
{
	$t = array() ;

	$y = $_POST['year'] ;

	include("dbcon.php") ;

	$query = "SELECT distinct(month) from user_views where year='$year' ;" ;

	mysqli_select_db($conn , "wiki") ;

	$result = mysqli_query($conn , $query) ;

	while($row = mysqli_fetch_assoc($result))
	{
		array_push($t, $row['month']) ;
	}

	return $t ;
}
?>

<?php
header('Content-Type: application/json');

    $aResult = array();

    if( !isset($aResult['error']) ) {


    	$yearPost = $_POST["year"] ;

    	$aResult['result'] = getMonth($yearPost) ;

    	


    }

    echo json_encode($aResult);
?>