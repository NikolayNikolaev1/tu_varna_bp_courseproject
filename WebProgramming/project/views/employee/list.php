<?php
require_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/database/index.php");
require_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/employee.service.php");

$employee_service = new EmployeeService($pdo);

$collection = $employee_service->all();
$table_header = "
    <th>ID</th>
    <th>First Name</th>
    <th>Last Name</th>
    <th>Position</th>
    <th>Actions</th>";

include($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/views/templates/table.php");

if (isset($_POST["delete"])) {
    $current_employee_id = $_POST["id"];
    $employee_service->delete($current_employee_id);
}

?>