<!DOCTYPE html>
<html>
<head>
<link rel="stylesheet" type="text/css" href="<?php echo base_url(); ?>assets/css/style.css"/>
<link rel="stylesheet" type="text/css" href="<?php echo base_url(); ?>assets/css/battlelog.css"/>
<link rel="stylesheet" type="text/css" href="<?php echo base_url(); ?>assets/css/login.css"/>
<link rel="stylesheet" type="text/css" href="<?php echo base_url(); ?>assets/css/shop.css"/>
<link href='http://fonts.googleapis.com/css?family=Love+Ya+Like+A+Sister&v2' rel='stylesheet' type='text/css'>
<title><?php echo $title; ?></title>
</head>
<body>

<div id="navigation" class="navigation">

	<div id="navigation_item" class="navigation_item">
	
		<a href="<?php echo site_url("shack"); ?>">Shack</a>
		
	</div>
	
	<div id="navigation_item" class="navigation_item">
	
		<a href="<?php echo site_url("shop"); ?>">Shop</a>
		
	</div>
	
	<div id="navigation_item" class="navigation_item">
	
		<a href="<?php echo site_url("battlelog"); ?>">Battle log</a>
		
	</div>
	
	<div id="navigation_item" class="navigation_item">
	
		<a href="<?php echo site_url("login/logout"); ?>">Log out</a>
		
	</div>
	
</div>