<?php
class research_cat_view extends main_view
{
	public function _construct()
	{
		$url = url_lib::s('/');
		$mycat = $url[0];

		//$this->data->lastnews = $this->query->select("m_posts","*","type='post' and address like '$mycat/%' ")->order("publish_date","desc")->all();

		$this->data->d_activity_detail			= $this->query->select('activities', '*', "slug='$mycat'")->assoc();
		$mycatid = $this->data->d_activity_detail['activity_id'];

		$this->data->d_research_list			= $this->query->select('researches,activities', 'researches.*,activities.*', "researches.activity_id = $mycatid", "activities.activity_id = researches.activity_id")->all();

	}
}
?>