<?php
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/database/index.php");
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/publisher.service.php");

$publisher_service = new PublisherService($pdo);
$publisher_id = $_POST["id"];
$publisher = $publisher_service->find($publisher_id);

$data = [
    [
        "name" => "name",
        "type" => "text",
        "value" => $publisher->name
    ],
];
$resource_name = "publisher";
$form = "Edit";

include($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/views/templates/form.php");

if (isset($_POST["edit"])) {
    $publisher = $_POST["publisher"];

    $publisher = $publisher_service->edit($publisher_id, $name);
}

?>