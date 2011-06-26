<?php

class User_model extends CI_Model {

	var $user_id = '';
	var $username = '';
	var $password = '';
	var $email = '';
	var $join_date = '';
	
	function __construct() {
	
		parent::__construct();
	}
	
	function validateUser($username, $password) {
	
		$query = "SELECT username, password FROM user WHERE username = ? AND password = ?";
		$result = $this->db->query($query, array($username, $password));
		
		if ($result->num_rows() > 0) {
		
			return TRUE;
			
		} else {
		
			return FALSE;
		}								
	}
}

?>
