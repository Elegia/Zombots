<?php

class Battle_model extends CI_Model {

	var $battle_id = '';
	var $user_id = '';
	var $zombie_amount = '';
	var $full_log = '';
	var $won = '';
	var $date = '';
	
	function __construct() {
	
		parent::__construct();
	}
	
	function storeBattle($user_id, $zombie_amount, $full_log, $won) {
		
		$data = array(
		   'battle_id' => 0,
		   'user_id' => $user_id,
		   'zombie_amount' => $zombie_amount,
		   'full_log' => $full_log,
		   'won' => $won,
		   'date' => date('Y-m-d')
		);
			
		$this->db->insert('battle', $data); 
	}
	
	function getBattleHistory($user_id) {
	
		$this->db->order_by("date", "desc");
		$query = $this->db->get_where('battle', array('user_id' => $user_id));
		return $query;
	}
}

?>