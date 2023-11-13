<?php
require_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/database/index.php");
require_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/loan.service.php");
require_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/employee.service.php");
require_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/book.service.php");
require_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/reader.service.php");

$loan_service = new LoanService($pdo);
$employee_service = new EmployeeService($pdo);
$book_service = new BookService($pdo);
$reader_service = new ReaderService($pdo);

$all_loans = $loan_service->all();
$all_employees = $employee_service->all();
$all_books = $book_service->all();
$all_readers = $reader_service->all();
$table_header = "
    <th>ID</th>
    <th>Book Title</th>
    <th>Reader Name</th>
    <th>Employee Name</th>
    <th>Loan Date</th>
    <th>Return Term</th>
    <th>Actions</th>";

?>


<META HTTP-EQUIV="Content-Type" CONTENT="text/html; charset=utf-8">
<!DOCTYPE html>
<html>

<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <?php include($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/utils/layout-constants.php");
    echo $bootstrap_scripts; ?>
    <title>Test</title>
</head>

<body>

<?php include($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/views/templates/navigation.php");
    echo $bootstrap_scripts; ?>
    <table class="p-3 mb-2 bg-info text-dark table">
        <thead>

            <tr>
                <?php echo $table_header ?>

                <?php foreach ($all_loans as $current_el): ?>
                <tr>
                    <?php $curr_id = 0;
                    $counter = 0; ?>
            </thead>

            <?php foreach ($current_el as $key => $value): ?>
                <?php if ($key == "id") {
                    $curr_id = $value;
                }

                ?>

                <form method="post">
                    <td>
                        <?php if ($key == "employee_id"): ?>
                            <select class=form-control name=employee id=employee>
                                <?php foreach ($all_employees as $curr_employee): ?>
                                    <option value=<?php echo $curr_employee->id ?>                 <?php echo $curr_employee->id == $current_el->employee_id ? " selected " : "" ?>><?php echo $curr_employee->first_name . " " . $curr_employee->last_name ?></option>
                                <?php endforeach; ?>
                            </select>
                            <?php elseif ($key == "book_id"): ?>
                            <select class=form-control name=book id=book>
                                <?php foreach ($all_books as $curr_book): ?>
                                    <option value=<?php echo $curr_book->id ?>                 <?php echo $curr_book->id == $current_el->book_id ? " selected " : "" ?>><?php echo $curr_book->title ?></option>
                                <?php endforeach; ?>
                            </select>
                        <?php elseif ($key == "reader_id"): ?>
                            <select class=form-control name=reader id=reader>
                                <?php foreach ($all_readers as $curr_reader): ?>
                                    <option value=<?php echo $curr_reader->id ?> <?php echo $curr_reader->id == $current_el->reader_id ? " selected" : "" ?>> <?php echo $curr_reader->first_name . " " . $curr_reader->last_name ?></option>
                                <?php endforeach; ?>
                            </select>
                        <?php else: ?>
                            <input class="form-control" name=<?php echo $key ?> value=<?php echo $value ?>             <?php echo $key == "id" ? "disabled" : "" ?> />
                        <?php endif; ?>

                    </td>

                <?php endforeach; ?>

                <td>
                    <div class="form-group">
                        <input type="hidden" name="id" value=<?php echo $curr_id ?>>
                        <input class="btn btn-warning" type="submit" name="edit" value="Edit">
                    </div>
            </form>
            <form method="post">
                <input type="hidden" name="id" value=<?php echo $curr_id ?>>
                <input class="btn btn-danger" type="submit" name="delete" value="Delete">
            </form>
            </td>
            </tr>
        <?php endforeach; ?>
        </tr>
    </table>

    
    <form method="post" action="/WebProjectTU/views/loan/filter.php">
        <div class="form-group">
                <label for="reader_name">Search by reader first name:</label>
                <input class="form-control" id="reader_name" name="reader_name" type="text">
        </div>

        <input class="btn btn-primary" type="submit" name="filter-reader" value="Filter by Reader">
    </form>
    
    <script src=https://cdn.jsdelivr.net/npm/bootstrap@3.4.1/dist/js/bootstrap.min.js
        integrity=sha384-aJ21OjlMXNL5UyIl/XNwTMqvzeRMZH2w8c5cRVpzpU8Y5bApTppSuUkhZXN0VxHd
        crossorigin=anonymous></script>

</body>

</html>


<?php
if (isset($_POST["delete"])) {
    $current_loan_id = $_POST["id"];
    $loan_service->delete($current_loan_id);

} else if (isset($_POST["edit"])) {
    $curr_id = $_POST["id"];
    $book_id = $_POST["book"];
    $reader_id = $_POST["reader"];
    $employee_id = $_POST["employee"];
    $loan_date = $_POST["loan_date"];
    $return_term = $_POST["return_term"];

    $emp = $loan_service->edit($curr_id, $book_id, $reader_id, $employee_id, $loan_date, $return_term);
}
?>