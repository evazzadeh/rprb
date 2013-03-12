<?php
class admin_termedit_view extends main_view
{
	public function _construct()
	{
		$this->data->show_page_title = false;
		$this->data->show_footer 	 = false;

		$url = url_lib::s('/');
		if($url[0]=='tag')
		{
			$this->data->type = 'tag';
			$title = 'نشانک';
			$this->data->m_terms = $this->query->select("m_terms","*","type='tag'")->all();
		}
		elseif($url[0]=='category')
		{
			$this->data->type = 'category';
			$title = 'دسته';
			$this->data->m_terms = $this->query->select("m_terms","*","type='cat'")->all();
		}
		if($url[1] == 'add'){
			$mode = 'add';
			$title = "ثبت $title";
		}else{
			$mode = 'edit';
			$g = $this->query->select('m_terms',"*", "term_id=$url[2]")->assoc();
			$title = "ویرایش $title";
		}
		$_s = $this->form('submit')->value($title);
		$_input = $this->form('hidden')->name('_post')->value($mode);

		$_name = $this->form('text')->label('عنوان')->id('name')->name('name')->pl('عنوان را وارد کنید');
		$_slug = $this->form('text')->label('نامک')->id('slug')->name('slug')->pl('نامک');
		$_desc = $this->form('text')->label('توضیح')->id('desc')->name('desc')->pl('توضیحات مختصر');

		$this->data->form[] = $_input->compile();
		if(isset($g)){
			$this->data->form[] = $this->form('hidden')->name('term_id')->value($g['term_id'])->compile();
			$_name->value($g['name']);
			$_slug->value($g['slug']);
			$_desc->value($g['desc']);
		}
		$this->data->form[] = $_name->compile();
		$this->data->form[] = $_slug->compile();
		$this->data->form[] = $_desc->compile();
		$this->data->form[] = $_s->compile();
		
	}
}
?>