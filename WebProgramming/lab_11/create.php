<?php
    $host= 'localhost';
    $dbUser= 'root';
    $dbPass= '';
    $db = "info_provider";

    $dbConn = mysqli_connect($host, $dbUser, $dbPass, $db);

    if(!$dbConn) {
        die('Error when trying to connect to the database: '. mysqli_connect_error());
    }

    
    $sql = "CREATE DATABASE $db";

    if ($dbConn->query($sql) === TRUE) {
    echo "Database created successfully";
    } else {
    echo "Error creating database: " . $dbConn->error;
    }

    // include "config.php";

    $sql ="CREATE TABLE provider(
        id INT NOT NULL AUTO_INCREMENT,
        company VARCHAR(32) NOT NULL,
        bulsat VARCHAR(30) NOT NULL,
        address_city VARCHAR(30) NOT NULL,
        phone VARCHAR(10) NOT NULL,
        year INT NOT NULL,
        contact VARCHAR(32) NOT NULL,
        PRIMARY KEY (id)
    ) ENGINE=INNODB DEFAULT CHARSET=utf8";
    
    $result = mysqli_query($dbConn, $sql);

    $sql ="CREATE TABLE city(
        id INT NOT NULL AUTO_INCREMENT,
        name VARCHAR(32) NOT NULL UNIQUE,
        PRIMARY KEY (id)
    ) ENGINE=INNODB DEFAULT CHARSET=utf8";

    $result = mysqli_query($dbConn, $sql);

    if(!$result) die('Table creation error: ' . mysqli_error());

    // echo "Table created!";
?>
