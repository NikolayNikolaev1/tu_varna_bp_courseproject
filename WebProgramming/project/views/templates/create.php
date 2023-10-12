<!DOCTYPE html>
<html>

<head>
    <title>Create Page</title>
</head>

<body>
    <form method="post">

        <h1> Create
            <?php echo $resource_name ?>.
        </h1>

        <?php foreach ($data as $curr_data): ?>

            <label for=<?php echo $curr_data["name"] ?>><?php echo $curr_data["name"] ?>: </label>
            <input id=<?php echo $curr_data["name"] ?> name=<?php echo $curr_data["name"] ?> type=<?php echo $curr_data["type"] ?>>
            <br />

        <?php endforeach; ?>


        <br />
        <input type="submit" name="create" value="Create">

    </form>

</body>

</html>