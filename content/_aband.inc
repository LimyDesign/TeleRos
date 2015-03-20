<?php
$arr_dep=array();

$smarty_select = new Smarty();

$name='';
$desc='';
$status='';
$status_type='';
$upid='';
$count=1;
$shrows=100;

if (!isset($_GET['ac']) || empty($_GET['ac'])) $smarty_select->assign('actype','add');
else {
	if ($_GET['ac'] =='add') {
		if (!empty($_GET['name'])) {
			mysql_db_query ($Dbname,"INSERT INTO  `bands` (`Name`) VALUES ('".$_GET['name']."')"); 
			$smarty_select->assign('actype','add');
			$status='Добавлена тарифная зона';
			$status_type='success';
		} else {
			$smarty_select->assign('actype','add');
			$status='Название тарифной зоны должно все же быть…';
			$status_type='error';
		}
	} elseif ($_GET['ac'] =='del') { 
		mysql_db_query ($Dbname,"DELETE FROM  `bands` WHERE  `BandId`='".$_GET['id']."'");
 		$smarty_select->assign('actype','add');
		$status='Тарифная зона удалена';
		$status_type='success';
	} elseif ($_GET['ac'] =='edit') { 
		$Result = mysql_db_query ($Dbname,"SELECT `BandId`,`Name` FROM  `bands` WHERE  `BandId`='".$_GET['id']."'");
 		$smarty_select->assign('actype','update');
		$arru = mysql_fetch_array($Result);
		$upid=$arru[0];
		$name=$arru[1];
		$status='Редактирование тарифной зоны';
		$status_type='';
		$smarty_select->assign('actype','update');
	} elseif ($_GET['ac'] =='update') {
		if (!empty($_GET['name'])) {
			mysql_db_query ($Dbname,"UPDATE  `bands` SET `Name`='".$_GET['name']."' WHERE  `BandId`='".$_GET['upid']."'");
	 		$smarty_select->assign('actype','add');
			$status='Тарифная зона изменена';
			$status_type='success';
		} else {
			$smarty_select->assign('actype','add');
			$status='Название тарифной зоны не может быть пустым. Если требуется удалить запись, нажмите соответствующую кнопку.';
			$status_type='error';
		}
	} elseif ($_GET['ac'] == 'find') {
		$SFind = "AND (`Name` LIKE '%".$_GET['find']."%')";
		$smarty_select->assign('acctype','add');
	}
}

$SQuery = "SELECT  `BandId`,`Name` FROM `bands`  WHERE `BandId`!='0' ".$SFind." ORDER BY `Name` " ;
$SResult = mysql_db_query ($Dbname,$SQuery) or die ("ERROR SQuery: нет контакта с базой");
while ($arr = mysql_fetch_array($SResult)) {
	$arr_dep[]=$count;
	$arr_dep[]=$arr[1];
	$arr_dep[]='<div class="btn-group">
				<a href="index.php?page=amasks&filter=bands&BandId='.$arr[0].'" class="btn btn-info"><i class="icon-asterisk icon-white"></i></a>
				<a href="index.php?page=aband&ac=edit&id='.$arr[0].'" class="btn btn-success"><i class="icon-pencil icon-white"></i></a>
				<a href="index.php?page=aband&ac=del&id='.$arr[0].'" class="btn btn-danger"><i class="icon-trash icon-white"></i></a>
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
$smarty_select->assign('th', array('style="text-align:center; width:3%"','','style="text-align:center;width:11%"'));
$smarty_select->assign('td', array('style="text-align:right"','',''));
$smarty_select->assign('data',$arr_dep);
$smarty_select->assign('status',$status);
$smarty_select->assign('status_type',$status_type);
$smarty_select->assign('trows', $total_rows);
$smarty_select->assign('shrows', $shrows);
$smarty_select->assign('name',$name);
$smarty_select->assign('upid',$upid);
$smarty_select->display('_aband.tpl');

?>
