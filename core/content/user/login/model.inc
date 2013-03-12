<?php
class user_login_model extends main_model
{
	public function post_login()
	{
		$username 	= $this->post('username')->preg("/^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$/i")->error('نام کاربری را به درستی وارد کنید')->get();
		$password 	= $this->post('password')->preg("#^.{6,}$#Ui")->error('گذرواژه بیشتر از شش حرف است!')->get();
		$name 		= $this->post('name')->get();

		if($name != '')
		{
			$this->debug->fatal('ربات عزیز، شما به این راحتی نمی توانید مهمان ما شوید! این سامانه برای انسان هاست!!!');
		}

		if($this->debug->x)												// if no fatal error occour
			{
				$datarow = $this->query->select('m_users', '*', array("username='$username'","password=md5('$password')"))->assoc(); 
				if($datarow)											// if user input data is correct
					{
						$_SESSION['u_login'] = true;
						$_SESSION['u_id'] = $datarow['user_id'];
						$_SESSION['u_username'] = $datarow['username'];
						$_SESSION['u_password'] = $datarow['password'];
						$_SESSION['u_email'] = $datarow['email'];
						$_SESSION['u_type'] = $datarow['type'];
						$_SESSION['u_firstname'] = $datarow['firstname'];
						$_SESSION['u_lastname'] = $datarow['lastname'];
						$_SESSION['u_tel'] = $datarow['tel'];
						$_SESSION['u_website'] = $datarow['website'];
						$_SESSION['u_status'] = $datarow['status'];
						
						$this->debug->true('ورود موفقیت آمیز');
					}
				else 													// if user or pass is incorrect
					{
						$_SESSION['login'] = false;
						$this->debug->fatal('نام کاربری یا کلمه عبور اشتباه است');
					}
			}

		if($this->debug->x)												// if no fatal error occour
			{
				$this->query->commit();
				$this->debug->msg('user_id', $_SESSION['u_id']);
			}
	}

}
?>