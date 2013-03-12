<?php
abstract class main_controller{
	public $ecode = 15;
	public $url = false;					// if false = extra slash is need to check in config url, if true extra slash is not errro
	public $session = false;				// faghat kasani ke login kardan mitonan bebinan
	public final function ___construct(){
		if($this->session && (!isset($_SESSION['u_login']) || !$_SESSION['u_login'])){
			e_lib::_403(11);
		}

		if(method_exists($this, '_construct')){
			$this->_construct();
		}

		if(config_lib::$type == 'source'){
			$this->CconfigUrl();
		}
	}

	public final function CconfigUrl(){
		if((isset($this->backUrl) && config_lib::$save != $this->backUrl) || !isset($this->backUrl)){
			if($this->url == false){
				if(method_exists($this, 'configUrl')){
					if(!$this->configUrl()) e_lib::_404(11); 
				}else{
					e_lib::_404(12);
				}
			}
		}
	}
}
?>