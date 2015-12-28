<?php

// changed to be totally static, constuctor is not needed
// $DBConnections = new clsDatabaseConnections();

// AWS DB - micro
$db_username = ""; // Your database login username
$db_password = ""; // Your database login password
$db_host = ""; // the url of your database server, example db.yoursite.com

clsDatabaseConnections::AddConnection('Live', $db_username, $db_password, $db_host, false);
clsDatabaseConnections::AddConnection('Test', $db_username, $db_password, $db_host, false);

// also add details for the localhost
$db_username = "root"; // Your database login username
$db_password = ""; // Your database login password
$db_host = "localhost"; // localhost database server for installs like WAMP, XAMPP and MYSQL running on test servers
clsDatabaseConnections::AddConnection('local', $db_username, $db_password, $db_host, false);
