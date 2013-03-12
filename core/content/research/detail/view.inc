<?php
class research_detail_view extends main_view
{
	public function _construct()
	{
		$url = url_lib::s('/');
		if(isset($url[0]))						$tmp_research_id = $url[0];
		if(isset($url[1]))						$tmp_proposal_id = $url[1];

		$this->data->contract_text       		= options_src::get('research','contract_text','قرارداد مشخص نیست!');
		//$this->data->d_research 				= db_src::get ( 'researches', 'research_id', $tmp_research_id );
		$this->data->d_research					= $this->query->select('researches, activities', '*', "researches.research_id=$tmp_research_id", "activities.activity_id = researches.activity_id")->all();


		if(isset($this->data->u_login) and $this->data->u_login )
		{
			$tmp_researcher_id 						= $_SESSION['u_id'];
			$tmp_researcher_name 					= 'شخص '. $_SESSION['u_firstname'] . ' ' . $_SESSION['u_lastname'];

			

			if($this->data->d_research[0]['status'] == 'declared')
			{
				$this->data->proposal_accept = false;
				if(isset($tmp_proposal_id))
				{
				// update proposal status in declare status, this mean if user accept one 
					$this->query->update("research_proposal","status='accept'", "research_id=$tmp_research_id and proposal_id=$tmp_proposal_id")->result();
					$this->query->commit();
					$this->data->proposal_accept = true;
				}

		// **************************************************************************************************************** Form 1
				$f1_input    = $this->form('hidden')->name('_post')->value('proposaladd');
				$f1_s        = $this->form('submit')->value('ارسال پروپوزال');
		// ********************************************************************************** Start Form
				$f1_content  = $this->form('textarea')->name('content')->label("توضیح")->id("content")->pl("توضیحات مورد نیاز برای پژوهش")->attr('class','input-xxlarge');
				$f1_price    = $this->form('text')->name('price')->label("قیمت (به تومان)")->id("price")->pl("قیمت اجرای طرح");
				$f1_day      = $this->form('text')->name('day')->label("زمان مورد نیاز")->id("day")->pl("به روز وارد کنید");
				$f1_file     = $this->form('file')->name('file')->label("فایل پروپوزال")->id("file");

		// in this code, we create a loop for fill select with needed value
				$f1_type     = $this->form('select')->name('type')->label('ارسال طرح از طرف')->id("type");
				$datatable   = db_src::get( 'groups', 'admin_id', "$tmp_researcher_id");

				$f1_type->child()->label($tmp_researcher_name)->value('me')->attr('selected','selected');
				foreach ($datatable as $datarow)
				{
					$f1_type->child()->label($datarow['title'])->value($datarow['group_id']);
				}
		// ********************************************************************************** End Form
				$this->data->form1[] = $f1_input->compile();
				$this->data->form1[] = $f1_content->compile();
				$this->data->form1[] = $f1_price->compile();
				$this->data->form1[] = $f1_day->compile();
				$this->data->form1[] = $f1_file->compile();
				$this->data->form1[] = $f1_type->compile();
				$this->data->form1[] = $f1_s->compile();
			}

			elseif($this->data->d_research[0]['status'] == 'contract')
			{
		// **************************************************************************************************************** Form 2
				$f2_input    = $this->form('hidden')->name('_post')->value('contractaccept');
				$f2_s        = $this->form('submit')->value('امضای قرارداد');

		// ********************************************************************************** Start Form
				$f2_agreement= $this->form('radio')->name('agreement')->label('قبول می کنید؟');
				$f2_agreement->child()->label('قرارداد را به طور کامل خواندم و موافقم')->id('agree')->value('agree');
				$f2_agreement->child()->label('مخالفم')->id('disagree')->value('disagree');
		// ********************************************************************************** End Form
				$this->data->form2[] = $f2_agreement->compile();
				$this->data->form2[] = $f2_input->compile();
				$this->data->form2[] = $f2_s->compile();
			}

			elseif($this->data->d_research[0]['status'] == 'study')
			{
		// **************************************************************************************************************** Form 2
				$f3_input    = $this->form('hidden')->name('_post')->value('reseaechsend');
				$f3_s        = $this->form('submit')->value('امضای قرارداد');

		// ********************************************************************************** Start Form
				$f3_file     = $this->form('file')->name('file')->label("طرح نهایی")->id("file");
				$f3_agreement= $this->form('radio')->name('agreement')->label('آیا طرح به اتمام رسیده است؟');
				$f3_agreement->child()->label('بله، آماده ارسال طرح نهایی هستم')->id('agree')->value('agree');
				$f3_agreement->child()->label('خیر')->id('disagree')->value('disagree');
		// ********************************************************************************** End Form
				$this->data->form3[] = $f3_agreement->compile();
				$this->data->form3[] = $f3_file->compile();
				$this->data->form3[] = $f3_input->compile();
				$this->data->form3[] = $f3_s->compile();
			}

			$this->data->d_research 				= db_src::get ( 'researches', 'research_id', $tmp_research_id );
			$this->data->d_proposal_list_group		= $this->query->select('research_proposal,groups', '*, research_proposal.content as r_content', "research_id=$tmp_research_id and research_proposal.group_id IS NOT NULL", "groups.group_id = research_proposal.group_id")->all();
			if($_SESSION['u_type'] == 'company')
			{
				//$this->data->d_proposal_list			= db_src::get ( 'research_proposal', 'research_id', $tmp_research_id );


				$this->data->d_proposal_list_researcher	= $this->query->select('research_proposal,m_users', '*, research_proposal.content as r_content, research_proposal.status as r_status', "research_id=$tmp_research_id and research_proposal.group_id IS NULL", "m_users.user_id = research_proposal.sender_id")->all();
			}

		}

	}
}
?>