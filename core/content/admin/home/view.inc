<?php
class admin_home_view extends main_view
{
	public function _construct()
	{
		$this->data->show_page_title = false;
		$this->data->show_footer     = false;
		$this->data->show_main       = false;
	}
}
?>