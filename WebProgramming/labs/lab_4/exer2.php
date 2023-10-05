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
    $cities = [
        "Tokyo",
        "Mexico City",
        "New York City",
        "Seoul",
        "Mumbai", 
        "Shanghai",
        "Lagos",
        "Buenos Aires",
        "Cairo",
        "London"];

        echo "<p>";

        foreach ($cities as $city) {
            echo "$city,";
        }

        echo "</p>";

        sort($cities);

        
        echo "<ul>";

        foreach ($cities as $city) {
            echo "<li>$city</li>";
        }

        echo "</ul>";

        $new_cities = ["Los Angeles", "Calcutta", "Osaka", "Beijing"];

        foreach ($new_cities as $city) {
            $cities[] = $city;
        }

        sort($cities);
        
        echo "<ol>";
        foreach ($cities as $city) {
            echo "<li>$city</li>";
        }

        echo "</ol>";

        

    echo "<table><tr>
    <th>key</th>
    <th>value</th>
  </tr>";

  foreach ($cities as $key=>$city) {
    echo "
    <tr>
      <td>$key</td>
      <td>$city</td>
    </tr>";
    

  }


    echo "</table>";
 ?>
</body>
</html>