<?php
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/database/index.php");
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/loan.service.php");
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/book.service.php");
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/reader.service.php");
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/employee.service.php");

$book_service = new BookService($pdo);
$reader_service = new ReaderService($pdo);
$employee_service = new EmployeeService($pdo);

$all_books = $book_service->all();
$all_readers = $reader_service->all();
$all_employees = $employee_service->all();

$data = [
    [
        "name" => "book_id",
        "label" => "Book Title",
        "type" => "select",
        "options" => $all_books,
        "prop" => "title",
    ],
    [
        "name" => "reader_id",
        "label" => "Reader Name",
        "type" => "select",
        "options" => $all_readers,
        "prop" => "first_name",
    ],
    [
        "name" => "employee_id",
        "label" => "Employee Name",
        "type" => "select",
        "options" => $all_employees,
        "prop" => "first_name",
    ],
    [
        "name" => "loan_date",
        "label" => "Loan Date",
        "type" => "text",
    ],
    [
        "name" => "return_term",
        "label" => "Return Term",
        "type" => "text",
    ],
];

$resource_name = "Loan";

include($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/views/templates/form.php");

if (isset($_POST["create"])) {
    $book_id = $_POST["book_id"];
    $reader_id = $_POST["reader_id"];
    $employee_id = $_POST["employee_id"];
    $loan_date = $_POST["loan_date"];
    $return_term = $_POST["return_term"];

    $loan_service = new LoanService($pdo);
    $loan = $loan_service->create($book_id, $reader_id, $employee_id, $loan_date, $return_term);
}

?>