<html>
    <head>
 <title>My first program!
</title>
 </head>
 
<style>
    form {
    display: grid;
    grid-template-columns: 1fr 3fr;
}
</style>

<body>
    <form method="post">
        <label for="city">City:</label>
        <input id="city" name="city" type="text" />
        <br/>
        
        <input type="submit" name="enter" value="enter" />
            
    </form>

 <?php
    include("create.php");

	if (isset($_POST["enter"])) {
		$city = $_POST["city"];

        $sql = "INSERT INTO city (name) VALUES ('$city')";
        $result = mysqli_query($dbConn, $sql);

        if (!$result) die('Error: ' . mysqli_error());
 
        echo "Values inserted.";
	}
 
 ?>
</body>
</html>