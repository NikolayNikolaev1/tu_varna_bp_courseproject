<html>
    <head>
 <title>My first program!
</title>
 </head>
<body>
    <form method="post">
	
        <p>Enter the number of month:</p>
        <input name="month" type="number" required>
        <br />        
        <input type="submit" name="go" value="GO">

    </form>

 <?php

    if (isset($_POST["go"])) {
        $month = getMonthName($_POST["month"]);

        echo "The result is: $month";
    }

    function getMonthName($month_number) {

        switch ($month_number) {
            case 1:
            case 2:
            case 12:
                return "winter";
            case 3:
            case 4:
            case 5:
                return "spring";
            case 6:
            case 7:
            case 8:
                return "summer";
            case 9:
            case 10:
            case 11:
                return "fall";
            default:
                return "Invaldi month number. Numbers must be between 1 and 12";
        }
    }
 
 ?>
</body>
</html>