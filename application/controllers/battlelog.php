<?php

class Battlelog extends CI_Controller {

	function Battlelog() {
	
		parent::__construct();
		
		$this->load->helper('url');
		$this->load->helper('form');
		$this->load->library('form_validation');
	}
	
	function index() {
		
		$this->load->model('Battle_model');
		
		$battlelog = $this->Battle_model->getBattleHistory($this->session->userdata('user_id'));

		$data = array();		
		$battles = array();
		
		foreach ($battlelog->result() as $battle) {
			$battles[] = $battle;
		}
		
		$data['battles'] = $battles;
		$data['title']['title'] = "Battle log";
		
		
		$this->load->view('battlelog', $data);
	}

}

?>