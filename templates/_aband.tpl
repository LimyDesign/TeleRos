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
		<form name="fsel" id="fsel_band" action="index.php" metod='GET' class="form-horizontal">
			<fieldset>
				<div class="control-group" id="NameGroup">
					<label class="control-label" for="name">Название</label>
					<div class="controls">
						<input type="text" name="name" id="name" value="{$name}" tabindex="1" placeholder="Россия / Московская обл.">
						<span class="help-inline">Введите понятное и краткое название тарифной зоны.</span>
					</div>
				</div>
				<div class="form-actions">
					<button type="submit" class="btn btn-primary"><i class="icon-ok icon-white"></i> Отправить</button>
				</div>
			</fieldset>
			<input type="hidden" name="page" value="aband"> 
			<input type="hidden" name="upid" value="{$upid}"> 
			<input type="hidden" name="ac" value="{$actype}"> 
		</form>
	</div>
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
		<div class="well"><strong>Выведена первая {$shrows} тарифных зон</strong>, для поиска конкретной тарифной зоны, воспользуйтесь поиском в строке меню.</div>
	</div>
</div>
{html_table loop=$data table_attr=$table_attr th_attr=$th cols="#,Название,Действие" tr_attr=$tr td_attr=$td}

{if ($shrows < $trows)}
<p align="center"><a href="index.php?page=aband&shrows={$trows}" class="btn btn-large"><i class="icon-arrow-down"></i> ПОКАЗАТЬ ВСЕ ЗАПИСИ <i class="icon-arrow-down"></i></a></p>
{/if}
