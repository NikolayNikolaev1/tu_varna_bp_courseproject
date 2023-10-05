<?php
$host = "localhost";
$user = "root";
$password = "";
$db_name = "library";

$pdo = new PDO("mysql:host=$host", $user, $password);
$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

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
    author_id INT NOT NULL REFERENCES author(id),
    release_year VARCHAR(4),
    publisher_id INT NOT NULL REFERENCES publisher(id),
    genre_id INT NOT NULL REFERENCES genre(id),
    loan_count INT NOT NULL DEFAULT 0,
    is_available BOOLEAN NOT NULL DEFAULT 1
) ENGINE=INNODB DEFAULT CHARSET=utf8");

$pdo->query("CREATE TABLE IF NOT EXISTS job_position(
    id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(30) NOT NULL UNIQUE
) ENGINE=INNODB DEFAULT CHARSET=utf8");

$pdo->query("CREATE TABLE IF NOT EXISTS employee(
    id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    first_name VARCHAR(30) NOT NULL,
    last_name VARCHAR(30) NOT NULL,
    position_id INT NOT NULL REFERENCES job_position(id),
    phone_number VARCHAR(12) NULL UNIQUE,
    email VARCHAR(50) NULL UNIQUE
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
    book_id INT NOT NULL REFERENCES book(id),
    reader_id INT NOT NULL REFERENCES reader(id),
    employee_id INT NOT NULL REFERENCES employee(id),
    loan_date DATE NOT NULL,
    return_term DATE NOT NULL
) ENGINE=INNODB DEFAULT CHARSET=utf8");
?>