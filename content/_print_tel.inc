<?
$arr_res=array();

$DQuery = "SELECT  DepId,Name FROM `departs` WHERE `DepId`!='0' ORDER BY `Name`" ;
$DResult = mysql_db_query ($Dbname,$DQuery) or die ("ERROR DQuery: нет контакта с базой");
while ($arr_d = mysql_fetch_array($DResult))
	{
	$AQuery = "SELECT  * FROM `abonent` WHERE `DepId`='".$arr_d[0]."' ORDER BY `Name`" ;
	$AResult = mysql_db_query ($Dbname,$AQuery) or die ("ERROR DQuery: нет контакта с базой");
	if (mysql_num_rows($DResult)) $arr_res[]="<td colspan=\"4\" align=\"center\"><h2>".$arr_d[1]."</h2></td>";
		while ($arr_a = mysql_fetch_array($AResult))
		{
		$arr_res[]="<td>".$arr_a['Name']."</td><td>".$arr_a['PersonNote']."</td><td>".$arr_a['OfficeName']."</td><td class=\"hdrb\" align=\"right\">".$arr_a['PhoneNumber']."</td>";
	
		}



	



	}




$smarty_select = new Smarty();


$smarty_select->assign('arows',$arr_res);

$smarty_select->display('_aabonen_print.tpl');

?>
