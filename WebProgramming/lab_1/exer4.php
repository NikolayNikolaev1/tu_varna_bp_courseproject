<html>
    <head>
 <title>My first program!
</title>
 </head>
<body>
    <form method="post">
        <p>Please enter your name:</p>
        <input name="name" type="text">
        <input type="submit" name="go" value="Go">

    </form>

 <?php
	if (isset($_POST["go"])) {
		$name = $_POST["name"];
		echo "Your name is $name.";
	}
 
 ?>
</body>
</html>