<?php
class admin_termedit_model extends main_model
{
	public function check(){
		$s = url_lib::s('/');
		$type = $s[0];
		
		$name 		= $this->post('name')->preg("/.{3,}/")->error('لطفا عنوان را وارد کنید')->get();

		$slug 		= $this->post('slug')->preg("/.{3,}/")->error('لطفا نامک را وارد کنید')->get();
		$slug 		= str_replace(' ', '_', $slug);

		$desc 		= $this->post('desc')->preg("/.{3,}/")->error('لطفا توضیحات را وارد کنید')->get();
		$user_id 	= $_SESSION['u_id'];

		$type = ($type == 'category')? 'cat' : $type;
		return array($name, $slug, $desc, $user_id, $type);
	}
	public function post_add(){
		list($name, $slug, $desc, $user_id, $type) = $this->check();
		$ch = $this->query->select('m_terms', '*', "name = '$name' OR slug = '$slug'");
		if($ch->num()){
			$this->debug->fatal('این مختصات موجود است');
		}
		$ch = $this->query->select('m_posts', '*', "slug = '$slug'");
		if($ch->num()){
			$this->debug->fatal('این مختصات در برگه ای موجود است موجود است');
		}

		if($this->debug->x){
			$q = $this->query->insert("m_terms","NULL, '$name', '$slug', '$desc', '$type'");
			$q->result();
		}
		if($this->debug->x){
			$this->debug->true("مشخصات شما ذخیره شد");
			$this->query->commit();
		}
	}

	public function post_edit(){
		list($name, $slug, $desc, $user_id, $type) = $this->check();
		$term_id = $this->post('term_id')->preg("/^\d+$/")->error('احتمال حمله به سیستم')->get();
		if($this->debug->x){
			$ch = $this->query->select('m_terms', '*', "(name = '$name' OR slug = '$slug') AND term_id != $term_id");
			if($ch->num()){
				$this->debug->fatal('این مختصات موجود است');
			}
			$ch = $this->query->select('m_posts', '*', "slug = '$slug'");
			if($ch->num()){
				$this->debug->fatal('این مختصات در برگه ای موجود است موجود است');
			}

			if($this->debug->x){
				$q = $this->query->update("m_terms",array(
					'name' => "'$name'",
					'slug' => "'$slug'",
					'm_terms.desc' => "'$desc'"
					)
					,"term_id = $term_id");
				$q->result();
			}
		}
		if($this->debug->x){
			$this->debug->true("مشخصات شما ویرایش شد");
			$this->query->commit();
		}
	}
}
?>