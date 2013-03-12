<?php
class profile_researcher_model extends main_model
{
	public function post_userdata(){
		$array = array();
		$array2 = array();
		if(isset($_POST['firstname'])){
			$firstname = $this->post('firstname')->get();
			$array['firstname'] = "'$firstname'";
		}

		if(isset($_POST['lastname'])){
			$lastname = $this->post('lastname')->get();
			$array['lastname'] = "'$lastname'";
		}

		if(isset($_POST['tel'])){
			$tel = $this->post('tel')->get();
			$array['tel'] = "'$tel'";
		}

		if(isset($_POST['website'])){
			$website 	= $this->post('website')->preg("/^(|(https?:\/\/)?([a-z0-9][a-z0-9\-]*\.)[a-z0-9][a-z0-9\-]*)$/")->error('آدرس وب سایت را به درستی وارد کنید')->get();
			$array['website'] = "'$website'";
		}

		if(isset($_POST['education'])){
			$education 	= $this->post('education')->preg("/^(دیپلم|فوق دیپلم|کارشناسی|کارشناسی ارشد|دکتری)$/")->error('مدرک را به درستی انتخاب کنید')->get();
			$array2['education'] = "'$education'";
		}

		if(isset($_POST['field'])){
			$field 	= $this->post('field')->preg("/^(.{3,})$/")->error('رشته تحصیلی را به درستی وارد کنید')->get();
			$array2['field'] = "'$field'";
		}

		if(isset($_POST['year'])){
			$year 	= $this->post('year')->preg("/^(\d{4})$/")->get();
			$array2['year'] = "'$year'";
		}

		if(isset($_POST['country'])){
			$country 	= $this->post('country')->preg("/^(.{3,})$/")->get();
			$array2['country'] = "'$country'";
		}

		if(isset($_POST['university'])){
			$university 	= $this->post('university')->preg("/^(.{3,})$/")->get();
			$array2['university'] = "'$university'";
		}

		if(isset($_POST['adjusted'])){
			$adjusted 	= $this->post('adjusted')->preg("/^(مربی|استادیار|دانشیار|استاد)$/")->get();
			$array2['adjusted'] = "'$adjusted'";
		}

		if(isset($_POST['isi'])){
			$isi 	= $this->post('isi')->preg("/^(\d+)$/")->get();
			$array2['isi'] = "'$isi'";
		}
		if(isset($_POST['val_one'])){
			$val_one 	= $this->post('val_one')->preg("/^(\d+)$/")->get();
			$array2['val_one'] = "'$val_one'";
		}
		if(isset($_POST['val_two'])){
			$val_two 	= $this->post('val_two')->preg("/^(\d+)$/")->get();
			$array2['val_two'] = "'$val_two'";
		}
		if(isset($_POST['val_three'])){
			$val_three 	= $this->post('val_three')->preg("/^(\d+)$/")->get();
			$array2['val_three'] = "'$val_three'";
		}
		if(isset($_POST['about'])){
			$about 	= $this->post('about')->preg("/^(.{3,})$/")->get();
			$array2['about'] = "'$about'";
		}

		if(isset($_POST['title'])){
			$title 	= $this->post('title')->get();
			$x = $this->query->select('activities',"*", "activity_title='$title'");
			if(!$x->num()){
				$this->debug->fatal('زیرمجموعه فعالیت ناصحیح است');
			}else{
				$array2['activity_id'] = $x->assoc('activity_id');
			}	
		}

		$s = url_lib::s('/');
		if(isset($s[0]) && preg_match("/^\d+$/", $s[0]) && $s[0] != $_SESSION['u_id']){
			$this->debug->fatal('کاربری غیر مجاز');
		}
		$this->debug->msg($array2);
		if($this->debug->x){
			if(count($array)){
				$q = $this->query->update('m_users', $array, "user_id=$_SESSION[u_id]");
			}elseif (count($array2)) {
				$q = $this->query->update('researchers', $array2, "user_id=$_SESSION[u_id]");
			}
			if(isset($q)){
				if(!$q->result()){
					$this->debug->fatal('خطای داخلی');
				}else{
					$this->query->commit();
					$this->debug->true('با موفقیت ویرایش شد');
				}
			}else{
				$this->debug->fatal('مقدار ناصحیح');
			}
		}
	}
	public function post_patentedit(){
		$array = array();
		if(isset($_POST['title'])){
			$array['title'] = $this->post('title')->get();
		}
		if(isset($_POST['country'])){
			$array['country'] = $this->post('country')->get();
		}
		if(isset($_POST['code'])){
			$array['code'] = $this->post('code')->get();
		}
		if(isset($_POST['date'])){
			$array['date'] = $this->post('date')->get();
		}
		$array2 = $array;
		if($this->debug->x){
			foreach ($array2 as $key => $value) {
				$array[$key] = "'$value'";
			}
			if(isset($_POST['status']) && $_POST['status'] =='del' && isset($_POST['rowid']) && $rowid = $this->post('rowid')->preg('/^\d+$/')->get()){
				$q = $this->query->delete("researcher_patents", "id = $rowid AND user_id=$_SESSION[u_id]");
				$q->result();

			}elseif(isset($_POST['rowid']) && $rowid = $this->post('rowid')->preg('/^\d+$/')->get()){
				$q = $this->query->update('researcher_patents',$array, "id=$rowid AND user_id=$_SESSION[u_id]");
				if(!$q->result()){
					$this->debug->fatal('خطایی در ویرایش رخ داده است');
				}
			}else{
				$array['user_id'] = $_SESSION['u_id'];
				$q = $this->query->insert('researcher_patents',$array);
				if(!$q->result()){
					$this->debug->fatal('خطایی در افزودن به جدول رخ داده است');
				}
				$array2['rowid'] = $q->id();
			}
		}
		if($this->debug->x){
			$this->query->commit();
			$this->debug->msg($array2);
		}
		else
		{
			$this->debug->fatal('خطایی در ثبت داده ها رخ داده است. مقادیر وارد شده را با دقت وارد کنید');
		}
	}


	public function post_bookedit(){
		$array = array();
		if(isset($_POST['title'])){
			$array['title'] = $this->post('title')->get();
		}
		if(isset($_POST['publisher'])){
			$array['publisher'] = $this->post('publisher')->get();
		}
		if(isset($_POST['year'])){
			$array['year'] = $this->post('year')->preg("/^(\d{2}|\d{4})$/")->error('سال را به درستی وارد کنید')->get();
		}
		if(isset($_POST['type'])){
			$array['type'] = $this->post('type')->preg("/^(نویسنده|گردآورنده|مترجم)$/")->error('نوع را به درستی وراد کنید')->get();
		}
		$array2 = $array;
		if($this->debug->x){
			foreach ($array2 as $key => $value) {
				$array[$key] = "'$value'";
			}
			if(isset($_POST['status']) && $_POST['status'] =='del' && isset($_POST['rowid']) && $rowid = $this->post('rowid')->preg('/^\d+$/')->get()){
				$q = $this->query->delete("researcher_books", "id = $rowid AND user_id=$_SESSION[u_id]");
				$q->result();

			}elseif(isset($_POST['rowid']) && $rowid = $this->post('rowid')->preg('/^\d+$/')->get()){
				$q = $this->query->update('researcher_books',$array, "id=$rowid AND user_id=$_SESSION[u_id]");
				if(!$q->result()){
					$this->debug->fatal('خطایی در ویرایش رخ داده است');
				}
			}else{
				$array['user_id'] = $_SESSION['u_id'];
				$q = $this->query->insert('researcher_books',$array);
				if(!$q->result()){
					$this->debug->fatal('خطایی در افزودن به جدول رخ داده است');
				}
				$array2['rowid'] = $q->id();
			}
		}
		if($this->debug->x){
			$this->query->commit();
			$this->debug->true('با موفقیت انجام شد');
			$this->debug->msg($array2);
		}
		else
		{
			$this->debug->fatal('خطایی در ثبت داده ها رخ داده است. مقادیر وارد شده را با دقت وارد کنید');
		}
	}

	public function post_contractsedit(){
		$array = array();
		if(isset($_POST['title'])){
			$array['title'] = $this->post('title')->get();
		}
		if(isset($_POST['name'])){
			$array['name'] = $this->post('name')->get();
		}
		if(isset($_POST['tel'])){
			$array['tel'] = $this->post('tel')->preg("/^(\d{7,})$/")->error('شماره تلفت را به درستی وارد کنید')->get();
		}
		$array2 = $array;
		if($this->debug->x){
			foreach ($array2 as $key => $value) {
				$array[$key] = "'$value'";
			}
			if(isset($_POST['status']) && $_POST['status'] =='del' && isset($_POST['rowid']) && $rowid = $this->post('rowid')->preg('/^\d+$/')->get()){
				$q = $this->query->delete("researcher_contracts", "id = $rowid AND user_id=$_SESSION[u_id]");
				$q->result();

			}elseif(isset($_POST['rowid']) && $rowid = $this->post('rowid')->preg('/^\d+$/')->get()){
				$q = $this->query->update('researcher_contracts',$array, "id=$rowid AND user_id=$_SESSION[u_id]");
				if(!$q->result()){
					$this->debug->fatal('خطایی در ویرایش رخ داده است');
				}
			}else{
				$array['user_id'] = $_SESSION['u_id'];
				$q = $this->query->insert('researcher_contracts',$array);
				if(!$q->result()){
					$this->debug->fatal('خطایی در افزودن به جدول رخ داده است');
				}
				$array2['rowid'] = $q->id();
			}
		}
		if($this->debug->x){
			$this->query->commit();
			$this->debug->true('با موفقیت انجام شد');
			$this->debug->msg($array2);
		}
		else
		{
			$this->debug->fatal('خطایی در ثبت داده ها رخ داده است. مقادیر وارد شده را با دقت وارد کنید');
		}
	}

	public function post_seminarsedit(){
		$array = array();
		if(isset($_POST['title'])){
			$array['title'] = $this->post('title')->get();
		}
		if(isset($_POST['name'])){
			$array['name'] = $this->post('name')->get();
		}
		if(isset($_POST['date'])){
			//$array['date'] = $this->post('date')->preg("/^(\d{4}[\-\/]\d{1,2}[\-\/]\d{1,2})$/")->error('تاریخ را به درستی وارد کنید')->get();
			$array['date'] = $this->post('date')->get();
		}
		if(isset($_POST['type'])){
			$array['type'] = $this->post('type')->preg("/^(سخنرانی|پوستر)$/")->error('نوع را به درستی وارد کنید')->get();
		}
		$array2 = $array;
		if($this->debug->x){
			foreach ($array2 as $key => $value) {
				$array[$key] = "'$value'";
			}
			if(isset($_POST['status']) && $_POST['status'] =='del' && isset($_POST['rowid']) && $rowid = $this->post('rowid')->preg('/^\d+$/')->get()){
				$q = $this->query->delete("researcher_seminars", "id = $rowid AND user_id=$_SESSION[u_id]");
				$q->result();

			}elseif(isset($_POST['rowid']) && $rowid = $this->post('rowid')->preg('/^\d+$/')->get()){
				$q = $this->query->update('researcher_seminars',$array, "id=$rowid AND user_id=$_SESSION[u_id]");
				if(!$q->result()){
					$this->debug->fatal('خطایی در ویرایش رخ داده است');
				}
			}else{
				$array['user_id'] = $_SESSION['u_id'];
				$q = $this->query->insert('researcher_seminars',$array);
				if(!$q->result()){
					$this->debug->fatal('خطایی در افزودن به جدول رخ داده است');
				}
				$array2['rowid'] = $q->id();
			}
		}
		if($this->debug->x){
			$this->query->commit();
			$this->debug->true('با موفقیت انجام شد');
			$this->debug->msg($array2);
		}
		else
		{
			$this->debug->fatal('خطایی در ثبت داده ها رخ داده است. مقادیر وارد شده را با دقت وارد کنید');
		}
	}

	public function post_workshopsedit(){
		$array = array();
		if(isset($_POST['title'])){
			$array['title'] = $this->post('title')->get();
		}
		if(isset($_POST['name'])){
			$array['name'] = $this->post('name')->get();
		}
		if(isset($_POST['date'])){
			//$array['date'] = $this->post('date')->preg("/^(\d{4}[\-\/]\d{1,2}[\-\/]\d{1,2})$/")->error('تاریخ را به درستی وارد کنید')->get();
			$array['date'] = $this->post('date')->get();
		}
		if(isset($_POST['type'])){
			$array['type'] = $this->post('type')->preg("/^(دبیر|رئیس کارگاه|عضو کمیته علمی|عضو کمیته داوری|عضو کمیته اجرایی)$/")->error('نوع را به درستی وارد کنید')->get();
		}
		$array2 = $array;
		if($this->debug->x){
			foreach ($array2 as $key => $value) {
				$array[$key] = "'$value'";
			}
			if(isset($_POST['status']) && $_POST['status'] =='del' && isset($_POST['rowid']) && $rowid = $this->post('rowid')->preg('/^\d+$/')->get()){
				$q = $this->query->delete("researcher_workshops", "id = $rowid AND user_id=$_SESSION[u_id]");
				$q->result();

			}elseif(isset($_POST['rowid']) && $rowid = $this->post('rowid')->preg('/^\d+$/')->get()){
				$q = $this->query->update('researcher_workshops',$array, "id=$rowid AND user_id=$_SESSION[u_id]");
				if(!$q->result()){
					$this->debug->fatal('خطایی در ویرایش رخ داده است');
				}
			}else{
				$array['user_id'] = $_SESSION['u_id'];
				$q = $this->query->insert('researcher_workshops',$array);
				if(!$q->result()){
					$this->debug->fatal('خطایی در افزودن به جدول رخ داده است');
				}
				$array2['rowid'] = $q->id();
			}
		}
		if($this->debug->x){
			$this->query->commit();
			$this->debug->true('با موفقیت انجام شد');
			$this->debug->msg($array2);
		}
		else
		{
			$this->debug->fatal('خطایی در ثبت داده ها رخ داده است. مقادیر وارد شده را با دقت وارد کنید');
		}
	}

	public function post_uploadedit()
	{
		$afile 			= $this->file('fileupd')->maxsize(10)->gtype('image')->error('فایل صحیح را بارگذاری کنید')->get();
		$title 			= $this->post('title')->preg("/^(کارت ملی|شناسنامه|مدرک تحصیلی|گواهی عضو هیئت علمی)$/")->get();
		$description 	= $this->post('description')->get();
		$user_id 		= $_SESSION['u_id'];

		if($this->debug->x)
		{
			if($afile)
			{
				$files               = new files_src($this->query);
				$file                = $afile->all();
				$file['title']       = "'$title'";
				$file['model']       = "'profile'";
				$file['description'] = "'$description'";
				$move                = $files->move($file);

				if(!$move)
				{
					$this->debug->fatal("انتقال ناموفق فایل");
				}
			}
		}

		if($this->debug->x)
		{
			$array['mytitle'] = $title;
			$array['mydescription'] = $description;
			$this->query->commit();
			$this->debug->true('با موفقیت انجام شد');
			$this->debug->msg($array);
		}
	}
}
?>