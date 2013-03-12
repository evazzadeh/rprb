<?php
class home_cat_view extends main_view
{
	public function _construct()
	{
		$url = url_lib::s('/');
		$mycat = $url[0];
		//var_dump($mycat);

		$this->data->lastnews = $this->query->select("m_posts","*","type='post' and slug_cat='$mycat' ")->order("publish_date","desc")->all();

	}
}
?>