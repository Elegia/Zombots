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

# Add sample users
INSERT INTO user VALUES(0, 'testuser','testuser','test@gmail.com', CURRENT_DATE());
