<?php
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/database/index.php");
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/author.service.php");

$author_service = new AuthorService($pdo);
$author_id = $_POST["id"];
$author = $author_service->find($author_id);

$data = [
    [
        "name" => "first name",
        "type" => "text",
        "value" => $author->first_name
    ],
    [
        "name" => "last name",
        "type" => "text",
        "value" => $author->last_name
    ],
];
$resource_name = "author";
$form = "Edit";

include($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/views/templates/create.php");

if (isset($_POST["edit"])) {
    $first_name = $_POST["first name"];
    $last_name = $_POST["last name"];

    $author = $author_service->create($first_name, $last_name);
}

?>