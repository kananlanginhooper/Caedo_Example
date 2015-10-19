# Caedo PHP Framework Example Project

This is an example project using the Caedo PHP Framework.  If you are looking to use Cadeo, you are in the right place!

If you are looking to make changes to the Caedo PHP Framework, the source is located here: https://github.com/kananlanginhooper/Caedo

 
 
# Caedo PHP Framework - Why?

Many people out there may be asking "why?". Why would you create a new framework when there are already so many options out there?

The main reason is that I didn't find a framework that fit my needs.  I needed a framework that was simple and fast to get running, but could be expanded to meet the needs of a complex project.

My goal for Caedo is enable php developers to launch a working site in 15 minutes.  The clock starts now, and you should continue by reading the rest of this page!

# Basics - Rendering Pages

There are at least two classes involved in rendering pages.
	
- BasePage

The Basepage is a core class of Caedo.  This class deals with the mechanics of loading pages and controling MVC.  This class is part of the framework and shoud be looked at an non-editable.  It is very generic, it's functionaility can (and should) be extending by adding a PageTemplate, but this isn't required.
	
- Page Template (Optional, but a good idea)

The Page Template inherits from the BasePage.  You can have many Page Templates.  This is an autoloaded class, the class name can be whatever you want provided it starts with 'cls' and ends with '.class.inc'.  So 'clsPageTemplate.class.inc' is a perfectly acceptable name.  We have created this class for you as an example, it is located in '/__LOCAL_USER_CLASSES/PageTemplates/clsPageTemplate.class.inc'.

It is common to use the Page Template to setup the look and feel of your site, such as Headers, Footers, Menus, as well as common CSS and Javascript.   
	
This class it totally optional, but again using a Page Template will save time.

	
- Page Class

This is the file that contains the page's actual content.  It also has a small amount of boiler plate code that sets up the framework.

It is also important to note, that page files are located in the folder that you would guess they would be in based on URL -- meaning there is no fancy re-writing or apache magic happening to make the framework work.

In this example project, there is a '/Basics' folder, it contains a file called index.php.  It is executed by opening (http:localhost)/Basics/index.php

_The Page class must be named the same as the file name_  So for the file index.php, the class must be named 'index'. 

Here is what the index.php file could look like:

```
<?php

require_once "../__CAEDO.php";

class index extends PageTemplate {
	
}

$ThisPage = new index();

```

Although this page doesn't do anything, or display anything. It is a legal page file.


# Basics - Hello World

This file is included in the root of the example project as HelloWorld.php

```
<?php

require_once "__CAEDO.php";

class HelloWorld extends PageTemplate {

	protected function BODY(){
		parent::BODY();
		?>
		
		<h1>Hello World!!!</h1>
		
		<?
	}
}

$ThisPage = new HelloWorld();

```

# Basics - Hello World - Using Base Page

This file is included in the root of the example project as HelloWorld_01.php

```
<?

require_once "__CAEDO.php";

class HelloWorld_01 extends BasePage {

	protected function BODY(){
		parent::BODY();
		?>
		
		<h1>Hello World!!!</h1>
		
		<?
	}
}

$ThisPage = new HelloWorld_01();

```


# Basics - Hello World

```
<?

require_once "../__CAEDO.php";

class index extends PageTemplate {

	protected function BODY(){
		parent::BODY();
		?>
		
		<h1>Hello World!!!</h1>
		
		<?
	}
}

$ThisPage = new index();

```



Each class inherits from the class above it, and can add information.  It is best to keep the most informaion in the Page Template to make the Page class file as small and simple as posible.  This will make it easy to create new pages without having to think to much about the template and layout.


# Javascript defaults

Caedo can be used with javascript framework.  I made the decision support jQuery and bootstrap our of the box, so if you'd like to use them, you don't have to do anything.  If you'd like to not use them, then change /__CAEDO/config/framework.defaults.php, and set $UsejQuery = false; and $UseBootstrap = false;



