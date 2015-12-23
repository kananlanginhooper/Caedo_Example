<?php

// don't really have to instancate, no constructor
// $SiteConfigs = new clsSiteConfigs();

$SiteConfig = new clsSiteConfig('localhost', 'default', '', true, 'caedo', false, '', false, '', 'file', '/tmp', true, true, true);
clsSiteConfigs::AddSiteConfig($SiteConfig);

// clone for IP access
$SiteConfig->Url = '127.0.0.1';
clsSiteConfigs::AddSiteConfig($SiteConfig);

 






