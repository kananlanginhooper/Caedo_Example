<?php

class CustomerLoggedInTemplate extends BasePage {

	public function __construct(){
		parent::__construct(); // load all the parent classes first
		
		$this->__PageTitle = 'My Account';
		
		$clsRateMixer = new clsRateMixer();
		$this->__arrJavaScript_Early[] = '<script src="//ajax.googleapis.com/ajax/libs/jquery/2.1.3/jquery.min.js"></script>
        <script src="//cdnjs.cloudflare.com/ajax/libs/jquery-form-validator/2.1.47/jquery.form-validator.min.js"></script>
        <script src="//cdn.jsdelivr.net/qtip2/2.2.1/jquery.qtip.min.js"></script>
		<script src="/__local/js/bootstrap.min.js"></script>';
		
		// check if they're really logged in
		if(!isset($_SESSION['LoggedIn']) || $_SESSION['LoggedIn'] != 'customer') {
			Redirect('/myaccount.php');
		}
	
	}
	
	protected $__Qtips = array();

	protected function HEAD(){
		parent::HEAD();
		?>
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<!-- Bootstrap -->
<link href="/__local/css/bootstrap.min.css" rel="stylesheet">
<link href='http://fonts.googleapis.com/css?family=Open+Sans:400,300,700,800' rel='stylesheet' type='text/css'>
<link href="/__local/css/style.css" rel="stylesheet">
<!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->
<!-- WARNING: Respond.js doesn't work if you view the page via file:// -->
<!--[if lt IE 9]>
          <script src="https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js"></script>
          <script src="https://oss.maxcdn.com/libs/respond.js/1.3.0/respond.min.js"></script>
        <![endif]-->
<link rel="stylesheet" media="screen" href="//cdn.jsdelivr.net/qtip2/2.2.1/jquery.qtip.min.css" type="text/css" />

<script type="text/javascript">
$(document).ready(function(){
<?php
		// xdebug_break();
		
		if($this->__Qtips && is_array($this->__Qtips)) {
			foreach($this->__Qtips as $qtip) {
				?>
	    $('#<?php print $qtip->ID ?>').qtip({
        content: '<?php print $qtip->Title ?>',
        show: {
            when: false, // Don't specify a show event
            ready: <?php print $qtip->ShowByDefault ?> // Show the tooltip when ready
        },
        position: {
            my: 'middle left',  // Position my top left...
            at: 'middle right', // at the bottom right of...
        },
        hide: false // Don't specify a hide event
        ,<?php print $qtip->GetStyle()?>
    });
    


<?php
			}
		}
		?>
		
		});
		</script>

<style>
<!--


a:link, a:visited, #crumbs li a:hover, #crumbs li a:focus {
	color: #dd2c0d;
}

.imgClass {
	background-image: url(/__local/images/dark-green-continue-button.png);
	background-position: 0px -47px;
	background-repeat: no-repeat;
	width: 256px;
	height: 45px;
	border: 0px;
	cursor: pointer;
	outline: 0;
	display: block;
	background-color: white;
}

.imgClass:hover {
	background-position: 0px 0px;
}

.imgClass:active {
	background-position: 0px -94px;
}

.center {
	margin-left: auto;
	margin-right: auto;
}

.center {
	margin-left: auto;
	margin-right: auto;
}

.blackTDtext td {
	color: black;
}

.center_text {
	text-align: center;
}
-->
</style>
<?php
	}

	public function __destruct(){
		parent::__destruct();
	}

	private function HEADER(){
		?>

<header class="main__header">
	<div class="container">
		<nav class="navbar navbar-default" role="navigation">
			<!-- Brand and toggle get grouped for better mobile display -->
			<!-- Collect the nav links, forms, and other content for toggling -->
			<div class="navbar-header">
				<h1 class="navbar-brand">
					<a href="/Account/">Logo</a>
				</h1>
				<a href="#" onClick="javascript.void()" class="submenu">Menus</a>
			</div>
			<div class="menuBar">
				<ul class="menu">

					<li <?php if(get_class($this) == 'account') print "class='active'"; ?>><a href="account.php">Account Settings</a></li>
					<li <?php if(get_class($this) == 'logout') print "class='active'"; ?>><a href="../logout.php">Logout</a></li>

				</ul>
			</div>
			<!-- /.navbar-collapse -->
		</nav>
	</div>
</header>
<?php
	}

	protected function BODY(){
		parent::BODY();
		$this->HEADER();
		
		?>

<?php
	}

	protected function FOOTER(){
		parent::FOOTER();
		?>


<p class="text-center copyright">
	&copy; All Rights Reserved.<br />Your customer number is: <?php print $_SESSION['CustomerNumber']?>
</p>

<script type="text/javascript">
$( "a.submenu" ).click(function() {

	$( ".menuBar" ).slideToggle( "normal", function() {
	// Animation complete.
	});

});

$( "ul li.dropdown a" ).click(function() {

	$( "ul li.dropdown ul" ).slideToggle( "normal", function() {
		// Animation complete.
	});

	$('ul li.dropdown').toggleClass('current');

	});
</script>
		
<?php
	}

}
