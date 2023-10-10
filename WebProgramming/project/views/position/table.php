<!DOCTYPE html>
<html>

<head>
    <title>Page Title</title>
</head>

<body>

    <?php
    require_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/database/index.php");
    require_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/position.service.php");

    $position_service = new PositionService($pdo);

    $collection = $position_service->all();
    $table_header = "
    <th>ID</th>
    <th>Name</th>";

    include($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/views/templates/table.php");

    if (isset($_POST["delete"])) {
        $current_position_id = $_POST["id"];
        $position_service->delete($current_position_id);
    }

    ?>


</body>

</html>