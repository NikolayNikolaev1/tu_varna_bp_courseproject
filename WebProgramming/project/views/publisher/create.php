<?php
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/database/index.php");
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/publisher.service.php");

$data = [
    [
        "name" => "name",
        "label" => "Name",
        "type" => "text"
    ],
];
$resource_name = "Publisher";

include($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/views/templates/form.php");

if (isset($_POST["create"])) {
    $name = $_POST["name"];

    $publisher_service = new PublisherService($pdo);

    $publisher = $publisher_service->create($name);

    echo "Succeesully create publisher " . $publisher->name;
}

?>