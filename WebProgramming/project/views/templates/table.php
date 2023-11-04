<!DOCTYPE html>
<html>

<head>
    <title>Page Table</title>
    <?php include($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/utils/layout-constants.php");
    echo $bootstrap_scripts; ?>
</head>

<body>
    <table class="table">
        <tr>
            <?php echo $table_header ?>

            <?php foreach ($collection as $curr_el): ?>
            <tr>
                <?php $current_id = 0; ?>

                <?php foreach ($curr_el as $key => $value): ?>
                    <?php if ($key == "id") {
                        $current_id = $value;
                    }
                    ?>

                    <td>
                        <input class="form-control" name=<?php echo $key ?> value=<?php echo $value ?>         <?php echo $key == "id" ? "disabled" : "" ?>>
                    </td>
                <?php endforeach; ?>

                <td>
                    <form method="post">
                        <input type="hidden" name="id" value=<?php echo $current_id ?>>
                        <input class="btn btn-warning" type="submit" name="edit-page" value="Edit">
                    </form>
                    <form method="post">
                        <input type="hidden" name="id" value=<?php echo $current_id ?>>
                        <input class="btn btn-danger" type="submit" name="delete" value="Delete">
                    </form>
                </td>

            </tr>
        <?php endforeach; ?>
        </tr>
    </table>

</body>

</html>