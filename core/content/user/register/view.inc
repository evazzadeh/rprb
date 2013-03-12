<?php
class user_register_view extends main_view
{
	public function _construct()
	{

		$_input = $this->form('hidden')->name('_post')->value('register');
		$_s = $this->form('submit')->value('ثبت نام');

		// ********************************************************************************** Start Form
		$_email 	= $this->form('text')->name('email')->label("رایانامه - نام کاربری")->id("email")->pl("yourid@sample.com")->attr('class','en');
		$_password 	= $this->form('password')->name('password')->label("گذرواژه")->id("password")->pl("Password")->attr('class','hint--left hint--always en')->attr('data-hint','کلمه عبور باید بیش از 6 کاراکتر باشد');
		$_name 		= $this->form('robot')->name('name')->label("انسان یا ربات!")->id("name")->pl("اگر انسان باشید نباید این فیلد را پر کنید!");

		$_type	 	= $this->form('radio')->name('type')->label('زمینه فعالیت');
		$_type->child()->label('پژوهشگر')->id('researcher')->value('researcher')->attr('class','hint--top')->attr('data-hint','اگر یک پژوهشگر حقیقی یا حقوقی هستید این گزینه را انتخاب کنید');
		$_type->child()->label('متقاضی پژوهش')->id('company')->value('company')->attr('class','hint--bottom')->attr('data-hint','اگر شرکت یا موسسه متقاضی خدمات پژوهشی هستید، این گزینه را انتخاب کنید');

		$_mode	 	= $this->form('radio')->name('mode')->label('ماهیت کاربر');
		$_mode->child()->label('حقیقی')->id('حقیقی')->value('حقیقی')->attr('selected','selected');
		$_mode->child()->label('حقوقی')->id('حقوقی')->value('حقوقی');

		
		$_firstname = $this->form('text')->name('firstname')->label("نام")->id("firstname")->pl("نام / نام شرکت");
		//$_lastname 	= $this->form('text')->name('lastname')->label("نام خانوادگی / نام شرکت")->id("lastname")->pl("نام خانوادگی شما");

		$_val_three = $this->form('text')->name('val_three')->label("شماره پرونده")->id("val_three")->pl("شماره پرونده هیئت علمی");

		$_activity	= $this->form('select')->name('activity')->label('زمینه فعالیت')->id("activity");
		$datatable  = db_src::getall ( 'activities');
		foreach ($datatable as $datarow)
		{
			$_activity->child()->label($datarow['activity_title'])->value($datarow['activity_id']);
		}
		// ********************************************************************************** End Form
		

		$this->data->form[] = $_input->compile();
		$this->data->form[] = $_email->compile();
		$this->data->form[] = $_password->compile();
		$this->data->form[] = $_name->compile();
		$this->data->form[] = $_type->compile();
		$this->data->form[] = $_activity->compile();
		$this->data->form[] = $_mode->compile();
		$this->data->form[] = $_val_three->compile();
		$this->data->form[] = $_firstname->compile();
		//$this->data->form[] = $_lastname->compile();
		
		$this->data->form[] = $_s->compile();

	}
}
?>