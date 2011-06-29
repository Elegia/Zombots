<?php

class Item_model extends CI_Model {

	var $item_id = '';
	var $item_name = '';
	var $item_price = '';
	var $item_health = '';
	var $item_damage = '';
	var $item_defense = '';
	
	function __construct() {
	
		parent::__construct();
	}
	
	function getItems() {
		
		$query = $this->db->get('item');

		$items = array();
		
		foreach ($query->result() as $row) {
		    $items[] = $row;
		}
		
		return $items;
	}
}

?>