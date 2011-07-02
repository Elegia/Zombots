<?php 

class Inventory_model extends CI_Model {

	var $inventory_id = '';
	var $user_id = '';
	var $item_id = '';
	var $amount = '';
	
	function __construct() {
	
		parent::__construct();
	}
	
	function getAllInventoryItems($user_id) {
	
		$query = $this->db->get_where('inventory', array('user_id' => $user_id));
		return $query;
	}
	
	function updateItems($user_id, $items) {
	
		foreach ($items as $item) {
		
			
			$this->db->where('inventory', array('user_id' => $user_id, 'item_id' => $item->item_id));
			$this->db->update('inventory', $item);
		}
	}
	
	function removeItem($user_id, $item) {
		
		$this->db->where('inventory', array('user_id' => $user_id, 'item_id' => $item->item_id));
		$this->db->delete('inventory');
	}
	
	function buy($user, $item, $amount) {
	
		$query = $this->db->get_where('inventory', array('user_id' => $user->user_id, 'item_id' => $item->item_id));
		
		if ($query->num_rows() == 1) {
			
			// We already own one or more instances of this item, so update the row
			$inventory = $query->row(0);
			
			$data = array(
               'amount' => $inventory->amount + $amount
            );

			$this->db->where('inventory_id', $inventory->inventory_id);
			$this->db->update('inventory', $data);
			
		} else {
			
			// We don't have an instance of this item in our inventory yet. Create it.
			
			$data = array(
			   'inventory_id' => 0,
			   'user_id' => $user->user_id ,
			   'item_id' => $item->item_id,
			   'amount' => $amount
			);
			
			$this->db->insert('inventory', $data); 
		}
	}
}

?>