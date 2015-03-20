<?

//форма отбора
$smarty_index = new Smarty();
//** раскомментируйте следующую строку для отображения отладочной консоли
//$smarty->debugging = true;

//select тарифная зона
$BQuery = "SELECT `BandId`,`Name` FROM  `bands` a WHERE `BandId` IN (SELECT `BandId` FROM `masks`)";
$arrband_id= array('null');
$arrband_name= array('Все тарифные зоны ');
		$BResult = mysql_db_query ($Dbname,$BQuery) or die ("ERROR BQuery: нет контакта с базой");
		if (mysql_num_rows($BResult)) 
			{
			while ($arrB = mysql_fetch_array($BResult))
				{
				$arrband_id[]=$arrB[0] ;
				$arrband_name[]=$arrB[1];
				//print_r($arrband_name);
				}
			}


$smarty_index ->assign('band_id',$arrband_id);
$smarty_index ->assign('band_name',$arrband_name);

if (isset($_GET['band'])) $smarty_index ->assign('band',$_GET['band']);
else $smarty_index ->assign('band','null');


//end select тарифная зона
//select абонент
$smarty_index ->assign('direct_id',array('0','1','2'));
$smarty_index ->assign('direct_name',array('Все','Входящие','Исходящие'));
if (isset($_GET['direct'])) $smarty_index ->assign('direct',$_GET['direct']);
else $smarty_index ->assign('direct','0');



$BQuery = "SELECT `PersonId`,`Name` FROM `person` ORDER BY `Name`";
$arrband_id= array('null');
$arrband_name= array('Все абоненты ');
		$BResult = mysql_db_query ($Dbname,$BQuery) or die ("ERROR BQuery: нет контакта с базой");
		if (mysql_num_rows($BResult)) 
			{
			while ($arrB = mysql_fetch_array($BResult))
				{
				$arrband_id[]=$arrB[0] ;
				$arrband_name[]=$arrB[1];
				//print_r($arrband_name);
				}
			}


$smarty_index ->assign('person_id',$arrband_id);
$smarty_index ->assign('person_name',$arrband_name);
if (isset($_GET['person'])) $smarty_index ->assign('person',$_GET['person']);
else $smarty_index ->assign('person','null');
//end select абонент
//DepId	Name
//select отдел
$BQuery = "SELECT `DepId`,`Name` FROM `departs` ORDER BY `Name`";
$arrband_id= array('null');
$arrband_name= array('Все отделы ');
		$BResult = mysql_db_query ($Dbname,$BQuery) or die ("ERROR BQuery: нет контакта с базой");
		if (mysql_num_rows($BResult)) 
			{
			while ($arrB = mysql_fetch_array($BResult))
				{
				$arrband_id[]=$arrB[0] ;
				$arrband_name[]=$arrB[1];
				//print_r($arrband_name);
				}
			}


$smarty_index ->assign('dep_id',$arrband_id);
$smarty_index ->assign('dep_name',$arrband_name);
if (isset($_GET['dep'])) $smarty_index ->assign('dep',$_GET['dep']);
else $smarty_index ->assign('dep','null');


//end select отдел
//select offices
//OfficeId,OfficeName

$BQuery = "SELECT `OfficeId`,`OfficeName` FROM `offices` ORDER BY `OfficeName`";
$arrband_id= array('null');
$arrband_name= array('Все кабинеты ');
		$BResult = mysql_db_query ($Dbname,$BQuery) or die ("ERROR BQuery: нет контакта с базой");
		if (mysql_num_rows($BResult)) 
			{
			while ($arrB = mysql_fetch_array($BResult))
				{
				$arrband_id[]=$arrB[0] ;
				$arrband_name[]=$arrB[1];
				//print_r($arrband_name);
				}
			}


$smarty_index ->assign('offices_id',$arrband_id);
$smarty_index ->assign('offices_name',$arrband_name);
if (isset($_GET['depat'])) $smarty_index ->assign('offices',$_GET['depat']);
else $smarty_index ->assign('offices','null');

//end select offices

//OfficeId,OfficeName
//tac,	trunkname
$BQuery = "SELECT `tac`,`trunkname` FROM `trunk` ORDER BY `trunkname`";
$arrband_id= array('null');
$arrband_name= array('Все транки ');
		$BResult = mysql_db_query ($Dbname,$BQuery) or die ("ERROR BQuery: нет контакта с базой");
		if (mysql_num_rows($BResult)) 
			{
			while ($arrB = mysql_fetch_array($BResult))
				{
				$arrband_id[]=$arrB[0] ;
				$arrband_name[]=$arrB[1];
				//print_r($arrband_name);
				}
			}


$smarty_index ->assign('trunk_id',$arrband_id);
$smarty_index ->assign('trunk_name',$arrband_name);
if (isset($_GET['trunk'])) $smarty_index ->assign('trunk',$_GET['trunk']);
else $smarty_index ->assign('trunk','null');





$RQuery = "SELECT `id_report`,`name`  FROM accreport  ORDER BY `name`";
$arrrep_id= array('null');
$arrrep_name= array('Готовые отчеты ');
		$RResult = mysql_db_query ($Dbname,$RQuery) or die ("ERROR $RQuery: нет контакта с базой");
		if (mysql_num_rows($RResult)) 
			{
			while ($arrR = mysql_fetch_array($RResult))
				{
				$arrrep_id[]=$arrR[0] ;
				$arrrep_name[]=$arrR[1];
				//print_r($arrband_name);
				}
			}

$smarty_index ->assign('rep_id',$arrrep_id);
$smarty_index ->assign('rep_name',$arrrep_name);
if (isset($_GET['srep'])) $smarty_index ->assign('srep',$_GET['srep']);
else $smarty_index ->assign('srep','null');



if (isset($_GET['rphone'])) $smarty_index ->assign('rphone',$_GET['rphone']);

$smarty_index->assign('sdur','1');
if (@$_GET['sdur']) $smarty_index->assign('sdur', $_GET['sdur']);
$smarty_index ->assign('ftime',@$_GET['ftime']);
$smarty_index ->assign('etime',@$_GET['etime']);


$smarty_index ->assign('llimit_id',array('50','100','500'));
$smarty_index ->assign('llimit_name',array('50','100','500'));
if (isset($_GET['llimit'])) $smarty_index ->assign('llimit',$_GET['llimit']);
else $smarty_index ->assign('llimit','0');
//end select offices

if (isset($_GET['tarif']) && @$_GET['tarif']=='1' ) $smarty_index ->assign('tarif','checked');
else $smarty_index ->assign('tarif','');

if (@$_GET['tsum']) $smarty_index ->assign('tsum','checked');


//соритровки
$smarty_index->assign('dir','1');
if (@$_GET['dir']) $smarty_index->assign('dir', $_GET['dir']);
if (@$_GET['srphone']) $smarty_index ->assign('srphone','checked');
if (@$_GET['sperson']) $smarty_index ->assign('sperson','checked');
if (@$_GET['sdep']) $smarty_index ->assign('sdep','checked');
if (@$_GET['sdepat']) $smarty_index ->assign('sdepat','checked');
if (@$_GET['ssdur']) $smarty_index ->assign('ssdur','checked');
if (@$_GET['strunc']) $smarty_index ->assign('strunk','checkek');
if (@$_GET['me']) $smarty_index->assign('me',$_GET['me']);
//конец соритровки



$smarty_index->display('form.tpl');

//end форма отбора
include ('content/_stat.inc');

?> 
