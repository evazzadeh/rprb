<?php
class profile_home_controller extends main_controller{
	public function _construct(){	}
	
	// zamani ke karbar profile khali ro mizane moshkel dare!
	public function configUrl()
	{	// this func run when nothing folder for this address is exist
		$url = url_lib::s('/');
		$sql = new sql_lib();
		//$u_id = (isset($url[0]))? $url[0] : $_SESSION['u_id'];

		if(isset($url[0])){
			$u_id = $url[0];
		}elseif(isset($_SESSION['u_id'])){
			$u_id = $_SESSION['u_id'];
		}else{
			$u_id = false;
		}

		// check if user add valid address for user id
		if ($u_id  and is_numeric($u_id))			// if user add account id to url (for other) 	like rprb.ir/profile/23
		{
			$datarow = $sql->select('m_users', '*',"user_id=$u_id and (status='active' or status='awaiting')")->assoc();
		//else 											// else if user dont input id (for me) 			like rprb.ir/profile/
		//$datarow = $sql->select('m_users', '*',"user_id=$this->data->u_username")->assoc();	

			if ($datarow)
			{
				if(count($url)>=2 ) 
				{
				return false;					// if user input site.com/profile/id/op/any... then show 404
			}

			if     ($datarow['type']=='researcher')			{config_lib::save('profile','researcher');}
			elseif ($datarow['type']=='company')			{config_lib::save('profile','company');}
			elseif ($datarow['type']=='overseer')			{config_lib::save('profile','overseer');}
			elseif ($datarow['type']=='admin')				{config_lib::save('admin','home');}
			return true;
		}
	}
		return false;											// if user id does not exist show 404
	}
}
?>