<?php
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/database/index.php");
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/genre.service.php");

$data = [
    [
        "name" => "name",
        "label" => "Name",
        "type" => "text",
    ],
];
$resource_name = "Genre";

include($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/views/templates/form.php");
include($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/utils/layout-constants.php");
echo $bootstrap_scripts;

if (isset($_POST["create"])) {
    $name = $_POST["name"];
    $genre_service = new GenreService($pdo);

    $genre = $genre_service->create($name);
}

?>