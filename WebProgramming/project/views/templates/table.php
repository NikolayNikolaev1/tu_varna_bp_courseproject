<!DOCTYPE html>
<html>

<head>
    <title>Page Title</title>
</head>

<body>
    <table>
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
                        <?php echo $value ?>
                    </td>
                <?php endforeach; ?>

                <td>
                    <form method="post" action="/WebProjectTU/views/author/edit.php">
                        <input type="hidden" name="id" value=<?php echo $current_id ?>>
                        <input type="submit" name="edit-page" value="Edit">
                    </form>
                    <form method="post">
                        <input type="hidden" name="id" value=<?php echo $current_id ?>>
                        <input type="submit" name="delete" value="Delete">
                    </form>
                </td>

            </tr>
        <?php endforeach; ?>
        </tr>
    </table>

</body>

</html>