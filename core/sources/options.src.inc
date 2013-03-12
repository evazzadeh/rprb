<?PHP
class options_src
{
	// ************************************************************** Get Data from option table - support default value
	static function get($tmp_option_cat, $tmp_option_name, $default=null)
	{
		$query = new sql_lib(false, false);
		$datarow = $query->select("m_options","*","option_status='on' and option_cat='$tmp_option_cat' and option_name = '$tmp_option_name'")->assoc('option_value');
		if ($datarow)	return $datarow;
		else			return $default;
	}


	static function set($tmp_option_cat, $tmp_option_name, $tmp_option_value, $tmp_option_status='on')
	{
		//$query = new sql_lib(false, false);
		//$tmp = $query->insert("m_options","$tmp_option_cat, $tmp_option_name, $tmp_option_value, $tmp_option_name, $tmp_option_status");
			//array("name" => $x, "h" => $y);	
			// in insertesh chejoriye?
		//return $tmp;
	}
}

class users_src
{
	// ************************************************************** Get Data from custom table with userid
	static function get($tmp_user_id,$tmp_table)
	{
		$query = new sql_lib(false, false);
		$q = $query->select("$tmp_table","*","user_id=$tmp_user_id");

		$datatable = array();
		while($row = $q->assoc()) {$datatable[] = $row;}
		return $datatable;
	}

	static function get_activity($tmp_activity_id)
	{
		$query = new sql_lib(false, false);
		$datarow = $query->select("activities","*","activity_id=$tmp_activity_id")->assoc();

		if ($datarow)	return $datarow;
		else			return null;
	}

	static function set($tmp_user_id,$tmp_table)
	{
		$query = new sql_lib(false, false);
		$q = $query->select("$tmp_table","*","user_id=$tmp_user_id");

		$datatable = array();
		while($row = $q->assoc()) {$datatable[] = $row;}
		return $datatable;
	}
}

class activities_src
{
	// ************************************************************** Get Data from Activities table with Array
	//																	Chert neveshtam, fek konam join konam behtare
	static function get($tmp_activities)
	{
		/*
		$query = new sql_lib(false, false);
		$q = $query->select("activities","*");

		$datatable = array();

		while($row = $q->assoc())
		{
			if ($row['id'] == )
			$datatable[] = $row;
		}


		if (!is_array($tmp_activities))
		{
			foreach ($tmp_activities as $row)
			{
				$datatable["id"][]    = $row["id"];
				$datatable["title"][] = $row["title"];
			}
		}
		var_dump($datatable);
		return $datatable;
		*/
	}
}

class notifications_src
{
	// ************************************************************** Get Data from Notifications table: seperate by sender or reciver
	static function get($tmp_id, $tmp_field='user_id',$tmp_limit = 10)
	{
		$query = new sql_lib(false, false);
		$datarow = $query->select("notifications","*","$tmp_field = $tmp_id");

		$datatable = array();
		while($row = $datarow->assoc()) {$datatable[] = $row;}
		return $datatable;
	}
}


class db_src
{
	static function get($tmp_table, $tmp_fieldname, $tmp_research_id )
	{
		$query = new sql_lib(false, false);
		return $query->select("$tmp_table","*","$tmp_fieldname=$tmp_research_id")->all();
	}

	static function getall($tmp_table )
	{
		$query = new sql_lib(false, false);
		return $query->select("$tmp_table","*")->all();
	}
}

?>