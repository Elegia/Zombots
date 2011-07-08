<!DOCTYPE html>
<html>
<head>
<link href='http://fonts.googleapis.com/css?family=Love+Ya+Like+A+Sister&v2' rel='stylesheet' type='text/css'>
<link rel="stylesheet" type="text/css" href="<?php echo base_url(); ?>assets/css/style.css"/>
<link rel="stylesheet" type="text/css" href="<?php echo base_url(); ?>assets/css/login.css"/>

<title>Login</title>
</head>
<body>

<div id="introduction" class="header">
	<p>
	Greetings survivor. 
	</p>
	
	<p>
	We have spotted a giant mass of zombies approaching your house. They are expected to reach you at midnight. <br />
	You better log in quick to take care of your defenses! <br />
	</p>
</div>



<!-- Login form -->

<div id="login_form" class="login_form">

	<div id="login_validation_errors" class="validation_errors">
		<?php echo validation_errors(); ?>
	</div>

	<?php $old_username = set_value('username'); ?>
	
	<?php echo form_open('login/loginUser'); ?>
	
	<div id="login_field_username" class="login_field">
		
		<div id="login_field_username_title" class="login_field_title">
			Username
		</div>
		<div id="login_field_username_input" class="login_field_input">
			<?php
				$data = array(
			          'name'        => 'username',
			          'id'          => 'username',
			          'value'       => $old_username,
			          'maxlength'   => '100',
			          'class'		=> 'login_textfield',
			        );
		
				echo form_input($data);
			?>
		</div>
	</div>
	
	<div id="login_field_password" class="login_field">
		
		<div id="login_field_password_title" class="login_field_title">
			Password
		</div>
		<div id="login_field_password_input" class="login_field_input">
			<?php
				$data = array(
			          'name'        => 'password',
			          'id'          => 'password',
			          'value'       => '',
			          'maxlength'   => '100',
			          'class'		=> 'login_textfield',
			        );
		
				echo form_password($data);
			?>
		</div>
	</div>
	
	<div id="login_field_submit" class="login_field">
	
		<div id="login_field_submit_title" class="login_field_title">
		</div>
		<div id="login_field_submit_button" class="login_field_input">
			<?php
				echo form_submit('submit_login', 'Log in');
			?>
		</div>
	</div>
	
	<?php echo form_close(""); ?>

</div>

</body>
</html>