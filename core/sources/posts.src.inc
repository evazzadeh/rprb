<?PHP
class posts_src
{
	static function get($tmp_type, $tmp_slug, $default =null)
	{
		$query   =new sql_lib(false, false);
		$datarow =$query->select("m_posts","*","type='$tmp_type' and slug = '$tmp_slug'")->assoc();
		
		if ($datarow) return $datarow;
		else return $default;
	}


	static function set($tmp_option_cat, $tmp_option_name, $tmp_option_value, $tmp_option_status='on')
	{

		$query = new sql_lib(false, false);
		$tmp = $query->insert("options","$tmp_option_cat, $tmp_option_name, $tmp_option_value, $tmp_option_name, $tmp_option_status");
			//array("name" => $x, "h" => $y);
		
			// in insertesh chejoriye?
		return $tmp;
	}
}

class terms_src
{
	static function get($tmp_type, $tmp_slug, $default=null)
	{
		$query = new sql_lib(false, false);
		$datarow = $query->select("m_posts","*","type='$tmp_type' and slug = '$tmp_slug'")->assoc();
		
		if ($datarow) 	return $datarow;
		else			return $default;
	}


	static function set($tmp_option_cat, $tmp_option_name, $tmp_option_value, $tmp_option_status='on')
	{

		$query = new sql_lib(false, false);
		$tmp = $query->insert("options","$tmp_option_cat, $tmp_option_name, $tmp_option_value, $tmp_option_name, $tmp_option_status");
			//array("name" => $x, "h" => $y);
		
			// in insertesh chejoriye?
		return $tmp;
	}
}
?>