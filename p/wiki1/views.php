<?php
function getViews($year , $month , $date) 
{
	$t = array() ;



	include("dbcon.php") ;

	$query = "SELECT views from user_views where year='$year' and month='$month' and date='$date';" ;

	mysqli_select_db($conn , "wiki") ;

	$result = mysqli_query($conn , $query) ;

	while($row = mysqli_fetch_assoc($result))
	{
		array_push($t, $row['views']) ;
	}

	return $t ;
}
?>

<?php
header('Content-Type: application/json');

    $aResult = array();

    if( !isset($aResult['error']) ) {


    	$yearPost = $_POST["year"] ;
    	$monthPost = $_POST["month"] ;
    	$datePost = $_POST["date"] ;

    	$aResult['result'] = getViews($yearPost , $monthPost , $datePost) ;

    	


    }

    echo json_encode($aResult);
?>