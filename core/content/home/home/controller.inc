<?php
class home_home_controller extends main_controller
{
	public function _construct(){	}
	
	public function configUrl()
	{
		$url = url_lib::s('/');
		$sql = new sql_lib();
		if(!isset($url[0])) return true;

		// if this page exist
		if($url[0]=='login')
		{
			if(count($url)>=2 ) {return false;}					// if user input site.com/login/any... then show 404	
			config_lib::save('user','login');
			return true;										// else show page template			
		}
		if($url[0]=='register')
		{
			if(count($url)>=2 ) {return false;}					// if user input site.com/login/any... then show 404	
			config_lib::save('user','register');
			return true;										// else show page template			
		}
		if($url[0]=='logout')
		{
			$this->session = true;
			if(count($url)>=2 ) {return false;}					// if user input site.com/login/any... then show 404	
			config_lib::save('user','logout');
			return true;										// else show page template			
		}
		if($url[0]=='forgotten')
		{
			if(count($url)>=2 ) {return false;}					// if user input site.com/login/any... then show 404	
			config_lib::save('user','forgotten');
			return true;										// else show page template			
		}
		if($url[0]=='researchers')
		{
			if(count($url)>=2 ) {return false;}					// if user input site.com/login/any... then show 404	
			config_lib::save('user','researchers');
			return true;										// else show page template			
		}
		if($url[0]=='companies')
		{
			if(count($url)>=2 ) {return false;}					// if user input site.com/login/any... then show 404	
			config_lib::save('user','companies');
			return true;										// else show page template			
		}
		elseif ($sql->select('m_posts', '*',"slug='$url[0]' and type='page'")->count())
		{
			if(count($url)>=2 ) {return false;}					// if user input site.com/page/any... then show 404

			config_lib::save('home','page');
			return true;										// else show page template
		}
		 // if is not page and cat exist
		elseif ($sql->select('m_terms', '*',"slug='$url[0]' and type='cat'")->count())
		{
			if(count($url)>=3 ) {return false;}					// if user input site.com/cat/news/any... then show 404

			if(count($url)==1 )									// if user input site.com/cat1 then cat tmeplate
			{
				config_lib::save('home','cat');
				return true;
			}
			elseif (count($url)==2)								// if user input site.com/cat/news then
			{
				// if user input correct news address show post template
				if ($sql->select('m_posts', '*',"slug='$url[1]' and type='post'")->count())
				{
					config_lib::save('home','post');
					return true;
				}
				else {return false;}							// else id news does not exist show 404
			}
		}
		return false;											// else id news does not exist show 404
	}
}
?>