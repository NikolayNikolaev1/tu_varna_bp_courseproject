<?php
require_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/database/index.php");
require_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/employee.service.php");
require_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/position.service.php");

$employee_service = new EmployeeService($pdo);
$position_service = new PositionService($pdo);

$all_employees = $employee_service->all();
$all_positions = $position_service->all();

$table_header = "
    <th>ID</th>
    <th>First Name</th>
    <th>Last Name</th>
    <th>Position</th>
    <th>Phone Number</th>
    <th>Email</th>
    <th>Actions</th>";
?>
<META HTTP-EQUIV="Content-Type" CONTENT="text/html; charset=utf-8">
<!DOCTYPE html>
<html>

<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <?php include($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/utils/layout-constants.php");
    echo $bootstrap_scripts; ?>
    <title>Test</title>
</head>

<body>

<?php include($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/views/templates/navigation.php");
    echo $bootstrap_scripts; ?>

    <table class="p-3 mb-2 bg-info text-dark table">
        <thead>

            <tr>
                <?php echo $table_header ?>

                <?php foreach ($all_employees as $current_el): ?>
                <tr>
                    <?php $curr_id = 0;
                    $counter = 0; ?>
            </thead>

            <?php foreach ($current_el as $key => $value): ?>
                <?php if ($key == "id") {
                    $curr_id = $value;
                }

                ?>

                <form method="post">
                    <td>
                        <?php if ($key == "position_id"): ?>
                            <select class=form-control name=position id=position>
                                <?php foreach ($all_positions as $curr_position): ?>
                                    <option value=<?php echo $curr_position->id ?>                 <?php echo $curr_position->id == $current_el->position_id ? "selected" : "" ?>><?php echo $curr_position->name ?></option>
                                <?php endforeach; ?>
                            </select>
                        <?php else: ?>
                            <input class="form-control" name=<?php echo $key ?> value=<?php echo $value ?>             <?php echo $key == "id" ? "disabled" : "" ?> />
                        <?php endif; ?>

                    </td>

                <?php endforeach; ?>

                <td>
                    <div class="form-group">
                        <input type="hidden" name="id" value=<?php echo $curr_id ?>>
                        <input class="btn btn-warning" type="submit" name="edit" value="Edit">
                    </div>
            </form>
            <form method="post">
                <input type="hidden" name="id" value=<?php echo $curr_id ?>>
                <input class="btn btn-danger" type="submit" name="delete" value="Delete">
            </form>
            </td>
            </tr>
        <?php endforeach; ?>
        </tr>
    </table>
    
    <script src=https://cdn.jsdelivr.net/npm/bootstrap@3.4.1/dist/js/bootstrap.min.js
        integrity=sha384-aJ21OjlMXNL5UyIl/XNwTMqvzeRMZH2w8c5cRVpzpU8Y5bApTppSuUkhZXN0VxHd
        crossorigin=anonymous></script>

</body>

</html>

<?php
if (isset($_POST["delete"])) {
    $current_employee_id = $_POST["id"];
    $employee_service->delete($current_employee_id);
} else if (isset($_POST["edit"])) {
    $curr_id = $_POST["id"];
    $first_name = $_POST["first_name"];
    $last_name = $_POST["last_name"];
    $position_id = $_POST["position"];
    $phone_number = $_POST["phone_number"];
    $email = $_POST["email"];


    $emp = $employee_service->edit($curr_id, $first_name, $last_name, $position_id, $phone_number, $email);
}

?>