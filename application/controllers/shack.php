<?php

class Shack extends CI_Controller {

	function Shack() {
	
		parent::__construct();
		
		$this->load->helper('url');
		$this->load->helper('form');
		$this->load->library('form_validation');
	}
	
	function index() {
		
		$data = array(
			'user' => $this->session->userdata('user')
		);
		
		$data['title']['title'] = "Shack";
		
		
		$this->load->view('shack', $data);
	}

}

?>