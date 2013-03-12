<?php
class error_lib{
		#errors
	private $x_fatal = array();
	private $x_warn = array();
	private $x_true = array();
		#msg
	private $x_msg = array();
	private $x_form = array();
		#error report: if is false have fatal error;
	public $x = true;

		#error status: 0 : fatal , 1 : true, 2 : warning;
	public $status = 1;


	#set errors
	public function fatal($error){
		$this->x = false;
		$this->status = 0;
		array_push($this->x_fatal, $error);
	}
	public function warn($error){
		if($this->x){
			$this->status = 2;
		}
		array_push($this->x_warn, $error);
	}
	public function true($error){
		array_push($this->x_true, $error);
	}

	#set msg
	public function msg($msg, $key = false){
		if(is_array($msg)){
			foreach ($msg as $key => $value) {
				$this->x_msg[$key] = $value;
			}
		}else{
			if($key){
				$this->x_msg[$msg] = $key;
			}else{
				array_push($this->x_msg, $msg);
			}
			
		}
	}

	public function form($f){
		if(!array_search($f, $this->x_form)){
			$this->x_form[] = $f;
		}
	}
	public function display($j = false){
		$e = array();
		$e['status'] = $this->status;
		if(count($this->x_fatal) > 0) $e['fatal'] = $this->x_fatal;
		if(count($this->x_warn) > 0) $e['warn'] = $this->x_warn;
		if(count($this->x_msg) > 0) $e['msg'] = $this->x_msg;
		if(count($this->x_form) > 0) $e['msg']['form'] = $this->x_form;
		if(count($this->x_true) > 0 || count($e) ==0) $e['true'] = $this->x_true;
		return ($j)? json_encode($e) : $e;
	}
}
?>