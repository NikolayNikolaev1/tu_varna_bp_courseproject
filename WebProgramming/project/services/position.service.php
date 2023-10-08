<?php
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/models/job-position.php");

class PositionService
{
    private $db;

    public function __construct($db)
    {
        $this->db = $db;
    }

    public function all()
    {
        $statement = $this->db->prepare("SELECT * FROM job_position");
        $statement->execute();

        return $statement->fetchAll(PDO::FETCH_OBJ);
    }

    public function create($name)
    {
        $statement = $this->db->prepare("INSERT INTO job_position(name) VALUES(:name)");
        $statement->execute([":name" => $name]);
        $position_id = $this->db->lastInsertId();

        return $this->find($position_id);
    }

    public function find($id)
    {
        $statement = $this->db->prepare("SELECT * FROM job_position WHERE id = :id");
        $statement->execute([":id" => $id]);

        return $statement->fetchObject("JobPosition");
    }

    public function edit($id, $name)
    {
        $statement = $this->db->prepare("UPDATE job_position SET name = :name WHERE id = :id");
        $statement->execute([":id" => $id, ":name" => $name]);

        return $statement->fetchObject("JobPosition");
    }

    public function delete($id)
    {
        $statement = $this->db->prepare("DELETE FROM job_position WHERE id = :id");
        $statement->execute([":id" => $id]);
    }
}

?>