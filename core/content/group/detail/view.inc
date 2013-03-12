<?php
class group_detail_view extends main_view
{
	public function _construct()
	{
		$this->data->page_title = "نمایش گروه";
		$this->data->title = $this->data->page_title . " | " . $this->data->site_title;
		//$query = new sql_lib(false, false);
		$url = url_lib::s('/');
		if(isset($url[0]))				$tmp_group_id	= $url[0];
		if(isset($this->data->u_id))	$tmp_user_id	= $this->data->u_id;

		$this->data->d_group			= $this->query->select('groups,activities', 'groups.*,activities.*', "group_id=$tmp_group_id", "activities.activity_id = groups.activity_id")->all();
		if (isset($this->data->d_group[0]['activity_id'])) $tmp_activity_id = $this->data->d_group[0]['activity_id'];

		$this->data->d_r_list  			= db_src::get( "researches", "group_id", $tmp_group_id);
		$this->data->d_rp_list  		= db_src::get( "research_proposal", "group_id", $tmp_group_id);
		$this->data->d_r_sug_list		= $this->query->select("researches", "*", "activity_id=$tmp_activity_id and status='declared'")->all();
		


		$this->data->d_group_detail		= $this->query->select('m_users,researchers,group_members', '*', "group_id=$tmp_group_id", "m_users.user_id = researchers.user_id,m_users.user_id = group_members.user_id")->all();

		if(isset($tmp_user_id))
		{
			$this->data->ismember 		= $this->query->select("group_members","*","group_id=$tmp_group_id and user_id=$tmp_user_id")->assoc();
		}

		
		// join kardan chetory bod? yadam raft!! bayad ba table researches join beshe




		$_input = $this->form('hidden')->name('_post')->value('joingroup');
		$_s = $this->form('submit')->value('عضویت در گروه');

		$this->data->form[] = $_input->compile();
		$this->data->form[] = $_s->compile();

	}
}
?>