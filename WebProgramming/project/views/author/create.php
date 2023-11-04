<?php
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/database/index.php");
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/author.service.php");

$data = [
    [
        "name" => "first_name",
        "label" => "First Name",
        "type" => "text",
        "value" => ""
    ],
    [
        "name" => "last_name",
        "label" => "Last Name",
        "type" => "text",
        "value" => ""
    ],
];
$resource_name = "Author";

include($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/views/templates/form.php");

if (isset($_POST["create"])) {
    $first_name = $_POST["first_name"];
    $last_name = $_POST["last_name"];

    $author_service = new AuthorService($pdo);
    $author = $author_service->create($first_name, $last_name);
}

?>