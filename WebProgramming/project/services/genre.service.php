<?php
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/models/genre.php");

class GenreService
{
    private $db;

    public function __construct($db)
    {
        $this->db = $db;
    }

    public function all()
    {
        $statement = $this->db->prepare("SELECT * FROM genre");
        $statement->execute();

        return $statement->fetchAll(PDO::FETCH_OBJ);
    }

    public function create($name)
    {
        $statement = $this->db->prepare("INSERT INTO genre(name) VALUES(:name)");
        $statement->execute([":name" => $name]);
        $genre_id = $this->db->lastInsertId();

        return $this->find($genre_id);
    }

    public function find($id)
    {
        $statement = $this->db->prepare("SELECT * FROM genre WHERE id = :id");
        $statement->execute([":id" => $id]);

        return $statement->fetchObject("Genre");
    }

    public function edit($id, $name)
    {
        $statement = $this->db->prepare("UPDATE genre SET name = :name WHERE id = :id");
        $statement->execute([":id" => $id, ":name" => $name]);

        return $statement->fetchObject("Genre");
    }

    public function delete($id)
    {
        $statement = $this->db->prepare("DELETE FROM genre WHERE id = :id");
        $statement->execute([":id" => $id]);
    }
}

?>