<html>
    <head>
 <title>My first program!
</title>
 </head>
<body>
 <?php
    $x = 8;
    echo "x=".$x."<br/>";
    echo " Add 2. x=" .  ($x += 2) ."<br/>";
	echo "Subtract 4. x=" . ($x -= 4)."<br/>";
	echo "Multiply by 5. x=" . ($x *= 5)."<br/>";
    echo "Divide by 3. x=" . ($x /= 3)."<br/>";
	echo " Increment value by one. x=" . ($x += 1)."<br/>";
	echo "Decrement value by one. x=" . ($x -= 1)."<br/>";  
 ?>
</body>
</html>