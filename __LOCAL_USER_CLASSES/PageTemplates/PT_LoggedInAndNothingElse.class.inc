<?php

class PT_LoggedInAndNothingElse extends BasePage {

	public function __construct(){
		parent::__construct(); // load all the parent classes first
		                       
		// check if they're really logged in
		if(!isset($_SESSION['LoggedIn']) || $_SESSION['LoggedIn'] != 'admin') {
			Redirect('../Login.php');
		}
	}

	protected function HEAD(){
		parent::HEAD();
	}

	public function __destruct(){
		parent::__destruct();
	}

	protected function BODY(){
		parent::BODY();
	}

	protected function FOOTER(){
		parent::FOOTER();
	}

}
