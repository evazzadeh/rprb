<?php
class research_add_controller extends main_controller
{
	public $session = true;
	public function _construct()
	{
		if(!isset($_SESSION['u_type']) || $_SESSION['u_type'] != 'company')
		{
			// access denied 403 error
			e_lib::_403(97);
			return false;
		}

		return true;
	}

	public function configUrl()
	{
		return true;
	}
}
?>