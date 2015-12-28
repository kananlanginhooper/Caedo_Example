<?php

require_once "__CAEDO.inc";

class HelloWorld extends BasePage {

	protected function BODY(){
		parent::BODY();
		?>

			<h1>Hello World!!!</h1>

		<?php
	}
}

$ThisPage = new HelloWorld();
