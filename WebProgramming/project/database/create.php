<?php

require("config.php");

$pdo->query("CREATE DATABASE IF NOT EXISTS $db_name");
$pdo->query("use $db_name");

$pdo->query("CREATE TABLE IF NOT EXISTS author(
    id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    first_name VARCHAR(30) NOT NULL,
    last_name VARCHAR(30) NOT NULL
) ENGINE=INNODB DEFAULT CHARSET=utf8");

$pdo->query("CREATE TABLE IF NOT EXISTS publisher(
    id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(30) NOT NULL
) ENGINE=INNODB DEFAULT CHARSET=utf8");

$pdo->query("CREATE TABLE IF NOT EXISTS genre(
    id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(30) NOT NULL UNIQUE
) ENGINE=INNODB DEFAULT CHARSET=utf8");

$pdo->query("CREATE TABLE IF NOT EXISTS book(
    id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    author_id INT NOT NULL,
    release_year VARCHAR(4),
    publisher_id INT NOT NULL,
    genre_id INT NOT NULL REFERENCES genre(id),
    loan_count INT NOT NULL DEFAULT 0,
    is_available BOOLEAN NOT NULL DEFAULT 1,
    FOREIGN KEY (author_id) REFERENCES author(id),
    FOREIGN KEY (publisher_id) REFERENCES publisher(id),
    FOREIGN KEY (genre_id) REFERENCES genre(id)
) ENGINE=INNODB DEFAULT CHARSET=utf8");

$pdo->query("CREATE TABLE IF NOT EXISTS job_position(
    id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(30) NOT NULL UNIQUE
) ENGINE=INNODB DEFAULT CHARSET=utf8");

$pdo->query("CREATE TABLE IF NOT EXISTS employee(
    id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    first_name VARCHAR(30) NOT NULL,
    last_name VARCHAR(30) NOT NULL,
    position_id INT NOT NULL,
    phone_number VARCHAR(12) NULL UNIQUE,
    email VARCHAR(50) NULL UNIQUE,
    FOREIGN KEY (position_id) REFERENCES job_position(id)
) ENGINE=INNODB DEFAULT CHARSET=utf8");

$pdo->query("CREATE TABLE IF NOT EXISTS reader(
    id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    first_name VARCHAR(30) NOT NULL,
    last_name VARCHAR(30) NOT NULL,
    phone_number VARCHAR(12) NULL UNIQUE,
    email VARCHAR(50) NULL UNIQUE
) ENGINE=INNODB DEFAULT CHARSET=utf8");

$pdo->query("CREATE TABLE IF NOT EXISTS loan(
    id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    book_id INT NOT NULL,
    reader_id INT NOT NULL,
    employee_id INT NOT NULL,
    loan_date DATE NOT NULL,
    return_term DATE NOT NULL,
    FOREIGN KEY (book_id) REFERENCES book(id),
    FOREIGN KEY (reader_id) REFERENCES reader(id),
    FOREIGN KEY (employee_id) REFERENCES employee(id)
) ENGINE=INNODB DEFAULT CHARSET=utf8");

?>