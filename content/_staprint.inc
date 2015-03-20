<?


$qdata = make_select(0,0);

function make_sel_par()
{
GLOBAL  $Dbname;
$res=array("Время формирования:",date("j.m.Y H:i"));

if (@$_GET['repname']) 
	{
	$res[]="Название отчета:";
	$res[]=$_GET['repname'];
	}




if (@$_GET['band'] && @$_GET['band']!='null') 
	{
	$res[]="Тарифная зона";$res[]="";
	$BQuery = "SELECT `Name` FROM  `bands` a WHERE `BandId`='".$_GET['band']."'";
	$BResult = mysql_db_query ($Dbname,$BQuery) or die ("ERROR BQuery: нет контакта с базой");
	$arrB = mysql_fetch_array($BResult);
	$res[]=$arrB[0] ;
	}

if (isset($_GET['direct'])) 
	{
	$res[]="Направление звонков:";
	if ($_GET['direct']=='1') {$res[]="Только входящие"; }
	elseif ($_GET['direct']=='2') {$res[]="Только исходящие"; }
	else {$res[]="Все"; }
	}
if (@$_GET['rphone']) 
	{
	$res[]="Номер телефона:";
	$res[]=$_GET['rphone'];
	}
if (@$_GET['dep'] && @$_GET['dep']!='null') 
	{
	$res[]="Подразделение абонента: ";$res[]="";
	$BQuery = "SELECT `Name`  FROM  `departs`  WHERE `DepId`='".$_GET['dep']."'";
	$BResult = mysql_db_query ($Dbname,$BQuery) or die ("ERROR BQuery: нет контакта с базой");
	$arrB = mysql_fetch_array($BResult);
	$res[]=$arrB[0] ;
	}


if (@$_GET['person'] && @$_GET['person']!='null') 
	{
	$res[]="Внутренний абонент: ";
	$BQuery = "SELECT `Name`  FROM  `person`  WHERE `PersonId`='".$_GET['person']."'";
	$BResult = mysql_db_query ($Dbname,$BQuery) or die ("ERROR BQuery: нет контакта с базой");
	$arrB = mysql_fetch_array($BResult);
	$res[]=$arrB[0] ;
	}

if (@$_GET['depat'] && @$_GET['depat']!='null') 
	{
	$res[]="Местоположение абонента: ";
	$BQuery = "SELECT `OfficeName` FROM `offices` WHERE`OfficeId`='".$_GET['depat']."'";
	$BResult = mysql_db_query ($Dbname,$BQuery) or die ("ERROR BQuery: нет контакта с базой");
	$arrB = mysql_fetch_array($BResult);
	$res[]=$arrB[0] ;
	}

if (@$_GET['dur']) 
	{
	$res[]="Продолжительность разговора:";
	if ($_GET['sdur']=='1') $res[]="больше ".$_GET['dur'];
	else $res[]="меньше ".$_GET['dur'];
	}

if (@$_GET['tarif']) 
	{
	$res[]="Только тарифицируемые:";
	$res[]="ДА";
	}


if (@$_GET['trunk'] && @$_GET['trunk']!='null') 
	{
	$res[]="Транковая группа: ";
	$BQuery = "SELECT `tac`,`trunkname` FROM `trunk` WHERE `tac`='".$_GET['trunk']."'";
	$BResult = mysql_db_query ($Dbname,$BQuery) or die ("ERROR BQuery: нет контакта с базой");
	$arrB = mysql_fetch_array($BResult);
	$res[]=$arrB[0] ;
	}

if  (@$_GET['me'] || @$_GET['etime'] || @$_GET['ftime'] )
	{
	$pr='';	
	$res[]="За период времени:";
	if (@$_GET['me']) 
		{
		$m=date ('n');
		$y= date ('Y');
		if  (@$_GET['me']=='1')
		{
		$pr="с ".$y."-".sprintf("%02d",$m-1)."-01 00:00:00 по ".$y."-".sprintf("%02d",($m))."-01 00:00:00";
		}
		else
		{
		$pr=" с ".$y."-".sprintf("%02d",($m));
		}	

		}	
	else
		{
		if (@$_GET['ftime']) $pr.=" c ".@$_GET['ftime']; 
		if (@$_GET['etime']) $pr.=" по ".@$_GET['ftime']; 
		}
	$res[]=$pr;
	}

return $res;
}





$smarty_select = new Smarty();
$smarty_select->assign('sdata',make_sel_par());

$smarty_select ->assign('std',array("class='hdrb'","class='hdr'"));

$smarty_select ->assign('tr',array('bgcolor="#ffffff"','bgcolor="#eeffff"'));
$smarty_select ->assign('th',array('bgcolor="#EEEEEE"','bgcolor="#EEEEEE" colspan=2','bgcolor="#EEEEEE" colspan=2','bgcolor="#EEEEEE"','bgcolor="#EEEEEE"','bgcolor="#EEEEEE"'));
$smarty_select->assign('rcount',$qdata[0]);
$smarty_select->assign('data',$qdata[1]);
$smarty_select->display('staprint.tpl');

?>
