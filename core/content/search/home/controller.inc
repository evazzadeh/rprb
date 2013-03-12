<?php
class search_home_controller extends main_controller
{
	public function _construct(){	}
	
	public function configUrl()
	{
		$s = url_lib::s();
		$array = array( 'q', 'page' );
		$ret = true;

		foreach ($s as $key => $value) {
			if(!preg_grep("/^$key$/", $array)){
				$ret = false;
				break;
			}
		}
		return $ret;
	}
}
?>