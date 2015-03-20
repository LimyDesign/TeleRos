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
		<form name="fsel" id="fsel_phone" action="index.php" metod='GET' class="form-horizontal">
			<fieldset>
				<div class="control-group" id="NameGroup">
					<label class="control-label" for="name">Номер телефона</label>
					<div class="controls">
						<input type="text" name="name" id="name" value="{$name}" tabindex="1" placeholder="1000">
						<span class="help-inline">Введите внутренний номер абонента.</span>
					</div>
				</div>
				<div class="control-group" id="PersonGroup">
					<label class="control-label" for="person">Абонент</label>
					<div class="controls">
						<select name="person" id="person" tabindex="2">{html_options values=$person_id output=$person_name selected=$person}</select>
						<span class="help-inline">Выберите соответсвующего абонента.</span>
					</div>
				</div>
				<div class="control-group" id="DepGroup">
					<label class="control-label" for="dep">Подразделение</label>
					<div class="controls">
						<select name="dep" id="dep" tabindex="3">{html_options values=$dep_id output=$dep_name selected=$dep}</select>
						<span class="help-inline">Выберите соответсвующее подразделение для текущего абонента.</span>
					</div>
				</div>
				<div class="control-group" id="OfficeGroup">
					<label class="control-label" for="office">Местоположение</label>
					<div class="controls">
						<select name="office" id="office" tabindex="4">{html_options values=$office_id output=$office_name selected=$office}</select>
						<span class="help-inline">Выберите соответсвующее местоположение для текущего абонента.</span>
					</div>
				</div>
				<div class="form-actions">
					<button type="submit" class="btn btn-primary"><i class="icon-ok icon-white"></i> Отправить</button>
				</div>
			</fieldset>
			<input type="hidden" name="page" value="aphone"> 
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
		<div class="well"><strong>Выведена первая {$shrows} внутренних телефонов</strong>, для поиска кокретного внутреннего телефона, воспользуйтесь поиском в строке меню.</div>
	</div>
</div>

<p align="right"><a href="print_tel.php" target="_blank" class="btn"><i class="icon-print"></i> Версия для печати</a></p>

{html_table loop=$data table_attr=$table_attr th_attr=$th cols="#,Телефон,Абонент,Подразделение,Местоположение,Действие" tr_attr=$tr td_attr=$td}

{if ($shrows < $trows)}
<p align="center"><a href="index.php?page=aphone&shrows={$trows}" class="btn btn-large"><i class="icon-arrow-down"></i> ПОКАЗАТЬ ВСЕ ЗАПИСИ <i class="icon-arrow-down"></i></a></p>
{/if}
