<!DOCTYPE html>
<html>
<?php include($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/utils/layout-constants.php");
echo $bootstrap_scripts; ?>

<head>
    <title>Create Page</title>
</head>

<body>

    <form method="post">

        <h3>
            <small class="text-muted">
                Create
            </small>
            <?php echo $resource_name ?>.
        </h3>
        <h1>

        </h1>

        <?php foreach ($data as $curr_data): ?>
            <div class="form-group">

                <?php if ($curr_data["type"] == "select"): ?>
                    <label for=<?php echo $curr_data["name"] ?>><?php echo $curr_data["label"] ?>: </label>
                    <select class=form-control name=<?php echo $curr_data["name"] ?> id=<?php echo $curr_data["name"] ?>>

                        <?php foreach ($curr_data["options"] as $current_option): ?>
                            <option value=<?php echo $current_option->id ?>>
                                <?php echo $current_option->{$curr_data["prop"]} ?>
                            </option>
                        <?php endforeach; ?>
                    </select>

                <?php else: ?>
                    <label for=<?php echo $curr_data["name"] ?>><?php echo $curr_data["label"] ?>: </label>
                    <input class="form-control" id=<?php echo $curr_data["name"] ?> name=<?php echo $curr_data["name"] ?>
                        type=<?php echo $curr_data["type"] ?>>
                <?php endif; ?>
            </div>
        <?php endforeach; ?>


        <br />
        <input class="btn btn-primary" type="submit" name="create" value="Create">

    </form>

</body>

</html>