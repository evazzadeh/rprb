<?php
class group_home_controller extends main_controller
{
	public function _construct()
	{

	}

	public function configUrl()
	{	// this func run when nothing folder for this address is exist
		$url = url_lib::s('/');
		$sql = new sql_lib();
		// check if user add valid address for user id
		if (isset($url[0])  and is_numeric($url[0]))			// if user add account id to url (for other) 	like rprb.ir/profile/23
		{
			$datarow = $sql->select('groups', '*',"group_id=$url[0]");

			if ($datarow->count())
			{
				if(count($url)>=2 ) 
				{
					return false;								// if user input site.com/research/id/any... then show 404
				}

				config_lib::save('group','detail');
				return true;
			}
		}
		return true;											// if user id does not exist show 404
	}
}
?>