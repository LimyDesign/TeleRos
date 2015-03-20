<?
$arr_dep=array();

$smarty_select = new Smarty();

$name='';
$desc='';
$status='';
$status_type='';
$upid='';
$count=1;
$shrows=100;

if (!isset($_GET['ac']) ) $smarty_select->assign('actype','add');
else {
	if ($_GET['ac'] =='add') {
		if (!empty($_GET['name'])) {
			mysql_db_query ($Dbname,"INSERT INTO  `offices` (`OfficeName`,`Note`) VALUES ('".$_GET['name']."','".$_GET['desc']."')"); 
			$smarty_select->assign('actype','add');
			$status='Местоположение добавленно';
			$status_type='success';
		} else {
			$smarty_select->assign('actype','add');
			$status='Поле «Местоположение» должно быть заполнено.';
			$status_type='error';
		}
	} elseif ($_GET['ac'] =='del') { 
		mysql_db_query ($Dbname,"DELETE FROM  `offices` WHERE  `OfficeId`='".$_GET['id']."'");
 		$smarty_select->assign('actype','add');
		$status='Местоположение удалено';
		$status_type='success';
	} elseif ($_GET['ac'] =='edit') { 
		$Result = mysql_db_query ($Dbname,"SELECT `OfficeId`,`OfficeName`,`Note` FROM  `offices` WHERE  `OfficeId`='".$_GET['id']."'");
 		$smarty_select->assign('actype','update');
		$arru = mysql_fetch_array($Result);
		$upid=$arru[0];
		$name=$arru[1];
		$desc=$arru[2];
		$status='Редактирование местоположения';
		$smarty_select->assign('actype','update');
	} elseif ($_GET['ac'] =='update') {
		if (!empty($_GET['name'])) {
			mysql_db_query ($Dbname,"UPDATE  `offices` SET OfficeName='".$_GET['name']."',Note='".$_GET['desc']."' WHERE  `OfficeId`='".$_GET['upid']."'");
	 		$smarty_select->assign('actype','add');
			$status='Местоположение изменено';
			$status_type='success';
		} else {
	 		$smarty_select->assign('actype','update');
			$status='Поле «Местоположение» должно быть заполнено. Если требуется удалить запись, нажмите соответствующую кнопку.';
			$status_type='error';
		}
	} elseif ($_GET['ac'] == 'find') {
		$SFind = "AND (`OfficeName` LIKE '%".$_GET['find']."%' OR `Note` LIKE '%".$_GET['find']."%')";
	}
}


$SQuery = "SELECT `OfficeId`,`OfficeName`,`Note` FROM `offices` WHERE `OfficeId`!='0' ".$SFind." ORDER BY `OfficeName`" ;
$SResult = mysql_db_query ($Dbname,$SQuery) or die ("ERROR SQuery: нет контакта с базой");
while ($arr = mysql_fetch_array($SResult)) {
	$arr_dep[]=$count;
	$arr_dep[]=$arr[1];
	$arr_dep[]=$arr[2]."&nbsp;";
	$arr_dep[]='<div class="btn-group">
				<a href="index.php?page=aphone&filter=office&OfficeId='.$arr[0].'" class="btn btn-info"><i class="icon-bullhorn icon-white"></i></a>
				<a href="index.php?page=arooms&ac=edit&id='.$arr[0].'" class="btn btn-success"><i class="icon-pencil icon-white"></i></a>
				<a href="index.php?page=arooms&ac=del&id='.$arr[0].'" class="btn btn-danger"><i class="icon-trash icon-white"></i></a>
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
$smarty_select->assign('th', array('style="text-align:center; width:3%"','','','style="text-align:center;width:11%"'));
$smarty_select->assign('td', array('style="text-align:right"','','',''));
$smarty_select->assign('data',$arr_dep);
$smarty_select->assign('status',$status);
$smarty_select->assign('status_type',$status_type);
$smarty_select->assign('trows', $total_rows);
$smarty_select->assign('shrows', $shrows);
$smarty_select->assign('name',$name);
$smarty_select->assign('desc',$desc);
$smarty_select->assign('upid',$upid);
$smarty_select->display('_arooms.tpl');

?>