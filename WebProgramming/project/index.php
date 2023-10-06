<?php
require("database/index.php");
require("models/author.php");

$first_name = "Test";
$last_name = "Tester";
$sql = "INSERT INTO author(first_name, last_name) VALUES(:first_name, :last_name)";
$sql = "SELECT * FROM author WHERE id = 1";
$statement = $pdo->prepare($sql);
$statement->execute();
$statement->execute([":first_name" => $first_name, ":last_name" => $last_name]);
// $statement->setFetchMode(PDO::FETCH_CLASS, "Author");

$author = $statement->fetchObject("Author");

echo $author->first_name;

?>