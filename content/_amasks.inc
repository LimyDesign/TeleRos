<?php
$arr_dep=array();

$smarty_select = new Smarty();

if (isset($_GET['filter'])) $sfilter= " AND a.`BandId` = '".$_GET['BandId']."'";
else $sfilter= "";

if (isset($_GET['shrows'])) $shrows = $_GET['shrows'];
else $shrows=100;

$uname='';
$umask='';
//$utr='';
$status='';
$status_type='';
$upid='';
$count=1;

if (!isset($_GET['ac']) || empty($_GET['ac'])) $smarty_select->assign('actype','add');
else {
	if ($_GET['ac'] =='add') {
		if (!empty($_GET['mask']) && !empty($_GET['name'])) {
			$Result = mysql_query( "SELECT `PhoneMask` FROM `masks` WHERE `PhoneMask`='".$_GET['mask']."'");		
			if (!mysql_num_rows($Result)) {
				mysql_query ("INSERT INTO `masks` (`PhoneMask`,`BandId`,`DialedArea`) VALUES ('".$_GET['mask']."','".$_GET['tr']."','".$_GET['name']."')"); 
				$smarty_select->assign('actype','add');
				$status = 'Маска добавлена';
				$status_type = 'success';
			} else {
				$smarty_select->assign('actype','add');
				$status = 'Маска уже имеется';
				$status_type = 'error';
			}
		} else {
			$smarty_select->assign('actype','add');
			$status = 'Все поля должны быть заполнены';
			$status_type = 'error';
		}
	} elseif ($_GET['ac'] =='del') { 
		mysql_query ("DELETE FROM  `masks` WHERE  `MaskId`='".$_GET['id']."'");
 		$smarty_select->assign('actype','add');
		$status = 'Маска удаленa';
		$status_type = 'success';
	} elseif ($_GET['ac'] =='edit') { 
		$Result = mysql_query ("SELECT `MaskId`,`PhoneMask`,`DialedArea`,`BandId` FROM  `masks` WHERE  `MaskId`='".$_GET['id']."'");
 		$smarty_select->assign('actype','update');
		$arru = mysql_fetch_array($Result);
		$upid=$arru[0];
		$umask=$arru[1];
		$uname=$arru[2];
		$utr=$arru[3];
		$status = 'Редактирование маски';
		$status_type = '';
		$smarty_select->assign('actype','update');
	} elseif ($_GET['ac'] =='update') {
		mysql_query ("UPDATE  `masks` SET `PhoneMask`='".$_GET['mask']."',`BandId`='".$_GET['tr']."',`DialedArea`='".$_GET['name']."' WHERE  `MaskId`='".$_GET['upid']."'");
 		$smarty_select->assign('actype','add');
		$status = 'Маска изменена';
		$status_type = 'success';
	} elseif ($_GET['ac'] == 'find') {
		$SFind = "AND (a.`PhoneMask` LIKE '%".$_GET['find']."%' OR a.`DialedArea` LIKE '%".$_GET['find']."%' OR b.`Name` LIKE '%".$_GET['find']."%')";
	}
}


// sel band
$BQuery = "SELECT `BandId`,`Name` FROM `bands`   ORDER BY `Name`";
$BResult = mysql_query ($BQuery) or die ("ERROR BQuery: нет контакта с базой");
if (mysql_num_rows($BResult)) 
{
	while ($arrB = mysql_fetch_array($BResult))
	{
		$arrband_id[]=$arrB[0] ;
		$arrband_name[]=$arrB[1];
	}
}
$smarty_select ->assign('tr_id',$arrband_id);
$smarty_select ->assign('tr_name',$arrband_name);
if (isset($utr)) $smarty_select ->assign('str',$utr);
else $smarty_select ->assign('str','0');
//end select band

$SQuery = "SELECT a.`MaskId`,a.`PhoneMask`,a.`DialedArea`, b.`Name` FROM `masks` a, `bands` b   WHERE a.BandId=b.BandId ".$sfilter." ".$SFind." ORDER BY `PhoneMask`";
$SResult = mysql_query($SQuery) or die ("ERROR SQuery: нет контакта с базой");
while ($arr = mysql_fetch_array($SResult)) {
	$arr_dep[]=$count;
	$arr_dep[]=$arr[1];
	$arr_dep[]=$arr[2];
	$arr_dep[]=$arr[3];
	$arr_dep[]='<div class="btn-group">
				<a href="index.php?page=amasks&ac=edit&id='.$arr[0].'" class="btn btn-success"><i class="icon-pencil icon-white"></i></a>
				<a href="index.php?page=amasks&ac=del&id='.$arr[0].'" class="btn btn-danger"><i class="icon-trash icon-white"></i></a>
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
$smarty_select->assign('th',array('width=1 style="text-align: center"','style="text-align: center"','style="text-align: center"','style="text-align: center"','style="text-align: center; width: 8%"'));
$smarty_select->assign('td',array('style="text-align: right"','','','',''));
$smarty_select->assign('data',$arr_dep);
$smarty_select->assign('status',$status);
$smarty_select->assign('status_type',$status_type);
$smarty_select->assign('trows', $total_rows);
$smarty_select->assign('shrows', $shrows);
$smarty_select->assign('name',$uname);
$smarty_select->assign('mask',$umask);
$smarty_select->assign('upid',$upid);
$smarty_select->display('_amasks.tpl');

?>
