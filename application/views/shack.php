<?php echo $this->load->view('header', $title) ?>

<div id="header" class="header">
	<p>
	<?php echo $user->username; ?>'s shack.
	</p>
</div>

<?php foreach($items as $item) { ?>

	<div id=<?php echo 'item'.$item->item_id; ?> class="">
	
		<?php echo $item->item_name; ?>
		
	</div>	
	
<?php } ?>

</body>
</html>