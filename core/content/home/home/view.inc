<?php
class home_home_view extends main_view{
	public function _construct(){
		$this->data->show_intro      = true;
		$this->data->show_page_title = false;
		$this->data->show_main       = false;
		$this->data->page_title = "صفحه اصلی";
		$this->data->title = $this->data->site_title;
		
		new login_src($this);

		$this->data->lastnews 		= $this->query->select("m_posts","*","type='post' and slug_cat='news'")->limit(0,5)->order("publish_date","desc")->all();
		$this->data->lastarticle	= $this->query->select("m_posts","*","type='post' and slug_cat='article'")->limit(0,5)->order("publish_date","desc")->all();


		$this->data->lastresearcher	= $this->query->select("m_users", "*", "status='active' and type='researcher'")->limit(0,7)->order("user_id","desc")->all();

		$this->data->lastcompany	= $this->query->select("m_users", "*", "status='active' and type='company'")->limit(0,5)->order("user_id","desc")->all();

		$this->data->lastgroup		= $this->query->select("groups","*")->limit(0,7)->order("date","desc")->limit(0,5)->order("group_id","desc")->all();
		
		$this->data->lastresearch_d	= $this->query->select("researches","*","status='declared'")->limit(0,5)->order("start_date","desc")->all();

		$this->data->lastresearch_s	= $this->query->select("researches","*","status='study'")->limit(0,5)->order("start_date","desc")->all();


		//$this->data->lastresearcher	= $this->query->select("m_users, researchers", "*", "m_users.status='active'", "m_users.user_id = researchers.user_id")->limit(0,7)->order("m_users.user_id","desc")->all();	nemoneye join
	}
}
?>