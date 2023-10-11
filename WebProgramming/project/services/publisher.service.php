<?php
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/models/publisher.php");

class PublisherService
{
    private $db;

    public function __construct($db)
    {
        $this->db = $db;
    }

    public function all()
    {
        $statement = $this->db->prepare("SELECT * FROM publisher");
        $statement->execute();

        return $statement->fetchAll(PDO::FETCH_OBJ);
    }

    public function create($name)
    {
        $statement = $this->db->prepare("INSERT INTO publisher(name) VALUES(:name)");
        $statement->execute([":name" => $name]);
        $publisher_id = $this->db->lastInsertId();

        return $this->find($publisher_id);
    }

    public function find($id)
    {
        $statement = $this->db->prepare("SELECT * FROM publisher WHERE id = :id");
        $statement->execute([":id" => $id]);

        return $statement->fetchObject("Publisher");
    }

    public function edit($id, $name)
    {
        $statement = $this->db->prepare("UPDATE publisher SET name = :name WHERE id = :id");
        $statement->execute([":id" => $id, ":name" => $name]);

        return $statement->fetchObject("Publisher");
    }

    public function delete($id)
    {
        $statement = $this->db->prepare("DELETE FROM publisher WHERE id = :id");
        $statement->execute([":id" => $id]);
    }
}

?>