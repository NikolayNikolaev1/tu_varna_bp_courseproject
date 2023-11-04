<?php
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/database/index.php");
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/book.service.php");
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/author.service.php");
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/publisher.service.php");
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/genre.service.php");

$author_service = new AuthorService($pdo);
$publisher_service = new PublisherService($pdo);
$genre_service = new GenreService($pdo);

$all_authors = $author_service->all();
$all_publishers = $publisher_service->all();
$all_genres = $genre_service->all();

$data = [
    [
        "name" => "title",
        "label" => "Title",
        "type" => "text",
    ],
    [
        "name" => "author_id",
        "label" => "Author Name",
        "type" => "select",
        "options" => $all_authors,
        "prop" => "last_name"
    ],
    [
        "name" => "release_year",
        "label" => "Release Year",
        "type" => "number",
    ],
    [
        "name" => "publisher_id",
        "label" => "Publisher Name",
        "type" => "select",
        "options" => $all_publishers,
        "prop" => "name",
    ],
    [
        "name" => "genre_id",
        "label" => "Genre Name",
        "type" => "select",
        "options" => $all_genres,
        "prop" => "name"
    ],
];

$notification = null;
$resource_name = "Book";

include($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/views/templates/form.php");
$employee = null;

if (isset($_POST["create"])) {
    $title = $_POST["title"];
    $author_id = $_POST["author_id"];
    $release_year = $_POST["release_year"];
    $publisher_id = $_POST["publisher_id"];
    $genre_id = $_POST["genre_id"];

    $book_service = new BookService($pdo);
    $book = $book_service->create($title, $author_id, $release_year, $publisher_id, $genre_id);
}

?>