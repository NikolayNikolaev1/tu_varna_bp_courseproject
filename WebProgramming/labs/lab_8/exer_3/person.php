<html>
    <head>
 <title>My first program!
</title>
 </head>
<body>

    
<form method="post">
    <label for="first-name">First Name:</label>
    <input id="first-name" name="first-name" type="text" required>
    </br>
    <label for="last-name">Last Name:</label>
    <input id="last-name" name="last-name" type="text" required>
    <br />
    <label for="email">Email:</label>
    <input id="email" name="email" type="text" required>
    <br />
    <input type="submit" name="create-person" value="Create and Show">

</form>

    

 <?php
    class Person {
        private $first_name;
        private $last_name;
        private $email;
        
        function __construct($first_name, $last_name, $email) {
            $this->first_name = $first_name;
            $this->last_name = $last_name;
            $this->email = $email;
        }

        function show_person() {
            return "Person: $this->first_name $this->last_name, Email: $this->email";
        }
    }

    
	if (isset($_POST["create-person"])) {
		$first_name = $_POST["first-name"];
		$last_name = $_POST["last-name"];
		$email = $_POST["email"];
		
        $person = new Person($first_name, $last_name, $email);
        

        echo $person->show_person();
	}
 ?>
</body>
</html>