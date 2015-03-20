{* Smarty *}




<table border="0" cellpadding="1" cellspacing="0" width="100%">

<tr>

	<td  colspan="2"><img src="images/logo.gif" border="0"></td>

</tr>

<tr>

	<td colspan="2" bgcolor="#333333"><img src="images/dumb.gif" border="0" height="1" width="1"></td>

</tr>

<tr>
     <td colspan="2">	
   {html_table loop=$sdata  cols=2  table_attr="border='0'" td_attr=$std}	

<tr>

	<td colspan="2" bgcolor="#333333"><img src="images/dumb.gif" border="0" height="1" width="1"></td>

</tr>


</table>










<br>
<i><b>Вего записей:</b> {$rcount} </i>
<table width='100%' border="0" bgcolor="#FFFFFF">


<tr>
<td align="center" bgcolor="#FFFFFF">
{$pages}
</td></tr>
</table>
<br>

<table width='100%' border="0" bgcolor="#cccccc">
<tr>
<th bgcolor="#eeeeee">Время вызова</th>
<th colspan="2" bgcolor="#eeeeee">Вызывающий</th>
<th colspan="2" bgcolor="#eeeeee">Вызываемый</th>
<th bgcolor="#eeeeee" align="center">Длительность</th>
<th bgcolor="#eeeeee" align="center">Транк</th>
<th bgcolor="#eeeeee">Тарифная зона</th>
</tr>

{section name=tableselect loop=$data}
<tr bgcolor="#ffffff">
<td>{$data[tableselect].1} </td>
<td>{$data[tableselect].2} </td>
<td bgcolor="#fdfdfd">{$data[tableselect].3} </td>
<td>{$data[tableselect].4} </td>
<td bgcolor="#fdfdfd">{$data[tableselect].5} </td>
<td align="right">{$data[tableselect].6} </td>
<td>{$data[tableselect].7} </td>
<td>{$data[tableselect].8} </td>
</tr>
{/section}

</table>

{*
{html_table loop=$data  th_attr=$th table_attr='width='100%' border="0" bgcolor="#000000"'  cols="Время вызова,Вызывающий,Вызываемый,Длительность,Подразделение,Тарифная зона"  tr_attr=$tr}
*}

<table width='100%' border="0" bgcolor="#FFFFFF">
<tr><td align="center" bgcolor="#FFFFFF">
{$pages}
</td></tr>
</table>
