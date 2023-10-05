<html>
    <head>
 <title>My first program!
</title>
 </head>
<body>
    <form method="post">
	
        <p>Enter the number:</p>
        <input name="number" type="number">
        <br />
        <input type="submit" name="submit" value="Submit">

    </form>

 <?php
	if (isset($_POST["submit"])) {
		$number = $_POST["number"];
        echo "The sum of digits that are equal to $number:</br>";
        
        for ($i = 1; $i <= 100; $i++) {
            $loop_digits = str_split($i);

            $digit_sum = array_sum($loop_digits);

            if ($number == $digit_sum) echo $i . "</br>";
        }
	}
 
 ?>
</body>
</html>