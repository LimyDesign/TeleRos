<?
$arr_dep=array();


$smarty_select = new Smarty();

$uname='';
$udesc='';
$status='';
$status_type='';
$upid='';
$count=1;
$shrows=100;

if (isset($_GET['filter'])) {	
	switch ($_GET['filter']) {
        case "dep":
			$sfilter= " AND DepId = '".$_GET['DepId']."'";
			break;
		case "office":
			$sfilter= " AND OfficeId = '".$_GET['OfficeId']."'";
			break;
		case "person":
			$sfilter= " AND PersonId = '".$_GET['PersonId']."'";
			break;
	}
} else $sfilter= "";

if (!isset($_GET['ac']) ) $smarty_select->assign('actype','add');
else {
	if ($_GET['ac'] =='add') {
		if (!empty($_GET['name']) && !empty($_GET['person']) && !empty($_GET['office']) && !empty($_GET['dep'])) {
			mysql_db_query ($Dbname,"INSERT INTO  `phones` (`PhoneNumber`,`PersonId`,`OfficeId`,`DepId`) VALUES ('".$_GET['name']."','".$_GET['person']."','".$_GET['office']."','".$_GET['dep']."')"); 
			$smarty_select->assign('actype','add');
			$status='Телефон добавлен';
			$status_type='success';
		} else {
			$smarty_select->assign('actype','add');
			$status='Все поля должны быть заполнены.';
			$status_type='error';
		}
	} elseif ($_GET['ac'] =='del') { 
		mysql_db_query ($Dbname,"DELETE FROM  `phones` WHERE  `PhoneId`='".$_GET['id']."'");
 		$smarty_select->assign('actype','add');
		$status='Телефон удален';
		$status_type='success';
	} elseif ($_GET['ac'] =='edit') { 
		$Result = mysql_db_query ($Dbname,"SELECT `PhoneId`,`PhoneNumber`,`OfficeId`,`PersonId`,`DepId` FROM  `phones` WHERE  `PhoneId`='".$_GET['id']."'");
 		$smarty_select->assign('actype','update');
		$arru = mysql_fetch_array($Result);
		$upid=$arru[0];
		$uname=$arru[1];
		$uoffice=$arru[2];
		$uperson=$arru[3];
		$udep=$arru[4];
		$status='Редактирование телефона';
		$smarty_select->assign('actype','update');
	} elseif ($_GET['ac'] =='update') {
		if (!empty($_GET['name']) && !empty($_GET['person']) && !empty($_GET['office']) && !empty($_GET['dep'])) {
			mysql_db_query ($Dbname,"UPDATE  `phones` SET `PhoneNumber`='".$_GET['name']."',`PersonId`='".$_GET['person']."',`DepId`='".$_GET['dep']."',`OfficeId`='".$_GET['office']."' WHERE  `PhoneId`='".$_GET['upid']."'");
	 		$smarty_select->assign('actype','add');
			$status='Телефон изменен';
			$status_type='success';
		} else {
	 		$smarty_select->assign('actype','update');
			$status='Поля не могут быть пустыми. Если требуется удалить запись, нажмите соответствующую кнопку.';
			$status_type='error';
		}
	} elseif ($_GET['ac'] == 'find') {
		$SFind = "AND (`PhoneNumber` LIKE '%".$_GET['find']."%' OR `Name` LIKE '%".$_GET['find']."%' OR `depatment` LIKE '%".$_GET['find']."%' OR `OfficeName` LIKE '%".$_GET['find']."%')";
	}
}


$arrband_id= array() ;
$arrband_name=array();
// sel deps
$BQuery = "SELECT `DepId`,`Name` FROM `departs` ORDER BY `Name`";
$BResult = mysql_db_query ($Dbname,$BQuery) or die ("ERROR BQuery: нет контакта с базой");
if (mysql_num_rows($BResult)) 
{
	while ($arrB = mysql_fetch_array($BResult)) {
		$arrband_id[]=$arrB[0] ;
		$arrband_name[]=$arrB[1];
	}
}

$smarty_select ->assign('dep_id',$arrband_id);
$smarty_select ->assign('dep_name',$arrband_name);
if (isset($udep)) $smarty_select ->assign('dep',$udep);
else $smarty_select ->assign('dep','0');
//end select отдел


$arrband_id= array() ;
$arrband_name=array();
// sel abonent
$BQuery = "SELECT `PersonId`,`Name` FROM `person` ORDER BY `Name`";
$BResult = mysql_db_query ($Dbname,$BQuery) or die ("ERROR BQuery: нет контакта с базой");
if (mysql_num_rows($BResult)) {
	while ($arrB = mysql_fetch_array($BResult)) {
		$arrband_id[]=$arrB[0] ;
		$arrband_name[]=$arrB[1];
	}
}

$smarty_select ->assign('person_id',$arrband_id);
$smarty_select ->assign('person_name',$arrband_name);
if (isset($uperson)) $smarty_select ->assign('person',$uperson);
else $smarty_select ->assign('person','0');
//end select abonent


$arrband_id= array() ;
$arrband_name=array();
// sel office
$BQuery = "SELECT `OfficeId`,`OfficeName` FROM `offices` ORDER BY `OfficeName`";
$BResult = mysql_db_query ($Dbname,$BQuery) or die ("ERROR BQuery: нет контакта с базой");
if (mysql_num_rows($BResult)) {
	while ($arrB = mysql_fetch_array($BResult)) {
		$arrband_id[]=$arrB[0] ;
		$arrband_name[]=$arrB[1];
	}
}

$smarty_select ->assign('office_id',$arrband_id);
$smarty_select ->assign('office_name',$arrband_name);
if (isset($uoffice)) $smarty_select ->assign('office',$uoffice);
else $smarty_select ->assign('office','0');
//end select office


$SQuery = "SELECT  `PhoneId`,`PhoneNumber`,`Name`,`depatment`,`OfficeName`  FROM `abonent` WHERE 1=1 ".$sfilter." ".$SFind."  ORDER BY `PhoneNumber`" ;
//echo $SQuery;
$SResult = mysql_db_query ($Dbname,$SQuery) or die ("ERROR SQuery: нет контакта с базой");
while ($arr = mysql_fetch_array($SResult)) {
	$arr_dep[]=$count;
	$arr_dep[]=$arr[1];
	$arr_dep[]=$arr[2];
	$arr_dep[]=$arr[3];
	$arr_dep[]=$arr[4];
	$arr_dep[]='<div class="btn-group">
				<a href="index.php?page=aphone&ac=edit&id='.$arr[0].'" class="btn btn-success"><i class="icon-pencil icon-white"></i></a>
				<a href="index.php?page=aphone&ac=del&id='.$arr[0].'" class="btn btn-danger"><i class="icon-trash icon-white"></i></a>
				</div>';
	if ($count > $shrows-1) break;
	else $count++;
}

// total rows in query
// DON'T MOVE TO ANOTHER LINES!!!
$_query = "SELECT FOUND_ROWS() as total";
$_result = mysql_query($_query);
$_row = mysql_fetch_row($_result);
$total_rows = $_row[0];
mysql_free_result($_result);
//end total rows in query

$smarty_select->assign('table_attr','class="table table-striped table-bordered table-condensed"');
$smarty_select->assign('th', array('style="text-align:center; width:3%"','','','','','style="text-align:center;width:11%"'));
$smarty_select->assign('td', array('style="text-align:right"','','','','',''));
$smarty_select->assign('data',$arr_dep);
$smarty_select->assign('status',$status);
$smarty_select->assign('status_type',$status_type);
$smarty_select->assign('trows', $total_rows);
$smarty_select->assign('shrows', $shrows);
$smarty_select->assign('name',$uname);
$smarty_select->assign('upid',$upid);
$smarty_select->display('_aphone.tpl');

?>