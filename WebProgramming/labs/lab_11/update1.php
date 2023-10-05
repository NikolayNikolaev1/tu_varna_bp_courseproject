<?php
    include("create.php");

    $result = mysqli_query($dbConn, "UPDATE provider SET contact = 'Maria Rumenova' WHERE company = 'Lazur'");
    $result = mysqli_query($dbConn, "SELECT company, contact FROM provider");

    $providers = mysqli_fetch_all($result, MYSQLI_ASSOC);
    mysqli_free_result($result);

    echo "<ol>";

    
    foreach ($providers as $provider) {
        echo "<li>";
        foreach ($provider as $key=>$value) {

            echo "
            <td>$value</td>";
        }
        echo "</li>";
        

    }
    echo "</ol>";

?>