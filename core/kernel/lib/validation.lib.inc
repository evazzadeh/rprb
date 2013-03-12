<?php
class validation_lib{
	public $m = null;
	public $p = false;
	public $e = null;
	public $value = false;
	public $status = false;
	public $iffalse = false;
	public $error = false;
	public $name = null;
	public function __construct($p, $e, $m = 'post'){
		$this->e = $e;
		if(!isset($p)){
			return false;
		}else{
			$this->p = $p;
		}
		if($m == 'post'){
			$this->m = $_POST;
		}elseif($m == 'file'){
			$this->m = $_FILES;
		}else{
			$this->m = $_POST;
		}
		$this->name = $p;
		if(isset($this->m[$p])){
			$this->value = fignore($this->m[$p]);
			$this->status = true;
			if($m == 'file' && (!isset($this->value['error']) || (isset($this->value['error']) && $this->value['error'] !=0 ) ) ){
				$this->status = false;
			}
		}
		return $this;
	}
	public function false($v = false){
		$this->iffalse = $v;
		return $this;
	}

	public function preg($p){
		if(!$this->status) return $this;
		if(!preg_match($p, $this->value)){
			$this->status = false;
		}
		return $this;
	}

	public function error($v){
		$this->error = $v;
		return $this;
	}

	public function get($e = true){
		if($this->status){
			if(!is_array($this->value)){
				$this->safe();
				return $this->value;
			}else{
				return $this;
			}
		}else{
			if($e){
				$this->e->fatal($this->error);
				$this->e->form($this->name);
			}
			return $this->iffalse;
		}
	}
	public function safe(){
		$this->value = htmlentities($this->value, ENT_QUOTES | ENT_IGNORE, "UTF-8");
		return $this;
	}
	public function minsize($size){
		if(!$this->status) return $this;
		if($this->value['size']/ (1024 * 1024) < $size){
			$this->status = false;
		}
		if(!$this->status){
			$this->error = ('حجم فایل کمتر از اندازه مجاز است');
		}
		return $this;
	}

	public function maxsize($size){
		if(!$this->status) return $this;
		if($this->value['size']/ (1024 * 1024) > $size){
			$this->status = false;
		}
		if(!$this->status){
			$this->error = ('حجم فایل بیشتر از اندازه مجاز است');
		}
		return $this;
	}

	public function type($ntype){
		if(!$this->status) return $this;
		$type = (count(preg_split("[,]", $ntype)) > 1)? preg_split('[,]', $ntype) : $ntype;
		$ret = false;
		$exp = explode('.', $this->value['name']);
		$xtype = strtolower(end($exp));
		if(is_array($type)){
			foreach ($type as $key => $value) {
				if($xtype == strtolower($value)){
					$ret = true;
					break;
				}
			}
		}else{
			$ret = ($xtype == strtolower($type)) ?true : false;
		}
		if(!$ret){
			$this->error = ('نوع فایل نامعتبر است');
		}
		$this->status = $ret;
		return $this;
	}
	public function gtype($ntype){
		if(!$this->status) return $this;
		$array = array(
			'document' 	=> 'doc,docx,pdf,rtf,txt',
			'image' 	=> 'jpg,jpeg,png,gif',
			'zip' 		=> 'zip,rar',
			);
		if(isset($array[$ntype])){
			$this->type($array[$ntype]);
		}else{
			//$this->debug->fatal("انتقال ناموفق فایل");
			$this->error = ('نوع فایل نامعتبر است');
			$this->status = false;
		}
		return $this;
	}

	public function tmname(){
		if(!$this->status) return $this;
		return $this->value['tmp_name'];
	}

	public function name(){
		if(!$this->status) return $this;
		return $this->value['name'];
	}

	public function size(){
		if(!$this->status) return $this;
		return $this->value['size'];
	}

	public function all(){
		if(!$this->status) return $this;
		$exp = explode('.', $this->value['name']);
		$xtype = strtolower(end($exp));
		$this->value['mytype'] = $xtype;
		return $this->value;
	}
}
?>