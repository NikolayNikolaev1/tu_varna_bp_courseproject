<?php
require_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/database/index.php");
require_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/genre.service.php");

$genre_service = new GenreService($pdo);

$collection = $genre_service->all();
$table_header = "
    <th>ID</th>
    <th>Name</th>
    <th>Actions</th>";

include($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/views/templates/table.php");

if (isset($_POST["delete"])) {
    $current_genre_id = $_POST["id"];
    $genre_service->delete($current_genre_id);

}
?>