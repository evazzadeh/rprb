<?php
class url_lib{
	static function s($split = '=', $url = false){
		$url = ($url)? $url : config_lib::$url;
		$url = urldecode($url);
		$url = htmlentities($url, ENT_QUOTES | ENT_IGNORE, "UTF-8");
		$url = ftoe($url);
		switch ($split) {
			case '/':
			case '=':
			$spl = "\/";
			break;
			
			default:
			$spl = "/";
			break;
		}
		$aurl = preg_split("[$spl]", $url, -1, PREG_SPLIT_NO_EMPTY);
		switch ($split) {
			case '=':
				$ret = self::s2($aurl, '=');
				break;
			
			default:
				$ret = $aurl;
				break;
		}
		return $ret;
	}

	static function s2($a, $s){
		$ret = array();
		foreach ($a as $key => $value) {
			$spl = preg_split("/$s/", $value, 2);
			$ret[$spl[0]] = (isset($spl[1]))? $spl[1] : NULL;
		}
		return $ret;
	}

}

?>