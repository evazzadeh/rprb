<?php
class admin_user_view extends main_view
{
	public function _construct()
	{
		$this->data->show_page_title = false;
		$this->data->show_footer 	 = false;

		//$this->data->m_users_awaiting = $this->query->select("m_users","*","type<>'admin'")->order("user_id","desc")->all();

		$this->data->m_users_all	  = $this->query->select("m_users","*","type<>'admin'")->order("user_id","desc")->all();
	}
}
?>