<?php
class verify_home_controller extends main_controller{
	public function _construct(){	}
	
	
	public function configUrl()
	{
		$url = url_lib::s('/');
		$sql = new sql_lib();
		// check if user add valid address for user id
		//var_dump($url[0]);
		if (isset($url[0]))			// if user add account id to url (for other) 	like rprb.ir/profile/23
		{
			$datarow = $sql->select('m_verifications', '*',"code='$url[0]'")->assoc();
			if ($datarow)
			{
				if(count($url)>=2 ) 
				{
					return false;					// if user input site.com/profile/id/op/any... then show 404
				}
				//var_dump($url[0]);
				config_lib::save('verify','home');
				return true;
			}
		}
		return false;											// if user id does not exist show 404
	}
}
?>