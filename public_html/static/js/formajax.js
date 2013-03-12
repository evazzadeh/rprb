(function($){
	var selctajx = null;
	ajxError = function(_$, s){
		this.$ = _$;
		if(s){
			selctajx = s;
		}
		this.s = selctajx;
		var _self = this;
		_self.type = 'post';
		this.onEvent = function(){
			$(this).click(function(){
				$(this).fadeOut('fast', function(){
					$(this).remove();
				});
			});
			var t = $(this);
			setTimeout(function(){
				_self.hide.call(t);
			}, 7000);
		}
		this.hide = function(){
			this.fadeOut('fast', function(){
				$(this).remove();
			});
		}
		this.make = function(data){
			var div = $("<div id='"+_self.s+"'></div>");
			div.addClass('error_'+data['status']);
			div.appendTo("body");
			delete data.status;
			for(err in data){
				var ul = $("<ul></ul>");
				ul.addClass(err);
				ul.appendTo(div);
				for(e in data[err]){
					var li = $("<li>"+data[err][e]+"</li>");
					li.appendTo(ul);
				}
			}
			div.fadeIn("fast");
			this.onEvent.call(div);
		}
		if(_$){
			_$.fadeIn('slow');
			this.onEvent.call(this.$);
		}
		return this;
	}
	$.fn.ajxError = function(s){
		return new ajxError($(this), s);
	}
	ajx = function(_$){
		this.$ = _$;
		var _self = this;
		var bl = function(){
			$("#ajaxbfload").fadeIn('fast');
		};
		var af = function(){
			$("#ajaxbfload").fadeOut('fast');
		};
		var onerror = function(){};
		var xinput = function(){}
		var inputs = function(d){
			if(typeof d.form == 'undefined') return;
			for (i in d.form){
				xinput.call($("[name='"+d.form[i]+"']"));
			}
		};
		var loaded = function(data){
			var x = new ajxError().make(data);
		};
		this.onajax = false;
		/*on submit form*/
		this.submit = function(){
			new ajxError().hide.call($("#"+selctajx));
			bl.call(this);
			if(_self.type == 'post' || !_self.type){
				var data = Object();
				var action = $(this).attr('action');
				$(this).find("input, select, textarea, button").attr('disabled', 'disabled');
				$(this).find('input[name],select[name],textarea[name]').each(function(){
					var name = $(this).attr('name');
					var value = $(this).val();
					if($(this).is(':radio,:checkbox')){
						if($(this).is(":checked")){
							data[name] = value;
						}
					}else{
						data[name] = value;
					}
				});
				_self.send.call(this,{data : data, action:action});
				return false;
			}else if(_self.type == 'a'){
				var action = $(this).attr('href');
				_self.send.call(this,{data : {}, action:action});
				return false;
			}
		}
		/*events*/
		this.done = function(){
			$(this).find("input, select, textarea, button").removeAttr('disabled');
			_self.onajax = false;
			af.call(this);
		}
		this.error = function(){

		}
		this.success = function(data){
			// console.log(data);
			json = Object();
			try{
				json = $.parseJSON(data);
			}catch(e){
				json = {status:false, fatal:['parsing error']};
				console.log(10);
				console.log(data);
			}
			var msg = json.msg;
			delete json.msg;
			if(typeof msg !='undefined'){
				inputs.call(this, msg);
			}
			loaded.call(this, json);
			if(!json.fatal && !json.warn && typeof $(this).data('istrue') == 'function'){
				$(this).data('istrue').call(this, msg);
			}
			if(json.fatal){
				onerror.call(this);
			}
		}
		/*file send*/
		this.fileafterload = function(){
			var data = $(this).contents().find("body").html();
			var _p = $(this).parents('form')[0];
			_self.success.call(_p, data);
			_self.done.call(_p, data);
		}
		/*ajax send*/
		this.send = function(O){
			var _ = this;
			if(typeof _self.onajax == 'object'){
				_self.onajax.abort();
			}
			_self.onajax = $.ajax({
				url : O.action,
				data : O.data,
				type : (_self.type != 'a')? 'post' : 'get',
				context : _,
				statusCode : {},
				timeout : function(){
					console.log("timeout");
				},
				success : _self.success
			}).done(_self.done).error(function(e){
				try{
					var text = e.statusText;
					text = /([^\s]+)\:\s(\d+)\s\((\d+)\)$/gi.exec(text);
					switch(e.status){
						case 404 : var es = 'صفحه یافت نشد';break;
						case 403 : var es = 'دسترسی غیر مجاز';break;
						default : var es = 'خطای'+e.status;
					}
					json = {
						status: 0,
						fatal : Array(es, text[1]+':'+text[2]+':'+text[3])
					};
				}catch(e){
					json = {
						status: 0,
						fatal : Array('خطای نا معتبرس')
					};
				}
				loaded.call(this, json);
				$(this).find("input, select, textarea, button").removeAttr('disabled');
				_self.onajax = false;
				af.call(this);
			});
		}
		/*before send*/
		this.inputs = function(f){
			if(typeof f == 'function'){
				xinput = f;
			}
			return _self;
		}
		this.bl = function(f){
			if(typeof f == 'function'){
				bl = f;
			}
			return _self;
		}
		this.af = function(f){
			if(typeof f == 'function'){
				af = f;
			}
			return _self;
		}

		this.onerror = function(f){
			if(typeof f == 'function'){
				onerror = f;
			}
			return _self;
		}

		/*after ajax load*/
		this.loaded = function(f){
			if(typeof f == 'function'){
				loaded = f;
			}
			return _self;
		}
		/*check if is true*/
		this.istrue = function(f){
			_self.$.each(function(){
				$(this).data('istrue', f);
			});
			return _self;
		}

		/* Constructor */
		if(this.$.is('a')){
			_self.type = 'a';
			this.$.each(function(){
				$(this).click(_self.submit);
			});
		}else{
			this.$.each(function(){
				//$(this).unbind('submit');
				if($(this).find("input[type='file']").length > 0){
					var r = Math.round(Math.random()*1301);
					$('<iframe name="file_input_target_'+r+'" class="file_target_iframe"></iframe>').appendTo($(this));
					$("<input type='hidden' name='refrash_for_post' = value='on'>").appendTo($(this));
					$(this).attr('target','file_input_target_'+r);
					$('[name="file_input_target_'+r+'"]').load(function(){
						$(this).load(_self.fileafterload);
					});
					_self.type = 'file';
				}
				$(this).bind('submit', _self.submit);
			});
		}
		return this;
	}
	$.fn.ajx = function(){
		return new ajx($(this));
	}
	$.fn.istrue = function(f){
		$(this).each(function(){
			$(this).data('istrue', f);
		});
	}
})(jQuery);
$(document).ready(function(){
	$("#proposaladd").istrue(function(){
		$(this)[0].reset()
	});
	$("#formError").ajxError("formError");
	$('#register').ajx().istrue(function(d){location.href="login/"});
	$('#login').ajx().istrue(function(){location.href="profile/"});
	$('#groupcreate').ajx().istrue(function(d){location.href="group/"+d.group_id});
	$('#researchadd').ajx().istrue(function(d){location.href="research/"+d.r_id});
	$('.ajx').ajx().bl(function(){
		$("#ajaxbfload").fadeIn('fast');
	}).af(function(){
		$("#ajaxbfload").fadeOut('fast');
	}).inputs(function(){
		$(this).addClass('alert-error');
	});
	$('#add-patent-macro').ajx().istrue(function(d){
		$(this)[0].reset();
		$('.closewindows').remove();
		$(this).hide();
		var tr = $("#users-patents").find("tr:eq(1)");
		var _ = $('<tr><td></td><td><label for="title"></label></td><td><label for="country"></label></td><td><label for="code"></label></td><td><label for="date"></label></td></tr>');
		_.find('label').each(function(){
			var _for = $(this).attr('for');
			if(d && d[_for]){
				$(this).text(d[_for]);
			}
		});
		if(d && d.rowid){
			_.attr('rowid',d.rowid);
		}
		_.insertBefore($("#goadd-patents"));
		_.parents('table').numberajx();	
		_.find('label').changetime(patent_option());
	}).bl(function(){
		$("#ajaxbfload").fadeIn('fast');
		$('.closewindows').fadeOut();
		$(this).fadeOut();
	}).af(function(){
		$("#ajaxbfload").fadeOut('fast');
	}).onerror(function(){
		$('.closewindows').fadeIn();
		$(this).fadeIn();
	});


	$('#add-book-macro').ajx().istrue(function(d){
		$(this)[0].reset();
		$('.closewindows').remove();
		$(this).hide();
		var tr = $("#users-books").find("tr:eq(1)");
		var _ = $('<tr><td></td><td><label for="title"></label></td><td><label for="publisher"></label></td><td><label for="year"></label></td><td><label for="type"></label></td></tr>');
		_.find('label').each(function(){
			var _for = $(this).attr('for');
			if(d && d[_for]){
				$(this).text(d[_for]);
			}
		});
		if(d && d.rowid){
			_.attr('rowid',d.rowid);
		}
		_.insertBefore($("#goadd-book"));
		_.parents('table').numberajx();	
		_.find('label').changetime(book_option());
	}).bl(function(){
		$("#ajaxbfload").fadeIn('fast');
		$('.closewindows').fadeOut();
		$(this).fadeOut();
	}).af(function(){
		$("#ajaxbfload").fadeOut('fast');
	}).onerror(function(){
		$('.closewindows').fadeIn();
		$(this).fadeIn();
	});

	$('#add-contracts-macro').ajx().istrue(function(d){
		$(this)[0].reset();
		$('.closewindows').remove();
		$(this).hide();
		var tr = $("#users-contracts").find("tr:eq(1)");
		var _ = $('<tr><td></td><td><label for="name"></label></td><td><label for="tel"></label></td><td><label for="title"></label></td></tr>');
		_.find('label').each(function(){
			var _for = $(this).attr('for');
			if(d && d[_for]){
				$(this).text(d[_for]);
			}
		});
		if(d && d.rowid){
			_.attr('rowid',d.rowid);
		}
		_.insertBefore($("#goadd-contracts"));
		_.parents('table').numberajx();	
		_.find('label').changetime(contracts_option());
	}).bl(function(){
		$("#ajaxbfload").fadeIn('fast');
		$('.closewindows').fadeOut();
		$(this).fadeOut();
	}).af(function(){
		$("#ajaxbfload").fadeOut('fast');
	}).onerror(function(){
		$('.closewindows').fadeIn();
		$(this).fadeIn();
	});

	$('#add-seminars-macro').ajx().istrue(function(d){
		$(this)[0].reset();
		$('.closewindows').remove();
		$(this).hide();
		var tr = $("#users-seminars").find("tr:eq(1)");
		var _ = $('<tr><td></td><td><label for="name"></label></td><td><label for="title"></label></td><td><label for="date"></label></td><td><label for="type"></label></td></tr>');
		_.find('label').each(function(){
			var _for = $(this).attr('for');
			if(d && d[_for]){
				$(this).text(d[_for]);
			}
		});
		if(d && d.rowid){
			_.attr('rowid',d.rowid);
		}
		_.insertBefore($("#goadd-seminars"));
		_.parents('table').numberajx();	
		_.find('label').changetime(seminars_option());
	}).bl(function(){
		$("#ajaxbfload").fadeIn('fast');
		$('.closewindows').fadeOut();
		$(this).fadeOut();
	}).af(function(){
		$("#ajaxbfload").fadeOut('fast');
	}).onerror(function(){
		$('.closewindows').fadeIn();
		$(this).fadeIn();
	});

	$('#add-workshops-macro').ajx().istrue(function(d){
		$(this)[0].reset();
		$('.closewindows').remove();
		$(this).hide();
		var tr = $("#users-workshops").find("tr:eq(1)");
		var _ = $('<tr><td></td><td><label for="name"></label></td><td><label for="title"></label></td><td><label for="date"></label></td><td><label for="type"></label></td></tr>');
		_.find('label').each(function(){
			var _for = $(this).attr('for');
			if(d && d[_for]){
				$(this).text(d[_for]);
			}
		});
		if(d && d.rowid){
			_.attr('rowid',d.rowid);
		}
		_.insertBefore($("#goadd-workshops"));
		_.parents('table').numberajx();	
		_.find('label').changetime(workshops_option());
	}).bl(function(){
		$("#ajaxbfload").fadeIn('fast');
		$('.closewindows').fadeOut();
		$(this).fadeOut();
	}).af(function(){
		$("#ajaxbfload").fadeOut('fast');
	}).onerror(function(){
		$('.closewindows').fadeIn();
		$(this).fadeIn();
	});

	$('#add-users-upload').ajx().istrue(function(d){
		$(this)[0].reset();
		$('.closewindows').remove();
		$(this).hide();
		var tr = $("#users-upload").find("tr:eq(1)");
		// console.log(d);
		var _ = $('<tr><td></td><td>'+(d.mytitle)+'</td><td>'+d.mydescription+'</td></tr>');
		_.insertBefore($("#goadd-upload"));
		_.parents('table').numberajx();	
		_.find('label').changetime(workshops_option());
	}).bl(function(){
		$("#ajaxbfload").fadeIn('fast');
		$('.closewindows').fadeOut();
		$(this).fadeOut();
	}).af(function(){
		$("#ajaxbfload").fadeOut('fast');
	}).onerror(function(){
		$('.closewindows').fadeIn();
		$(this).fadeIn();
	});



	function gotox(){
		$(this).ajx().istrue(function(d){
			var txt = $(this).text();
			var p = $(this).parent();
			$(this).parents('td').children('span').each(function(){
				var txt = $(this).text();
				$(this).html('<a href="admin/user/'+$(this).attr("cls-name")+'='+$(this).attr("cls-value")+'">'+txt+'</a>');
				gotox.call($(this).children('a'));
			});
			p.text(txt);
		});
	}
	gotox.call($(".a-ajx"));
	$("#researcher[type=radio]").parents("li").next().hide();
	$("#researcher[type=radio]").parents("li").next().next().hide();
	$("#researcher[type=radio]").parents("li").next().next().next().hide();
	$("#researcher[type=radio]").click(function(){
		$(this).parents("li").next().slideDown("fast");
		$(this).parents("li").next().next().slideDown("fast");
		$(this).parents("li").next().next().next().slideDown("fast");
	});
	$("#company[type=radio]").click(function(){
		$(this).parents("li").next().slideUp("fast");
		$(this).parents("li").next().next().slideUp("fast");
		$(this).parents("li").next().next().next().slideUp("fast");
	});
});