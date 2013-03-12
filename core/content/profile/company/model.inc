<?php
class profile_company_model extends main_model
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
			$website 	= $this->post('website')->preg("/^(|(https?:\/\/)?([a-z0-9][a-z0-9\-]*\.)[a-z0-9][a-z0-9\-]*)$/")->get();
			$array['website'] = "'$website'";
		}

		if(isset($_POST['code'])){
			$code 	= $this->post('code')->preg("/^(\d{3,})$/")->get();
			$array2['code'] = "'$code'";
		}

		if(isset($_POST['date'])){
			$date = $this->post('date')->preg("/^(\d{4}[\/\-]\d{1,2}[\/\-]\d{1,2}$/")->get();
				$array2['date'] = "'$date'";
			}

			if(isset($_POST['country'])){
				$country 	= $this->post('country')->preg("/^(.{3,})$/")->get();
				$array2['country'] = "'$country'";
			}

			if(isset($_POST['address'])){
				$address 	= $this->post('address')->preg("/^(.{3,})$/")->get();
				$array2['address'] = "'$address'";
			}

			if(isset($_POST['type'])){
				$type 	= $this->post('type')->preg("/^(.{3,})$/")->get();
				$array2['type'] = "'$type'";
			}

			if(isset($_POST['isic'])){
				$isic 	= $this->post('isic')->preg("/^(\d{3,})$/")->get();
				$array2['isic'] = "'$isic'";
			}

			if(isset($_POST['capacity'])){
				$capacity 	= $this->post('capacity')->preg("/^(.{3,})$/")->get();
				$array2['capacity'] = "'$capacity'";
			}

			if(isset($_POST['personnel'])){
				$personnel 	= $this->post('personnel')->preg("/^(\d{1,})$/")->get();
				$array2['personnel'] = "'$personnel'";
			}

			if(isset($_POST['rd_name'])){
				$rd_name 	= $this->post('rd_name')->preg("/^(.{3,})$/")->get();
				$array2['rd_name'] = "'$rd_name'";
			}

			if(isset($_POST['rd_tel'])){
				$rd_tel 	= $this->post('rd_tel')->preg("/^(.{3,})$/")->get();
				$array2['rd_tel'] = "'$rd_tel'";
			}

			if(isset($_POST['priority'])){
				$priority 	= $this->post('priority')->preg("/^(الف|ب|غیره)$/")->get();
				$array2['priority'] = "'$priority'";
			}

			if(isset($_POST['electric'])){
				$electric 	= $this->post('electric')->preg("/^(.*)$/")->get();
				$array2['electric'] = "'$electric'";
			}

			if(isset($_POST['water'])){
				$water 	= $this->post('water')->preg("/^(.*)$/")->get();
				$array2['water'] = "'$water'";
			}

			if(isset($_POST['energy'])){
				$energy 	= $this->post('energy')->preg("/^(.*)$/")->get();
				$array2['energy'] = "'$energy'";
			}

			if(isset($_POST['energy_type'])){
				$energy_type 	= $this->post('energy_type')->preg("/^(گازوئیل|گاز|نفت و گاز)$/")->get();
				$array2['energy_type'] = "'$energy_type'";
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
					$q = $this->query->update('companies', $array2, "user_id=$_SESSION[u_id]");
				}
				if(isset($q)){
					if(!$q->result()){
						$this->debug->fatal('خطای داخلی');
					}else{
						$this->query->commit();
					}
				}else{
					$this->debug->fatal('مقدار ناصحیح');
				}
			}
		}




		public function post_uploadedit()
		{
			$afile 			= $this->file('fileupd')->maxsize(10)->gtype('image')->error('فایل صحیح را بارگذاری کنید')->get();
			$title 			= $this->post('title')->preg("/^(کارت ملی|شناسنامه|مدرک تحصیلی|گواهی عضو هیئت علمی)$/")->get();
			$description 	= $this->post('description')->get();
			$user_id 		= $_SESSION['u_id'];
			$fileAddr 		= false;

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