<?php
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/models/employee.php");

class EmployeeService
{
    private $db;

    public function __construct($db)
    {
        $this->db = $db;
    }

    public function all()
    {

        $statement = $this->db->prepare("SELECT * FROM employee");
        $statement->execute();

        return $statement->fetchAll(PDO::FETCH_OBJ);
    }

    // public function all($top_books = false)
    // {
    //     $sql =
    //         "SELECT 
    //         e.id, 
    //         e.first_name, 
    //         e.last_name, 
    //         jp.name 
    //     FROM employee e 
    //     JOIN job_position jp 
    //     ON e.position_id = jp.id
    //     JOIN loan l
    //     ON e.id = l.employee_id
    //     JOIN book b
    //     ON l.book_id = b.id";

    //     if ($top_books) {
    //         $sql = "TOP 5 " . $sql . " ORDER BY DESC b.loan_count";
    //     }

    //     $statement = $this->db->prepare($sql);
    //     $statement->execute();

    //     return $statement->fetchAll(PDO::FETCH_OBJ);
    // }

    public function create($first_name, $last_name, $position_id, $phone_number, $email)
    {
        $statement = $this->db->prepare(
            "INSERT INTO employee(first_name, last_name, position_id, phone_number, email) VALUES(:first_name, :last_name, :position_id, :phone_number, :email)"
        );

        $statement->execute([
            ":first_name" => $first_name,
            ":last_name" => $last_name,
            ":position_id" => $position_id,
            ":phone_number" => $phone_number,
            ":email" => $email
        ]);

        $employee_id = $this->db->lastInsertId();

        return $this->find($employee_id);
    }

    public function find($id)
    {
        $statement = $this->db->prepare("SELECT * FROM employee WHERE id = :id");
        $statement->execute([":id" => $id]);

        return $statement->fetchObject("Employee");
    }

    public function edit($id, $first_name, $last_name, $position_id, $phone_number, $email)
    {
        $statement = $this->db->prepare(
            "UPDATE employee 
            SET first_name = :first_name,
                last_name = :last_name,
                position_id = :position_id,
                phone_number = :phone_number,
                email = :email
             WHERE id = :id"
        );

        $statement->execute([
            ":id" => $id,
            ":first_name" => $first_name,
            ":last_name" => $last_name,
            ":position_id" => $position_id,
            ":phone_number" => $phone_number,
            ":email" => $email
        ]);


        return $statement->fetchObject("Employee");
    }

    public function delete($id)
    {
        $statement = $this->db->prepare("DELETE FROM employee WHERE id = :id");
        $statement->execute([":id" => $id]);
    }
}

?>