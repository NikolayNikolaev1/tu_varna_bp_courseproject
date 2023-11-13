<?php
require_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/database/index.php");
require_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/reader.service.php");

$reader_service = new ReaderService($pdo);

$collection = $reader_service->all();
$table_header = "
    <th>ID</th>
    <th>First Name</th>
    <th>Last Name</th>
    <th>Phone Number</th>
    <th>Email</th>
    <th>Actions</th>";

    $resource_name = "Reader";
include($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/views/templates/table.php");

if (isset($_POST["delete"])) {
    $current_reader_id = $_POST["id"];
    $reader_service->delete($current_reader_id);

}
?>