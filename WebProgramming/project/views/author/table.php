<!DOCTYPE html>
<html>

<head>
    <title>Page Title</title>
</head>

<body>

    <?php
    require_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/database/index.php");
    require_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/services/author.service.php");

    $author_service = new AuthorService($pdo);

    $authors = $author_service->all();
    echo "
    <table>
        <tr>
            <th>ID</th>
            <th>First Name</th>
            <th>LastName</th>
        </tr>";

    foreach ($authors as $author) {
        echo "<tr>";

        foreach ($author as $key => $value) echo "<td>$value</td>";
        
        echo "</tr>";
    }



    echo "</table>"
        ?>

</body>

</html>