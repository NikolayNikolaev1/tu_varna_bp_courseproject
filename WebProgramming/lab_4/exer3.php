<html>
    <head>
 <title>My first program!
</title>
 </head>
<body>
    <form method="post">
	
        <p>Please enter your your information:</p>
        <label for="city">City:</label>
        <input id="city" name="city" type="text">
        <label for="month">Month:</label>
        <input id="month" name="month" type="text">
        <label for="year">Year:</label>
        <input id="year" name="year" type="text">
        </br>
        <p>Please choose the kinds of weather you experienced from the list below.</p>
        <p>Choose all that apply.</p>

        <?php 
            $weathers = [
                "Sunshine",
                "Clouds",
                "Rain",
                "Hail",
                "Sleet",
                "Snow",
                "Wind",
                "Cold",
                "Heat"
            ];

            foreach ($weathers as $weather) {
                echo "<input id=$weather type=checkbox value=$weather/>
                <label for=$weather>$weather</label>
                </br>";
            }
        ?>
        

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