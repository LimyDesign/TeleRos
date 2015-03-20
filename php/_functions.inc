<?php
//------------------------------------------ Авторизация ------------------------------------------------//

//------------------------------------------ END Авторизация ------------------------------------------------//

//------------------------------------------ ОШИБКА ------------------------------------------------//
function error () {
	GLOBAL $ERRORCode, $zid, $ac;
	if (isset($ac) && isset($ERRORCode) && $ERRORCode != "")
	{
		$link = "<a href='?page=p6&zid=$zid'>Вернуться</a>";
		$output = "design/error.html";
		$output = implode("",file($output));
		$output = str_replace("[error]",$ERRORCode,$output);
		$output = str_replace("[link]",$link,$output);
		echo $output;
		unset($output);
	}
}
//------------------------------------------ END ОШИБКА ------------------------------------------------//


//------------------------------------------ \n на \<br> --------------------------------------------------//
function textdatevalid ($text) {
	$text = str_replace("\n","<br>",$text);
	$text = str_replace("[b]","<b>",$text);
	$text = str_replace("[/b]","</b>",$text);
	$text = str_replace("[i]","<i>",$text);
	$text = str_replace("[/i]","</i>",$text);
	$text = str_replace("[u]","<u>",$text);
	$text = str_replace("[/u]","</u>",$text);
	$text = str_replace("[p]","<p>",$text);
	$text = str_replace("[li]","<li>",$text);
	
	return $text;
}
//------------------------------------------ END \n на \<br> --------------------------------------------------//
//------------------------------------------ \<br> на \n --------------------------------------------------//
function textdatevalid2 ($text) {
	$text = str_replace("<br>","\n",$text);
	return $text;
}


//------------------------- Генерация ID события -------------------------//

function make_id() {
	$tan = rand(100,0);
	$id = date("mdHis") . $tan . date("y");
	return($id);
}

//------------------------- END Генерация ID события ---------------------//


//------------------------- Генерация NN события -------------------------//

//------------------------- пользовательский вход ---------------------//





function make_select($line,$limit) {
	GLOBAL  $Dbname;	
	$stable="acccall";	
	
	// подготовка фильтра
	$filter='';
	
	//тариф
	if (isset($_GET['tarif']) && @$_GET['tarif']=='1') {
		$filter.= " AND  `dialed-num` like '8%' AND CHAR_LENGTH(`dialed-num`) > 9  ";
	}
	//end тариф
	
	
	//зона
	if (isset($_GET['band']) && @$_GET['band']!='null') {
		$FQuery = "SELECT a.`PhoneMask` FROM `masks` a,`bands` b WHERE a.`BandId`=b.`BandId` AND b.`BandId`='".$_GET['band']."'" ;
		$FResult = mysql_db_query ($Dbname,$FQuery) or die ("ERROR FQuery: нет контакта с базой");
		if (mysql_num_rows($FResult)) {
			$filter.= " AND ( ";
			$arrf = mysql_fetch_array($FResult);
			$filter.= " `dialed-num` like '".$arrf[0]."%' ";
			while ($arrf = mysql_fetch_array($FResult)) {
				$filter.= " OR 	`dialed-num` like '".$arrf[0]."%' ";
			}
			$filter.= ") ";
		}
	}
	//end зона
	
	
	//направление
	if (isset($_GET['direct']) && @$_GET['direct']!='0') {
		if (@$_GET['direct'] =='1') $filter.= " AND `code-used`='' ";
		else  $filter.= " AND `in-trk-code`='' ";
	}

	if (isset($_GET['rphone']) && @$_GET['rphone']!='') {
		$filter.= " AND (`clg-num-in-tac` like '%".$_GET['rphone']."' OR  `dialed-num` like '%".$_GET['rphone']."') ";
	}
	//end направление
	
	
	//абонент
	if (isset($_GET['person']) && @$_GET['person']!='null') {
		$FQuery = "SELECT `PhoneNumber` FROM `abonent` WHERE `PersonId`='".$_GET['person']."'  " ;
		$FResult = mysql_db_query ($Dbname,$FQuery) or die ("ERROR FQuery: нет контакта с базой");
		if (mysql_num_rows($FResult)) {
			$filter.= " AND ( ";
			$arrf = mysql_fetch_array($FResult);
			$filter.= " `dialed-num`='".$arrf[0]."' OR `clg-num-in-tac`='".$arrf[0]."'  ";
			while ($arrf = mysql_fetch_array($FResult)) {
				$filter.= " OR `dialed-num`='".$arrf[0]."' OR `clg-num-in-tac`='".$arrf[0]."' ";
			}
			$filter.= ") ";
		}
	}
	//end абонент
	
	
	//подразделение
	if (isset($_GET['dep']) && @$_GET['dep']!='null') {
		$FQuery = "SELECT `PhoneNumber` FROM `abonent` WHERE `DepId`='".$_GET['dep']."'  " ;
		$FResult = mysql_db_query ($Dbname,$FQuery) or die ("ERROR FQuery: нет контакта с базой");
		if (mysql_num_rows($FResult)) {
			$filter.= " AND ( ";
			$arrf = mysql_fetch_array($FResult);
			$filter.= " `dialed-num`='".$arrf[0]."' OR `clg-num-in-tac`='".$arrf[0]."'  ";
			while ($arrf = mysql_fetch_array($FResult)) {
				$filter.= " OR `dialed-num`='".$arrf[0]."' OR `clg-num-in-tac`='".$arrf[0]."' ";
			}
			$filter.= ") ";
		}
	}
	//end подразделение
	
	
	//кабинет
	if (isset($_GET['depat']) && @$_GET['depat']!='null') {
		$FQuery = "SELECT `PhoneNumber` FROM `abonent` WHERE `OfficeId`='".$_GET['depat']."'  " ;
		$FResult = mysql_db_query ($Dbname,$FQuery) or die ("ERROR FQuery: нет контакта с базой");
		if (mysql_num_rows($FResult)) {
			$filter.= " AND ( ";
			$arrf = mysql_fetch_array($FResult);
			$filter.= " `dialed-num`='".$arrf[0]."' OR `clg-num-in-tac`='".$arrf[0]."'  ";
			while ($arrf = mysql_fetch_array($FResult)) {
				$filter.= " OR `dialed-num`='".$arrf[0]."' OR `clg-num-in-tac`='".$arrf[0]."' ";
			}
			$filter.= ") ";
		}
	}
	//end кабинет
	
	
	//продолжительность
	if (isset($_GET['dur']) && @$_GET['dur']!='') {		
		if ($_GET['sdur']== 1) $ss=">";
		else $ss="<";
		$ss.=preg_replace("/^0+/","",str_replace(":","",$_GET['dur']));
				
		$filter.=" AND `sec-dur`".$ss. " ";
	}
	//end продолжительность
	
	
	//транк
	if (isset($_GET['trunk']) && @$_GET['trunk']!='null') {
		$filter.=" AND (`code-used`='".$_GET['trunk']."' OR `in-trk-code`='".$_GET['trunk']."' ) ";
	}
	//end транк
	
	//время
	if (isset($_GET['me'])) {
		$m=date ('n');
		$y= date ('Y');
		if  (@$_GET['me']=='2') {
			$filter.=" AND `date` >'".$y."-".sprintf("%02d",$m)."-01'  AND `date` <'".$y."-".sprintf("%02d",($m+1))."-01'";
		} else {
			$filter.=" AND `date` >'".$y."-".sprintf("%02d",($m-1))."-01'  AND `date` <'".$y."-".sprintf("%02d",$m)."-01'";
		}
	} else {
		if (isset($_GET['ftime']) && @$_GET['ftime']!='') {
			$filter.=" AND `date` >'".$_GET['ftime']."'  ";
		} 
		if (isset($_GET['etime']) && @$_GET['etime']!='') {
			$filter.=" AND `date` <'".$_GET['etime']."'  ";
		}
	}
	//end время
	//echo $filter.'<br>';
	//end подготовка фильтра
	
	
	//подготовка соритовки
	$arr_order=array();
	if (isset($_GET['dir'])) {
		$order ="";
		
		$arr_order[]="CAST(`date` AS DATE) DESC";
		
		if (@$_GET['dir'] == 1 ) {
			$stable="vo_acccall";
			if (@$_GET['srphone']) $arr_order[]="`clg-num-in-tac` ASC";
			if (@$_GET['strunk']) $arr_order[]="`code-used` ASC";
		} else {
			$stable="vo_acccall";
			if (@$_GET['srphone']) $arr_order[]="`dialed-num` ASC";
			if (@$_GET['strunk']) $arr_order[]="`in-trk-code` ASC";
		}
		if (@$_GET['sperson']) $arr_order[]="`PhoneNumber` ASC";
		if (@$_GET['sdep']) $arr_order[]="`DepId` ASC";
		if (@$_GET['sdepat']) $arr_order[]="`OfficeId` ASC";
		if (@$_GET['ssdur']) $arr_order[]="`sec-dur` ASC";
		
	} else $arr_order[] = "`date` DESC";
	$order="ORDER BY ".implode(",", $arr_order);
	//конец подготовка соритовки
	
	
	// Разбиение на страницы
	//$limit=0;
	//$line=50;
	$res_q =array();
	$res_t =array();
	
	$CountQuery="SELECT count(*) FROM `".$stable."` WHERE '1'='1' ".$filter;
	$CountQuery = mysql_db_query ($Dbname,$CountQuery) or die ("ERROR CountQuery: нет контакта с базой");
	$arrcount = mysql_fetch_array($CountQuery);
	$res_count=$arrcount[0];
	
	if ($limit || $line) $llim= "LIMIT ".$limit.",".$line.";";
	else $llim="";
	
	$SQuery = "SELECT * FROM `".$stable."` WHERE '1'='1' ".$filter."  ".$order." ".$llim;
	#echo $SQuery;
	//конец разбиение на страницы
	
	
	// Получение данных
	//echo $SQuery;
	$SResult = mysql_db_query ($Dbname,$SQuery) or die ("ERROR SQuery: нет контакта с базой");
	while ($arr = mysql_fetch_array($SResult)) {
		$trunk='';
		if ($arr['code-used']) $trunk= $arr['code-used'];
		if ($arr['in-trk-code']) $trunk= $arr['in-trk-code'];
		//Время вызова 	Вызывающий 	Вызываемый 	Длительность 	Подразделение 	Тарифная зона
		$last_date = date_parse($arr['date']);
		$curr_date = date_parse(date('Y-m-d H:i:s'));
		if (($last_date['year'] == $curr_date['year']) && ($last_date['month'] == $curr_date['month']) && ($last_date['day'] == $curr_date['day'])) $res_t[1] = 'Сегодня в '.date('H:i:s', mktime($last_date['hour'],$last_date['minute'],$last_date['second']));
		elseif (($last_date['year'] == $curr_date['year']) && ($last_date['month'] == $curr_date['month']) && ($last_date['day'] == $curr_date['day']-1)) $res_t[1] = 'Вчера в '.date('H:i:s', mktime($last_date['hour'],$last_date['minute'],$last_date['second']));
		else $res_t[1]=$arr['date'];
		$res_t[2]=$arr['clg-num-in-tac'];
		if (strlen($arr['clg-num-in-tac']) < 5) {
			$PQuery = "SELECT * FROM `abonent` WHERE  `PhoneNumber`='".$arr['clg-num-in-tac']."'" ;
			//echo $PQuery;
			$PResult = mysql_db_query ($Dbname,$PQuery) or die ("ERROR PResult: нет контакта с базой");
			if (mysql_num_rows($PResult)) {
				$arrp = mysql_fetch_array($PResult);
				$res_t[3]="<span  style='color : #155c2c;' alt='".$arrp['OfficeNote']." ".$arrp['depatment']." (".$arrp['OfficeName'].")' title='".$arrp['OfficeNote']." ".$arrp['depatment']." (".$arrp['OfficeName'].")'>".$arrp['Name']."</span>";
			} else $res_t[3]=" абонент не определен";
		} elseif (strlen($arr['clg-num-in-tac']) > 8) {
			$RQuery = "SELECT *  FROM `masks` WHERE  '8".$arr['clg-num-in-tac']." '  regexp  concat('^',`PhoneMask`) OR '".$arr['clg-num-in-tac']."'  regexp  concat('^',`PhoneMask`) ORDER BY PhoneMask";
			$RResult = mysql_db_query ($Dbname,$RQuery) or die ("ERROR RResult: нет контакта с базой");
			if (mysql_num_rows($RResult)) {
				$arrr = mysql_fetch_array($RResult);
				$res_t[3]="<span  style='color : red;'>".$arrr['DialedArea']."</span>"; 
			} else $res_t[3]=" <span  style='color : red;'>направление не определено</span>";
		} else $res_t[3]=" <span  style='color : red;'>направление не определено</span>";
	

		$res_t[4]=$arr['dialed-num'];
	//вызываемый
		$tr="&nbsp;";
		if (strlen($arr['dialed-num']) < 5) {
			$PQuery = "SELECT * FROM `abonent` WHERE  `PhoneNumber`='".$arr['dialed-num']."';" ;
			//echo $PQuery;
			$PResult = mysql_db_query ($Dbname,$PQuery) or die ("ERROR PResult: нет контакта с базой");
			if (mysql_num_rows($PResult)) {
				$arrp = mysql_fetch_array($PResult);
				$res_t[5]="<span  style='color : #155c2c;' alt='".$arrp['OfficeNote']." ".$arrp['depatment']." (".$arrp['OfficeName'].")' title='".$arrp['OfficeNote']." ".$arrp['depatment']." (".$arrp['OfficeName'].")'>".$arrp['Name']."</span>";
			} else $res_t[5]=" абонент не определен";
		} elseif ((strlen($arr['dialed-num']) == 5) || (strlen($arr['dialed-num']) == 6) ) {
			$res_t[5]="<span  style='color : red;'>Город</span>";
		} elseif (strlen($arr['dialed-num']) > 8) {
			$RQuery = "SELECT a.*,b.Name band FROM `masks` a,`bands` b WHERE a.`BandId`=b.`BandId` AND ('8".$arr['dialed-num']." '  regexp  concat('^',a.`PhoneMask`) OR '".$arr['dialed-num']."'  regexp  concat('^',a.`PhoneMask`)) ORDER BY a.PhoneMask";
			$RResult = mysql_db_query ($Dbname,$RQuery) or die ("ERROR RQuery: нет контакта с базой");
			if (mysql_num_rows($RResult)) {
				$arrr = mysql_fetch_array($RResult);
				$res_t[5]="<span  style='color : red;'>".$arrr['DialedArea']."</span>";
				//$tr=$RQuery;
				$tr=$arrr['band'];
			} else $res_t[5]=" <span  style='color : red;'>направление не определено</span>";
		} else $res_t[5]=" <span  style='color : red;'>направление не определено</span>";
	//end вызываемый

	
		$res_t[6]=make_t($arr['sec-dur']);
	//транк
		$TQuery = "SELECT trunkname FROM `trunk` WHERE `tac`='".$trunk."'";
		$TResult = mysql_db_query ($Dbname,$TQuery) or die ("ERROR TQuery: нет контакта с базой");
		if (mysql_num_rows($TResult)) {
			$arrt = mysql_fetch_array($TResult);
			$trunk=$arrt[0];
		}
	//end транк
		$res_t[7]=$trunk;
		$res_t[8]=$tr;
		$res_q[]=$res_t;
	}
	//end Получение данных
		
	return array($res_count, $res_q); // Отправка полученных, данных, выбранной страницы согласно применяемым фильтрам
}

function make_t($ts) {
	
	$ts=str_pad($ts, 5, "0", STR_PAD_LEFT);
	
	$s=substr($ts,3,2); 
	$m=substr($ts,1,2);
	$h=substr($ts,0,1);

	$rez= $s; 
	//if ( $m!="00" ) $rez= $m.":".$rez;
	//if ($m="00" &&  $h!="0") $rez= "00:".$rez;  
	//if ($h != "0" ) $rez= "0".$h .":".  $rez; 
	
	$rez= "0".$h.":".$m.":".$s;
	
	return $rez;
}
?>
