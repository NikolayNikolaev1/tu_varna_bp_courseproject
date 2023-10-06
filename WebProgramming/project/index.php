<?php
require("database/index.php");
require("models/author.php");
require("services/author.service.php");

$authorService = new AuthorService($pdo);
$author = $authorService->find(4);
$authorService->delete(4);
// var_dump($author);
// var_dump($author2);
// var_dump($author);
?>