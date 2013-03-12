<?php
class group_create_model extends main_model
{
	public function post_groupcreate()
	{
		$admin_id	= $_SESSION['u_id'];
		$title		= $this->post('title')->preg("/.{3,}/")->error('لطفا عنوان پژوهش را وارد کنید')->get();
		$content	= $this->post('content')->get();
		$activity	= $this->post('activity')->preg("/^[0-9]+$/")->error('لطفا دسته را به درستی انتخاب کنید')->get();


		if($this->query->select("groups","*","admin_id=$admin_id")->count()>10)
		{
			$this->debug->fatal('متاسفیم، شما بیش از 10 گروه ساخته اید! بهتر است به سایرین هم اجازه فعالیت بدهید!!');
		}
		else 						// if researcher can create group
		{
			if($this->query->select("groups","*","title='$title'")->count()>0)
			{
				$this->debug->fatal('متاسفیم، گروهی با این نام در سامانه ثبت شده است. لطفا نام دیگری را انتخاب کنید.');
			}
			if( is_numeric($activity) and ($this->query->select("activities","*","activity_id=$activity")->count()==0))
			{
				$this->debug->fatal('چنین دسته ای وجود ندارد');
			}

			
			if( $this->debug->x)
			{
				$g_id = $this->query->insert('groups', array(
					'title' 		=> "'$title'",
					'content' 		=> "'$content'",
					'admin_id' 		=> "$admin_id",
					'activity_id' 		=> "$activity"
					))->id();
				// automatically add user detail in group_member table with trigger
			}

			if($this->debug->x)
			{
				$this->debug->true('گروه شما با موفقیت ایجاد شد. حالا می توانید از دوستان خود برای پیوستن به گروه دعوت کنید');
				$this->debug->msg('group_id', $g_id);
				$this->query->commit();
			}
		}
	}
}
?>