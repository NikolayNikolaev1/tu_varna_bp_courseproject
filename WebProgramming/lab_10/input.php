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
        <label for="title">Title:</label>
        <input id="title" name="title" type="text" />
            
        <label for="author">Author:</label>
        <input id="author" name="author" type="text" />
        
        <label for="publisher">Publisher:</label>
        <input id="publisher" name="publisher" type="text" />
        
        <label for="year">Year published:</label>
        <input id="year" name="year" type="text" />
        
        <input type="submit" name="submit" value="submit" />
            
    </form>

 <?php
    include("create.php");

	if (isset($_POST["submit"])) {
		$title = $_POST["title"];
		$author = $_POST["author"];
		$publisher = $_POST["publisher"];
		$year = $_POST["year"];

        $sql = "INSERT INTO books (title, author, publisher, year) VALUES ('$title', '$author', '$publisher', '$year')";
        $result = mysqli_query($dbConn, $sql);

        if (!$result) die('Error: ' . mysqli_error());
 
        echo "Values inserted.";
	}
 
 ?>
</body>
</html>