<?php
class admin_user_model extends main_model
{
	public function post_mode(){
		$url = url_lib::s();
		$mode = array("active", "awaiting", "deactive", "removed");
		$access = false;
		$status = false;
		foreach ($mode as $key => $value) {
			if(isset($url[$value])){
				$access = $url[$value];
				$status = $value;
				break;
			}
		}
		if($access === false){
			$this->debug->fatal('عملیات نامشخص');
		}else{
			if(!preg_match("/^\d+$/", $access)){
				$this->debug->fatal('شناسه عملیات نامعتبر است');
			}else{
				$g = $this->query->select("m_users","*","user_id=$access")->num();
				if($g != 1){
					$this->debug->fatal('کاربری برای تغییر نیست');
				}
			}
		}
		if($this->debug->x){
			$u = $this->query->update("m_users","status='$status'","user_id=$access");
			if(!$u->result()){
				$this->debug->fatal('خطای داخلی');
			}
		}
		if($this->debug->x){
			$this->debug->msg($status, $access);
			$this->query->commit();
		}
	}
}
?>