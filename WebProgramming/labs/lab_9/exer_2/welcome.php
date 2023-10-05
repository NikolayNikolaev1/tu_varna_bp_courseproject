<?php
    setcookie("user", "Alex Porter");

    echo "Welcome " . $_COOKIE["user"] . "!";
    echo "<br />All coockies:<br />";
    print_r($_COOKIE);
    
    echo "<a href=/demo/last.php>Next page - delete cookie</a>";
?>