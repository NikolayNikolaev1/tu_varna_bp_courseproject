<?php
require_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/database/index.php");
require_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/book.service.php");

$book_service = new BookService($pdo);

$collection = $book_service->all();
$table_header = "
    <th>ID</th>
    <th>Title</th>
    <th>book</th>
    <th>Release Year</th>
    <th>Publisher</th>
    <th>Genre</th>
    <th>Loan Count</th>
    <th>Is Available</th>
    <th>Actions</th>";

include($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/views/templates/table.php");

if (isset($_POST["delete"])) {
    $current_book_id = $_POST["id"];
    $book_service->delete($current_book_id);

}
?>