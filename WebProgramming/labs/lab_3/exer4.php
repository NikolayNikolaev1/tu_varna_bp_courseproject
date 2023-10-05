<html>
    <head>
 <title>My first program!
</title>
 </head>
<body>
    <form method="post">
	
        <label for="number">Enter number:</label>
        <input id="number" name="number" type="number">
        </br>
        <input type="submit" name="check" value="Check">

    </form>

 <?php
	if (isset($_POST["check"])) {
		$number = $_POST["number"];

        echo "The number $number " . (isPrime($number) ? "is a prime number" : "is not a prime number");
	}

    function isPrime($number) {
        if ($number == 1) return false;

        for ($i=2; $i < $number; $i++) {
            if ($number % $i == 0) {
                return false;
            }
        }

        return true;
    }
 
 ?>
</body>
</html>