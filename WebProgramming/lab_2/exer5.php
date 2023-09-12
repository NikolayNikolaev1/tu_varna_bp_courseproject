<html>
    <head>
 <title>My first program!
</title>
 </head>
<body>
    <form method="post">
	
        <p>Enter the number:</p>
        <input name="number" type="number">
		<p>Enter the digit: </p>
        <input name="digit" type="number">
        <br />
        <input type="submit" name="go" value="GO">

    </form>

 <?php
	if (isset($_POST["go"])) {
		$number = $_POST["number"];
		$digit = $_POST["digit"];

        $num_digits = str_split($number);
        $counter = 0;

        foreach ($num_digits as $current_digit) {
            if ($current_digit == $digit) $counter++;
        }

        echo "The number contains $counter times digit $digit.";
	}
 
 ?>
</body>
</html>