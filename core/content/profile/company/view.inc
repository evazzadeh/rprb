<?php
class profile_company_view extends main_view
{
	public function _construct()
	{
		$url = url_lib::s('/');
		$this->data->page_title = "نمایش پروفایل بنگاه اقتصادی";
		$this->data->title = $this->data->page_title . " | " . $this->data->site_title;
		
		if(isset($url[0]))	$tmp_user_id = $url[0];
		else 				$tmp_user_id = $this->data->u_id;

		// **************************************************************************************************
		// aya in moteghayer ha faghat dar in mahdode zende hastan? ya biron az inja ham ghabele dastresiand?
		// **************************************************************************************************
		
		$this->data->d_users        = users_src::get( $tmp_user_id, 'm_users');
		$this->data->d_companies  	= users_src::get( $tmp_user_id, 'companies');
		$y = $this->data->d_companies[0]['activity_id'];
		if (isset($y))
		{
			$x = $this->query->select('activities',"activity_title", "activity_id=$y");
			
			if($x->num()){
				$this->data->d_activity = $x->assoc('activity_title');
			}
		}
		if(isset($_SESSION['u_id']) && ((isset($url[0]) && $url[0] == $_SESSION['u_id']) || !isset($url[0])) || (isset($_SESSION['u_type']) && $_SESSION['u_type'] == "admin")){
			$this->data->iftulogin = 1;
			$activities = $this->query->select('activities',"activity_title")->all();
			$_activities = array();
			foreach ($activities as $key => $value) {
				$_activities[] = $activities[$key]['activity_title'];
			}
			$this->data->_activities = json_encode($_activities);
			$this->data->d_up_list		= $this->query->select("m_files", "*", "model='profile' and user_id=$tmp_user_id")->all();

		}
		else
		{
			$this->data->iftulogin = 0;
		}
		
		$this->data->d_r_list  		= db_src::get( "researches", "company_id", $tmp_user_id);
		$this->data->d_user_grav = "http://www.gravatar.com/avatar/" . md5( strtolower( trim( $this->data->d_users[0]['email'] ) ) ) . "?d=mm&s=80";

	}
}
?>