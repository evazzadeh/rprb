<?php
class group_create_controller extends main_controller
{
	public $session = true;
	public function _construct()
	{
		if(!isset($_SESSION['u_type']) || $_SESSION['u_type'] != 'researcher')
		{
			// access denied 403 error
			e_lib::_403(98);
		}
	}
}
?>