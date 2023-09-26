<?php
    include("create.php");

    $result = mysqli_query($dbConn, "UPDATE books SET publisher = 'Prosveta' WHERE publisher = 'Anubis'");
    $result = mysqli_query($dbConn, "SELECT * FROM books");

    $books = mysqli_fetch_all($result, MYSQLI_ASSOC);
    mysqli_free_result($result);

    echo "<ul>";

    
    foreach ($books as $book) {
        echo "<li>";
        foreach ($book as $key=>$value) {

            echo "
            <td>$value</td>";
        }
        echo "</li>";
        

    }
    echo "</ul>";

?>