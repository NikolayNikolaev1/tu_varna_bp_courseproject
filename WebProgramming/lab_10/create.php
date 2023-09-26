<?php
    $host= 'localhost';
    $dbUser= 'root';
    $dbPass= '';
    $db = "info_books";

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

    include "config.php";

    $sql ="CREATE TABLE books(
        id INT NOT NULL AUTO_INCREMENT,
        title VARCHAR(32) NOT NULL,
        author VARCHAR(30) NOT NULL,
        publisher VARCHAR(30) NOT NULL,
        year INT NOT NULL,
        PRIMARY KEY (id)
    ) ENGINE=INNODB DEFAULT CHARSET=utf8";

    $result = mysqli_query($dbConn, $sql);

    if(!$result) die('Table creation error: ' . mysqli_error());

    // echo "Table created!";
?>
