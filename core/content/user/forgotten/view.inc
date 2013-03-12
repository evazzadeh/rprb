<?php
class user_forgotten_view extends main_view
{
	public function _construct()
	{
		$_input = $this->form('hidden')->name('_post')->value('forgotten');
		$_s = $this->form('submit')->value('بازیابی رمز عبور');

		// ********************************************************************************** Start Form
		$_email 	= $this->form('text')->name('email')->label("رایانامه")->id("email")->pl("yourid@sample.com")->attr('class','hint--left hint--always en')->attr('data-hint','لطفا ایمیل خود را به صورت صحیح وارد کنید');
		$_name 		= $this->form('robot')->name('name')->label("انسان یا ربات!")->id("name")->pl("اگر انسان باشید نباید این فیلد را پر کنید!");
		// ********************************************************************************** End Form

		$this->data->form[] = $_input->compile();
		$this->data->form[] = $_email->compile();
		$this->data->form[] = $_name->compile();
		$this->data->form[] = $_s->compile();

	}
}
?>