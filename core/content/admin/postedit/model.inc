<?php
class admin_postedit_model extends main_model
{
	public function check(){
		$s = url_lib::s('/');
		$title 		= $this->post('title')->preg("/.{3,}/")->error('لطفا عنوان را وارد کنید')->get();
		$content	= $this->post('content')->get();
		$this->debug->fatal($content);

		$slug 		= $this->post('slug')->preg("/.{3,}/")->error('لطفا نامک را وارد کنید')->get();
		$slug 		= str_replace(' ', '_', $slug);
		$cat		= $this->post('cat')->preg("/^[0-9]+$/")->error('لطفا دسته را به درستی انتخاب کنید')->get();
		$status 	= $this->post('status')->get();
		$type = $s[0];
		$type = ($type == 'news')? 'post' : $type;
		$user_id = $_SESSION['u_id'];
		if($type == 'post'){
			$cat_slug	 = $this->query->select("m_terms","*","term_id=$cat")->assoc("slug");
			$addr = "$cat_slug";
		}else{
			$addr = $slug;
		}
		return array($title, $content, $slug, $cat, $status, $user_id, $type, $addr);
	}
	public function post_add()
	{
		list($title, $content, $slug, $cat, $status, $user_id, $type, $addr) = $this->check();
		if($this->debug->x)
		{
			$isexist = $this->query->select('m_posts', 'post_id', "slug='$slug'")->count();
			if($isexist > 0)
			{
				$this->debug->fatal('این نامک از قبل موجود است. لطفا برای ادامه نامک جدیدی را وارد کنید');
			}
			else
			{
				
				$tmp_post_id = $this->query->insert('m_posts', array(
					'user_id'		=> "$user_id",
					'publish_date'	=> "now()",
					'title' 		=> "'$title'",
					'content'	 	=> "'$content'",
					'slug' 			=> "'$slug'",
					'slug_cat'		=> "'$addr'",
					'status' 		=> "'$status'",
					'type'		=> "'$type'"
					))->id();

				$tmp_term_id = $this->query->insert('m_term_usage', array(
					'term_id' 		=> "$cat",
					'post_id' 		=> "$tmp_post_id",
					))->id();
			}
		}

		if($this->debug->x)
		{
			$this->debug->msg('user_id', $tmp_post_id);
			$this->query->commit();
			$this->debug->true('ثبت نام شما با موفقیت به اتمام رسید');
		}
	}

	public function post_edit()
	{
		list($title, $content, $slug, $cat, $status, $user_id, $type, $addr) = $this->check();
		$post_id = $this->post('post_id')->preg("/^\d+$/")->error('احتمال حمله به سیستم')->get();
		if($this->debug->x)
		{
			$isexist = $this->query->select('m_posts', 'post_id', "slug='$slug' AND post_id != $post_id")->count();
			if($isexist > 0)
			{
				$this->debug->fatal('این نامک از قبل موجود است. لطفا برای ادامه نامک جدیدی را وارد کنید');
			}
			else
			{
				$cat_slug	 = $this->query->select("m_terms","*","term_id=$cat")->assoc("slug");
				$tmp_post_id = $this->query->update('m_posts', array(
					'user_id'		=> "$user_id",
					'publish_date'	=> "now()",
					'title' 		=> "'$title'",
					'content'	 	=> "'$content'",
					'slug' 			=> "'$slug'",
					'slug_cat'		=> "'$addr'",
					'status' 		=> "'$status'"
					), "post_id = $post_id AND type='$type'")->result();

				$tmp_term_id = $this->query->update('m_term_usage', array(
					'term_id' 		=> "$cat"
					), "post_id = $post_id")->result();
			}
		}

		if($this->debug->x)
		{
			$this->debug->msg('user_id', $tmp_post_id);
			$this->query->commit();
			$this->debug->true('تغییر موفقیت آمیز');
		}
	}
}


?>