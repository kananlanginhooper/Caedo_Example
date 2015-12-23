<?php

// These are to support xdebug and PhpED debuggers, and prevent breakpoints from breaking server code

if(!function_exists('xdebug_break')) {

	function xdebug_break(){
		;
	}
}

if(!function_exists('DebugBreak')) {

	function DebugBreak(){
		xdebug_break();
	}
}

// Setup Root folder
$RootFolder = realpath(__DIR__) . DIRECTORY_SEPARATOR;

// see if we're using composer
if(is_dir($RootFolder . "vendor/")) {
	// yes we are!
	$UsingComposer = true;
	
	// Add Composer Autoloader. If the vendor directory doesn't exist, it will not error out
	require_once $RootFolder . "vendor/autoload.php";
	
	// If this project is using composer, assume Caedo is also be loaded by composer

}
else {
	// Not using composer, assume the framework is in the root
	$UsingComposer = false;
	
	// require the main framework file
	require_once $RootFolder . "caedo/framework/Caedo.inc";
}



