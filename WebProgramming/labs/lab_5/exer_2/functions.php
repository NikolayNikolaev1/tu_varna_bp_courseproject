<?php
    function calcTriangleArea($a, $b, $c) {
        $p = ($a + $b + $c) / 2;

        return sqrt($p * ($p - $a) * ($p - $b) * ($p - $c));
    }
?>