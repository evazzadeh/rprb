<?php
class group_create_view extends main_view
{
	public function _construct()
	{
		$_input = $this->form('hidden')->name('_post')->value('groupcreate');

		// ********************************************************************************** Start Form
		$_title 	= $this->form('text')->name('title')->label("عنوان")->id("title")->pl("عنوان گروه");
		$_content 	= $this->form('textarea')->name('content')->label("توضیح")->id("content")->pl("توضیحات در مورد هدف تشکیل گروه و ویژگی های آن")->attr('class','input-xxlarge');

		// in this code, we create a loop for fill select with needed value
		$_activity	= $this->form('select')->name('activity')->label('زمینه فعالیت')->id("activity");
		$datatable  = db_src::getall ( 'activities');
		foreach ($datatable as $datarow)
		{
			$_activity->child()->label($datarow['activity_title'])->value($datarow['activity_id']);
		}


		// ********************************************************************************** End Form
		$_s = $this->form('submit')->value('ایجاد گروه جدید');

		$this->data->form[] = $_input->compile();
		$this->data->form[] = $_title->compile();
		$this->data->form[] = $_content->compile();
		$this->data->form[] = $_activity->compile();
		
		$this->data->form[] = $_s->compile();
	}
}
?>