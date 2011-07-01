<!DOCTYPE html>
<html>
<head>
<link rel="stylesheet" type="text/css" href="<?php echo base_url(); ?>assets/css/style.css"/>
<link rel="stylesheet" type="text/css" href="<?php echo base_url(); ?>assets/css/game.css"/>
<link rel="stylesheet" type="text/css" href="<?php echo base_url(); ?>assets/css/login.css"/>
<link rel="stylesheet" type="text/css" href="<?php echo base_url(); ?>assets/css/shop.css"/>

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
	
		<a href="<?php echo site_url("log"); ?>">Battle log</a>
		
	</div>
	
	<div id="navigation_item" class="navigation_item">
	
		<a href="<?php echo site_url("login/logout"); ?>">Log out</a>
		
	</div>
	
</div>