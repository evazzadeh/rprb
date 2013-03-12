<?PHP
class autoload{
	public $ecode = 31;
	static function loader($Class){
		$split = explode('_', $Class);
		if(count($split) == 3 && preg_match("#^(model|view|controller)$#", $split[2])){
			self::TLoad($split);
		}elseif(count($split) == 2 && preg_match("#^(lib|cls|src)$#", $split[1])){
			self::kLoad($split);
		}else{

		}
	}

	static function kLoad($aClass){
		if($aClass[1] == 'src'){
			$addr = sources."$aClass[0].$aClass[1]".exec;
		}else{
			$addr = kernel."$aClass[1]/$aClass[0].$aClass[1]".exec;
		}
		if(!file_exists($addr)){
			echo $addr;
			e_lib::_404(11);
		}else{
			require_once $addr;
		}
	}

	static function TLoad($aClass){
		$addr = content."$aClass[0]/$aClass[1]/$aClass[2]".exec;
		if(!file_exists($addr)){
			e_lib::_404(12);
		}else{
			require_once $addr;
		}
	}

	static function file($name, $c=false, $m=false){
		$c = ($c)? $c : config_lib::$class;
		$m = ($m)? $m : config_lib::$method;
		if($name == 'display'){
			$file = content.$c.'/'.$m.'/'.$name.html;
			$name = false;
		}else{
			$file = content.$c.'/'.$m.'/'.$name.exec;
			$name = $c.'_'.$m.'_'.$name;
		}
		return array($file, $name);
	}
}
spl_autoload_register('autoload::loader');
?>