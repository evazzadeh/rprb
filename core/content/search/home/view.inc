<?php
class search_home_view extends main_view{
	public $onq;
	public $countResult = 10;
	public $url;
	public function _construct(){
		$s = url_lib::s();
		if(isset($s['page']) && preg_match("/^\d+$/", $s['page']) && $s['page'] >= 1){
			$page = $s['page'];
		}else{
			$page = 1;
		}

/*
		if(count($s) < 1){
			$this->data->page_title = 'جوینده یابنده است...';
			$this->data->search_type = 'researcher';
		}else{
			list($search) = array_keys($s);
			$q = urldecode($s[$search]);
			$q = safe(fignore($q));
			$this->url = "$search=$q";
			$title = array(
				'research' => 'پژوهش ها',
				'group' => 'گروه ها',
				'researcher' => 'پژوهشگران',
				);
			$this->data->page_title = "جستجوی $title[$search]: $q";
			$this->data->search_type = $search;
			if($s[$search] == '') return;
			$this->$search($q, $page);
			
		}
*/

		if(!isset($s['q'])){
			$this->data->page_title = 'جوینده یابنده است...';
			$this->data->search_type = 'researcher';
		}else{
			$search = $s['q'];
			$q = urldecode($s['q']);
			$q = safe(fignore($q));
			$this->url = "q=$q";
			$this->researcher($q, $page);

		}
	}

	public function Gq($q, $page){
		$sq = $q->sq;
		$count = $q->num();
		$p = ceil($count / $this->countResult);
		$limit = ($page -1) * $this->countResult;
		$s = $this->query->goc($sq)->limit($limit, $this->countResult);
		$url = $this->url;
		$tpage = $page;
		return array($s, array("all"=>$p, "url"=>$url, "tpage"=>$page));
	}

	public function search($q, $page){
		$this->data->searchx = $q;
		$sq = $this->query->select("researches",'*', "content LIKE '%$q%' OR title LIKE '%$q%'");
		list($s, $page) = $this->Gq($sq, $page);
		$analis = $s->all();
		$skey = array('title', 'content');
		foreach ($analis as $key => $value) {
			foreach ($skey as $k => $v) {
				$msearch = $analis[$key][$v];
				if(preg_match("/$q/", $msearch)){
					$this->onq = $analis[$key];
					$sg = "/$q/";
					$msearch = preg_replace_callback($sg,array($this, 'rep_'.$v),$msearch);
					$analis[$key][$v] = $msearch;
				}
			}
		}
		$this->data->page = $page;
		$this->data->search = $analis;
	}
	public function group($q, $page){
		
	}
	public function researcher($q, $page){
		$this->data->searchx = $q;
		$sq = $this->query->goc("SELECT distinct
			m_users.*, researchers.*
			FROM m_users
			INNER JOIN  researchers ON 
			researchers.user_id = m_users.user_id
			INNER JOIN  researches ON 
			researches.sender_id = researchers.user_id
			WHERE
			researchers.education LIKE '%$q%'
			OR researchers.field LIKE '%$q%'
			OR researchers.adjusted LIKE '%$q%'
			Or m_users.lastname LIKE '%$q%'
			Or m_users.firstname LIKE '%$q%'
			");
		list($s, $page) = $this->Gq($sq, $page);
		$analis = $s->all();
		$skey = array('education', 'field', 'adjusted');
		foreach ($analis as $key => $value) {
			foreach ($skey as $k => $v) {
				$msearch = $analis[$key][$v];
				if(preg_match("/$q/", $msearch)){
					$this->onq = $analis[$key];
					$sg = "/$q/";
					$msearch = preg_replace_callback($sg,array($this, 'rep_'.$v), $msearch);
					$analis[$key][$v] = $msearch;
				}
			}
		}
		$this->data->page = $page;
		$this->data->search = $analis;
	}
	public function rep_education($n){
		return $this->replace($n);
	}
	public function rep_field($n){
		return $this->replace($n);
	}
	public function rep_adjusted($n){
		return $this->replace($n);
	}
	public function rep_content($n){
		return $this->replace($n);
	}
	public function rep_title($n){
		return $this->replace($n);
	}
	public function replace($n){
		$class = debug_backtrace(true);
		$fun = str_replace('rep_','',$class[1]['function']);
		switch ($fun) {
			case 'education':
			$addr = 'profile/'.$this->onq['user_id'];
			break;
			case 'field':
			$addr = 'profile/'.$this->onq['user_id'];
			break;
			case 'adjusted':
			$addr = 'profile/'.$this->onq['user_id'];
			break;
			case 'content':
			$addr = 'research/'.$this->onq['research_id'];
			break;
			case 'title':
			$addr = 'research/'.$this->onq['research_id'];
			break;
		}
		/*if(!preg_match("/^\s/", $n[0])){
			if(preg_match("/^[ابپتثجچحخدذرزژسشصضطظعغفقکگلمنوهیآ]/", $n[0])){
				$n[0] = '&zwj;'.$n[0];
			}
		}
		if(!preg_match("/\s$/", $n[0])){
			if(preg_match("/[ابپتثجچحخدذرزژسشصضطظعغفقکگلمنوهیآ]$/", $n[0])){
				$n[0] = $n[0].'&zwj;';
			}
		}*/
		/*return "<a href='$addr' target='_blank'>$n[0]</a>";*/
		return "<a>$n[0]</a>";
	}
}
?>