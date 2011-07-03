<?php 

class Inventory_model extends CI_Model {

	var $inventory_id = '';
	var $user_id = '';
	var $item_id = '';
	var $item_health = '';
	var $item_damage = '';
	var $item_defense = '';
	
	function __construct() {
	
		parent::__construct();
	}
	
	function getAllInventoryItems($user_id) {
	
		$query = $this->db->get_where('inventory', array('user_id' => $user_id));
		return $query;
	}
	
	function updateItem($inventory_item) {
	
		$this->db->where('inventory_id', $inventory_item->inventory_id);
		$this->db->update('inventory', $inventory_item);
	}
	
	function removeItem($inventory_id) {
		
		$this->db->where('inventory_id', $inventory_id);
		$this->db->delete('inventory');
	}
	
	function buy($user, $item, $amount) {
	
		for ($i = 0; $i < $amount; $i++) {
		
			$data = array(
			   'inventory_id' => 0,
			   'user_id' => $user->user_id ,
			   'item_id' => $item->item_id,
			   'item_health' => $item->item_health,
			   'item_damage' => $item->item_damage,
			   'item_defense' => $item->item_defense
			);
				
			$this->db->insert('inventory', $data); 
		}
	}
}

?>