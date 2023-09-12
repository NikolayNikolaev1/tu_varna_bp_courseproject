<html>
    <head>
 <title>My first program!
</title>
 </head>
<body>
    <form method="post">
	
        <h1>Registration Form</h1>
        <p>Name</p>
        <input name="name" type="text"/>
		<p>Family</p>
        <input name="family" type="text"/>
        <p>E-mail</p>
        <input name="email" type="text"/>

        <p>Choose a course:</p>
        <input id="php" type="radio" name="course" value="PHP" />
        <label for="php">PHP</label>
        <br/>
        <input id="lisp" type="radio" name="course" value="Lisp" />
        <label for="php">Lisp</label>
        <br/>
        <input id="perl" type="radio" name="course" value="Perl" />
        <label for="php">Perl</label>
        <br/>
        <input id="unix" type="radio" name="course" value="Unix" />
        <label for="php">Unix</label>

        <p>Additional Information for you?</p>
        <textarea name="information" rows="4" cols="50">
        </textarea>
        </br>
        <input id="confirm" type="checkbox" checked />
        <label for="confirm">Confirm the receiving of the information</label>
        </br>
        <input type="submit" name="submit" value="Submit"/>
        <input type="button" name="reset" value="Reset"/>

    </form>

 <?php
	if (isset($_POST["submit"])) {
		$name = $_POST["name"];
		$family = $_POST["family"];
		$course = $_POST["course"];
        
		
        echo "Hello, $name $family!</br> Your choice is $course";
	}
 
 ?>
</body>
</html>