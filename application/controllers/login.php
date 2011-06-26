<?php 

class Login extends CI_Controller {


	function Login() {
		
		parent::__construct();
		$this->load->helper('url');
		$this->load->helper('form');
	}

	function index() {
		
		$data['test'] = "Greetings earthling!";
		
		$this->load->view('login', $data);
	}
	
	
}

?>