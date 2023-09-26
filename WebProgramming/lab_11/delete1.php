<?php
    include("create.php");

    $result = mysqli_query($dbConn, "DELETE FROM provider WHERE company = 'Orhideq'");
    $result = mysqli_query($dbConn, "SELECT * FROM provider");

    $publishers = mysqli_fetch_all($result, MYSQLI_ASSOC);
    mysqli_free_result($result);

    echo "<ol>";

    
    foreach ($publishers as $publisher) {
        echo "<li>";
        foreach ($publisher as $key=>$value) {

            echo "
            <td>$value</td>";
        }
        echo "</li>";
        

    }
    echo "</ol>";

?>