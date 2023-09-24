<?php
    $host= 'localhost';
    $dbUser= 'root';
    $dbPass= 'root';

    if(!$dbConn = mysql_connect($host, $dbUser, $dbPass)) {
        die('Error when trying to connect to the database: '.mysql_error());
    }

    echo 'Database connected!';

    // include "config.php";

    $sql ="CREATE TABLE books(
        title VARCHAR(32) NOT NULL UNIQUE,
        author VARCHAR(30) NOT NULL,
        publisher VARCHAR(30) NOT NULL,
        year INT NOT NULL,
        PRIMARY KEY (title)
    ) ENGINE=INNODB DEFAULT CHARSET=utf8";

    $result = mysql_query($sql);

    if(!$result) die('Table creation error: ' . mysql_error());

    echo "Table created!";
?>
