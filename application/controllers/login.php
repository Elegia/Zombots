<?php 

class Login extends CI_Controller {


	function Login() {
		
		parent::__construct();
		$this->load->helper('url');
		$this->load->helper('form');
		$this->load->library('form_validation');
	}

	function index() {
		
		$this->form_validation->set_rules('username', 'Username', 'trim|required|xss_clean');
		$this->form_validation->set_rules('password', 'Password', 'trim|required|xss_clean');
			
		if ($this->form_validation->run() == FALSE)
		{	
			$this->load->view('login');
		}
		else
		{
			//$this->load->view('formsuccess');
		}
	}
	
	
}

?>