<html>
    <head>
 <title>My first program!
</title>
 </head>
<body>
    <form method="post">
	
        <p>Please enter your age:</p>
        <input name="age" type="number" style="margin-bottom: 10px">
		<p>Please enter the price: </p>
        <input name="price" type="text" style="margin-bottom: 10px">
        <br />
        <input type="submit" name="go" value="Go">

    </form>

 <?php
	if (isset($_POST["go"])) {
		$price = $_POST["price"];
		$age = $_POST["age"];
		
		if ($age <= 6 || $age >= 65) {
			$price = 50 * ($price / 100);
		}
		
		echo "Your age is $age. The price is " . round($price, 2);
	}
 
 ?>
</body>
</html>