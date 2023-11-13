<!DOCTYPE html>
<html>
<?php include($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/utils/layout-constants.php");
echo $bootstrap_scripts; ?>

<head>
    <title>Create Page</title>
</head>

<body>
    <?php include($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/views/templates/navigation.php");
    echo $bootstrap_scripts; ?>

    <h3>
        <small class="text-muted">
            Create
        </small>
        <?php echo $resource_name ?>.
    </h3>

    <form class="p-3 mb-2 bg-info text-dark" method="post">


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

    <script src=https://cdn.jsdelivr.net/npm/bootstrap@3.4.1/dist/js/bootstrap.min.js
        integrity=sha384-aJ21OjlMXNL5UyIl/XNwTMqvzeRMZH2w8c5cRVpzpU8Y5bApTppSuUkhZXN0VxHd
        crossorigin=anonymous></script>

</body>

</html>