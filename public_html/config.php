<?php
ini_set('display_errors','On');
ini_set('display_startup_errors','On');
ini_set('error_reporting','E_ALL | E_STRICT');
ini_set('track_errors','On');
ini_set('session.save_path','/home/rprb/public_html/tmp');
ini_set('display_errors',0);
 // error_reporting(E_ALL);
define("kernel", "../core/kernel/");
define("content", "../core/content/");
define("sources", "../core/sources/");

define("path",'/');

define("domain", 'rprb.ir');
define("host", 'http://'.domain);
define("exec", ".inc");
define("html", ".html");

define("sql_host", "localhost");
define("sql_user", "user");
define("sql_password", "pass");
define("sql_database", "rprb");
?>
