<?php

class Battle_model extends CI_Model {

	var $battle_id = '';
	var $user_id = '';
	var $zombie_amount = '';
	var $full_log = '';
	var $won = '';
	
	function __construct() {
	
		parent::__construct();
	}
	
	function storeBattle($user_id, $zombie_amount, $full_log, $won) {
		
		$data = array(
		   'battle_id' => 0,
		   'user_id' => $user_id,
		   'zombie_amount' => $zombie_amount,
		   'full_log' => $full_log,
		   'won' => $won
		);
			
		$this->db->insert('battle', $data); 
	}
}

?>