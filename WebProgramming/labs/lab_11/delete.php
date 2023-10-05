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

<a href="/demo/delete1.php">Delete</a>

 <?php
    include("create.php");

    $result = mysqli_query($dbConn, "SELECT * FROM provider");

    $publishers = mysqli_fetch_all($result, MYSQLI_ASSOC);
    mysqli_free_result($result);
        
    echo "<table><tr>
        <th>id</th>
        <th>Publisher</th>
        <th>bulsat</th>
        <th>Address</th>
        <th>Phone</th>
        <th>Register Year</th>
        <th>Contact</th>
    </tr>";
    
    foreach ($publishers as $publisher) {
        echo "<tr>";
        foreach ($publisher as $key=>$value) {

            echo "
            <td>$value</td>";
        }
        echo "</tr>";
        

    }


    echo "</table>";
 
 ?>
</body>
</html>