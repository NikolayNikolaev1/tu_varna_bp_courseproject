<html>
    <head>
 <title>My first program!
</title>
 </head>
<body>
    <form method="post">
	
        <h1>Area of rectangle:</h1>
        <p>Enter length and width for rectangle.</p>
        <label for="length">Length:</label>
        <input id="length" name="length" type="number">
        <label for="width">Width:</label>
        <input id="width" name="width" type="number">
        <br />
        <input type="submit" name="go" value="Go">

    </form>

 <?php
	if (isset($_POST["go"])) {
		$length = $_POST["length"];
		$width = $_POST["width"];
		
        $area = recArea($length, $width);

        echo "Rectangle area</br>Rectangle with length $length and width $width has area $area.";
	}
 

    function recArea($l, $w) {
        return $l * $w;
    }
 ?>
</body>
</html>