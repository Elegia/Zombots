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

}

?>