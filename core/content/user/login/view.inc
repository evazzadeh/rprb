<?php
class user_login_view extends main_view
{
	public function _construct()
	{
		new login_src($this);
	}
}
?>