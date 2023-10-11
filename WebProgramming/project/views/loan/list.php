<?php
require_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/database/index.php");
require_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/loan.service.php");

$loan_service = new LoanService($pdo);

$collection = $loan_service->all();
$table_header = "
    <th>ID</th>
    <th>Reader</th>
    <th>Employee</th>
    <th>Loan Date</th>
    <th>Actions</th>";

include($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/views/templates/table.php");

if (isset($_POST["delete"])) {
    $current_loan_id = $_POST["id"];
    $loan_service->delete($current_loan_id);

}
?>