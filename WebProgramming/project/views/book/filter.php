<!DOCTYPE html>
<html>

<head>
    <?php include($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/utils/layout-constants.php");
    echo $bootstrap_scripts; ?>
</head>

<?php
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/database/create.php");
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/book.service.php");


$book_service = new BookService($pdo);
$filtered_books = [];

if (isset($_POST["filter-title"])) {
    $title = $_POST["title"];

    $filtered_books = $book_service->filter_by_title($title);
} else if (isset($_POST["filter-author"])) {
    $author_name = $_POST["author_name"];

    $filtered_books = $book_service->filter_by_author($author_name);
} else if (isset($_POST["filter-genre"])) {
    $genre_name = $_POST["genre_name"];

    $filtered_books = $book_service->filter_by_genre($genre_name);
} else if (isset($_POST["filter-reader"])) {
    $reader_name = $_POST["reader_name"];

    $filtered_books = $book_service->filter_by_reader($reader_name);
}
?>

<table class="table">
    <thead>
        <tr>
            <th>ID</th>
            <th>Title</th>
            <th>Author Name</th>
            <th>Release Year</th>
            <th>Publisher Name</th>
            <th>Genre Name</th>
            <th>Loan Count</th>
            <th>Is Available</th>
            <?php foreach ($filtered_books as $current_book): ?>
            <tr>
        </thead>

        <?php foreach ($current_book as $key => $value): ?>
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