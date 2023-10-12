<?php
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/database/index.php");
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/publisher.service.php");

$data = [
    [
        "name" => "name",
        "type" => "text"
    ],
];
$resource_name = "publisher";

include($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/views/templates/create.php");

if (isset($_POST["create"])) {
    $first_name = $_POST["name"];

    $publisher_service = new PublisherService($pdo);
    $publisher = $publisher_service->create($name);
}

?>