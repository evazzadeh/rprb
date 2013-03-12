<?php
class verify_home_model extends main_model
{
	public function post_forgottenaccept()
	{
		$url         = url_lib::s('/');
		$tmp_code    = $url[0];
		$datarow     = $this->query->select('m_verifications', '*', "code ='$tmp_code'")->assoc();
		$tmp_user_id = $datarow['user_id'];
		$tmp_verify  = $datarow['verify'];
		$tmp_email   = $datarow['email'];

		
		if($tmp_verify == 'yes')
		{
			$this->debug->fatal('شما یکبار از طریق این کد گذرواژه خود را بازیابی نموده اید. لطفا ایمیل خود را بررسی کنید. گذرواژه جدید برای شما ارسال شده است.');
		}


		if($this->debug->x)
		{
			$this->query->update('m_verifications', "verify='yes'", "code ='$tmp_code'" )->result();
			$tmp_rand = rand(111111, 999999);				// create random password
			$this->query->update('m_users', "password = md5('$tmp_rand') ", "user_id=$tmp_user_id")->result();
		}
		
		if($this->debug->x)
		{
					// *******************************************Send Email
			$to      = "$tmp_email";
			$subject = 'سامانه پژوهش های تقاضا محور - گذرواژه جدید';
			$headers = "From: no-reply@rprb.ir" . "\r\n" . 'X-Mailer: PHP/' . phpversion();
			$headers .= 'MIME-Version: 1.0' . "\r\n" . 'Content-type: text/html; charset=UTF-8' . "\r\n";

			$message = '<html><body style="direction:rtl; font-family:tahoma;">';
			$message .= '<h2>سامانه پژوهش های تقاضا محور</h2><hr />';
			$message .= '<p>گذرواژه شما با موفقیت بازیابی شد. برای دسترسی به اکانت خود می توانید از این اطلاعات استفاده کنید.</p>';
			$message .= '<p>نام کاربری: ' . $tmp_email . ' </p>';
			$message .= '<p>رمز عبور جدید شما: ' . $tmp_rand . ' </p>';
			$message .= '<br /><p>با احترام، سامانه پژوهش های تقاضا مجور</p>';
			$message .= '</body></html>';

			mail($to, '=?UTF-8?B?'.base64_encode($subject).'?=', $message, $headers);



			if($this->debug->x)
			{
				//$this->debug->msg('user_id', $v_id);
				$this->query->commit();
				$this->debug->true('لطفا ایمیل خود را چک کنید. گذرواژه جدید برای شما ارسال شده است.');
			}
		}
	}
}
?>