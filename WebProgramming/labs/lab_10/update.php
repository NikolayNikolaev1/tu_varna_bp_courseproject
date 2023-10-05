<html>
    <head>
 <title>My first program!
</title>
 </head>
 

 <style>
    table, th, td {
  border: 1px solid black;
}
 </style>
<body>

<a href="/demo/update1.php">Edit</a>

 <?php
    include("create.php");

    $result = mysqli_query($dbConn, "SELECT * FROM books");

    $books = mysqli_fetch_all($result, MYSQLI_ASSOC);
    mysqli_free_result($result);
        
    echo "<table><tr>
        <th>Number</th>
        <th>title</th>
        <th>Author</th>
        <th>Publisher</th>
        <th>Year</th>
    </tr>";
    
    foreach ($books as $book) {
        echo "<tr>";
        foreach ($book as $key=>$value) {

            echo "
            <td>$value</td>";
        }
        echo "</tr>";
        

    }


    echo "</table>";
 
 ?>
</body>
</html>