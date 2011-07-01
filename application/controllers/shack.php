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
		
		
		$user = $this->User_model->getUserById($this->session->userdata('user_id'));
		
		$data = array(
			'user' => $user
		);
		
		$data['title']['title'] = "Shack";
		
		
		$this->load->view('shack', $data);
	}

}

?>