<?php
include("phpqrcode/qrlib.php");

$smarty_select = new Smarty();

$qr = 'cache/jrQR.png';
$qr_thumb = 'cache/jrQR_thumb.png';

QRcode::png('http://'.$_SERVER['SERVER_ADDR'].'/jrate/', $qr, 'H', 10, 2);
QRcode::png('http://'.$_SERVER['SERVER_ADDR'].'/jrate/', $qr_thumb, 'H', 5, 2);

$smarty_select->assign('qr',$qr);
$smarty_select->assign('qr_thumb', $qr_thumb);
$smarty_select->display('_qr.tpl');
?>