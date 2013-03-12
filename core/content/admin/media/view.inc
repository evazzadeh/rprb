<?php
class admin_media_view extends main_view
{
	public function _construct()
	{
		$this->data->show_page_title = false;
		$this->data->show_footer 	 = false;

		$this->data->m_users = $this->query->select("m_files","*","model='admin'")->all();
	}
}
?>