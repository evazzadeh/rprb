<?php
class admin_term_view extends main_view
{
	public function _construct()
	{
		$this->data->show_page_title = false;
		$this->data->show_footer 	 = false;

		$url = url_lib::s('/');
		if($url[0]=='tag')
		{
			$this->data->type = 'tag';
			$this->data->m_terms = $this->query->select("m_terms","*","type='tag'")->all();
		}
		elseif($url[0]=='category')
		{
			$this->data->type = 'category';
			$this->data->m_terms = $this->query->select("m_terms","*","type='cat'")->all();
		}
	}
}
?>