<?php
class profile_researcher_view extends main_view
{
	public function _construct()
	{

		$url = url_lib::s('/');

		$this->session = true;
		if(isset($url[0]))					$tmp_user_id = $url[0];
		elseif(isset($this->data->u_id)) 	
		{
			$tmp_user_id = $this->data->u_id;

		}
		else 								$show = false;			// show access denied page, how?



		if(isset($tmp_user_id))
		{
			
			$z   						= users_src::get( $tmp_user_id, 'm_users');
			$x  					 	= users_src::get( $tmp_user_id, 'researchers');

			$this->data->d_users 		= $z[0];
			$this->data->d_researchers	= $x[0];
			$this->data->d_r_books      = users_src::get( $tmp_user_id, 'researcher_books');
			$this->data->d_r_patents    = users_src::get( $tmp_user_id, 'researcher_patents');
			$this->data->d_r_contracts  = users_src::get( $tmp_user_id, 'researcher_contracts');
			$this->data->d_r_seminars   = users_src::get( $tmp_user_id, 'researcher_seminars');
			$this->data->d_r_workshops  = users_src::get( $tmp_user_id, 'researcher_workshops');

			$this->data->d_g_list  		= $this->query->select("groups, group_members", "*", "group_members.user_id=$tmp_user_id", "group_members.group_id = groups.group_id")->all();
			//db_src::get( "groups, group_members", "user_id", $tmp_user_id);

			$this->data->d_r_list  		= db_src::get( "researches", "sender_id", $tmp_user_id);
			$this->data->d_rp_list  	= db_src::get( "research_proposal", "sender_id", $tmp_user_id);
			$this->data->d_up_list		= $this->query->select("m_files", "*", "model='profile' and user_id=$tmp_user_id")->all();
//			foreach ($nm as $key => $value) {
//				$nm[$key]['files'] = files_src::Gn($nm[$key]['file_id']);
//			}
//			$this->data->d_up_list = $nm;
			//$this->data->d_r_sug_list		= $this->query->select("researches", "*", "activity_id=$tmp_activity_id and status='declared'")->all();

			
			$this->data->d_user_grav 	= "http://www.gravatar.com/avatar/" . md5( strtolower( trim( $this->data->d_users['email'] ) ) ) . "?d=mm&s=80";
		}
		if(isset($_SESSION['u_id']) && ((isset($url[0]) && $url[0] == $_SESSION['u_id']) || !isset($url[0])) || (isset($_SESSION['u_type']) && $_SESSION['u_type'] == "admin")){
			$this->data->iftulogin = 1;
		}else{
			$this->data->iftulogin = 0;
		}

	}
}
?>
