<?php
class login_src
{
	public function __construct($view)
	{
		$_input = $view->form('hidden')->name('_post')->value('login');
		
		// ********************************************************************************** Start Form
		$_username 	= $view->form('text')->name('username')->label("نام کاربری")->id("username")->pl("نام کاربری")->attr('class','en');
		$_password 	= $view->form('password')->name('password')->label("گذرواژه")->id("password")->pl("کلمه عبور")->attr('class','en');
		$_name 		= $view->form('robot')->name('name')->label("انسان یا ربات!")->id("name")->pl("اگر انسان باشید نباید این فیلد را پر کنید!");
		$_s = $view->form('submit')->value('ورود');

		// ********************************************************************************** Render Form
		$view->data->form[] = $_input->compile();
		$view->data->form[] = $_name->compile();
		$view->data->form[] = $_username->compile();
		$view->data->form[] = $_password->compile();
		$view->data->form[] = $_s->compile();
	}
}

?>