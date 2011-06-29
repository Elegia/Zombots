<?php

class Battle_model extends CI_Model {

	var $battle_id = '';
	var $user_id = '';
	var $player_damage = '';
	var $zombie_damage = '';
	var $won = '';
	
	function __construct() {
	
		parent::__construct();
	}
}

?>