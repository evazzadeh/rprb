<?php
class user_forgotten_model extends main_model
{
	public function post_forgotten()
	{
		$email 		= $this->post('email')->preg("/^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$/")->error('آدرس ایمیل وارد شده صحیح نیست')->get();
		$name 		= $this->post('name')->get();

		if($name != '')
		{
			$this->debug->fatal('ربات عزیز، شما به این راحتی نمی توانید مهمان ما شوید! این سامانه برای انسان هاست!!!');
		}

		if($this->debug->x)
		{
			$isuser = $this->query->select('m_users', '*', array("email='$email'"))->count();
			if($isuser == 0)
			{
				$this->debug->fatal('چنین ایمیلی در سامانه وجود ندارد!');
			}
			elseif($isuser == 1)
			{

				$datarow = $this->query->select('m_users', '*', array("email='$email'"))->assoc();
				$tmp_user_id = $datarow['user_id'];
				$tmp_user_pass = $datarow['password'];
				$today = date("Ymd");

				$isdup = $this->query->select('m_verifications', '*', "code = md5('$tmp_user_id $tmp_user_pass $today')")->count();
				if($isdup>20)		// change to 0
				{
					$this->debug->fatal('شما روزانه فقط یکبار می توانید درخواست بازیابی کلمه عبور را صادر کنید.');
				}
				else
				{
					$v_id = $this->query->insert('m_verifications', array(
						'type' 		=> "'forget'",
						'email' 	=> "'$email'",
						'code' 		=> "md5('$tmp_user_id $tmp_user_pass $today')",
						'user_id' 	=> "$tmp_user_id",
						'verify' 	=> "'no'"
						));

					if($v_id->result())
					{
						$tmp_verify_id = $v_id->id();
						$datarow = $this->query->select('m_verifications', '*', array("verify_id='$tmp_verify_id'"))->assoc();
						$tmp_verify_code = $datarow['code'];

					// *******************************************Send Email
						$to      = "$email";
						$subject = 'سامانه پژوهش های تقاضا محور - بازیابی گذرواژه';
						$headers = "From: no-reply@rprb.ir" . "\r\n" . 'X-Mailer: PHP/' . phpversion();
						$headers .= 'MIME-Version: 1.0' . "\r\n" . 'Content-type: text/html; charset=UTF-8' . "\r\n";

						$message = '<html><body style="direction:rtl; font-family:tahoma;">';

						$message .= '<h1>سامانه پژوهش های تقاضا محور</h1><hr />';
						$message .= '<p>شما تقاضای بازیابی گذرواژه خود را در سامانه اعلام نموده اید. در صورتی که این تقاضا توسط شما صادر شده است، بر روی <a href="http://rprb.ir/verify/'. $tmp_verify_code .'">لینک زیر</a> کلیک کنید.</p>';
						$message .= '<p style="direction:ltr"><a href="http://rprb.ir/verify/'. $tmp_verify_code .'">http://rprb.ir/verify/'. $tmp_verify_code .'</a></p>';
						$message .= '<br /><p>در صورتی که شما از این تقاضا بی خبرید! نیاز به انجام هیچ کاری نیست، حتی می توانید این ایمیل را پاک کنید.</p>';

						$message .= '<br /><p>با احترام، سامانه پژوهش های تقاضا مجور</p>';
						$message .= '</body></html>';

						mail($to, '=?UTF-8?B?'.base64_encode($subject).'?=', $message, $headers);
					}
				}

			}
		}

		if($this->debug->x)
		{
			//$this->debug->msg('user_id', $v_id);
			$this->query->commit();
			$this->debug->true('لطفا ایمیل خود را چک کنید. لینک تایید بازیابی گذرواژه به ایمیل شما ارسال شده است.در صورت عدم دریافت در اینباکس، لطفا بخش spam یا junk ایمیل خود را چک کنید.');
		}
	}

}
?>