<?php
class user_register_model extends main_model
{
	public function post_register()
	{
		$email 		= $this->post('email')->preg("/^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$/")->error('آدرس ایمیل وارد شده صحیح نیست')->get();
		$password 	= $this->post('password')->preg("#^.{6,}$#Ui")->error('گذرواژه باید بیشتر از شش حرف باشد')->get();
		$name 		= $this->post('name')->get();
		$type 		= $this->post('type')->preg("/^(researcher|company)$/")->error('نوع فعالیت نامشخص است')->get();
		if ( $type=='researcher' )
		{
			$mode 		= $this->post('mode')->preg("/^(حقیقی|حقوقی)$/")->error('ماهیت کاربر نامشخص است')->get();
			$activity	= $this->post('activity')->preg("/^[0-9]+$/")->error('لطفا زمینه فعالیت را به درستی انتخاب کنید')->get();
			$val_three	= $this->post('val_three')->preg("/.{3,}/")->error('شماره پرونده هیئت علمی را وارد کنید')->get();

			if(is_numeric($activity) and $this->query->select("activities","*","activity_id=$activity")->count()==0)
			{
				$this->debug->fatal('چنین دسته ای وجود ندارد');
			}
		}
		else
		{
			$mode = 'حقیقی';
		}
		$firstname 	= $this->post('firstname')->preg("/.{2,}/")->error('نام را وارد کنید')->get();
		//$lastname 	= $this->post('lastname')->preg("/.{3,}/")->error('نام خانوادگی را وارد کنید')->get();




		if($name != '')
		{
			$this->debug->fatal('ربات عزیز، شما به این راحتی نمی توانید مهمان ما شوید! این سامانه برای انسان هاست!!!');
		}

		if($this->debug->x)
		{
			$isuser = $this->query->select('m_users', 'username', array("email='$email'"))->count();
			if($isuser > 0)
			{
				$this->debug->fatal('این نام کاربری موجود می باشد');
			}
			else
			{
				$tmp_user_id 	= $this->query->insert('m_users', array(
					'username' 	=> "'$email'",
					'password' 	=> "md5('$password')",
					'email' 	=> "'$email'",
					'type' 		=> "'$type'",
					'mode' 		=> "'$mode'",
					'firstname' => "'$firstname'",
					'status' 	=> "'awaiting'"
					))->id();
					//'lastname' 	=> "'$lastname'",
				// automatically add user detail in related table by user type with trigger

			}
		}

		if($type=='researcher' and $this->debug->x)
		{
			$tmp_user_id 	= $this->query->update('researchers', "activity_id=$activity, val_three=$val_three","user_id = $tmp_user_id")->id();
}

if($this->debug->x)
{
	$this->debug->msg('user_id', $tmp_user_id);
	$this->query->commit();
	$this->debug->true('ثبت نام شما با موفقیت به اتمام رسید');
}
}

}
?>