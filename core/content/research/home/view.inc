<?php
class research_home_view extends main_view
{
	public function _construct()
	{
		$this->data->d_research_list			= $this->query->select('researches,activities', 'researches.*,activities.*', "", "activities.activity_id = researches.activity_id")->all();

		$this->data->d_activity_list			= $this->query->select('activities', '*')->all();
	}
}
?>