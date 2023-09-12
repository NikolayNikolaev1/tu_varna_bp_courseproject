<html>
    <head>
 <title>My first program!
</title>
 </head>
<body>
    <form method="post">
	
        <p>Hello! Please enter the given infortion form:</p>
		Your name: 
        <input name="name" type="text" style="margin-bottom: 5px">
        <br />
		Age: 
        <input name="age" type="number" style="margin-bottom: 5px">
        <br />
        <input type="submit" name="send" value="Send">

    </form>

 <?php
	if (isset($_POST["send"])) {
		$name = $_POST["name"];
		$age = $_POST["age"];
		echo "Hello, $name!</br>";
		echo "You are $age years old!";
	}
 
 ?>
</body>
</html>