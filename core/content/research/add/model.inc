<?php
class research_add_model extends main_model
{
	public function post_researchadd()
	{
		$company_id = $_SESSION['u_id'];
		$title		= $this->post('title')->preg("/.{3,}/")->error('لطفا عنوان پژوهش را وارد کنید')->get();
		$content	= $this->post('content')->get();
		$activity	= $this->post('activity')->preg("/^[0-9]+$/")->error('لطفا دسته را به درستی انتخاب کنید')->get();


		if(is_numeric($activity) and $this->query->select("activities","*","activity_id=$activity")->count()==0)
		{
			$this->debug->fatal('چنین دسته ای وجود ندارد');
		}

		if($this->query->select("researches","*","company_id=$company_id and title='$title'")->count()>0)
		{
			$this->debug->fatal('چنین درخواستی با عنوان نام قبلا توسط شما به ثبت رسیده است');
		}

		if( $this->debug->x)
		{
			$r_id = $this->query->insert('researches', array(
				'company_id' 	=> "$company_id",
				'title' 		=> "'$title'",
				'content' 		=> "'$content'",
				'activity_id'	=> "$activity"
				))->id();
			// automatically create notify for related researchers with trigger
		}

		if($this->debug->x)
		{
			$this->debug->true('تقاضای شما برای پژوهش جدید ثبت شده و به پژوهشگران مرتبط در این زمینه اعلام گردید. منتظر دریافت پاسخ از پژوهشگران باشید.');
			$this->debug->msg('r_id', $r_id);
			$this->query->commit();
		}
	}
}
?>