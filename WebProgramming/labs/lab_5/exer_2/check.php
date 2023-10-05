<?php
    include "functions.php";
    include "index.php";

    $s =  calcTriangleArea($a, $b, $c);

    if ($a == $b && $a == $c) {
        echo "Triangle is equilateral.";
    } else if ($a == $b || $a == $c || $b == $c) {
        echo "Triangle is isosceles.";
    } else {
        echo "Triangle is scalene.";

    }
    echo "</br>Triangle area is $s sm^2.";

?>