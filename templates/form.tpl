{* Smarty *}

<ul class="nav nav-tabs" id="jrTabs">
	<li class="active"><a href="#reports" data-toggle="tab"><i class="icon-list-alt"></i> Шаблоны</a></li>
	<li><a href="#add_reports" data-toggle="tab"><i class="icon-hdd"></i> Добавить шаблон</a></li>
	<li><a href="#new_reports" data-toggle="tab"><i class="icon-plus-sign"></i> Новый отчет</a></li>
	<li><a href="#help" data-toggle="tab"><i class="icon-question-sign"></i> Справка</a></li>
</ul>

<div class="tab-content">
	<div class="tab-pane active" id="reports">
		<form name="fsel" id="fsel_showrep" action="index.php" metod='GET' class="form-horizontal">
		<input type="hidden" name="page" value="statform">
		<fieldset>
			<legend>Готовые отчеты</legend>
			<div class="control-group">
				<label class="control-label" for="srep">Отчет</label>
				<div class="controls">
					<select name="srep" id="srep">{html_options values=$rep_id output=$rep_name selected=$srep}</select>
					<p class="help-block"><span class="label label-info">СПРАВКА</span> Для того, чтобы воспользоваться шаблонной системой отчетности, необходимо первично создать новый отчет, а затем сохранить. После этого вы сможете воспользоваться сохраненным шаблоном отчетности, либо удалить его, если сохраненный шаблон отчета будет более не нужен.<br><br><span class="label label-warning">ВНИМАНИЕ</span> Кол-во выводимых строк на одну страницу настраивается при создании отчета.</p>
				</div>
			</div>
			<div class="form-actions">
				<button type="submit" name="showrep" class="btn btn-success"><i class="icon-eye-open icon-white"></i> Показать отчет</button>
				<button type="submit" name="delrep" class="btn btn-danger"><i class="icon-trash icon-white"></i> Удалить отчет</button>
			</div>
		</fieldset>
		</form>
	</div>
	<div class="tab-pane" id="add_reports">
		<form name="fsel" id="fsel_addrep" action="index.php" metod='GET' class="form-horizontal">
		<input type="hidden" name="page" value="statform">
		<input type="hidden" name="band" value="{$band}">
		<input type="hidden" name="direct" value="{$direct}">
		<input type="hidden" name="rphone" value="{$rphone}">
		<input type="hidden" name="person" value="{$person}">
		<input type="hidden" name="dep" value="{$dep}">
		<input type="hidden" name="depat" value="{$offices}">
		<input type="hidden" name="trunk" value="{$trunk}">
		<input type="hidden" name="sdur" value="{$sdur}">
		<input type="hidden" name="ftime" value="{$ftime}">
		<input type="hidden" name="etime" value="{$etime}">
		<input type="hidden" name="me" value="{$me}">
		<input type="hidden" name="dir" value="{$dir}">
		<input type="hidden" name="llimit" value="{$llimit}">
		{if $tarif == 'checked'}<input type="hidden" name="tarif" value="1">{/if}
		{if $srhpone == 'checked'}<input type="hidden" name="srhpone" value="1">{/if}
		{if $sperson == 'checked'}<input type="hidden" name="sperson" value="1">{/if}
		{if $sdep == 'checked'}<input type="hidden" name="sdep" value="1">{/if}
		{if $sdepat == 'checked'}<input type="hidden" name="sdepat" value="1">{/if}
		{if $strunk == 'checked'}<input type="hidden" name="strunk" value="1">{/if}
		{if $ssdur == 'checked'}<input type="hidden" name="ssdur" value="1">{/if}
		<fieldset>
			<legend>Добавить текущий отбор в отчеты</legend>
			<div class="control-group" id="p_rep">
				<label class="control-label" for="repname">Название шаблона</label>
				<div class="controls">
					<input type="text" name="repname" id="repname" placeholder="Отчет за текущий месяц"><span id="addrep_err" class="help-inline hide">Данное поле не может быть пустым.</span>
					<p class="help-block"><span class="label label-info">СПРАВКА</span> Дайте название новому созданному отчету, чтобы он наиболее ясно описывал метод отбора данных и метод сортировки, т.к. не только вам может понадобиться данный отчет.
					<br><br><span class="label label-warning">ВНИМАНИЕ</span> Вы можете указать имя уже имеющегося шаблона отчетости, таким образом заменить фильтр отбора данных.
					</p>
				</div>
			</div>
			<div class="form-actions">
				<button type="submit" name="addrep" id="addrep" class="btn btn-primary"><i class="icon-hdd icon-white"></i> Сохранить текущий отбор</button>
			</div>
		</fieldset>
		</form>
	</div>
	<div class="tab-pane" id="new_reports">
		<form name="fsel" id="fsel_rep" action="index.php" metod='GET' class="form-horizontal">
		<input type="hidden" name="page" value="statform">
		<div class="row">
			<div class="span6">
				<fieldset>
					<legend>Критерии отбора</legend>
					<div class="control-group">
						<label class="control-label" for="band">Тарифная зона</label>
						<div class="controls">
							<select name="band" id="band">{html_options values=$band_id output=$band_name selected=$band}</select>
						</div>
					</div>
					<div class="control-group">
						<label class="control-label" for="direct">Направление звонка</label>
						<div class="controls">
							<select name="direct" id="direct">{html_options values=$direct_id output=$direct_name selected=$direct}</select>
						</div>
					</div>
					<div class="control-group">
						<label class="control-label" for="rphone">Номер телефона</label>
						<div class="controls">
							<input type="text" name="rphone" value="{$rphone}" id="rphone" placeholder="88002000600">
						</div>
					</div>
					<div class="control-group">
						<label class="control-label" for="person">Внутренний абонент</label>
						<div class="controls">
							<select name="person" id="person">{html_options values=$person_id output=$person_name selected=$person}</select>
						</div>
					</div>
					<div class="control-group">
						<label class="control-label" for="dep">Подразделение абонента</label>
						<div class="controls">
							<select name="dep" id="dep">{html_options values=$dep_id output=$dep_name selected=$dep}</select>
						</div>
					</div>
					<div class="control-group">
						<label class="control-label" for="depat">Местоположение абонента</label>
						<div class="controls">
							<select name="depat" id="depat">{html_options values=$offices_id output=$offices_name selected=$offices}</select>
						</div>
					</div>
					<div class="control-group">
						<label class="control-label" for="trunk">Транковая группа (TAC)</label>
						<div class="controls">
							<select name="trunk" id="trunk">{html_options values=$trunk_id output=$trunk_name selected=$trunk}</select>
						</div>
					</div>
					<div class="control-group">
						<label class="control-label" for="dur">Продолжительность</label>
						<div class="controls">
							<div class="btn-group" data-toggle-name="sdur" data-toggle="buttons-radio">
								<button type="button" class="btn" name="sdur" value="1"><i class="icon-chevron-right"></i></button>
								<button type="button" class="btn" name="sdur" value="2"><i class="icon-chevron-left"></i></button>						
								<input name="dur" id="dur" type="text" placeholder="ч:мм:сс">
							</div>
							<input name="sdur" type="hidden" value="{$sdur}">					
						</div>
					</div>
					<div class="control-group">
						<label class="control-label" for="ftime">Временной интервал</label>
						<div class="controls">
							<div class="input-prepend">
								<span class="add-on">С</span>
								<input class="span2" name="ftime" id="ftime" value="{$ftime}" placeholder="ГГГГ-ММ-ДД чч:мм:сс">
								<span class="add-on">ПО</span>
								<input class="span2" name="etime" id="etime" value="{$etime}" placeholder="ГГГГ-ММ-ДД чч:мм:сс">
							</div>
							<p></p><span class="label label-important">ИЛИ</span></p>
							<div class="btn-group" data-toggle-name="me" data-toggle="buttons-radio">
								<button type="button" class="btn" name="me" value="1">Прошлый месяц</button>
								<button type="button" class="btn" name="me" value="2">Текущий месяц</button>
							</div>
							<input name="me" type="hidden" value="{$me}">
						</div>
					</div>
					<div class="control-group">
						<label class="control-label" for="tarif">Учет времени</label>
						<div class="controls">
							<label class="checkbox">
								<input type="checkbox" name="tarif" id="tarif" value="1" {$tarif}>Только тарифицируемые
							</label>
						</div>
					</div>
				</fieldset>
			</div><!-- /span -->
			
			<div class="span6">
				<fieldset>
					<legend>Критерии сортировки</legend>
					<div class="control-group">
						<label class="control-label">По направлению</label>
						<div class="controls">
							<div class="btn-group" data-toggle-name="dir" data-toggle="buttons-radio">
								<button type="button" class="btn" name="dir" value="1"><i class="icon-arrow-up"></i> Исходящие</button>
								<button type="button" class="btn" name="dir" value="2"><i class="icon-arrow-down"></i> Входящие</button>
							</div>
							<input type="hidden" name="dir" value="{$dir}">
						</div>
					</div>
					<div class="control-group" id="sortErrGroup">
						<label class="control-label">Условие сортировки</label>
						<div class="controls">
							<label class="checkbox">
								<input type="checkbox" name="srphone" id="srphone" value="1" {$srhpone}> По номеру телефона
							</label>
							<label class="checkbox">
								<input type="checkbox" name="sperson" id="sperson" value="1" {$sperson}> По внутреннему абоненту
							</label>
							<label class="checkbox">
								<input type="checkbox" name="sdep" id="sdep" value="1" {$sdep}> По подразделению абонента
							</label>
							<label class="checkbox">
								<input type="checkbox" name="sdepat" id="sdepat" value="1" {$sdepat}> По местоположению абонента
							</label>
							<label class="checkbox">
								<input type="checkbox" name="strunk" id="strunk" value="1" {$strunk}> По транковой группе
							</label>
							<label class="checkbox">
								<input type="checkbox" name="ssdur" id="ssdur" value="1" {$ssdur}> По продолжительности
							</label>
							<p class="help-block hide"><span class="label label-important">ОШИБКА</span> Вы выбрали направление сортровки, необходимо указать хотя бы одно условие!</p>
						</div>
					</div>
					
					<legend>Параметры отображения</legend>
					<div class="control-group">
						<label class="control-label" for="llimit">Кол-во строк на странице</label>
						<div class="controls">
							<select name="llimit" id="llimit">{html_options values=$llimit_id output=$llimit_name selected=$llimit}</select>
						</div>
					</div>
				</fieldset>
			</div><!-- /span -->
		</div><!-- /row -->
		<fieldset>
			<div class="form-actions">
				<button type="submit" name="sel" class="btn btn-primary"><i class="icon-filter icon-white"></i> Отобрать</button>
			</div>		
		</fieldset>
		</form>
	</div><!-- /reports -->
	<div class="tab-pane" id="help">
		<div class="well">Справка находиться в разработке… Печалько, однако…</div>
	</div>
</div><!-- /tab-content -->
</form>