<?php
class files_src{
	public $query;
	public static $pathn = 'filesuplaod';
	public static $dir = './updfiles/';
	public function __construct($q){
		$this->query = $q;
	}

	public function move($file){
		$i = $this->query->insert("m_files", array(
			'title' => (isset($file['title'])?$file['title']:'null'),
			'model' => (isset($file['model'])?$file['model']:'null'),
			'type' => "'$file[mytype]'",
			'size' => "'$file[size]'",
			'description' => (isset($file['description'])?$file['description']:'NULL'),
			'user_id' => $_SESSION['u_id'],
			'time' => '\''.date('Y-m-d H:i:s').'\''
			));
		$id = $i->id();
		$filec = $this->query->select('m_files', "*", "id=$id")->assoc();
		if(!is_dir(self::$dir)){
			mkdir(self::$dir);
		}
		$path = self::$dir.self::$pathn.'_'.$filec['addr_id'];
		if(!is_dir($path)){
			mkdir($path);
		}
		
		$addr = self::getFileAddr($filec);
		if(move_uploaded_file($file['tmp_name'], $addr)){
			return $filec;
		}
		return false;

	}

	static function getFileAddr($array){
		$dir = self::$dir;
		$path = self::$pathn;
		$addr = $dir.$path.'_'.$array['addr_id'].'/'.$array['filename'].'.'.$array['type'];
		return $addr;
	}
}
?>