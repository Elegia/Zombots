<?php

class Shop extends CI_Controller {

	function Shop() {
	
		parent::__construct();
		
		$this->load->helper('url');
		$this->load->helper('form');
		$this->load->library('form_validation');
	}
	
	function index() {

		$this->load->model('Item_model');

		
		$data = array(
			'user' => $this->session->userdata('user'),
			'items' => $this->Item_model->getItems()
		);
		
		$data['title']['title'] = "Shop";
		
		$this->load->view('shop', $data);
	}

	function buy() {
		
		// Write the bought stuff to the database
		$this->load->model('Item_model');
		$this->load->model('Inventory_model');
		$this->load->model('User_model');
		
		if (isset($_POST['item_amount']) &&
			isset($_POST['item_id'])) {

			$amount = $_POST['item_amount'];
			$item_id = $_POST['item_id'];
			
			$user = $this->User_model->getUserById($this->session->userdata('user_id'));
			$item = $this->Item_model->getItemById($item_id);
			
			if ($user->gold >= ($item->item_price * $amount)) {
			
				$this->User_model->spend($user, ($item->item_price * $amount));
				$this->Inventory_model->buy($user, $item, $amount);
				
				$this->session->set_flashdata('last_bought', 'Successfully bought '.$amount.' units of \''.$item->item_name.'\'. Thank you, come again.');
			}
		}
		
		// Page info
		$data = array(
			'user' => $this->session->userdata('user_id'),
			'items' => $this->Item_model->getItems()
		);
		
		$data['title']['title'] = "Shop";

		redirect('/shop');
	}
}

?>