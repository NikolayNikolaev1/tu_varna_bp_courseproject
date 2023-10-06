<?php
require_once("models/author.php");

class AuthorService
{
    private $db;

    public function __construct($db)
    {
        $this->db = $db;
    }

    public function create($first_name, $last_name)
    {
        $statement = $this->db->prepare("INSERT INTO author(first_name, last_name) VALUES(:first_name, :last_name)");
        $statement->execute([":first_name" => $first_name, ":last_name" => $last_name]);
        $author_id = $this->db->lastInsertId();

        return $this->find($author_id);
    }

    public function find($id)
    {
        $statement = $this->db->prepare("SELECT * FROM author WHERE id = :id");
        $statement->execute([":id" => $id]);

        return $statement->fetchObject("Author");
    }

    public function edit($id, $first_name, $last_name)
    {
        $statement = $this->db->prepare("UPDATE author SET first_name = :first_name, last_name = :last_name WHERE id = :id");
        $statement->execute([":id" => $id, ":first_name" => $first_name, ":last_name" => $last_name]);

        return $statement->fetchObject("Author");
    }

    public function delete($id) {
        $statement = $this->db->prepare("DELETE FROM author WHERE id = :id");
        $statement->execute([":id" => $id]);
    }
}

?>