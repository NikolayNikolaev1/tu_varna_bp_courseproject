<?php
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/database/index.php");
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/reader.service.php");

$data = [
    [
        "name" => "first_name",
        "label" => "First Name",
        "type" => "text",
    ],
    [
        "name" => "last_name",
        "label" => "Last Name",
        "type" => "text",
    ],
    [
        "name" => "phone_number",
        "label" => "Phone Number",
        "type" => "text",
    ],
    [
        "name" => "email",
        "label" => "Email",
        "type" => "text",
    ],
];
$resource_name = "Reader";

include($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/views/templates/form.php");

if (isset($_POST["create"])) {
    $first_name = $_POST["first_name"];
    $last_name = $_POST["last_name"];
    $phone_number = $_POST["phone_number"];
    $email = $_POST["email"];

    $reader_service = new ReaderService($pdo);
    $reader = $reader_service->create($first_name, $last_name, $phone_number, $email);
}

?>