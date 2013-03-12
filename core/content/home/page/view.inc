<?php
class home_page_view extends main_view
{
	public function _construct()
	{
		$url = url_lib::s('/');
		$page_detail = posts_src::get('page',$url[0]);

		$this->data->page_title = $page_detail['title'];
		$this->data->page_content = html_entity_decode($page_detail['content'], ENT_QUOTES | ENT_IGNORE, "UTF-8");
		//$this->data->page_content = nl2br($page_detail['content']);
		$this->data->page_publish_date = $page_detail['publish_date'];

		$this->data->title = $this->data->page_title . " | " . $this->data->site_title;
	}
}
?>