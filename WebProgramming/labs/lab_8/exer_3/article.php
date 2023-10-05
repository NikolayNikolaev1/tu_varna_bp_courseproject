<html>
    <head>
 <title>My first program!
</title>
 </head>
<body>

    
<form method="post">
    <label for="title">title:</label>
    <input id="title" name="title" type="text" required>
    </br>
    <label for="author">aurthor:</label>
    <input id="author" name="author" type="text" required>
    <br />
    <label for="description">description:</label>
    <input id="description" name="description" type="text" required>
    <br />
    <input type="submit" name="create-article" value="Create and Show">

</form>

    

 <?php
    class Article {
        private $title;
        private $author;
        private $description;

        function __construct($title, $author, $description) {
            $this->title = $title;
            $this->author = $author;
            $this->description = $description;
        }

        function show_article() {
            return "<h1><b>$this->title </b></h1></br> $this->description</br>Author: $this->author";
        }
    }

    
	if (isset($_POST["create-article"])) {
		$title = $_POST["title"];
		$author = $_POST["author"];
		$description = $_POST["description"];
		
        $article = new Article($title, $author, $description);
        

        echo $article->show_article();
	}
 ?>
</body>
</html>