{* Smarty *}

{if ($status) }
<div class="alert alert-{$status_type}">
	<button class="close" data-dismiss="alert">×</button>
	{$status}
</div>
{/if}

<ul class="nav nav-tabs" id="jrTabs">	
	<li class="active"><a href="#add-edit" data-toggle="tab"><i class="icon-file"></i> Новая / Правка</a></li>
	<li><a href="#help" data-toggle="tab"><i class="icon-question-sign"></i> Справка</a></li>
</ul>

<div class="tab-content">
	<div class="tab-pane active" id="add-edit">
		<form name="fsel" id="fsel_deps" action="index.php" metod='GET' class="form-horizontal">
			<fieldset>
				<div class="control-group" id="NameGroup">
					<label class="control-label" for="name">Название подразделения</label>
					<div class="controls">
						<input type="text" name="name" id="name" value="{$name}" tabindex="1" placeholder="Руководство">
						<span class="help-inline">Введите название подразделения. Краткое, но ёмкое и понятное для всех.</span>
					</div>
				</div>
				<div class="control-group" id="DescGroup">
					<label class="control-label" for="desc">Описание</label>
					<div class="controls">
						<input type="text" name="desc" id="desc" value="{$desc}" tabindex="2" placeholder="">
						<span class="help-inline">Введи пояснение подразделения, например расшифруйте аббревиатуру подразделения.</span>
					</div>
				</div>
				<div class="form-actions">
					<button type="submit" class="btn btn-primary"><i class="icon-ok icon-white"></i> Отправить</button>
				</div>
			</fieldset>
			<input type="hidden" name="page" value="adeps"> 
			<input type="hidden" name="upid" value="{$upid}"> 
			<input type="hidden" name="ac" value="{$actype}"> 
		</form>
	</div>
	<div class="tab-pane" id="help">
		<div class="well">Справочник в разработке…</div>
	</div>
</div>

<div class="row">
	<div class="span6">
		<div class="well">
			Всего найдено в базе: <span class="badge badge-success">{$trows}</span><br>
			Лимит отображения записей: <span class="badge badge-info">{$shrows}</span>
		</div>
	</div>
	<div class="span6">
		<div class="well"><strong>Выведена первая {$shrows} подразделений</strong>, для поиска конкретного подразделения, воспользуйтесь поиском в строке меню.</div>
	</div>
</div>

<p align="right"><a href="print_tel.php" target="_blank" class="btn"><i class="icon-print"></i> Версия для печати</a></p>

{html_table loop=$data table_attr=$table_attr th_attr=$th cols="#,Название,Описание,Действие" tr_attr=$tr td_attr=$td}

{if ($shrows < $trows)}
<p align="center"><a href="index.php?page=adeps&shrows={$trows}" class="btn btn-large"><i class="icon-arrow-down"></i> ПОКАЗАТЬ ВСЕ ЗАПИСИ <i class="icon-arrow-down"></i></a></p>
{/if}
