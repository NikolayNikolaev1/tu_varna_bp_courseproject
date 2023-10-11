<?php
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/models/book.php");

class BookService
{
    private $db;

    public function __construct($db)
    {
        $this->db = $db;
    }

    public function all($reader_id = null, $is_available = null, $loan_count = null)
    {
        $sql =
            "SELECT 
                b.id, 
                b.title, 
                a.first_name, 
                b.release_year, 
                p.name, 
                g.name, 
                b.loan_count, 
                b.is_available
            FROM book b
            JOIN author a
            ON b.author_id = a.id
            JOIN publisher p
            ON b.publisher_id = p.id
            JOIN genre g
            ON b.genre_id = g.id
            JOIN loan l
            ON b.id = l.book_id ";

        if ($reader_id != null) {
            $sql = $sql . "WHERE b.reader_id = '$reader_id'";
        } else if ($is_available != null) {
            $sql = $sql . "WHERE b.is_available = '$is_available' ";

            $sql = $is_available ? $sql . "ORDER BY DESC b.return_date"
                : $sql . "ORDER BY l.loan_date";
        } else if ($loan_count != null) {
            $sql = "TOP 5 " . $sql . " ORDER BY DESC b.loan_count";
        }

        $statement = $this->db->prepare($sql);
        $statement->execute();

        return $statement->fetchAll(PDO::FETCH_OBJ);
    }

    public function create(
        $title,
        $author_id,
        $release_year,
        $publisher_id,
        $genre_id
    ) {
        $statement = $this->db->prepare(
            "INSERT INTO book(title, author_id, release_year, publisher_id, genre_id, loan_count, is_available)
                VALUES(:title, :author_id, :release_year, :publisher_id, :genre_id, 0, true)"
        );
        $statement->execute([
            ":title" => $title,
            ":author_id" => $author_id,
            ":release_year" => $release_year,
            ":publisher_id" => $publisher_id,
            ":genre_id" => $genre_id
        ]);
        $reader_id = $this->db->lastInsertId();

        return $this->find($reader_id);
    }

    public function find($id)
    {
        $statement = $this->db->prepare("SELECT * FROM book WHERE id = :id");
        $statement->execute([":id" => $id]);

        return $statement->fetchObject("Book");
    }

    public function edit(
        $id,
        $title,
        $author_id,
        $release_year,
        $publisher_id,
        $genre_id
    ) {
        $statement = $this->db->prepare(
            "UPDATE book 
            SET title = :title,
                author_id = :author_id,
                release_year = :release_year,
                publisher_id = :publisher_id,
                genre_id = :genre_id
             WHERE id = :id"
        );
        $statement->execute([
            ":id" => $id,
            ":title" => $title,
            ":author_id" => $author_id,
            ":release_year" => $release_year,
            ":publisher_id" => $publisher_id,
            ":genre_id" => $genre_id
        ]);

        return $statement->fetchObject("Book");
    }

    public function delete($id)
    {
        $statement = $this->db->prepare("DELETE FROM book WHERE id = :id");
        $statement->execute([":id" => $id]);
    }
}

?>