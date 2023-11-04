<?php
include_once($_SERVER['DOCUMENT_ROOT'] . "/WebProjectTU/models/loan.php");

class LoanService
{
    private $db;

    public function __construct($db)
    {
        $this->db = $db;
    }

    public function all()
    {

        $statement = $this->db->prepare(
            "SELECT * FROM loan"
        );
        $statement->execute();

        return $statement->fetchAll(PDO::FETCH_OBJ);
    }

    public function filter_by_reader($reader_name)
    {
        $statement = $this->db->prepare(
            "SELECT 
                l.id,
                b.title,
                r.first_name AS reader_name,
                e.first_name,
                l.loan_date,
                l.return_term,
                b.loan_count
            FROM loan l 
            JOIN book b 
            ON l.book_id = b.id
            JOIN reader r
            ON l.reader_id = r.id
            JOIN employee e
            ON e.id = l.employee_id
            WHERE r.first_name = :reader_name"
        );
        $statement->execute([
            ":reader_name" => $reader_name
        ]);

        return $statement->fetchAll(PDO::FETCH_OBJ);
    }

    public function create($book_id, $reader_id, $employee_id, $loan_date, $return_term)
    {
        $statement = $this->db->prepare(
            "INSERT INTO loan(book_id, reader_id, employee_id, loan_date, return_term)
                VALUES(:book_id, :reader_id, :employee_id, :loan_date, :return_term)"
        );
        $statement->execute([
            ":book_id" => $book_id,
            ":reader_id" => $reader_id,
            ":employee_id" => $employee_id,
            ":loan_date" => $loan_date,
            ":return_term" => $return_term
        ]);

        $statement = $this->db->prepare(
            "UPDATE book 
                SET loan_count = loan_count + 1
             WHERE id = :book_id"
        );

        $statement->execute([
            ":book_id" => $book_id,
        ]);

        $reader_id = $this->db->lastInsertId();

        return $this->find($reader_id);
    }

    public function find($id)
    {
        $statement = $this->db->prepare("SELECT * FROM loan WHERE id = :id");
        $statement->execute([":id" => $id]);

        return $statement->fetchObject("Loan");
    }

    public function edit($id, $book_id, $reader_id, $employee_id, $loan_date, $return_term)
    {
        $statement = $this->db->prepare(
            "UPDATE loan 
            SET book_id = :book_id,
                reader_id = :reader_id,
                employee_id = :employee_id,
                loan_date = :loan_date,
                return_term = :return_term
             WHERE id = :id"
        );
        $statement->execute([
            ":id" => $id,
            ":book_id" => $book_id,
            ":reader_id" => $reader_id,
            ":employee_id" => $employee_id,
            ":loan_date" => $loan_date,
            ":return_term" => $return_term
        ]);

        return $statement->fetchObject("Loan");
    }

    public function delete($id)
    {
        $statement = $this->db->prepare("DELETE FROM loan WHERE id = :id");
        $statement->execute([":id" => $id]);
    }
}

?>