<?php
class profile_overseer_view extends main_view
{
	public function _construct()
	{
		$this->data->page_title = options_src::get('page_title',config_lib::$class.'/'.config_lib::$method.'/'.config_lib::$url, $this->data->site_title);
		$this->data->title = $this->data->page_title . " | " . $this->data->site_title;
	}
}
?>