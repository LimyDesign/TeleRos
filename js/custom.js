$(document).ready(function() {
	
	// Focus all tabindex=1 input type text
	$('input[tabindex=1]').focus();
	
	//
	// Validate Forms
	//
	$('#fsel_addrep').submit(function() {
		var repname = $('#repname').val();
		if (repname == '') {
			$('#p_rep').addClass('error');
			$('#addrep_err').show();
			$('#repname').focus();
			return false;
		} else { return true; }
	});
	
	$('#fsel_rep').submit(function() {
		var s1 = $('#srphone:checked').length;
		var s2 = $('#sperson:checked').length;
		var s3 = $('#sdep:checked').length;
		var s4 = $('#sdepat:checked').length;
		var s5 = $('#ssdur:checked').length;
		var s6 = $('#strunk:checked').length;
		
		if (s1 > 0 || s2 > 0 || s3 > 0 || s4 > 0 || s5 > 0 || s6 > 0) {
			return true;
		} else {
			$('#srphone').focus();
			$('#sortErrGroup').addClass('error');
			$('#sortErrGroup p.help-block').show();
			return false;
		}
	});
	
	$('#fsel_deps').submit(function() {
		var name = $('#name').val();
		if (name == '') {
			$('#NameGroup').addClass('error');
			$('#name').focus();
			return false;
		} else {
			return true;
		}
	});
	
	$('#fsel_rooms').submit(function() {
		var name = $('#name').val();
		if (name == '') {
			$('#NameGroup').addClass('error');
			$('#name').focus();
			return false;
		} else {
			return true;
		}
	});
	
	$('#fsel_abonent').submit(function() {
		var name = $('#name').val();
		if (name == '') {
			$('#NameGroup').addClass('error');
			$('#name').focus();
			return false;
		} else {
			return true;
		}
	});
	
	$('#fsel_phone').submit(function() {
		var name = $('#name').val();
		var person = $('#person').val();
		var dep = $('#dep').val();
		var office = $('#office').val();
		if (name == '') {
			$('#NameGroup').addClass('error');
			$('#PersonGroup').removeClass('error');
			$('#DepGroup').removeClass('error');
			$('#OfficeGroup').removeClass('error');
			$('#name').focus();
			return false;
		} else if (person == '0') {
			$('#PersonGroup').addClass('error');
			$('#NameGroup').removeClass('error');
			$('#DepGroup').removeClass('error');
			$('#OfficeGroup').removeClass('error');
			$('#person').focus();
			return false;
		} else if (dep == '0') {
			$('#DepGroup').addClass('error');
			$('#NameGroup').removeClass('error');
			$('#PersonGroup').removeClass('error');
			$('#OfficeGroup').removeClass('error');
			$('#dep').focus();
			return false;
		} else if (office == '0') {
			$('#OfficeGroup').addClass('error');
			$('#NameGroup').removeClass('error');
			$('#PersonGroup').removeClass('error');
			$('#DepGroup').removeClass('error');
			$('#office').focus();
			return false;
		} else {
			return true;
		}
	});
	
	$('#fsel_tarif').submit(function() {
		var name = $('#name').val();
		var desc = $('#desc').val();
		if (name == '') {
			$('#NameGroup').addClass('error');
			$('#DescGroup').removeClass('error');
			$('#name').focus();
			return false;
		} else if (desc == '') {
			$('#DescGroup').addClass('error');
			$('#NameGroup').removeClass('error');
			$('#desc').focus();
			return false;
		} else {
			return true;
		}
	});
	
	$('#fsel_band').submit(function() {
		var name = $('#name').val();
		if (name == '') {
			$('#NameGroup').addClass('error');
			$('#name').focus();
			return false;
		} else { return true; }
	});
	
	$('#fsel_mask').submit(function() {
		var mask = $('#mask').val();
		var name = $('#name').val();
		if (mask == '') {
			$('#MaskGroup').addClass('error');
			$('#NameGroup').removeClass('error');
			$('#mask').focus();
			return false;
		} else if (name == '') {
			$('#NameGroup').addClass('error');
			$('#MaskGroup').removeClass('error');
			$('#name').focus();
			return false;
		} else { return true; }
	});
	//
	// End Validate Forms
	//
	
	// for Radio button toogle send value
	$('div.btn-group[data-toggle-name=*]').each(function() {
		var group	= $(this);
		var form 	= group.parents('form').eq(0);
		var name	= group.attr('data-toggle-name');
		var hidden	= $('input[name="' + name + '"]', form);
		$('button', group).each(function() {
			var button = $(this);
			button.on('click', function() {
				hidden.val($(this).val());
			});
			if(button.val() == hidden.val()) {
				button.addClass('active');
			}
		});
	});
	
	//
	// Animation for search input
	//
	$('#main-search').focusin(function () {
		$(this).animate({width: 380}, "slow");
	});
	
	$('#main-search').focusout(function () {
		$(this).animate({width: 220}, "slow");
	});
	//
	// end Animation
	//
	
	
	$('a.lightbox').lightBox();
	
});

function Check()
{
	var s1 = $('#srphone:checked').length;
	var s2 = $('#sperson:checked').length;
	var s3 = $('#sdep:checked').length;
	var s4 = $('#sdepat:checked').length;
	var s5 = $('#ssdur:checked').length;
	var s6 = $('#strunk:checked').length;
	
	if (s1 > 0 || s2 > 0 || s3 > 0 || s4 > 0 || s5 > 0 || s6 > 0) {
		document.fsel.submit();
	} else {
		$('#sortErrGroup').addClass('error');
		$('#sortErrGroup p.help-block').show('fast');
	}
}