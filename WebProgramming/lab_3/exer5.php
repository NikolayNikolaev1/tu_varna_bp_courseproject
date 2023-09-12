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
        <input type="submit" name="check" value="Check">

    </form>

 <?php
	if (isset($_POST["check"])) {
		$number = $_POST["number"];

        $num_digits = str_split($number);
        $counter = 0;

        foreach ($num_digits as $current_digit) {
            if ($current_digit % 2 == 0) $counter++;
        }

        echo "The number $number contains $counter even digits";
	}
 
 ?>
</body>
</html>