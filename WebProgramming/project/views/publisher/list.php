<?php
require_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/database/index.php");
require_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/publisher.service.php");

$publisher_service = new PublisherService($pdo);

$collection = $publisher_service->all();
$table_header = "
    <th>ID</th>
    <th>Name</th>
    <th>Actions</th>";

$resource_name = "Publisher";
include($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/views/templates/table.php");

if (isset($_POST["delete"])) {
    $current_publisher_id = $_POST["id"];
    $publisher_service->delete($current_publisher_id);

}
?>