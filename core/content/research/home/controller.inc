<?php
class research_home_controller extends main_controller
{
	public function _construct()
	{

	}

	public function configUrl()
	{	// this func run when nothing folder for this address is exist
		$url = url_lib::s('/');
		$sql = new sql_lib();

		if (count($url)==0) return true;
		if(isset($url[0]) and is_numeric($url[0]))			$tmp_research_id = $url[0];
		if(isset($url[1]) and is_numeric($url[1]))			$tmp_proposal_id = $url[1];

		// check if user add valid address for user id
		if (isset($tmp_research_id) and $sql->select('researches', '*',"research_id=$tmp_research_id")->count())
		{
			if(count($url)>=2)
			{

				if (isset($_SESSION['u_login']) and isset($tmp_proposal_id) and $sql->select('researches', '*', "research_id=$tmp_research_id and status='declared'")->count() and $sql->select('research_proposal', '*',"research_id=$tmp_research_id and proposal_id=$tmp_proposal_id")->count())
				{
					config_lib::save('research','detail');
					return true;
				}
				else 
					return false;

			}
			else
			{
				config_lib::save('research','detail');
				return true;
			}
		}

		
		// for category
		if(isset($url[0]))			$tmp_activity_id = $url[0];
		$sql = new sql_lib();
		if (isset($tmp_activity_id) and $sql->select('activities', '*',"slug='$tmp_activity_id'")->count())
		{
			config_lib::save('research','cat');
			return true;
		}

		return false;											// if user id does not exist show 404
	}
}
?>