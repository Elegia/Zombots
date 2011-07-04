<?php echo $this->load->view('header', $title) ?>

<div id="header" class="header">
	<p>
	Your battle history
	</p>
</div>

<?php 
foreach ($battles as $battle) { 
?>
	<div id=<?php echo 'battle_entry'.$battle->battle_id; ?> class="battle_entry">
	
		<div id=<?php echo 'battle_header'.$battle->battle_id; ?> class="battle_header">
			<?php echo 'Date: '.$battle->date; ?><br/>
			<?php echo 'Zombies fought: '.$battle->zombie_amount; ?><br/>
		</div>
		<div id=<?php echo 'battle_body'.$battle->battle_id; ?> class="battle_body">
			<?php echo $battle->full_log; ?>
		</div>

	</div>
<?php 
}
?>
</body>
</html>