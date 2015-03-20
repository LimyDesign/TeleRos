<?php
ob_start("ob_gzhandler",9);
ini_set("display_errors", "1");
require ("php/_config.inc");
require ("php/_functions.inc");

// фильтрация GET данных
//@reset $_GET;
while (list($key, $val) = @each($_GET)) {
	$_GET[$key] = trim(htmlspecialchars($val));
}
// конец фильтрации GET данных

// показать готовый отчет
if (isset ($_GET['showrep'])  && @$_GET['srep']) {
	$Qurl="SELECT `get_rep` FROM accreport WHERE  `id_report`='".$_GET['srep']."'";
	$UResult = mysql_db_query ($Dbname,$Qurl) or die ("ERROR $RQuery: нет контакта с базой");
	if (mysql_num_rows($UResult)) {
		$arrU = mysql_fetch_array($UResult);
		header("Location: ".$arrU[0]."&srep=".$_GET['srep']);
		exit;
	}
}
//конец показать готовый отчет


//добавить отчет
if (count(@$_GET) > 3 && !empty($_GET['repname']) && isset($_GET['addrep'])) {
	$get='';
	$ins='index.php?rep=1';
	@reset($_GET);
	while(list($key, $val) = @each($_GET)) {
		if ( $key != "page_num" && $key != "addrep" && $key != "srep" )  $get.= "&".$key."=".$val;
	}
	mysql_db_query ($Dbname,"INSERT INTO accreport (`name`,`get_rep`) value ('".$_GET['repname']."','".$ins.$get."')");
}
//конец добавить отчет

//удалить отчет
if (isset ($_GET['delrep'])  && @$_GET['srep']) {
	mysql_db_query ($Dbname,"DELETE FROM  accreport WHERE `id_report`='".$_GET['srep']."'");
}
//конец удалить отчет

//готовый отчет
if (isset ($_GET['rep'])  && @$_GET['srep']) {
	$Qurl="SELECT `name` FROM accreport WHERE  `id_report`='".$_GET['srep']."'";
	$UResult = mysql_db_query ($Dbname,$Qurl) or die ("ERROR $RQuery: нет контакта с базой");
	if (mysql_num_rows($UResult)) {
		$arrU = mysql_fetch_array($UResult);
		$REPORT=$arrU[0];
	}
}


include ("php/_case.inc");

$trans = array("<small>" => "/ ", "</small>" => "");
$title_page = strtr($title, $trans);

// Подсказка на строку поиска
$search_disabled = '';
if (isset($active['adeps'])) $search_placeholder = 'Поиск по подразделениям…';
elseif (isset($active['arooms'])) $search_placeholder = 'Поиск по помещениям…';
elseif (isset($active['aabonent'])) $search_placeholder = 'Поиск по абонентам…';
elseif (isset($active['aphone'])) $search_placeholder = 'Поиск по телефонам…';
elseif (isset($active['atrunk'])) $search_placeholder = 'Поиск по транковым группам…';
elseif (isset($active['aband'])) $search_placeholder = 'Поиск по тарифным зонам…';
elseif (isset($active['amasks'])) $search_placeholder = 'Поиск по маскам…';	
else { 
	$search_placeholder = 'Поиск не доступен…';
	$search_disabled = 'disabled';
}

?>
<!DOCTYPE html>
<html lang="ru">
	<head>
		<meta charset="UTF-8">
		<title><?php echo $title_page; ?></title>
		<meta name="viewport" content="width=device-width, initial-scale=1.0">
		<meta name="description" content="JRate">
		<meta name="author" content="Arsen Bespalov">		
		<?php if (!count($_GET)) echo "<meta http-equiv=\"Refresh\" content=\"50\">"; ?>
		
		<!-- Стили -->
		<link href="css/bootstrap.css" rel="stylesheet">
		<style type="text/css">
		  body {
		  	padding-top: 60px;
		  	padding-bottom: 40px;
		  }
		  
		  .sidebar-nav {
		  	padding: 9px 0;
		  }
		</style>
		<link href="css/bootstrap-responsive.css" rel="stylesheet">
		<link href="css/jquery.lightbox-0.5.css" rel="stylesheet" media="screen">
		<link href="css/style.css" rel="stylesheet">
		
		<!-- HTML5 схемы для поддержки браузеров IE 6-8 элементов HTML5 -->
		<!--[if lt IE 9 ]>
			<script src="http://html5shim.googlecode.com/svn/trunk/html5.js"></script>
		<![endif]-->
		
		<!-- Иконки для браузеров и Apple гаджетов -->
		<link rel="shortcut icon" href="ico/favicon.ico">
		<link rel="apple-touch-icon-precomposed" sizes="144x144" href="ico/apple-touch-icon-144-precomposed.png">
		<link rel="apple-touch-icon-precomposed" sizes="114x114" href="ico/apple-touch-icon-114-precomposed.png">
		<link rel="apple-touch-icon-precomposed" sizes="72x72" href="ico/apple-touch-icon-72-precomposed.png">
		<link rel="apple-touch-icon-precomposed" href="ico/apple-touch-icon-57-precomposed.png">
	</head>
	<body>
		
		<div class="navbar navbar-fixed-top">
			<div class="navbar-inner">
				<div class="container">
					<a class="btn btn-navbar" data-toggle="collapse" data-target=".nav-collapse">
						<span class="icon-bar"></span>
						<span class="icon-bar"></span>
						<span class="icon-bar"></span>
					</a>
					<a class="brand" href="http://www.jrate.ru" target="_blank">JRate&trade;</a>
					<div class="btn-group pull-right">
						<a class="btn dropdown-toggle" data-toggle="dropdown" href="#">
							<i class="icon-cog"></i> Настройка
							<span class="caret"></span>
						</a>
						<ul class="dropdown-menu">
							<li <?php echo @$active['adeps']; ?>>
								<a href="index.php?page=adeps"><i class="icon-briefcase"></i> Справочник подразделений</a>
							</li>
							<li <?php echo @$active['arooms']; ?>>
								<a href="index.php?page=arooms"><i class="icon-th-large"></i> Справочник помещений</a>
							</li>
							<li <?php echo @$active['aabonent']; ?>>
								<a href="index.php?page=aabonent"><i class="icon-user"></i> Справочник абонентов</a>
							</li>
							<li <?php echo @$active['aphone']; ?>>
								<a href="index.php?page=aphone"><i class="icon-bullhorn"></i> Справочник телефонов</a>
							</li>
							<li <?php echo @$active['atrunk']; ?>>
								<a href="index.php?page=atrunk"><i class="icon-random"></i> Справочник транковых групп</a>
							</li>
							<li <?php echo @$active['aband']; ?>>
								<a href="index.php?page=aband"><i class="icon-shopping-cart"></i> Справочник тарифных зон</a>
							</li>
							<li <?php echo @$active['amasks']; ?>>
								<a href="index.php?page=amasks"><i class="icon-asterisk"></i> Справочник масок направлений</a>
							</li>
							<li class="divider"></li>
							<li <?php echo @$active['profile']; ?>>
								<a href="index.php?page=profile"><i class="icon-pencil"></i> Профиль</a>
							</li>
							<li <?php echo @$active['update']; ?>>
								<a href="index.php?page=update"><i class="icon-refresh"></i> Обновление JRate&trade;</a>
							</li>
							<li <?php echo @$active['about']; ?>>
								<a href="index.php?page=about"><i class="icon-exclamation-sign"></i> О тарификаторе JRate&trade;</a>
							</li>
							<li class="divider"></li>
							<li>
								<a href="http://logout@<? echo $_SERVER['SERVER_ADDR']; ?>/jrate/"><i class="icon-off"></i> Выход</a>
							</li>
						</ul>
					</div><!-- /.btn-group .pull-right -->
					<div class="nav-collapse">
						<ul class="nav">
							<li <?php echo @$active['stat']; ?>>
								<a href="index.php"><i class="icon-home icon-white"></i> Текущие звонки</a>
							</li>
							<li <?php echo @$active['statform']; ?>>
								<a href="index.php?page=statform"><i class="icon-list-alt icon-white"></i> Отчет о звонках</a>
							</li>
							<li <?php echo @$active['qr']; ?>>
								<a href="index.php?page=qr"><i class="icon-qrcode icon-white"></i> Вход с мобильного</a>
							</li>
							<li class="divider-vertical"></li>
						</ul>
						<form class="navbar-search pull-left" action _lpchecked="1">
							<input type="text" name="find" value="<?php echo @$_GET['find']; ?>" id="main-search" class="search-query span3" placeholder="<?php echo $search_placeholder;?>" <?php echo $search_disabled; ?>>
							<input type="hidden" name="page" value="<?php echo @$_GET['page']; ?>">
							<input type="hidden" name="ac" value="find">
						</form>
					</div><!-- /.nav-collapse -->
				</div><!-- /.container-fluid -->
			</div><!-- /.navbar-inner -->
		</div><!-- /.navbar .navbar-fixed.top -->
		
		<div class="container">
			
			<div class="page-header">
				<h1><?php echo $title; ?></h1>
			</div>

			<?php if (!isset($active['stat'])) { ?>
			<ul class="breadcrumb">
				<li><a href="index.php">Главная</a><span class="divider">/</span></li>
				<?php if (isset($active['statform'])) { ?>
				<li class="active">Отчет о звонках</li>
				<?php } elseif (isset($active['qr'])) { ?>
				<li class="active">Вход с мобильного</li>
				<?php } if (!isset($active['stat']) && !isset($active['statform']) && !isset($active['qr'])) { ?>
				<li><a href="#">Настройки</a><span class="divider">/</span></li>
				<?php } if (isset($active['adeps'])) { ?>
				<li class="active">Справочник подразделений</li>
				<?php } elseif (isset($active['arooms'])) { ?>
				<li class="active">Справочник помещений</li>
				<?php } elseif (isset($active['aabonent'])) { ?>
				<li class="active">Справочник абонентов</li>
				<?php } elseif (isset($active['aphone'])) { ?>
				<li class="active">Справочник телефонов</li>
				<?php } elseif (isset($active['atrunk'])) { ?>
				<li class="active">Справочник транковых групп</li>
				<?php } elseif (isset($active['aband'])) { ?>
				<li class="active">Справочник тарифных зон</li>
				<?php } elseif (isset($active['amasks'])) { ?>
				<li class="active">Маски направления</li>
				<?php } elseif (isset($active['profile'])) { ?>
				<li class="active">Профиль</li>
				<?php } elseif (isset($active['about'])) { ?>
				<li class="active">О JRate</li>
				<?php } ?>
			</ul>
			<?php } ?>
			
			<span id="loading"></span>
			<span id="container"><? include($content); ?></span>
		
			<hr>
			
			<footer>
				<p><strong>JRate&trade;</strong> — CDR collector for Avaya Aura&reg; CM by Arsen Bespalov &copy;, 2012</p>
			</footer>
			
			</div><!-- /row -->
			
		</div><!-- /container -->
	
		<!-- JavaScript фреймворки, обработчики и плагины -->
		<!-- Обязательно в конце html документа, для быстрой загрузки контента, 
		очень сильно заметно на медленных машинах -->
		<script src="js/jquery.js"></script>
	    <script src="js/bootstrap-transition.js"></script>
	    <script src="js/bootstrap-alert.js"></script>
	    <script src="js/bootstrap-modal.js"></script>
	    <script src="js/bootstrap-dropdown.js"></script>
	    <script src="js/bootstrap-scrollspy.js"></script>
	    <script src="js/bootstrap-tab.js"></script>
	    <script src="js/bootstrap-tooltip.js"></script>
	    <script src="js/bootstrap-popover.js"></script>
	    <script src="js/bootstrap-button.js"></script>
	    <script src="js/bootstrap-collapse.js"></script>
	    <script src="js/bootstrap-carousel.js"></script>
	    <script src="js/bootstrap-typeahead.js"></script>
	    <script src="js/jquery.lightbox-0.5.min.js"></script>
	    <script src="js/custom.js"></script>

	</body>
</html>