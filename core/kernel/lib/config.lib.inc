<?php
if(!function_exists('apache_request_headers')) {
	function apache_request_headers() {
		$headers = array();
		foreach($_SERVER as $key => $value) {
			if(substr($key, 0, 5) == 'HTTP_') {
				$headers[str_replace(' ', '-', ucwords(str_replace('_', ' ', strtolower(substr($key, 5)))))] = $value;
			}
		}
		return $headers;
	}
}
function ftoe($s){
	$farsi_array   = array('۰', '۱', '۲', '۳', '۴', '۵', '۶', '۷', '۸', '۹','ي', 'ك');
	$english_array = array('0', '1', '2', '3', '4', '5', '6', '7', '8', '9','ي', 'ک');
	return str_replace($farsi_array, $english_array, $s);
}
function etof($s){
	$farsi_array   = array('۰', '۱', '۲', '۳', '۴', '۵', '۶', '۷', '۸', '۹');
	$english_array = array('0', '1', '2', '3', '4', '5', '6', '7', '8', '9');
	return str_replace($english_array, $farsi_array, $s);
}
function fignore($s){
	$ignore   = array('ي', 'ك');
	$farsi = array('ی', 'ک');
	return str_replace($ignore, $farsi, $s);
}
function safe($s){
	return htmlentities($s, ENT_QUOTES | ENT_IGNORE);
}
class config_lib{
	public static $class;
	public static $method;
	public static $url;
	public static $type;
	public static $ecode = 12;
	public static $save;
	public function __construct(){
		$url = $_SERVER['REQUEST_URI'];
		$url = str_replace("?".$_SERVER['QUERY_STRING'], "", $url);
		$url = preg_replace("#^".path."#i", "", $url);
		$url = preg_replace("#\/$#", "", $url);
		$this->configRedirect($url);
		
		$aUrl = preg_split("/\//", $url, 3);
		$this->configObjects($aUrl);
		$this->configRequest();
		$this->configAdress();
	}
	static function save($class, $method, $action = false){
		self::$class = $class;
		self::$method = $method;
		self::$save = $class.'/'.$method.'/';
		if($action){
			self::$type = 'model';
			$_POST['_post'] = $action;
		}
	}
	public function configRedirect($url){
		$make = array();
		$redirect = '';
/*		if($url == 'search' && isset($_GET['q'])){
			$op = (isset($_GET['op']))? $_GET['op'] : '';
			if(isset($_GET['op'])){
				unset($_GET['op']);
			}
			$get = $_GET['q'];
			if(preg_match("/^@/", $get) || $op == 'researcher' || $op == ''){
				unset($_GET['q']);
				$_GET['researcher'] = preg_replace("/^@/", '', $get);
			}elseif(preg_match("/^\#/", $get) || $op == 'research'){
				var_dump($_GET['q']);
				exit();
				unset($_GET['q']);
				$_GET['research'] = preg_replace("/^#/", '', $get);
			}elseif(preg_match("/^\$/", $get) || $op == 'group'){
				unset($_GET['q']);
				$_GET['group'] = preg_replace("/^\$/", '', $get);
			}
		}
*/
		foreach ($_GET as $key => $value) {
			if($key != "redirect"){
				$value = str_replace(' ', '+', $value);
				if($value == ''){
					$make[] = "$key";
				}else{
					$make[] = "$key=$value";
				}
			}else{
				$redirect = "?$key=$value";
			}
		}
		if(count($make)){
			$redirect = join($make, '/').$redirect;
			$url = ($url != '')? $url.'/' : '';
			header("location:".host.path.$url.$redirect);
			exit();
		}
	}

	public function configObjects($aUrl){
		$gMethod = true;
		if(count($aUrl) == 0 || preg_match("/=/", $aUrl[0]) || $aUrl[0] == ''){
			self::$class = 'home';
			self::$method = 'home';
			self::$url = join($aUrl,'/');
			$gMethod = false;
		}else{
			$Header = apache_request_headers();
			if($aUrl[0] == 'home'){
				e_lib::_404(11);
			}elseif(preg_match("#\.src$#", $aUrl[0]) && isset($Header['source']) && $Header['source'] == 'true'){
				self::$class = str_replace(".src", "", $aUrl[0]);
				self::$method = false;
				unset($aUrl[0]);
				self::$url = join($aUrl,'/');
				$gMethod = false;
			}else{
				self::$class = $aUrl[0];
			}
		}
		if($gMethod && (count($aUrl) < 2 || preg_match("/=/", $aUrl[1])) ){
			self::$method = 'home';
			unset($aUrl[0]);
			self::$url = join($aUrl, '/');
		}elseif($gMethod){
			if($aUrl[1] == 'home'){
				e_lib::_404(12);
			}else{	
				self::$method = $aUrl[1];
				self::$url = (isset($aUrl[2]))? $aUrl[2] : '';
			}
		}
	}

	public function configRequest(){
		$Header = apache_request_headers();
		if(self::$method ==false && isset($Header['source']) && $Header['source'] == 'true'){
			self::$type = 'source';
		}elseif($_SERVER['REQUEST_METHOD'] == 'POST'){
			if(!isset($_POST['_post'])) e_lib::_403(31);
			self::$type = 'model';
		}else{
			self::$type = 'theme';
		}
	}

	public function configAdress(){
		$this->MCA = content.'controller'.exec;
		$this->MCC = 'main_controller';
		$this->MMA = content.'model'.exec;
		$this->MMC = 'main_model';
		$this->MVA = content.'view'.exec;
		$this->MVC = 'main_view';
		$this->MDA = content.'display'.html;
	}
}
?>