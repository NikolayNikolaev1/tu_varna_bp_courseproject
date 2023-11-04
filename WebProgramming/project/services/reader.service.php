<?php
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/models/reader.php");

class ReaderService
{
    private $db;

    public function __construct($db)
    {
        $this->db = $db;
    }

    public function all()
    {

        $statement = $this->db->prepare("SELECT * FROM reader");
        $statement->execute();

        return $statement->fetchAll(PDO::FETCH_OBJ);
    }

    // public function all($top_books = false)
    // {
    //     $sql =
    //         "SELECT 
    //             r.id,
    //             r.first_name,
    //             r.last_name,
    //             r.phone_number,
    //             r.email
    //         FROM reader r
    //         JOIN loan l
    //         ON r.id = l.employee_id
    //         JOIN book b
    //         ON l.book_id = b.id";

    //     if ($top_books) {
    //         $sql = "TOP 5 " . $sql . " ORDER BY DESC b.loan_count";
    //     }

    //     $statement = $this->db->prepare($sql);
    //     $statement->execute();

    //     return $statement->fetchAll(PDO::FETCH_OBJ);
    // }

    public function create($first_name, $last_name, $phone_number, $email)
    {
        $statement = $this->db->prepare("INSERT INTO reader(first_name, last_name, phone_number, email) VALUES(:first_name, :last_name, :phone_number, :email)");
        $statement->execute([
            ":first_name" => $first_name,
            ":last_name" => $last_name,
            ":phone_number" => $phone_number,
            ":email" => $email
        ]);
        $reader_id = $this->db->lastInsertId();

        return $this->find($reader_id);
    }

    public function find($id)
    {
        $statement = $this->db->prepare("SELECT * FROM reader WHERE id = :id");
        $statement->execute([":id" => $id]);

        return $statement->fetchObject("Reader");
    }

    public function edit($id, $first_name, $last_name, $phone_number, $email)
    {
        $statement = $this->db->prepare("UPDATE reader SET first_name = :first_name, last_name = :last_name, phone_number = :phone_number, email = :email WHERE id = :id");
        $statement->execute([
            ":id" => $id,
            ":first_name" => $first_name,
            ":last_name" => $last_name,
            ":phone_number" => $phone_number,
            ":email" => $email
        ]);

        return $statement->fetchObject("Reader");
    }

    public function delete($id)
    {
        $statement = $this->db->prepare("DELETE FROM reader WHERE id = :id");
        $statement->execute([":id" => $id]);
    }
}

?>