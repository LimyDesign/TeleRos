<?php
ob_start("ob_gzhandler",9);
ini_set("display_errors", "1");
require ("php/_config.inc");
require ("php/_functions.inc");


//готовый отчет
if (isset ($_GET['rep'])  && @$_GET['srep'])
{

$Qurl="SELECT `name` FROM accreport WHERE  `id_report`='".$_GET['srep']."'";
$UResult = mysql_db_query ($Dbname,$Qurl) or die ("ERROR RQuery: нет контакта с базой");
		if (mysql_num_rows($UResult)) 
			{
			$arrU = mysql_fetch_array($UResult);
			$REPORT=$arrU[0];
			
			}


}




?>
<html><head>
<title>ACCtools статистика звонков <?=$REPORT; ?></title>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<meta name="description" content="Savage Studio tools " />
<meta name="keywords" content="" />

</head><body leftmargin=0 topmargin=0>

<link href="style.css" rel="stylesheet" type="text/css">

<?
include ("content/_staprint.inc");
?>

</body></html>
