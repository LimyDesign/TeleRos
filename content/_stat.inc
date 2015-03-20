<?

if (isset($_GET['llimit'])) $line = $_GET['llimit'];
else $line=50;

$limit=0;
if (isset($_GET['page_num'])) $page_num=$_GET['page_num'];
else $page_num=1;

if ($page_num == 1) $limit = 0;
else $limit = ($page_num - 1) * $line;

$adjacents = 3;


$qdata = make_select($line,$limit);
$smarty_select = new Smarty();


if (@$_GET['page']=='statform' && count(@$_GET) > 3) {
	$get_print="";
	@reset($_GET);
	
	while(list($key, $val) = @each($_GET)) {
	 	if ( $key != "page_num" && $key != "addrep" && $key != "deldrep" )  $get_print.= "&".$key."=".$val;
	}
	
	$smarty_select->assign('get_print',"<p align=\"right\"><a target=\"_blank\" href=\"print.php?print=1".$get_print."\" class=\"btn\"><i class=\"icon-print\"></i> Версия для печати</a></p>");
	$prev = $page_num - 1;
	$next = $page_num + 1;	
	$count_page=ceil($qdata[0]/$line);
	$lpm1 = $count_page - 1;	
	$smarty_select->assign('p_total',"<a name=\"hstart\"></a><div class=\"alert alert-info\"> Всего отобранно <b>".$qdata[0]."</b> записей на <b>".$count_page."</b>  страницах.</div>");
}

$smarty_select ->assign('th',array('','colspan=2','colspan=2','','',''));
$smarty_select->assign('data',$qdata[1]);

$ipage='';
$get='';

@reset($_GET);
while(list($key, $val) = @each($_GET)) {
	if ( $key != "page_num")  $get.= "&".$key."=".$val;
}

if (@$_GET['page']=='statform' && count(@$_GET) > 3 ) 
{
	if ($count_page > 1) {
		
		// кнопка "назад"
		if ($page_num > 1) $ipage.="<li><a href=\"index.php?page=statform&page_num=".$prev.$get."#hstart\">«</a></li>";
		else $ipage.='<li class="active"><a>«</a></li>';

		// страницы
		if ($count_page < 7 + ($adjacents * 2)) { // если страниц мало, то выводим весь список страниц

			for($i=1; $i<=$count_page; $i++) {
				if ($page_num == $i) $ipage.="<li class=\"active\"><a href=\"index.php?page=statform&page_num=".$i.$get."#hstart\">".$i."</a></li>";
				else $ipage.="<li><a href=\"index.php?page=statform&page_num=".$i.$get."#hstart\">".$i."</a></li>";
			}
			$ipage.="<li class=\"active\"><a>…</a></li>";
			$ipage.="<li><a href=\"index.php?page=statform&page_num=".$lpm1.$get."#hstart\">".$lpm1."</a></li>";
			$ipage.="<li><a href=\"index.php?page=statform&page_num=".$count_page.$get."#hstart\">".$count_page."</a></li>";

		} elseif ($count_page > 5 + ($adjacents * 2)) { // если страниц много, то избыточные страницы скрываем

			if ($page_num < 1 + ($adjacents * 2)) { // начало; выводим список первых, остальные скрываем
				for ($i = 1; $i < 4 + ($adjacents * 2); $i++) {
					if ($i == $page_num) $ipage.='<li class="active"><a href="index.php?page=statform&page_num='.$i.$get.'#hstart">'.$i.'</a></li>';
					else $ipage.='<li><a href="index.php?page=statform&page_num='.$i.$get.'#hstart">'.$i.'</a></li>';
				}
				$ipage.="<li class=\"active\"><a>…</a></li>";
				$ipage.='<li><a href="index.php?page=statform&page_num='.$lpm1.$get.'#hstart">'.$lpm1.'</a></li>';
				$ipage.='<li><a href="index.php?page=statform&page_num='.$count_page.$get.'#hstart">'.$count_page.'</a></li>';
			} elseif ($count_page - ($adjacents * 2) > $page_num && $page_num > ($adjacents * 2)) { // середина; выводим часть середины
				$ipage.='<li><a href="index.php?page=statform&page_num=1'.$get.'#hstart">1</a></li>';
				$ipage.='<li><a href="index.php?page=statform&page_num=2'.$get.'#hstart">2</a></li>';
				$ipage.='<li class="active"><a>…</a><li>';
				for ($i = $page_num - $adjacents; $i <=  $page_num + $adjacents; $i++) {
					if ($i == $page_num) $ipage.='<li class="active"><a href="index.php?page=statform&page_num='.$i.$get.'#hstart">'.$i.'</a></li>';
					else $ipage.='<li><a href="index.php?page=statform&page_num='.$i.$get.'#hstart">'.$i.'</a></li>';
				}
				$ipage.='<li class="active"><a>…</a></li>';
				$ipage.='<li><a href="index.php?page=statform&page_num='.$lpm1.$get.'#hstart">'.$lpm1.'</a></li>';
				$ipage.='<li><a href="index.php?page=statform&page_num='.$count_page.$get.'#hstart">'.$count_page.'</a></li>';
			} else { // конец; выводим конечные страницы
				$ipage.='<li><a href="index.php?page=statform&page_num=1'.$get.'#hstart">1</a></li>';
				$ipage.='<li><a href="index.php?page=statform&page_num=2'.$get.'#hstart">2</a></li>';
				$ipage.='<li class="active"><a>…</a></li>';
				for ($i = $count_page - (2 + ($adjacents * 2)); $i <= $count_page; $i++) {
					if ($i == $page_num) $ipage.='<li class="active"><a href="index.php?page=statform&page_num='.$i.$get.'#hstart">'.$i.'</a></li>';
					else $ipage.='<li><a href="index.php?page=statform&page_num='.$i.$get.'#hstart">'.$i.'</a></li>';
				}
			}
		}
		
		// кнопка "вперед"
		if ($page_num < $count_page) $ipage.='<li><a href="index.php?page=statform&page_num='.$next.$get.'#hstart">»</a></li>';
		else $ipage.='<li class="active"><a>»</a></li>';		
	}
}

$smarty_select->assign('pages',$ipage);
$smarty_select->assign('get',htmlspecialchars($get));
$smarty_select->display('select.tpl');

?>
