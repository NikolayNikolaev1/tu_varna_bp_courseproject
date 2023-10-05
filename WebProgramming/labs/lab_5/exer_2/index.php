<html>
    <head>
 <title>My first program!
</title>
 </head>
<body>
    <form method="post">
	
        <p>Enter positive values:</p>
        <label for="a">a:</label>
        <input id="a" name="a" type="number" style="margin-bottom: 5px" required>
        <br />
        <label for="b">b:</label>
        <input id="b" name="b" type="number" style="margin-bottom: 5px" required>
        <br />
        <label for="c">c:</label>
        <input id="c" name="c" type="number" style="margin-bottom: 5px" required>
        <br />
        <input type="submit" name="check" value="Check">

    </form>

    <?php
	if (isset($_POST["check"])) {
		$a = $_POST["a"];
		$b = $_POST["b"];
		$c = $_POST["c"];
	}
 
    ?>
</body>
</html>