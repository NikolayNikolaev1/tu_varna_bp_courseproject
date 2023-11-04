<?php
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/database/index.php");
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/reader.service.php");

$reader_service = new ReaderService($pdo);
$reader_id = $_POST["id"];
$reader = $reader_service->find($reader_id);

$data = [
    [
        "name" => "first_name",
        "type" => "text",
        "value" => ""
    ],
    [
        "name" => "last_name",
        "type" => "text",
        "value" => ""
    ],
    [
        "name" => "phone_number",
        "type" => "text",
        "value" => ""
    ],
    [
        "name" => "email",
        "type" => "text",
        "value" => ""
    ],
];
$resource_name = "reader";
$form = "Edit";

include($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/views/templates/form.php");

if (isset($_POST["edit"])) {
    $first_name = $_POST["first_name"];
    $last_name = $_POST["last_name"];
    $phone_number = $_POST["phone_number"];
    $email = $_POST["email"];

    $reader = $reader_service->edit($id, $first_name, $last_name, $phone_number, $email);
}

?>