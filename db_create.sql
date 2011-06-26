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
	join_date DATE not null
);

CREATE TABLE inventory
(
	inventory_id int unsigned not null auto_increment primary key,
	user_id int unsigned unique not null foreign key,
	turret int unsigned not null
);

CREATE TABLE battle
(
	battle_id int unsigned not null auto_increment primary key,
	user_id int unsigned unique not null foreign key,
	player_damage int unsigned not null,
	zombie_damage int unsigned not null,
	won boolean not null
);

# Add sample users
INSERT INTO user VALUES(0, 'testuser','testuser','test@gmail.com', CURRENT_DATE());
