<html>
    <head>
 <title>My first program!
</title>
 </head>
<body>
    <form method="post">
	
        <p>Please enter your your information:</p>
        <label for="city">City:</label>
        <input id="city" name="city" type="text" required>
        <label for="month">Month:</label>
        <input id="month" name="month" type="text" required>
        <label for="year">Year:</label>
        <input id="year" name="year" type="text" required>
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
                echo "<input id=$weather type=checkbox name=weather[] value=$weather/>
                <label for=$weather>$weather</label>
                </br>";
            }
        ?>
        

        <input type="submit" name="go" value="Go">

    </form>

 <?php
	if (isset($_POST["go"])) {
		$city = $_POST["city"];
		$month = $_POST["month"];
		$year = $_POST["year"];
		$weather = $_POST["weather"];
        
        echo "In $city in the month of $month $year, you observed the following weather:</br>";
        echo "<ul>";

        foreach ($weather as $current_weather) {
            $curr_weather = substr($current_weather, 0, -1);
            echo "<li>$curr_weather</li>";
        }

        echo "</ul>";

	}
 
 ?>
</body>
</html>