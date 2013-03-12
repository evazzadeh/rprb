<?php
abstract class main_view{
	public $ecode = 17;
	public function __construct($controller){
		$this->controller            = $controller;
		/*$this->controller->CconfigUrl();*/
		$this->data                  = new dataT();
		$this->setE();
		$this->query 				 = new sql_lib(false);
		$this->data->domain          = domain;
		$this->data->host            = host;
		$this->data->path            = path;
		$this->data->site_url        = 'http://'.domain.path;
		$this->data->template_static = 'http://'.domain.path.'static/';

		// --------------------------------------------------------------------------------------------- Options
		//$this->data->m_options 		 = $this->query->select("m_options")->all();
		//foreach ($this->data->m_options as $key => $value) {	# code...	}

		$this->data->site_title      = options_src::get('general','site_title','Mixa');
		$this->data->page_title      = options_src::get('page_title',config_lib::$class.'/'.config_lib::$method.'/', $this->data->site_title);
		$this->data->page_class      = config_lib::$class.(config_lib::$method=='home'?'':'_'.config_lib::$method);
		$this->data->show_intro		 = false;
		$this->data->show_page_title = true;
		$this->data->show_main       = true;
		$this->data->show_footer 	 = true;
		$this->data->title           = $this->data->page_title . " | " . $this->data->site_title;
		$this->data->site_desc       = options_src::get('general','site_desc','proudly powered by Mixa');
		//$this->data->site_email      = options_src::get('general','site_email','info@'.domain);
		

		// save login detail in local variable for next use
		if(isset($_SESSION['u_login']) and $_SESSION['u_login'])
		{
			$this->data->u_login 	 = $_SESSION['u_login'];
			if(isset($_SESSION['u_id']))
			{
				$tmp_user_id					= $_SESSION['u_id'];
				$this->data->u_id 				= $tmp_user_id;
				$this->data->u_notifications 	= $this->query->select("notifications","*","user_id=$tmp_user_id")->limit(0,7)->order("date","desc")->all();
			}
			if(isset($_SESSION['u_username'])) 	{$this->data->u_username 	= $_SESSION['u_username'];}
			if(isset($_SESSION['u_password'])) 	{$this->data->u_password 	= $_SESSION['u_password'];}
			if(isset($_SESSION['u_email'])) 	
			{
				$this->data->u_email      = $_SESSION['u_email'];
				$this->data->u_grav_small = "http://www.gravatar.com/avatar/" . md5( strtolower( trim( $_SESSION['u_email'] ) ) ) . "?d=mm&s=40";
				$this->data->u_grav       = "http://www.gravatar.com/avatar/" . md5( strtolower( trim( $_SESSION['u_email'] ) ) ) . "?d=mm&s=200";
			}
			if(isset($_SESSION['u_type'])) 		{$this->data->u_type 		= $_SESSION['u_type'];}
			if(isset($_SESSION['u_firstname'])) {$this->data->u_firstname 	= $_SESSION['u_firstname'];}
			if(isset($_SESSION['u_lastname'])) 	{$this->data->u_lastname 	= $_SESSION['u_lastname'];}
			if(isset($_SESSION['u_tel'])) 		{$this->data->u_tel 		= $_SESSION['u_tel'];}
			if(isset($_SESSION['u_website'])) 	{$this->data->u_website 	= $_SESSION['u_website'];}
			if(isset($_SESSION['u_status'])) 	{$this->data->u_status 		= $_SESSION['u_status'];}


		}



		

		if(method_exists($this, '_construct')){
			$this->_construct();
		}
		$this->makeDisplay();

	}

	public function form($type){
		return new Mkform($type);
	}

	public function makeDisplay(){
		$Header = apache_request_headers();
		$tmppath		= content.config_lib::$class.'/';
		$tmpname		= config_lib::$method.'/display'.html;
		require_once kernel.'lib/Twig/lib/Twig/Autoloader.php';
		Twig_Autoloader::register();

		if(isset($Header['X-Requested-With']) && $Header['X-Requested-With'] == 'XMLHttpRequest'){
			$display = autoload::file('display');
			$file = file_get_contents($display[0]);
			$file = preg_replace("#\{%\s?extends[^\}]*%\}#Ui", "", $file);
			$file = preg_replace("/^\s?\n/", "", $file);
			$file = preg_replace("#\{%\s?block\s([^\}]*)%\}#Ui", "<mxblock name='$1'>", $file);
			$file = preg_replace("#\{%\s?endblock%\}#Ui", "</mxblock>", $file);
			$loader = new Twig_Loader_String();
			$twig		= new Twig_Environment($loader);
			$this->main_Extentions($twig);
			echo $twig->render($file, $this->data->compile());
		}else{
			$loader		= new Twig_Loader_Filesystem(content);

			$twig		= new Twig_Environment($loader);
			$this->main_Extentions($twig);
			$template		= $twig->loadTemplate(config_lib::$class.'/'.$tmpname);
			$template ->	display($this->data->compile());
		}
	}
	public function setE(){
		$s_e_name = 'ERROR_'.config_lib::$class.'_'.config_lib::$method;
		if(isset($_SERVER['HTTP_REFERER']) && isset($_SESSION[$s_e_name])){
			$err = $_SESSION[$s_e_name];
			$msg = (isset($err['msg']))? $err['msg'] : false;
			unset($err['msg']);
			$this->data->error = $err;
			$this->data->msg = $msg;
			unset($_SESSION[$s_e_name]);
		}
	}

	public function main_Extentions($twig){
		$twig->addFilter($this->twig_fcache());
		$twig->addFilter($this->twig_date());
		$twig->addFilter($this->twig_fileaddr());
	}
	public function twig_date(){
		return new Twig_SimpleFilter('jdate', function ($string) {
			$date = preg_match("/^(\d{4})\-(\d{2})\-(\d{2})(\s(\d{2}):(\d{2}):(\d{2}))?$/", $string, $datex);
			$jd = new jdate_lib(true, true, 'Asia/Tehran');
			if(count($datex) <=4){
				list($y, $m, $d) = $jd->toJalali($datex[1], $datex[2], $datex[3]);
				return $y-$m-$d;
			}else{
				$mk = mktime($datex[5], $datex[6], $datex[7], $datex[2], $datex[3], $datex[1]);
				return ($jd->date("Y-m-d H:i:s", $mk));
			}
		});
	}

	public function twig_fileaddr(){
		return new Twig_SimpleFilter('file_addr', function ($string) {
			//$this->query->select("notifications","*","user_id=$tmp_user_id")->limit(0,7)->order("date))");
			if(is_numeric($string))
			{
				$file_id          = (int) $string;
				//$tmp           = $this->query->select("m_files","*")->assoc();
				$query   		  = new sql_lib(false, false);
				$tmp              = $query->select("m_files","*","id = $file_id")->assoc();
				
				$tmp_folder       = $tmp['addr_id'];
				$tmp_filename     = $tmp['filename'];
				$tmp_type         = $tmp['type'];
				
				$file_fulladdress = "$tmp_folder/$tmp_filename.$tmp_type";
				return $file_fulladdress;
			}
			else
				return '#';
		});
	}

	public function twig_fcache(){
		return new Twig_SimpleFilter('fcache', function ($string) {
			$file = ltrim($string, '.');
			if(file_exists($string)){
				return $file.'?'.filemtime($string);
			}
		});
	}
}
class dataT{
	public function __set($n, $v){
		$this->$n = $v;
	}
	public function compile(){
		$array = array();
		foreach ($this as $key => $value) {
			$array[$key] = $value;
		}
		return $array;
	}
}

class Mkform{
	public $form = array();
	public function __construct($type = 'input'){
		$class = debug_backtrace(true);
		$class = $class[1];
		if($type == 'child' && $class['class'] == 'Mkform'){
			$class = $class['object'];
			$this->base = $class;
			$this->index = count($class->child);
			$this->base->child[$this->index] = array();
			$this->type = false;
		}else{
			$this->type($type);
		}
		return $this;
	}

	public function child(){
		if(!isset($this->child)){
			$this->child = array();
		}
		return new Mkform('child');
	}

	function compile(){
		if(isset($this->child)){
			$this->form['childs'] = $this->child;
		}
		return $this->form;
	}

	public function attr($n, $v){
		if(isset($this->base)){
			if(preg_match("/^type|label$/Ui", $n)){
				$this->base->child[$this->index][$n] = $v;
			}else{
				if(!isset($this->base->child[$this->index]['attr'])){
					$this->base->child[$this->index]['attr'] = array();
				}
				$this->base->child[$this->index]['attr'][$n] = $v;
			}
		}else{
			if(preg_match("/^type|label$/Ui", $n)){
				$this->form[$n] = $v;
			}else{
				if(!isset($this->form['attr'])){
					$this->form['attr'] = array();
				}
				$this->form['attr'][$n] = $v;
			}
			
		}
		return $this;
	}

	function type($v){
		$this->attr('type', $v);
		return $this;
	}
	function name($v){
		$this->attr('name', $v);
		return $this;
	}
	function classname($v){
		$this->attr('class',$v);
		return $this;
	}
	function pl($v){
		$this->attr('placeholder',$v);
		return $this;
	}
	function label($v){
		$this->attr('label',$v);
		return $this;
	}
	function id($v){
		$this->attr('id',$v);
		return $this;
	}
	function value($v){
		$this->attr('value',$v);
		return $this;
	}
}
?>