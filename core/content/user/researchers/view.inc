<?php
class user_researchers_view extends main_view
{
	public function _construct()
	{

		$this->data->lastresearcher	= $this->query->select("m_users", "*", "status='active' and type='researcher'")->order("user_id","desc")->all();

		//$this->data->lastcompany	= $this->query->select("m_users", "*", "status='active' and type='company'")->limit(0,5)->order("user_id","desc")->all();
	}
}
?>