{* Smarty *}

{if ($status) }
<div class="alert alert-{$status_type}">
	<button class="close" data-dismiss="alert">×</button>
	{$status}
</div>
{/if}

<ul class="nav nav-tabs" id="jrTabs">	
	<li class="active"><a href="#add-edit" data-toggle="tab"><i class="icon-file"></i> Новая / Правка</a></li>
	<li><a href="#import" data-toggle="tab"><i class="icon-globe"></i> Обновление</a></li>
	<li><a href="#help" data-toggle="tab"><i class="icon-question-sign"></i> Справка</a></li>
</ul>

<div class="tab-content">
	<div class="tab-pane active" id="add-edit">
		<form name="fsel" id="fsel_mask" action="index.php" metod='GET' class="form-horizontal">
			<fieldset>
				<div class="control-group" id="MaskGroup">
					<label class="control-label" for="mask">Маска</label>
					<div class="controls">
						<input type="text" name="mask" value="{$mask}" placeholder="8495" tabindex="1" id="mask" class="input-xlarge num-only">
						<span class="help-inline">Начало телефонного номера, или полный номер.</span>
					</div>
				</div>
				<div class="control-group" id="NameGroup">
					<label class="control-label" for="name">Описание</label>
					<div class="controls">
						<input type="text" name="name" value="{$name}" placeholder="Москва" tabindex="2" id="name" class="input-xlarge">
						<span class="help-inline">Описание текущей маски, например город, области, страна или оператор мобильной/стационарной связи.</span>
					</div>
				</div>
				<div class="control-group">
					<label class="control-label" for="tr">Тарифная зона</label>
					<div class="controls">
						<select name="tr" tabindex="3" id="tr">{html_options  values=$tr_id output=$tr_name selected=$str}</select>
					</div>
				</div>
				<div class="form-actions">
					<button type="submit" class="btn btn-primary"><i class="icon-ok icon-white"></i> Отправить</button>
				</div>
			</fieldset>
			<input type="hidden" name="page" value="amasks"> 
			<input type="hidden" name="upid" value="{$upid}"> 
			<input type="hidden" name="ac" value="{$actype}"> 
		</form>
	</div><!-- /home -->
	<div class="tab-pane" id="import">
		<form method="post" class="form-horizontal">
			<fieldset>
				<div class="control-group">
					<label class="control-label">Импорт</label>
					<div class="controls">
						<button type="button" name="iband" class="btn btn-large" disabled><i class="icon-download"></i> Загрузить справочник от разработчика</button>
						<p class="help-block">При загрузке справочника из базы разработчика происходит обновление и замена текущей базы с сохранением пользовательских данных. Для данных действий требуется активная лицензия. Справочник также может не обновляться из-за отсутствия доступа к Интернету.</p>
					</div>
				</div>
			</fieldset>
		</form>
	</div>
	<div class="tab-pane" id="help">
		<div class="well">
			<h3>Общие сведения</h3>
			<p>В данном разделе добавляются, редактируются или удаляются цифровые маски возможных направлений. Эти маски соответствуют началу набираемых телефонных номеров и под обработку по максам не попадают номера в сумме цифр которых меньше 7, т.е. набранный номер 123-45-67 будет считаться городским номером и не будет обрабатываться по существующим маскам в системе тарификатора, также не попадают под обработку номера которые корче 7 цифр. Макси не обязательно задавать в международном стандарте E.164, а могут быть заданы в любом удобном виде, соответствующему способу передачи набираемых номеров вашему оператору.</p>
	
		</div>
	</div>
</div><!-- /tab-content -->

<div class="row">
	<div class="span6">
		<div class="well">
			Всего найдено в базе: <span class="badge badge-success">{$trows}</span><br>
			Лимит отображения записей: <span class="badge badge-info">{$shrows}</span>
		</div>
	</div>
	<div class="span6">
		<div class="well"><strong>Выведена первая {$shrows} масок</strong>, для поиска конкретной маски направления, воспользуйтесь поиском в строке меню.</div>
	</div>
</div>
{html_table loop=$data table_attr=$table_attr th_attr=$th cols="#,Маска,Описание,Тарифная зона,Действие" tr_attr=$tr td_attr=$td}

{if ($shrows < $trows)}
<p align="center"><a href="index.php?page=amasks&shrows={$trows}" class="btn btn-large"><i class="icon-arrow-down"></i> ПОКАЗАТЬ ВСЕ ЗАПИСИ <i class="icon-arrow-down"></i></a></p>
{/if}