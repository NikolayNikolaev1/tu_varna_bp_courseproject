<?php

$host = "localhost";
$user = "root";
$password = "";
$db_name = "library";

$pdo = new PDO("mysql:host=$host", $user, $password);
$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
$pdo->setAttribute(PDO::ATTR_DEFAULT_FETCH_MODE, PDO::FETCH_OBJ);

?>