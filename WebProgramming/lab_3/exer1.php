<html>
    <head>
 <title>My first program!
</title>
 </head>
<body>
    

 <?php
    echo "<ul>";
    for ($x = 1; $x <= 10; $x++) {
        echo "<li>X=$x</li>";
        echo "<ul><li>X^3=". pow($x, 3) ."</li></ul>";
    }
    echo "</ul>";
 
 ?>
</body>
</html>