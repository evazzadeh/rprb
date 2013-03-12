<?php
class main_lib{
	public $ecode = 11;
	public $lConfig;
	public $controller;
	public function __construct(){
		$lConfig = new config_lib();
		$this->lConfig = $lConfig;
		#check main controller
		if(!file_exists($lConfig->MCA)) e_lib::_404(11);
		require_once $lConfig->MCA;
		$type = config_lib::$type;
		if($type != 'source'){
			#check file controller
			list($fca, $fcc) = autoload::file('controller');
			if(!file_exists($fca)){
				$this->checkp();
				list($fca, $fcc) = autoload::file('controller');
				if(file_exists($fca)){
					$this->controller = new $fcc();
				}
				$this->controller->backUrl = preg_replace("/\/$/", '', config_lib::$class.'/'.config_lib::$method.'/'.config_lib::$url);
			}else{
				$this->controller = new $fcc();
				if(method_exists($this->controller, 'configUrl')){
					$this->controller->CconfigUrl();
				}
			}
		}
		$type = config_lib::$type;
		$this->$type();
	}

	public function theme(){
		#check file view
		list($x, $sview) = autoload::file('view');
		if(!file_exists($x)) e_lib::_404(13);

		$controller = $this->controller;

		$controller->___construct();

		require_once $this->lConfig->MVA;
		$view = new $sview($controller);
	}

	public function model(){
		#check file display
		list($x, $smodel) = autoload::file('model');
		if(!file_exists($x)) e_lib::_404(14);

		$controller = $this->controller;
		$controller->___construct();

		require_once $this->lConfig->MMA;
		$model = new $smodel($controller);
		$method = 'post_'.$_POST['_post'];
		if(!method_exists($model, $method)) e_lib::_403(32);
		$model->$method();
		$model->__atEnd();
	}

	public function source(){
		$class = config_lib::$class.'_src';
		$Class = new $class();
	}

	public function checkp(){
		list($sa, $sc) = autoload::file('controller', config_lib::$class, 'home');
		if(file_exists($sa)){
			$url = (config_lib::$method != 'home') ? config_lib::$method : '';
			$url .= ($url != '') ? '/'.config_lib::$url : config_lib::$url;
			config_lib::$url = $url;
			config_lib::$method = 'home';
			$controller = new $sc();
		}else{
			$url = (config_lib::$class != 'home') ? config_lib::$class : '';
			$url .= (config_lib::$method != 'home') ? '/'.config_lib::$method : '';
			$url .= ($url != '') ? '/'.config_lib::$url : config_lib::$url;
			config_lib::$url = $url;
			config_lib::$class = 'home';
			config_lib::$method = 'home';
			list($sa, $sc) = autoload::file('controller', 'home', 'home');
			$controller = new $sc();
		}
		if(method_exists($controller, 'configUrl')){
			if(!$controller->configUrl()){
				e_lib::_404(17);
			}
		}
		$this->controller = $controller;
		
	}
}
?>