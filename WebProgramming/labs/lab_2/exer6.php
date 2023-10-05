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
    echo "<table><tr>
    <th>x</th>
    <th>Square</th>
    <th>Square root</th>
  </tr>";
    for ($i = 1; $i <= 12; $i++) {
        echo "
        <tr>
          <td>$i</td>
          <td>".pow($i, 2)."</td>
          <td>".round(sqrt($i), 2)."</td>
        </tr>";
    }

    echo "</table>";
 ?>
</body>
</html>