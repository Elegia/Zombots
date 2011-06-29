<?php echo $this->load->view('header', $title) ?>

<div id="header" class="header">
	<p>
	The Survivor's Do It Yourself
	</p>
	<p>
	Open 24/24
	</p>
</div>

<!-- Shop form -->

<?php foreach($items as $item) { ?>

<div id="shop_form" class="shop_form">

	<?php echo form_open('shop/buy'); ?>
	
	<div id="shop_field_turret" class="shop_field">
	
		<div id="shop_field_turret_name" class="shop_field_title">
			<?php echo $item->item_name; ?></br>
			Price: $<?php echo $item->item_price; ?>
		</div>
		
		<div id="shop_field_turret_input" class="shop_field_input">
			<?php
				$data = array(
			          'name'        => $item->item_name,
			          'id'          => $item->item_name,
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

<?php } ?>

</body>
</html>