<!DOCTYPE html>
<html>

<head>
    <?php include($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/utils/layout-constants.php");
    echo $bootstrap_scripts; ?>
</head>

<?php
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/database/create.php");
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/loan.service.php");


$loan_service = new LoanService($pdo);
$filtered_loans = [];

if (isset($_POST["filter-reader"])) {
    $reader_name = $_POST["reader_name"];

    $loans_by_title = $loan_service->filter_by_reader($reader_name);
}
?>

<table class="table">
    <thead>
        <tr>
            <th>ID</th>
            <th>Book title</th>
            <th>Reader Name</th>
            <th>Employee Name</th>
            <th>Loan Date</th>
            <th>Return term</th>
            <th>Loan Count</th>
            <?php foreach ($loans_by_title as $current_loan): ?>
            <tr>
        </thead>

        <?php foreach ($current_loan as $key => $value): ?>
            <td>
                <?php echo $value ?>
            </td>
        <?php endforeach; ?>
        </tr>
    <?php endforeach; ?>
    </tr>
</table>

</body>

</html>