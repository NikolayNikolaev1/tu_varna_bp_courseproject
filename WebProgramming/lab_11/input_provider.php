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
        <label for="company">Company:</label>
        <input id="company" name="company" type="text" />
            
        <label for="bulsat">Bulsat:</label>
        <input id="bulsat" name="bulsat" type="text" />

        <?php
            
            include("create.php");

            $result = mysqli_query($dbConn, "SELECT * FROM city");

            $cities = mysqli_fetch_all($result, MYSQLI_ASSOC);
            mysqli_free_result($result);

            echo "
            <label for=city>City:</label>

            <select name=city id=city>";
            $counter = 0;
            foreach ($cities as $city) {
                foreach ($city as $key=>$value) {
                    $counter++;
                    if ($counter % 2 != 0) continue;

                    echo "
                    <option value=$value>$value</option>";
                }
                

            }
            echo " </select>";
        ?>
        
        <label for="phone">phone:</label>
        <input id="phone" name="phone" type="text" />
        
        <label for="year">Resgier year:</label>
        <input id="year" name="year" type="text" />
        
        <label for="contact">Contact:</label>
        <input id="contact" name="contact" type="text" />
        
        <input type="submit" name="submit" value="submit" />
            
    </form>

 <?php
    include("create.php");

	if (isset($_POST["submit"])) {
		$company = $_POST["company"];
		$bulsat = $_POST["bulsat"];
		$city = $_POST["city"];
		$phone = $_POST["phone"];
		$contact = $_POST["contact"];
		$year = $_POST["year"];

        $sql = "INSERT INTO provider (company, bulsat, address_city, phone, contact, year) VALUES ('$company', '$bulsat', '$city', '$phone', '$contact', '$year')";
        $result = mysqli_query($dbConn, $sql);

        if (!$result) die('Error: ' . mysqli_error());
 
        echo "Values inserted.";
	}
 
 ?>
</body>
</html>