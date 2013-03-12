<?php
class admin_postedit_view extends main_view
{
	public function _construct()
	{
		$this->data->show_page_title = false;
		$this->data->show_footer 	 = false;

		$url = url_lib::s('/');
		if($url[0]=='news')
		{
			$this->data->type = 'post';
			$this->data->m_posts = $this->query->select("m_posts","*","type='post'")->all();
		}
		elseif($url[0]=='page')
		{
			$this->data->type = 'page';
			$this->data->m_posts = $this->query->select("m_posts","*","type='page'")->all();
		}

		$title;
		if($url[1]=='add')
		{
			$this->data->mode = 'add';
			$title = 'ثبت';
		}
		elseif($url[1]=='edit')
		{
			$this->data->mode = 'edit';
			$title = 'ویرایش';
		}
		elseif($url[1]=='delete')
		{
			$this->data->mode = 'delete';
			$title = 'حذف';
		}

		$_input = $this->form('hidden')->name('_post')->value($this->data->mode);
		$_s = $this->form('submit')->value($title);

		// ********************************************************************************** Start Form
		if($this->data->mode == 'edit'){
			$id = (preg_match("/^\d+$/", $url[2]))? $url[2] : false;
			if(!$id){
				e_lib::_404(12);
			}
			$gn = $this->query->select("m_posts, m_term_usage", "m_posts.*, m_term_usage.*", "m_posts.post_id=$id" ,"m_posts.post_id = m_term_usage.post_id");
			if(!$gn->num()){
				e_lib::_404(13);	
			}
			$_edit = $gn->assoc();
			$_postid = $this->form('hidden')->name('post_id')->value($id);
			$this->data->form[] = $_postid->compile();
		}
		$_title 	= $this->form('text')->name('title')->label("عنوان")->id("firstname")->pl("عنوان را وارد کنید");
		$_content 	= $this->form('textarea')->name('content')->label("توضیح")->id("contentframe")->pl("متن مورد نظر را اینجا وارد کنید")->attr('class','input-xxlarge');;
		$_slug 		= $this->form('text')->name('slug')->label("نامک")->id("lastname")->pl("نامک")->attr('class','en');

		// in this code, we create a loop for fill select with needed value
		$_cat		= $this->form('select')->name('cat')->label('دسته')->id("cat");
		$datatable  = db_src::get('m_terms',"type","'cat'");

		foreach ($datatable as $datarow)
		{
			if(isset($_edit) && $datarow['term_id'] == $_edit['term_id']){
				$_cat->child()->label($datarow['name'])->value($datarow['term_id'])->attr("selected","selected");
			}else{
				$_cat->child()->label($datarow['name'])->value($datarow['term_id']);
			}
		}

		$_status	= $this->form('select')->name('status')->label('وضعیت')->id("status");
		if(isset($_edit)){
			if($_edit['status'] == 'publish'){
				$_status->child()->label('انتشار')->value('publish')->attr('selected','selected');
			}else{
				$_status->child()->label('انتشار')->value('publish');
			}
		}else{
			$_status->child()->label('انتشار')->value('publish')->attr('selected','selected');
		}
		if(isset($_edit) && $_edit['status']=='draft'){
			$_status	->child()->label('پیش نویس')->value('draft')->attr('selected','selected');;
		}else{
			$_status	->child()->label('پیش نویس')->value('draft');
		}
		if(isset($_edit)){
			$_title->value($_edit['title']);
			$_content->value(html_entity_decode($_edit['content'], ENT_QUOTES | ENT_IGNORE, "UTF-8"));
			$_slug->value($_edit['slug']);
		}
		// ********************************************************************************** End Form
		$this->data->form[] = $_input->compile();
		$this->data->form[] = $_title->compile();
		$this->data->form[] = $_content->compile();
		$this->data->form[] = $_slug->compile();
		$this->data->form[] = $_cat->compile();
		$this->data->form[] = $_status->compile();
		$this->data->form[] = $_s->compile();

	}
}
?>