<?php
class research_detail_model extends main_model
{
	public function post_proposaladd()
	{
		$url               = url_lib::s('/');
		$tmp_research_id   = $url[0];
		$tmp_sender_id 	   = $_SESSION['u_id'];
		$content           = $this->post('content')->preg("/.{10,}/")->error('لطفا توضیحی کوتاه در رابطه با پروپوزال خود ارائه کنید.')->get();
		$price             = $this->post('price')->preg("/.{2,}/")->error('لطفا قیمت خود را برای این طرح وارد نمایید')->get();
		$day               = $this->post('day')->preg("/\d{1,}/")->error('مدت زمان مورد نیاز برای پژوهش را مشخص کنید')->get();
		$afile             = $this->file('file')->maxsize(10)->gtype('document')->error('فایل صحیح را بارگذاری کنید')->get();
		$type              = $this->post('type')->preg("/.{2,}/")->error('لطفا ارسال کننده طرح خود را مشخص کنید')->get();
		$user_id 		   = $_SESSION['u_id'];

		if($this->debug->x)
		{
			if($type=='me')
			{
				$tmp_sender_type	= 'researcher';
				$tmp_group_id 		= 'null';
			}
			elseif(is_numeric($type))
			{
				$tmp_sender_type 	= 'group';
				$tmp_group_id 		= $type;
			}
			else
			{
				$this->debug->fatal('داده های ورودی با اشکال مواجه است. لطفا داده صحیح وارد کنید');
			}

		}

		// ************************************************ Upload File
			if($this->debug->x)
			{
				if($afile)
				{
					$files               = new files_src($this->query);
					$file                = $afile->all();
					$file['title']       = "'$tmp_sender_type'";
					$file['model']       = "'proposal'";
					$file['description'] = "'$content'";
					$move                = $files->move($file);

					if(!$move)
					{
						$this->debug->fatal("انتقال ناموفق فایل");
					}
					//$this->debug->true(var_dump($move["id"]));
				}
			}

		

		if($this->debug->x)
		{

			if($this->query->select("research_proposal","*","sender_type='$tmp_sender_type' and sender_id=$tmp_sender_id and research_id=$tmp_research_id and content='$content'")->count()>0)
				$this->debug->fatal('شما قبلا برای این تقاضا یک پروپوزال ارسال کرده اید. برای ارسال مجدد از توضیح متفاوت استفاده کنید');

			else
			{
				$fileid = $move["id"];
				$rp_id = $this->query->insert('research_proposal', array(
					'sender_type' 	=> "'$tmp_sender_type'",
					'sender_id' 	=> "$tmp_sender_id",
					'group_id' 		=> "$tmp_group_id",
					'research_id' 	=> "$tmp_research_id",
					'content' 		=> "'$content'",
					'price' 		=> "'$price'",
					'day'	 		=> "$day",
					'file' 			=> "$fileid"
					))->result();
				// automatically create notify for company in notification table with trigger! enjoy ^_^
			}
		}



		if($this->debug->x)
		{
			$this->debug->msg('r_id', $tmp_research_id);
			$this->query->commit();
			$this->debug->true('پروپوزال شما برای متقاضی پژوهش با موفقیت ارسال شد. منتظر دریافت پاسخ باشید.');
		}
	}


	public function post_contractaccept()
	{
		$url               		= url_lib::s('/');
		$tmp_research_id   		= $url[0];
		$agreement 				= $this->post('agreement')->preg("/.{4,}/")->error('لطفا یکی از گزینه ها را انتخاب کنید')->get();
		

		if($this->debug->x)
		{
			if($agreement=='agree')
			{
				$this->query->update("researches","status = 'study'", "research_id = $tmp_research_id")->result();
			}
			else
			{
				$this->debug->fatal('مخالفید؟ تا زمانی که موافقت خود را ثبت نکنید اتفاقی رخ نخواهد داد!');
			}
		}

		
		if($this->debug->x)
		{
			$this->query->commit();
			$this->debug->msg('r_id', $tmp_research_id);
			$this->debug->true('قرار داد با موفقیت ثبت شد. با خیالی راحت پژوهش خود را شروع کنید.');
		}

	}


	public function post_reseaechsend()
	{
		$url               		= url_lib::s('/');
		$tmp_research_id   		= $url[0];
		$agreement 				= $this->post('agreement')->preg("/.{4,}/")->error('لطفا یکی از گزینه ها را انتخاب کنید')->get();
		

		if($this->debug->x)
		{
			if($agreement=='agree')
			{
				$this->query->update("researches","status = 'ended'", "research_id = $tmp_research_id")->result();
			}
			else
			{
				$this->debug->fatal('آیا طرح به اتمام نرسیده است! هنوز فرصت دارید.');
			}
		}

		
		if($this->debug->x)
		{
			$this->query->commit();
			$this->debug->msg('r_id', $tmp_research_id);
			$this->debug->true('طرح نهایی شما برای کارفرما ارسال شده است. خدا قوت پژوهشگر');
		}

	}


}
?>