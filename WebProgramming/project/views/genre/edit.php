<?php
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/database/index.php");
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/genre.service.php");

$genre_service = new GenreService($pdo);
$genre_id = $_POST["id"];
$genre = $genre_service->find($genre_id);

$data = [
    [
        "name" => "name",
        "type" => "text",
        "value" => $genre->name
    ],
];
$resource_name = "genre";
$form = "Edit";

include($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/views/templates/form.php");

if (isset($_POST["edit"])) {
    $genre = $_POST["genre"];

    $genre = $genre_service->edit($genre_id, $name);
}

?>