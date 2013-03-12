<?php
abstract class main_model{
	public $ecode = 16;
	public $errors;
	
	#sql config
	public $transition = true;
	public $sqlerror = true;
	public $sql = true;
	public final function __construct($controller){
		$this->debug = new error_lib();
		if($this->sql){
			$er = ($this->sqlerror)? $this->debug : false;
			$this->query = new sql_lib($er, $this->transition);
		}
		$this->controller = $controller;
		$this->controller->CconfigUrl($this);
		if(method_exists($this, '_construct')){
			$this->_construct();
		}
	}

	public final function post($v){
		return new validation_lib($v, $this->debug, 'post');
	}

	public final function file($v){
		return new validation_lib($v, $this->debug, 'file');
	}
	public final function __atEnd(){
		$Header = apache_request_headers();
		$ajx = false;
		if((isset($Header['X-Requested-With']) && $Header['X-Requested-With'] == 'XMLHttpRequest') || (isset($_POST['refrash_for_post']) && $_POST['refrash_for_post'] == 'on')){
			$ajx = true;
		}
		$this->error = $this->debug->display($ajx);
		if($ajx){
			echo $this->error;
		}else{
			$_SESSION['ERROR_'.config_lib::$class.'_'.config_lib::$method] = $this->error;

			$location = (config_lib::$class == "home") ? "/" : '/'.config_lib::$class;

			$location .= (config_lib::$method == "home") ? "" : '/'.config_lib::$method;

			echo '<meta http-equiv="refresh" content="0; url='.host.$location.'">';
		}
		exit();
	} 
}
?>