<?php echo $this->load->view('header', $title) ?>

<div id="header" class="header">
	<p>
	The Survivor's Do It Yourself
	</p>
	<p>
	Open 24/24
	</p>
</div>

<!-- Last bought -->

<div id="last_bought" class="info_field">
<?php 
	if ($this->session->flashdata('last_bought') != null) {
	
		echo $this->session->flashdata('last_bought');
	}
?>
</div>

<!-- Repair form -->

<div id="repair_form" class="shop_form">
	<?php echo form_open('shop/repair'); ?>
		<div id="repair_submit_button" class="shop_field_submit">
			<?php echo form_submit('submit_repair', 'Repair all ('.$items_repair_cost.'$)'); ?>
		</div>
		
		<!-- Hidden data fields -->
		<?php echo form_hidden('items_repair_cost', $items_repair_cost); ?>
		
	<?php echo form_close(); ?>
</div>

<!-- Shop form -->

<?php foreach($items as $item) { ?>

<div id="shop_form" class="shop_form">

	<?php echo form_open('shop/buy'); ?>
	
	<div id="shop_field_turret" class="shop_field">
	
		<div id="shop_field_turret_info" class="shop_field_info">
			<div id="shop_field_turret_name" class="shop_field_title">
				<?php echo $item->item_name; ?>
			</div>
			
			<div id="shop_field_turret_price" class="shop_field_price">
				Price: $<?php echo $item->item_price; ?>
			</div>
		</div>
		
		<div id="shop_field_turret_input" class="shop_field_input">
			<?php
				$data = array(
			          'name'        => 'item_amount',
			          'id'          => 'item_amount',
			          'value'       => '',
			          'maxlength'   => '100',
			          'class'		=> 'login_field_input',
			        );
		
				echo form_input($data);
			?>
		</div>
		
		<div id="shop_field_submit_button" class="shop_field_submit">
			<?php
				echo form_submit('submit_login', 'Buy');
			?>
		</div>
		
		
		<!-- Hidden data fields -->
		<?php echo form_hidden('item_id', $item->item_id); ?>
		
	</div>

	<?php echo form_close(); ?>
</div>

<?php } ?>

</body>
</html>