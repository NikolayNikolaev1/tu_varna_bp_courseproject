<!DOCTYPE html>
<html>
<?php include($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/utils/layout-constants.php");
echo $bootstrap_scripts; ?>

<head>
    <title>Create Page</title>
</head>

<body>
    <form method="post">

        <h1>
            <?php echo $form . " " . $resource_name ?>.
        </h1>

        <?php foreach ($data as $curr_data): ?>

            <label for=<?php echo $curr_data["name"] ?>><?php echo $curr_data["name"] ?>: </label>
            <input id=<?php echo $curr_data["name"] ?> name=<?php echo $curr_data["name"] ?> type=<?php echo $curr_data["type"] ?> value=<?php echo $curr_data["value"] ?>>
            <br />

        <?php endforeach; ?>


        <br />
        <input type="submit" name="create" value="Create">

    </form>

</body>

</html>