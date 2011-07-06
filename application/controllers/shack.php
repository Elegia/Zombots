<?php

class Shack extends CI_Controller {

	function Shack() {
	
		parent::__construct();
		
		$this->load->helper('url');
		$this->load->helper('form');
		$this->load->library('form_validation');
	}
	
	function index() {
		
		$this->load->model('User_model');
		$this->load->model('Inventory_model');
		
		
		$user = $this->User_model->getUserById($this->session->userdata('user_id'));
		
		$item_list = $this->Inventory_model->getAllInventoryItems($user->user_id); 
		$items = array();
		foreach ($item_list->result() as $item) {
			$items[] = $item;
		}
		
		
		$data = array(
			'user' => $user,
			'items' => $items
		);
		
		$data['title']['title'] = "Shack";
		
		
		$this->load->view('shack', $data);
	}

}

?>