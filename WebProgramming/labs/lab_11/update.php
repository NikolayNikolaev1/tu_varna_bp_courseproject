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

    $result = mysqli_query($dbConn, "SELECT * FROM provider");

    $providers = mysqli_fetch_all($result, MYSQLI_ASSOC);
    mysqli_free_result($result);
        
    echo "<table><tr>
        <th>Id</th>
        <th>Publisher</th>
        <th>bulsat</th>
        <th>Address</th>
        <th>Phone</th>
        <th>Register Year</th>
        <th>Contact</th>
    </tr>";
    
    foreach ($providers as $provider) {
        echo "<tr>";
        foreach ($provider as $key=>$value) {

            echo "
            <td>$value</td>";
        }
        echo "</tr>";
        

    }


    echo "</table>";
 
 ?>
</body>
</html>