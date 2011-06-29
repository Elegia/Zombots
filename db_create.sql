DROP DATABASE zombots_dev;
CREATE DATABASE zombots_dev;

USE zombots_dev;

DROP USER 'zombotdb'@'localhost';
CREATE USER 'zombotdb'@'localhost' IDENTIFIED BY 'zombotdbpass';

GRANT SELECT ON zombots_dev.* TO 'zombotdb'@'localhost';
GRANT UPDATE ON zombots_dev.* TO 'zombotdb'@'localhost';
GRANT INSERT ON zombots_dev.* TO 'zombotdb'@'localhost';

CREATE TABLE user 
(
	user_id int unsigned not null auto_increment primary key,
	username varchar(100) not null,
	password varchar(100) not null,
	email varchar(255) not null,
	join_date DATE not null,
	gold int unsigned not null
);

CREATE TABLE item
(
	item_id int unsigned not null auto_increment primary key,
	item_name varchar(255) not null,
	item_price int not null,
	item_health int not null,
	item_damage int not null,
	item_defense int not null
);

CREATE TABLE inventory
(
	inventory_id int unsigned not null auto_increment primary key,
	user_id int unsigned unique not null,
	item_id int unsigned not null,
	amount int unsigned not null,
  	foreign key (user_id) REFERENCES user(user_id),
  	foreign key (item_id) REFERENCES item(item_id)
);

CREATE TABLE battle
(
	battle_id int unsigned not null auto_increment primary key,
	user_id int unsigned unique not null,
	player_damage int unsigned not null,
	zombie_damage int unsigned not null,
	won boolean not null,
  	foreign key (user_id) REFERENCES user(user_id)
);

# Add sample users
INSERT INTO user VALUES(0, 'testuser','testuser','test@gmail.com', CURRENT_DATE(), 1000);

# Add sample items
INSERT INTO item VALUES(0, 'Beginner\'s turret', 100, 250, 10, 0);
INSERT INTO item VALUES(0, 'Gatling', 250, 250, 50, 0);
INSERT INTO item VALUES(0, 'Cannon', 1000, 400, 100, 0);


# Add sample inventory entries
INSERT INTO inventory VALUES(0, 1, 1, 2);