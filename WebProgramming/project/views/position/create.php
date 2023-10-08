<!DOCTYPE html>
<html>

<head>
    <title>My first program!</title>
</head>

<body>
    <form method="post" action="/WebProjectTU/views/position/table.php">

        <h1>Create Position.</h1>
        <label for="name">Name:</label>
        <input id="name" name="name" type="text">
        <br />
        <input type="submit" name="create" value="Create">

    </form>

    <?php
    include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/database/index.php");
    include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/position.service.php");

    if (isset($_POST["create"])) {
        $name = $_POST["name"];

        $position_service = new PositionService($pdo);
        $position_service->create($name);
    }

    ?>
</body>

</html>