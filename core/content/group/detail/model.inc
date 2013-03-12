<?php
class group_detail_model extends main_model
{
	public function post_joingroup()
	{
		$url               = url_lib::s('/');
		$tmp_group_id      = $url[0];
		$tmp_user_id = $_SESSION['u_id'];


		if($this->query->select("group_members", "*", "group_id=$tmp_group_id and user_id=$tmp_user_id")->count()>0)
		{
			$this->debug->fatal('شما عضو این گروه هستید!');
		}
		else
		{
			$r_id = $this->query->insert('group_members', array(
				'group_id' 		=> "$tmp_group_id",
				'user_id' 		=> "$tmp_user_id"
				))->result();
		}	

		if($this->debug->x)
		{
			//$this->debug->msg('research_id', $r_id);
			$this->query->commit();
			$this->debug->true('درخواست شما برای عضویت در گروه با موفقیت برای مدیر گروه ارسال شد. منتظر تایید مدیر گروه پژوهشی باشید.');
		}
	}
}
?>