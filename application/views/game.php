<!DOCTYPE html>
<html>
<head>
<link rel="stylesheet" type="text/css" href="<?php echo base_url(); ?>assets/css/style.css"/>
<link rel="stylesheet" type="text/css" href="<?php echo base_url(); ?>assets/css/game.css"/>

<title>Game</title>
</head>
<body>

<div id="header" class="header">
	<p>
	Welcome back, <?php echo $user['username'] ?>.
	</p>
	
	<p>
	Shop till ya drop.
	</p>
</div>

<!-- Shop form -->

<div id="shop_form" class="shop_form">

	<?php echo form_open('game/buy'); ?>
	
	<div id="shop_field_turret" class="shop_field">
	
		<div id="shop_field_turret_name" class="shop_field_title">
			Turret (Basic)
		</div>
		
		<div id="shop_field_turret_input" class="shop_field_input">
			<?php
				$data = array(
			          'name'        => 'username',
			          'id'          => 'username',
			          'value'       => '',
			          'maxlength'   => '100',
			          'class'		=> 'login_field_input',
			        );
		
				echo form_input($data);
			?>
		</div>
	</div>
	
	<div id="shop_field_submit" class="shop_field">
	
		<div id="shop_field_submit_title" class="shop_field_title">
		</div>
		<div id="shop_field_submit_button" class="shop_field_input">
			<?php
				echo form_submit('submit_login', 'Buy');
			?>
		</div>
	</div>
	
	<?php echo form_close(); ?>
</div>

</body>
</html>