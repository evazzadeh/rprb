<?php
class e_lib{
	public static function _404($code){
		$class = debug_backtrace(true);
		header("HTTP/1.0 404 page not found ".$class[1]['class'].': '. $class[0]['line'] ." ($code)");
		//echo 'Page not found '.$class[1]['class'].': '. $class[0]['line'] ." ($code)<br>\n";
		require_once "static/404.php";
		exit();
	}

	public static function _403($code){
		$class = debug_backtrace();
		header("HTTP/1.0 403 access is denied ".$class[1]['class'].': '. $class[0]['line'] ." ($code)");
		echo 'access is denied '.$class[1]['class'].': '. $class[0]['line'] ." ($code)<br>\n";
		exit();
	}
}
?>