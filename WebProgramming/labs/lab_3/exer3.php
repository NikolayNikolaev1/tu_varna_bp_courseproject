<html>
    <head>
 <title>My first program!
</title>
<style>
    table, th, td {
  border: 1px solid black;
}
 </style>
 </head>
<body>

 <?php
    echo "<table><tr>";
    for ($i = 1; $i <= 49; $i++) {        
        echo "<td>$i</td>";
        if ($i % 7 == 0) echo "</tr>";
    }

    echo "</table>";
 ?>
</body>
</html>