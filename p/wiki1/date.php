<?php
function getDat($year , $month) 
{
	$t = array() ;

	

	include("dbcon.php") ;

	$query = "SELECT distinct(date) from user_views where year='$year' and month='$month';" ;



	mysqli_select_db($conn , "wiki") ;

	$result = mysqli_query($conn , $query) ;

	while($row = mysqli_fetch_assoc($result))
	{
		array_push($t, $row['date']) ;
	}

	return $t;
}


?>

<?php
header('Content-Type: application/json');

    $aResult = array();

    if( !isset($aResult['error']) ) {


    	$yearPost = $_POST["year"] ;
        $monthPost = $_POST['month'] ;

        $monthnum = 

    	$aResult['result'] = getDat($yearPost,$monthPost) ;

    }

    echo json_encode($aResult);
?>
