{* Smarty *}

{if isset($get_print)}
<div class="row">
	<div class="span10">{$p_total}</div>
	<div class="span2">{$get_print}</div>
</div>

<div class="pagination" style="text-align: center">
	<ul>{$pages}</ul>
</div>
{/if}

<table class="table table-striped table-bordered table-condensed">
	<tr>
		<th>Время вызова</th>
		<th colspan="2">Вызывающий</th>
		<th colspan="2">Вызываемый</th>
		<th>Длительность</th>
		<th>Транк</th>
		<th>Тарифная зона</th>
	</tr>{section name=tableselect loop=$data}<tr>
		<td>{$data[tableselect].1} </td>
		<td>{$data[tableselect].2} </td>
		<td>{$data[tableselect].3} </td>
		<td>{$data[tableselect].4} </td>
		<td>{$data[tableselect].5} </td>
		<td>{$data[tableselect].6} </td>
		<td>{$data[tableselect].7} </td>
		<td>{$data[tableselect].8} </td>
	</tr>{/section}</tr>
</table>

{if isset($get_print)}
<div class="pagination" style="text-align: center">
	<ul>{$pages}</ul>
</div>
{/if}