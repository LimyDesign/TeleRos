<?php                                             

$Host      = "localhost";
$User      = "utel";
$Password  = "ptel";
$Dbname    = "tel"; // Имя базы данных

$jrver		= '1.0a';

$Url="http://".$_SERVER['HTTP_HOST'] ."/jrate/";
$homeurl = $_SERVER['REQUEST_URI'];
$home = "http://" . $_SERVER['HTTP_HOST'] ;

//smarty
define('SMARTY_DIR', str_replace("\\", "/", getcwd()).'/smarty/libs/');
require_once(SMARTY_DIR . 'Smarty.class.php');
$smarty->template_dir = 'templates/';
$smarty->compile_dir = 'templates_c/';
$smarty->config_dir = 'configs/';
$smarty->cache_dir = 'cache/';
//end smarty
$REPORT="";
$SFind="";

// bootstrap vars
$active_class = 'class="active"';

// Array for selected active page
$active = array();


mysql_connect ($Host, $User, $Password); 
mysql_select_db($Dbname);
mysql_set_charset('utf8');

date_default_timezone_set('Asia/Irkutsk');

?>
