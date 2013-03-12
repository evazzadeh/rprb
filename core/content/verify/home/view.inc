<?php
class verify_home_view extends main_view
{
	public function _construct()
	{
		$url         = url_lib::s('/');
		$tmp_code    = $url[0];

		$this->data->isused= $this->query->select('m_verifications', '*', "code ='$tmp_code' and verify='yes'")->count();


		$_input = $this->form('hidden')->name('_post')->value('forgottenaccept');
		$_s = $this->form('submit')->value('رمز جدید را ارسال کن');

		$this->data->form[] = $_input->compile();
		$this->data->form[] = $_s->compile();
	}
}
?>