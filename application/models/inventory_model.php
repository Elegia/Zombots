<html>
<head>
<style type="text/css">

header {
	color: white;
	font-family: sans-serif;
}

element1 {
}

</style>
</head>
</html><?php

class Inventory_model extends CI_Model {

	var $inventory_id = '';
	var $user_id = '';
	var $item_id = '';
	var $amount = '';
	
	function __construct() {
	
		parent::__construct();
	}
}

?>