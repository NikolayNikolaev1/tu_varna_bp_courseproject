<?php
    include("create.php");

    $result = mysqli_query($dbConn, "DELETE FROM books WHERE publisher = 'Prosveta'");
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