<?php
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/database/index.php");
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/author.service.php");

$data = [
    [
        "name" => "first name",
        "type" => "text",
        "value" => ""
    ],
    [
        "name" => "last name",
        "type" => "text",
        "value" => ""
    ],
];
$resource_name = "author";
$form = "create";

include($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/views/templates/create.php");

if (isset($_POST["create"])) {
    $first_name = $_POST["first name"];
    $last_name = $_POST["last name"];

    $author_service = new AuthorService($pdo);
    $author = $author_service->create($first_name, $last_name);
}

?>