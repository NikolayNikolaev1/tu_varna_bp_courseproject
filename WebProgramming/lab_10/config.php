<?php
    $dbName= 'info_books';
    include "create.php";

    if (!mysql_select_db($dbName, $dbConn)) {
        die('Database selection error: '. mysql_error());
    }
?>
