<?php
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/database/index.php");
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/position.service.php");

$position_service = new PositionService($pdo);
$position_id = $_POST["id"];
$position = $position_service->find($position_id);

$data = [
    [
        "name" => "name",
        "type" => "text",
        "value" => $position->name
    ],
];
$resource_name = "position";
$form = "Edit";

include($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/views/templates/form.php");

if (isset($_POST["edit"])) {
    $position = $_POST["position"];

    $position = $position_service->edit($position_id, $name);
}

?>