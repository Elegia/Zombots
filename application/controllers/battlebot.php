<?php

class Battlebot extends CI_Controller {


	function Battlebot()
	{
		parent::__construct();
		
		$this->load->helper('date');
	}
	
	function index() {
	
		$this->attack();
	}
	
	
	function attack() {
	
		$removedItems = array();
		
		$this->load->model('User_model');
		$this->load->model('Inventory_model');
		$this->load->model('Item_model');
		$this->load->model('Battle_model');
		
		$users = $this->User_model->getAllUsers();
		foreach ($users->result() as $user) {
		
			$log = "";
			
			// Calculate the play day
			
			$dateTimeJoinDate = new DateTime($user->join_date);
			$dateTimeCurrentDate = new DateTime(date('Y-m-d'));
			
			$interval = $dateTimeJoinDate->diff($dateTimeCurrentDate);
			
			$daysPassed = $interval->format('%a');
		
		
			// Create zombies
				
			$totalZombieHealth = 0;
			
			$zombieAmount = round($daysPassed * 10 * (rand(50, 150)/100));
			
			$zombies = array();
			for ($i = 0; $i < $zombieAmount; $i++) {
			
				$zombieData = array(
						'health' => 10,
						'damage' => round(10 * (rand(50, 150)/100))
					);
					
				$zombies[] = $zombieData;
				
				$totalZombieHealth += 10;
			}
			
			$log = $log.'Generated zombies:<br />';
			//echo 'Generated zombies:<br/>';
			foreach ($zombies as $zombie) {
			
				$log = $log.'Zombie: '.$zombie['health'].' health and '.$zombie['damage'].' damage.<br />';
				//echo 'Zombie: '.$zombie['health'].' health and '.$zombie['damage'].' damage.<br />';
			}
			
			
			// Calculate the player parameters
			
			$totalPlayerHealth = 0;

			$items = array();
			
			$inventory = $this->Inventory_model->getAllInventoryItems($user->user_id);
			foreach ($inventory->result() as $inventory_item) {
				
				$items[] = $inventory_item;			
				
				$totalPlayerHealth += $inventory_item->item_health;
			}
			
			$log = $log.'Player defense items:<br />';
			//echo 'Player defense structures:<br/>';
			foreach ($items as $item) {
			
				$log = $log.'Item: '.$item->item_health.' health and '.$item->item_damage.' damage.<br />';
				//echo 'Item: '.$item->item_health.' health and '.$item->item_damage.' damage.<br />';
			}
			
			
			$battleCount = 0;
			while ($totalPlayerHealth > 0 && $totalZombieHealth > 0) {
				
				// Fight!
				
				if ($battleCount % 2 == 0) {
					
					// Pick a random zombie to attack with
					
					$index = rand(0, count($zombies) - 1);
					$zombie = $zombies[$index];
					
					// Pick a random item target to attack
					
					$target = $items[ rand(0, count($items) - 1) ];
					
					// Attack
					
					$totalPlayerHealth -= $zombie['damage'];
					$target->item_health -= $zombie['damage'];
					
					$log = $log.'Zombie attacked turret for '.$zombie['damage'].' damage.<br />';
					$log = $log.'Turret health left: '.$target->item_health.'<br />';
					//echo 'Zombie attacked turret for '.$zombie['damage'].' damage.<br />';
					//echo 'Turret health left: '.$target->item_health.'<br />';
					
					if ($target->item_health <= 0) {
						
						// Target was destroyed. Remove it from the battle
						$removedItems[] = $target;
						unset($items[$index]);
						$items = array_values($items);
						
						$log = $log.'Turret was destroyed.<br />';
						//echo 'Turret was destroyed.<br />';
					}
					
					
				} else {
				
					// Pick a random item to 'attack with'
					
					$index = rand(0, count($items) - 1);
					$item = $items[$index];
					
					// Pick a random zombie target to attack
					
					$target = $zombies[ rand(0, count($zombies) - 1) ];
					
					// Attack
					
					$totalZombieHealth -= $item->item_damage;
					$target['health'] -= $item->item_damage;
					
					$log = $log.'Turret attacked zombie for '.$item->item_damage.' damage.<br />';
					$log = $log.'Zombie health left: '.$target['health'].'<br />';
					//echo 'Turret attacked zombie for '.$item->item_damage.' damage.<br />';
					//echo 'Zombie health left: '.$target['health'].'<br />';
					
					if ($target['health'] <= 0) {
					
						// Target was destroyed. Remove it from battle
						unset($zombies[$index]);
						$zombies = array_values($zombies);
						
						$log = $log.'Zombie was killed.<br />';
						//echo 'Zombie was killed.<br />';
					}
				}
				
				$battleCount++;
			}
			
			$won = false;
			if ($totalPlayerHealth <= 0) {
				
				$won = false;
				$log = $log.'<br />You are dead. You lost.';
				//echo '<br />You are dead. You lost.';
				
			} else {
			
				$won = true;
				$log = $log.'<br />You won.';
				//echo '<br />You won.';
			}
			
			// Write the updated items back to the database
			
			foreach ($items as $inventory_item) {
					
				$this->Inventory_model->updateItem($inventory_item);
			}
			
			// Remove the destroyed items from the database
			
			foreach ($removedItems as $inventory_item) {
				
				$this->Inventory_model->removeItem($inventory_item->inventory_id);				
			}
			
			// Fill in the battle log
			
			$this->Battle_model->storeBattle($user->user_id, $zombieAmount, $log, $won);
		}
	}
}

?>