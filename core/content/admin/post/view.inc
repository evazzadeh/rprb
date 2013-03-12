<?php
class admin_post_view extends main_view
{
	public function _construct()
	{
		$this->data->show_page_title = false;
		$this->data->show_footer     = false;
		$this->data->show_main       = false;
		
		$url = url_lib::s('/');
		$this->data->xtype = $url[0];
		if($url[0]=='news')
		{
			$this->data->type = 'post';
			$this->data->m_posts = $this->query->select("m_posts","*","type='post'")->order("publish_date","desc")->all();
		}
		elseif($url[0]=='page')
		{
			$this->data->type = 'page';
			$this->data->m_posts = $this->query->select("m_posts","*","type='page'")->order("publish_date","desc")->all();
		}
	}
}
?>