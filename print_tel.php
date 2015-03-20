<?php
ob_start("ob_gzhandler",9);
ini_set("display_errors", "1");
require ("php/_config.inc");
require ("php/_functions.inc");

?>
<html><head>
<title>ACCtools справчник телефонов </title>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<meta name="description" content="Savage Studio tools " />
<meta name="keywords" content="" />

</head><body leftmargin=0 topmargin=0>

<link href="style.css" rel="stylesheet" type="text/css">

<?
include ("content/_print_tel.inc");
?>

</body></html>
