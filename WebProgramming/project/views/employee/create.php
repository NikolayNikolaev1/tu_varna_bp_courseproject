<?php
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/database/index.php");
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/employee.service.php");
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/position.service.php");

$position_service = new PositionService($pdo);
$all_positions = $position_service->all();


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
        "name" => "position",
        "label" => "Position Name",
        "type" => "select",
        "options" => $all_positions,
    ],
    [
        "name" => "phone",
        "label" => "Phone Number",
        "type" => "text",
    ],
    [
        "name" => "email",
        "label" => "Email",
        "type" => "text",
    ],
];

$notification = null;
$resource_name = "Employee";

include($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/views/templates/form.php");
$employee = null;

if (isset($_POST["create"])) {
    $first_name = $_POST["first_name"];
    $last_name = $_POST["last_name"];
    $position_id = $_POST["position"];
    $phone = $_POST["phone"];
    $email = $_POST["email"];

    $employee_service = new EmployeeService($pdo);
    $employee = $employee_service->create($first_name, $last_name, $position_id, $phone, $email);
}

if ($employee != null) {
    $notification = "Successfuly created employe " . $employee->first_name . " " . $employee->last_name;
}

?>