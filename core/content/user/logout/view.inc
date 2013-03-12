<?php
class user_logout_view extends main_view
{
	public function _construct()
	{
		session_destroy();
		$_SESSION['u_login'] = false;
		$_SESSION['u_id'] = false;
		$_SESSION['u_username'] = false;
		$_SESSION['u_password'] = false;
		$_SESSION = array();
		
		header('location: ' . $this->data->site_url);
		exit();
	}
}
?>