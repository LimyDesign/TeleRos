<?php
switch (@$_GET['page']) {

    case "statform":
        $content = "content/_statform.inc";
        $title = "Статистика звонков <small>".$REPORT."</small>";
        $active['statform'] = $active_class;
    break;
    
    case "adeps":
        $content = "content/_adeps.inc";
        $title = "Настройки <small>Подразделения</small>";
        $active['adeps'] = $active_class;
	break;
	
	case "arooms":
        $content = "content/_arooms.inc";
        $title = "Настройки <small>Помещения</small>";
        $active['arooms'] = $active_class;
	break;	

	case "aabonent":
        $content = "content/_aabonent.inc";
        $title = "Настройки <small>Абоненты</small>";
        $active['aabonent'] = $active_class;
	break;	

	case "aphone":
        $content = "content/_aphone.inc";
        $title = "Настройки <small>Телефоны</small>";
        $active['aphone'] = $active_class;
	break;	

	case "atrunk":
        $content = "content/_atrunk.inc";
        $title = "Настройки <small>Транковые группы</small>";
        $active['atrunk'] = $active_class;
	break;	
	
	case "aband":
        $content = "content/_aband.inc";
        $title = "Настройки <small>Тарифные зоны</small>";
        $active['aband'] = $active_class;
	break;	
	
	case "amasks":
        $content = "content/_amasks.inc";
        $title = "Настройки <small>Маски направления</small>";
        $active['amasks'] = $active_class;
	break;

	case "profile":
		$content = "content/_achpassword.inc";
		$title = "Настройки <small>Профиль</small>";
		$active['profile'] = $active_class;
	break;
	
	case "about":
		$content = "content/_about.inc";
		$title = "О тарификаторе JRate&trade; <small>Версия ".$jrver."</small>";
		$active['about'] = $active_class;
	break;
	
	case "qr":
		$content = "content/_qr.inc";
		$title = "Вход с мобильного";
		$active['qr'] = $active_class;
	break;

    default:
        $content = "content/_stat.inc";
        $title = "Текущие звонки <small>50 последних, обновление раз в минуту</small>";
        $active['stat'] = $active_class;
}
?>
