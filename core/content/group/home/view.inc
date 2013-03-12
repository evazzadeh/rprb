<?php
class group_home_view extends main_view
{
	public function _construct()
	{
		//$this->data->d_group_list = $this->query->select("groups","*")->all();

		$this->data->d_group_list			= $this->query->select('groups,activities', 'groups.*,activities.*', "", "activities.activity_id = groups.activity_id")->all();
	}
}
?>