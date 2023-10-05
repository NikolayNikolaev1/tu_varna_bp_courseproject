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

 <?php
    $student_avg_arr = [
        "Ivan Ivanov" => 4,
        "Dragan Draganov" => 5.46,
        "Dimo Petrov" => 5.67
    ];

    
    echo "<ol>";

    foreach ($student_avg_arr as $student=>$avg) {
        echo "<li>
            Student ". $student ." has average result: ". $avg ."
        </li>";
    }

    echo "</ol>";

    echo "<ul>";
    
    foreach ($student_avg_arr as $student=>$avg) {
        echo "<li>
            Student ". $student ." has average result: ". $avg ."
        </li>";
    }

    echo "</ul>";

    echo "<table><tr>
    <th>Name, Surname</th>
    <th>Avg</th>
  </tr>";

  foreach ($student_avg_arr as $student=>$avg) {
    echo "
    <tr>
      <td>$student</td>
      <td>$avg</td>
    </tr>";
    

  }


    echo "</table>";
 ?>
</body>
</html>