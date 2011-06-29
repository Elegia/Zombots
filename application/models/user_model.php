<?php

class User_model extends CI_Model {

	var $user_id = '';
	var $username = '';
	var $password = '';
	var $email = '';
	var $join_date = '';
	var $gold = '';
	
	function __construct() {
	
		parent::__construct();
	}
	
	function validateUser($username, $password) {
	
		$query = "SELECT * FROM user WHERE username = ? AND password = ?";
		$result = $this->db->query($query, array($username, $password));

		if ($result->num_rows() > 0) {
			
			$row = $result->row();
			$user = array(
				'user_id' => $row->user_id,
				'username' => $row->username,
				'email' => $row->email,
				'join_date' => $row->join_date
				'gold' => $row->gold
			);
		
			return $user;
			
		} else {
		
			return null;
		}
	}
	
}

?>
