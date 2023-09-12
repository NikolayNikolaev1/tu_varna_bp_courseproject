<html>
    <head>
 <title>My first program!
</title>
 </head>
<body>
    <form method="post">
	
        <p>Find solution for ax^2 + bx + c:</p>
        a: 
        <input name="a" type="number" required>
        <br />
		b: 
        <input name="b" type="number" required>
        <br />
        c: 
        <input name="c" type="number" required>
        <br />        
        <input type="submit" name="find" value="Find x!">

    </form>

 <?php
	if (isset($_POST["find"])) {

		$a = $_POST["a"];
		$b = $_POST["b"];
		$c = $_POST["c"];
        if ($a === 0 && b != 0) {
            $x = calcSingleX($c, $b);
            echo "X = ". round($x, 2);
        } else if  ($c == 0 && $b != 0) {
            $x = calcSingleX($a, $b);
            echo "X = ". round($x, 2);
        } else {
            $d = $b * $b - 4 * $a * $c;

            if ($d == 0) {
                $x = ($b * -1)/(2 * $a);
                echo "X = ". round($x, 2);
            } else if ($d > 0) {
                $x1 = (($b * -1) - sqrt($d)) / (2 * $a);
                $x2 = (($b * -1) + sqrt($d)) / (2 * $a);
                echo "x1 = " . round($x1, 2);
                echo "x2 = " . round($x2, 2);
            } else {
                echo "Invaldi inptus... soryy";
            }
        }

		 
        
	}

    

    function calcSingleX($first_num, $second_num) {
        return ($first_num*-1)/$second_num;
    }
 
 ?>
</body>
</html>