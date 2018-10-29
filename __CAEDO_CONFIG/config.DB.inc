<?php

// changed to be totally static, constuctor is not needed
// $DBConnections = new clsDatabaseConnections();

// some live or test database
$db_username = ""; // Your database login username
$db_password = ""; // Your database login password
$db_host = ""; // the url of your database server, example db.yoursite.com
$db_alias = ''; // 
clsDatabaseConnections::AddConnection('Live', $db_username, $db_password, $db_host, $db_alias, false, false);
clsDatabaseConnections::AddConnection('Test', $db_username, $db_password, $db_host, $db_alias, false, false);


/******first Database details******/
// also add details for the localhost
$db_username = "root"; // Your database login username
$db_password = ""; // Your database login password
$db_host = "localhost"; // localhost database server for installs like WAMP, XAMPP and MYSQL running on test servers
$db_alias = '';
clsDatabaseConnections::AddConnection('local', $db_username, $db_password, $db_host, $db_alias, false, false);

/******Second Database details******/
// After first DB connection you can't left db_alias variable empty
$db_alias_second = ''; // Add another database like alternate1
clsDatabaseConnections::AddConnection('local', $db_username, $db_password, $db_host, $db_alias_second, false, false);

/******third Database details******/
// After first DB connection you can't left db_alias variable empty
$db_alias_third = ''; // Add another database like alternate1
clsDatabaseConnections::AddConnection('local', $db_username, $db_password, $db_host, $db_alias_third, false, false);

// 
//
//
// And you can add more databases like above

/////////////////////////////// $Url, $Site, $Env, $IsLocal, $WriteDatabase, $HasReadReplica, $ReadDatabase, $AllowURLOverride, $URLOverridePassKey, $SessionManager, $SessionManagerPath, $TidyUp, $ShowErrors, $ShowStats

$Env = 'local';
$CDNDataHost = ''; // Add amazon url like //amazonaws.amazonaws.com
$CDNBucket = ''; // Add S3 bucket name like serverbucketupload
// Set database name like NameOfTheDBWeAreGoingToUseInOurAplication => DatabaseName
$WriteDatabase = array(
					'default' => 'TestDB_1', // First key should always be "default" // Database Name like "TestDB_1"
					$db_alias_second => 'TestDB_2', //  // Database Name like "TestDB_2"
					$db_alias_third => 'TestDB_3' //  // Database Name like "TestDB_3"
				); 
// Primary database key should be default then you can add whatever name you want for your alternative databases
$SiteConfig = new clsSiteConfig('localhost', 'default', $Env, true, $WriteDatabase, false, '', false, '', 'file', '/tmp', false, true, true);
clsSiteConfigs::AddSiteConfig($SiteConfig);
