<?php

class Game extends CI_Controller {

	function Game() {
	
		parent::__construct();
		
		$this->load->helper('url');
		$this->load->helper('form');
		$this->load->library('form_validation');
	}
	
	function index() {
		
		$data = array(
			'user' => $this->session->userdata('user')
		);
		
		$data['title']['title'] = "Shop";
		
		$this->load->view('game', $data);
	}
	
}

?>