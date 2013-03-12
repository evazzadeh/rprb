(function($){
	$.fn.numberajx = function(){
		var _t = $(this).find('tr').has('td').length;
		$(this).find('tr').has('td').each(function(i){
			if(_t > i+1)
				$(this).find('td:eq(0)').text(i+1);
		});
	}

	$.fn.changetime = function(o){
		var r= Object();
		r.close = function(e){
			if(e.keyCode != 27) return;
			o.add.fadeOut('fast');
			$('.closewindows').fadeOut('fast',function(){
				$(this).remove();
			});
			$('html').css('overflow','auto');
		}
		r.runoption = function(){
			if($(this).is('.option-disable')) return;
			$(this).addClass('option-disable');
			var _p = $(this).parents('td').eq(0);
			_p.addClass('on-option');
			var txt = $(this).text();
			var name = $(this).attr('for');
			var type = (o.types && o.types[name])? o.types[name] : 'text';
			if(type == 'select'){
				var input = $('<select></select>');
				for(c in o.child[name]){
					var xselect = (txt == o.child[name][c].label)? 'selected="selected"' : '';
					$("<option "+xselect+" value='"+o.child[name][c].value+"'>"+o.child[name][c].label+"</option>").appendTo(input);
				}

			}else{
				var input = $('<input type="'+type+'" value="'+txt+'">');
			}
			$(this).html(input);
			var _input = $(this).find('input,select');
			_input[0].focus();
			$(this).data('value',txt);
			_input.change(r.change).blur(r.closeoption);
		}
		r.closeoption = function(){
			if(!$(this).parent().is('.option-disable')) return;
			$(this).parent().removeClass('option-disable');
			var _p = $(this).parents('td').eq(0);
			var txt = $(this).val();
			_p.removeClass('on-option');
			var p = $(this).parent();
			$(this).remove();
			p.text(txt);
		}

		r.err = function(){
			this.text(this.data('value'));
		}

		r.change = function(x){
			var data = {
				_post : o._post,
				rowid : $(this).parents('tr').attr('rowid')
			}
			var _p = $(this).parents('label');
			var name = _p.attr('for');
			data[name] = $(this).val();
			$.ajax({
				url : o.action,
				data : data,
				type : 'post',
				context : _p,
				timeout : function(){
					r.err.call(_p);
				},
				success : function(data){
					try{
						data = $.parseJSON(data);
					}catch(e){

					}
					console.log(data);
					if(!data.status){
						r.err.call(_p);
					}else{
						_p.parents('tr').removeClass('fadeadd');
					}
				}
			}).error(function(e){
				console.log(e.responseText);	
				r.err.call(_p);

			});
			r.closeoption.call(this);
		}
		$(this).each(function(){
			$(this).click(r.runoption);
		});

		r.fadeadd = function(){
			console.log(o.add);
			o.add.fadeIn('fast');
		}

		if(o.add){
			o.parent.find('.add').click(function(){
				var b = $("<div></div>");
				b.addClass('closewindows');
				b.appendTo('body');
				b.show();
				r.fadeadd();
				$(document).bind('keyup.optionsBase', r.close);
				$('.closewindows').click(function(){
					o.add.fadeOut('fast');
					$(this).fadeOut('fast',function(){
						$(this).remove();
					});
				});
			});
			$(this).parents('tr').hover(function(){
				$('<td class="delete-option"><i class="foundicon-remove" title="حدف"></i></td>').appendTo($(this));
				$(this).find('.delete-option').click(function(){
					$(this).fadeOut(function(){
						var data = {
							_post : o._post,
							status: 'del',
							rowid : $(this).parents('tr').attr('rowid')
						}
						$.ajax({
							url : o.action,
							data : data,
							type : 'post',
							success : function(d){
								console.log(d);
							}
						});
						$(this).parents('tr').remove();
						o.parent.numberajx();
					});
				});
			},function(){
				$(this).find('.delete-option').remove();
			});
		}
	}
})(jQuery);
function patent_option(){
	var x = {
		action : $("#users-patents.xlogin_1").attr('action'),
		_post : 'patentedit',
		types : {
			title : 'url'
		},
		add : $("#add-patent-macro"),
		parent : $("#users-patents.xlogin_1")
	}
	return x;
}

function user_data_option(){
	var activ = $("[for='title']").attr('data-child');
	var activj = Array();
	try{
		activ = $.parseJSON(activ);
		for(key in activ){
			activj.push({
				value : activ[key],
				label : activ[key]});
		}
	}catch(e){
		activj = {};
	}
	var x = {
		action : $("#users-data.xlogin_1").attr('action'),
		_post : 'userdata',
		types : {
			website : 'url',
			education : 'select',
			adjusted : 'select',
			energy_type : 'select',
			title : 'select'
		},
		child : {
			education : Array(
			{
				value : 'دیپلم',
				label : 'دیپلم'
			},
			{
				value : 'فوق دیپلم',
				label : 'فوق دیپلم'
			},
			{
				value : 'کارشناسی',
				label : 'کارشناسی'
			},
			{
				value : 'کارشناسی ارشد',
				label : 'کارشناسی ارشد'
			},
			{
				value : 'دکتری',
				label : 'دکتری'
			}
			),
			adjusted : Array(
			{
				value : 'مربی',
				label : 'مربی'
			},
			{
				value : 'استادیار',
				label : 'استادیار'
			},
			{
				value : 'دانشیار',
				label : 'دانشیار'
			},
			{
				value : 'استاد',
				label : 'استاد'
			}
			),
			energy_type : Array(
			{
				value : 'گاز',
				label : 'گاز'
			},
			{
				value : 'گازوئیل',
				label : 'گازوئیل'
			},
			{
				value : 'نفت و گاز',
				label : 'نفت و گاز'
			}
			),
			title : activj
		},
		parent : $("#users-data.xlogin_1")
	}
	return x;
}

function book_option(){
	var x = {
		action : $("#users-books.xlogin_1").attr('action'),
		_post : 'bookedit',
		types : {
			type : 'select'
		},
		add : $("#add-book-macro"),
		parent : $("#users-books.xlogin_1"),
		child : {
			type : Array(
			{
				value : 'نویسنده',
				label : 'نویسنده'
			},
			{
				value : 'گردآورنده',
				label : 'گردآورنده'
			},
			{
				value : 'مترجم',
				label : 'مترجم'
			}
			)
		}
	}
	return x;
}

function contracts_option(){
	var x = {
		action : $("#users-contracts.xlogin_1").attr('action'),
		_post : 'contractsedit',
		add : $("#add-contracts-macro"),
		parent : $("#users-contracts.xlogin_1")
	}
	return x;
}
function seminars_option(){
	var x = {
		action : $("#users-seminars.xlogin_1").attr('action'),
		_post : 'seminarsedit',
		add : $("#add-seminars-macro"),
		parent : $("#users-seminars.xlogin_1"),
		types : {
			type : 'select'
		},
		child : {
			type : Array(
			{
				value : 'سخنرانی',
				label : 'سخنرانی'
			},
			{
				value : 'پوستر',
				label : 'پوستر'
			}
			)
		}
	}
	return x;
}
function workshops_option(){
	var x = {
		action : $("#users-workshops.xlogin_1").attr('action'),
		_post : 'workshopsedit',
		add : $("#add-workshops-macro"),
		parent : $("#users-workshops.xlogin_1"),
		types : {
			type : 'select'
		},
		child : {
			type : Array(
			{
				value : 'دبیر',
				label : 'دبیر'
			},
			{
				value : 'رئیس کارگاه',
				label : 'رئیس کارگاه'
			},
			{
				value : 'عضو کمیته علمی',
				label : 'عضو کمیته علمی'
			},
			{
				value : 'عضو کمیته داوری',
				label : 'عضو کمیته داوری'
			},
			{
				value : 'عضو کمیته اجرایی',
				label : 'عضو کمیته اجرایی'
			}
			)
		}
	}
	return x;
}
function user_upload(){
	var x = {
		action : $("#users-upload.xlogin_1").attr('action'),
		_post : 'uploadedit',
		add : $("#add-users-upload"),
		parent : $("#users-upload.xlogin_1")
	}
	return x;
}
$(document).ready(function(){
	$("#users-patents.xlogin_1 label[for]").changetime(patent_option());
	$("#users-data.xlogin_1 label[for]").changetime(user_data_option());
	$("#users-books.xlogin_1 label[for]").changetime(book_option());
	$("#users-contracts.xlogin_1 label[for]").changetime(contracts_option());
	$("#users-seminars.xlogin_1 label[for]").changetime(seminars_option());
	$("#users-upload.xlogin_1 label[for]").changetime(user_upload());
	$("#users-workshops.xlogin_1 label[for]").changetime(workshops_option());
});