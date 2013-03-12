<?php
class admin_home_controller extends main_controller
{
	public $session = true;
	public function _construct()
	{
		// change type to admin after complete 
		if(!isset($_SESSION['u_type']) || $_SESSION['u_type'] != 'admin')
		{
			// access denied 403 error
			e_lib::_403(77);
		}
	}


	public function configUrl()
	{
		$url = url_lib::s('/');
		$sql = new sql_lib();

		
		if(!isset($url[0])) return true;								// if is not set custom url show home and exit

// ------------------------------------------------------------------------------------------------------------ Posts
		if($url[0]=='news' or $url[0]=='page')							// if set admin/post/[any]
		{
			if(!isset($url[1]))
			{
				config_lib::save('admin','post');
				return true;
			}
			elseif($url[1]=='add' or $url[1]=='edit' or $url[1]=='delete')
			{
				config_lib::save('admin','postedit');
				return true;
			}

			return false;
		}


// ------------------------------------------------------------------------------------------------------------ Terms
		if($url[0]=='tag' or $url[0]=='category')							// if set admin/post/[any]
		{
			if(!isset($url[1]))
			{
				config_lib::save('admin','term');
				return true;
			}
			elseif($url[1]=='add' or $url[1]=='edit' or $url[1]=='delete')
			{
				config_lib::save('admin','termedit');
				return true;
			}

			return false;
		}


// ------------------------------------------------------------------------------------------------------------ Media
		if($url[0]=='media')												// if set admin/post/[any]
		{
			if(!isset($url[1]))
			{
				config_lib::save('admin','media');
				return true;
			}
		}



// ------------------------------------------------------------------------------------------------------------ User
		if($url[0]=='user')												// if set admin/post/[any]
		{

			if(!isset($url[1]))
			{
				config_lib::save('admin','user');
				return true;
			}elseif(isset($url[1]) && preg_match('/^(active|awaiting|deactive|removed)/', $url[1]) && !isset($url[2])){

				config_lib::save('admin','user', "mode");
				return true;
			}

		}

// ------------------------------------------------------------------------------------------------------------ Setting
		if($url[0]=='setting')												// if set admin/post/[any]
		{
			if(!isset($url[1]))
			{
				config_lib::save('admin','setting');
				return true;
			}
		}


	}

}
?>