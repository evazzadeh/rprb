<?PHP
class sql_lib{  
	static $connect = false;
	public $error = false;
	public $transaction = false;

	public function __toString(){
		return $this->KEY;
	}
	public function __construct($p1= false, $p2 = false){
		$this->host = sql_host;
		$this->user = sql_user;
		$this->pass = sql_password;
		$this->db = sql_database;
		if(is_object($p1)){
			$this->error = $p1;
		}
		if(!self::$connect) $this->connect();
		if($p1 === true || $p2 === true){
			$this->transaction();
			$this->transaction = true;
		}
	}

	public function connect(){
		if(!$c = mysql_connect($this->host, $this->user, $this->pass)){
			$this->errors(3901, "connection error");
		}elseif(!mysql_select_db($this->db)){
			$this->errors(3902, 'database error');
		}else{
			mysql_set_charset('utf8', $c);
			self::$connect = $c;
		}
	}
	public function errors($num = 3901, $err = 'connection error'){
		if(isset($this->error)){
			$this->error->fatal($err);
		}else{
			perror_lib::_403($num);
		}
	}

	public function transaction() {
		$q = $this->goc('START TRANSACTION');
		$q->u();
	}

	public function commit() {
		$q = $this->goc('COMMIT');
		$q->u();
	}

	public function rollback() {
		$q = $this->goc('ROLLBACK');
		$q->u();
	}

	public function select($t,$f = "*", $w = false, $jf = false){
		if($w && is_array($w)){
			$sw = 'WHERE ';
			foreach ($w as $key => $value) {
				$sw .= "$value";
				if($key != count($w) -1){
					$sw .=" AND ";
				}
			}
			$w = $sw;
		}elseif($w){
			$w = "WHERE ".$w;
		}
		$join='';
		$tables=explode(",", $t);
		$joins=explode(",", $jf);
		if (count($tables)>1){
			$t=$tables[0];
			for($i=1; $i < count($tables); $i++)
				$join.="INNER JOIN ".$tables[$i]. " ON ".$joins[$i-1]." ";
		}
		//var_dump("SELECT $f FROM $t $join $w");							// ba in mishe debug kard !! peydash kardam ^_^
		return $this->goc("SELECT $f FROM $t $join $w");
	}

	public function insert($t, $p){
		if(is_array($p)){
			$sf = join(array_keys($p), ',');
			$sv = join($p,',');	
			$sp = "($sf) VALUES ($sv)";

		}else{
			if(preg_match("/=/", $sp)){
				$sp = "SET ".$p;
			}else{
				$sp = "VALUES ($p)";
			}
		}
		return $this->goc("INSERT INTO $t $sp");
	}

	public function update($t, $p, $w){
		// *************************************************** add by javad
		if($p && is_array($p))
		{
			$fields = array_keys($p);
			$values = array_values($p);
			$update = array();
			foreach ($p as $key => $value) {
				$update[] = "$key=$value";
			}
			$p = join(', ',$update);

		}
		// ****************************************************************

		if($w && is_array($w)){
			$sw = 'WHERE ';
			foreach ($w as $key => $value) {
				$sw .= "$value";
				if($key != count($w) -1){
					$sw .=" AND ";
				}
			}
			$w = $sw;
		}elseif($w){
			$w = "WHERE ".$w;
		}
	//var_dump("UPDATE $t SET $p $w");									// ba in mishe debug kard !! peydash kardam ^_^
		return $this->goc("UPDATE $t SET $p $w");
	}

	public function delete($t, $w){
		if($w && is_array($w)){
			$sw = 'WHERE ';
			foreach ($w as $key => $value) {
				$sw .= "$value";
				if($key != count($w) -1){
					$sw .=" AND ";
				}
			}
			$w = $sw;
		}elseif($w){
			$w = "WHERE ".$w;
		}
		return $this->goc("DELETE FROM $t $w");
	}

	public function goc($q){
		$q = new sql_q($q, $this->error, $this->transaction);
		//var_dump($q);													// ba in mishe debug kard !! peydash kardam ^_^
		return $q;
	}
	public function end($e = false){
		if($this->transaction){
			if($this->error->error != 2){
				$this->COMMIT();
			}else{
				$this->ROLLBACK();
			}
		}
		if($e && isset($this->error)){
			return $this->error->output();
		}else{
			return true;
		}
	}
}
/**

**/
class sql_q{
	public $sq = '';
	public $slimit = false;
	public $sorder = false;
	public $sgroup = false;


	public function __construct($q, $p1, $p2){
		if(is_object($p1)){
			$this->error = $p1;
		}
		if($p1 === true || $p2 === true){
			$this->transaction = true;
		}
		$this->sq = $q;
		return $this;

	}
	public function u(){
		if(isset($this->tq)) return false;
		$sq = $this->sq;
		$sq .= ($this->sgroup)? ' '.$this->sgroup : '';
		$sq .= ($this->sorder)? ' '.$this->sorder : '';
		$sq .= ($this->slimit)? ' '.$this->slimit : '';
		$this->sq = $sq;
		if($q = mysql_query($sq)){
			$this->tq = $q;
			return $this;
		}else{
			var_dump($sq);
			var_dump(mysql_error());
			$this->errors(3903, mysql_error());
			return false;
		} 
	}


	public function result(){
		$this->u();
		return $this->tq;
	}
	
	public function id(){
		$this->u();
		return mysql_insert_id();
	}

	public function a($index = false){
		$this->u();
		if($index){
			$xn = mysql_fetch_assoc($this->tq);
			return $xn[$index];
		}else{
			return mysql_fetch_assoc($this->tq);
		}
	}

	public function assoc($index = false){
		return $this->a($index);
	}

	public function num(){
		$this->u();
		return mysql_num_rows($this->tq);
	}

	public function count(){
		return $this->num();
	}

	public function all(){
		$a = array();
		while ($r = $this->a()) {
			$a[] = $r;
		}
		return $a;
	}
	public function limit($s, $t, $pn= false){
		if ($pn){

			$s=intval($s);
			if ($s){
				$s--;
				$s*=DEFAULT_COUNT;
				$t=!strlen($t) ? DEFAULT_COUNT : $t;
			}else
			$t=1;
		}

		$this->slimit = "LIMIT $s,$t";
		
		return $this;
	}

	public function group($f){
		$this->sgroup = "GROUP BY $f";
		return $this;
	}

	public function order($t, $f){
		$this->sorder = "ORDER BY $t $f";
		return $this;
	}


	public function p($p = 10){
		$cb = $this->sq;
		$this->sq = preg_replace("#SELECT (.*) FROM#", "SELECT COUNT($1) FROM", $this->sq);
		$this->u();
		$this->sq = $cb;
		$p = (preg_match("#^\d+$#", $p))? $p : 10; 
		$n = $this->n();
		$url = url_lib::s();
		$page = (isset($url['page']) && preg_match("#^\d+$#", $url['page']))? $url['page'] : 1;
		$slimit = ($page - 1) * $p;
		$elimit = $p;
		$sql = new sql_lib($this->error, $this->transaction);
		$q = $sql->goc($this->sq);
		$q->limit($slimit, $elimit);
		$q->ptotoal = $n;
		$q->tpage = (int) $page;
		return $q->u();
	}
	public function etype($type = "fatal"){
		$this->et = $type;
	}
	public function errors($num = 3901, $err = 'connection error'){
		$e = (isset($this->et))? $this->et : 'fatal';
		if(isset($this->error)){
			$this->error->$e($err);
		}else{
			perror_lib::_403($num);
		}
	}

}
?>