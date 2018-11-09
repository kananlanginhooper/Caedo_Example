<?php

require_once "##CAEDO.inc";

class MultipleDatabaseConnection extends BasePage {

	protected function BODY(){
		parent::BODY();
		
		?>

			<h1>Test with Multiple Database Connections!!!</h1>

		<?php
		// LoadDatabase 'default';
		
		// $sql = sql_query('SELECT * FROM TABLENAME1');
		// while($rs = fetch_assoc($sql)){
		// 	echo "<pre>";print_r($rs);echo "</pre>";			
		// }
		
		// echo '<br>========================Connect Second Database===========================<br>';
		// $db_alias_second = 'SECOND DATABSE ALIAS NAME';
		
		// $sql = sql_query('SELECT * FROM TABLENAME2', $db_alias_second);
		// while($rs = fetch_assoc($sql)){
		// 	echo "<pre>";print_r($rs);echo "</pre>";			
		// }
	}
}

$ThisPage = new MultipleDatabaseConnection();
