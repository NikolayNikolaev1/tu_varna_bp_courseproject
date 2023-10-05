<?php
    class Book {
        private $title;
        private $author;
        private $price;

        function __construct($title, $author, $price) {
            $this->title = $title;
            $this->author = $author;
            $this->price = $price;
        }

        function show_books() {
            return "Book: $this->title, $this->author, $this->price" . "lv.";
        }
    }

    $book = new Book("PHP and MySQL", "Ivan Ivanov", 12);

    echo $book->show_books();
?>