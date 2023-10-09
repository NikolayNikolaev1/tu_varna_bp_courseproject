<!DOCTYPE html>
<html>

<head>
    <title>Page Title</title>
</head>

<body>

    <?php
    require_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/database/index.php");
    require_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/employee.service.php");

    $employee_service = new EmployeeService($pdo);

    $employees = $employee_service->all();
    echo "
    <table>
        <tr>
            <th>ID</th>
            <th>First Name</th>
            <th>Last Name</th>
            <th>Position</th>
            <th>Actions</th>
        </tr>";

    foreach ($employees as $employee) {
        echo "<tr>";
        $current_id = 0;

        foreach ($employee as $key => $value) {
            echo "<td>$value</td>";

            if ($key === "id") {
                $current_id = $value;
            }
        }

        echo "<td><a href=/test>Edit</a>";
        echo "<form method=post>
                <input type=hidden  name=id value=$current_id>
                <input type=submit name=delete value=Delete>
            </form>
            </td></tr>";
    }

    echo "</table>";

    if (isset($_POST["delete"])) {
        $current_employee_id = $_POST["id"];
        $employee_service->delete($current_employee_id);

    }
    ?>

</body>

</html>