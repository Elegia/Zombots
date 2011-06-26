<?php 

class Login extends CI_Controller {


	function Login() {
		
		parent::__construct();
		
		$this->load->helper('url');
		$this->load->helper('form');
		$this->load->library('form_validation');
		
	}

	function index() {
		
		$this->loginUser();
	}
	
	function loginUser() {
	
		$this->load->model('User_model');
		
		$this->form_validation->set_rules('username', 'Username', 'trim|required|xss_clean');
		$this->form_validation->set_rules('password', 'Password', 'trim|required|xss_clean');
			
		if ($this->form_validation->run() == FALSE) {	
			
			$this->load->view('login');
			
		} else {
			
			if (isset($_POST['username']) && isset($_POST['password'])) {
			
				$username = $_POST['username'];
				$password = $_POST['password'];
				
			} else {
			
				echo "POST error";
			}
			
			
			$user = $this->User_model->validateUser($username, $password);
			if ($user != null) {
			
				$this->session->set_userdata('user', $user);
				redirect('/game');
				
			} else {
			
				echo "validation error";
			}
			
		}
	}
	
	
}

?>