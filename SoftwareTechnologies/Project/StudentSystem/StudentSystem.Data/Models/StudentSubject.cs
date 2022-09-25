namespace StudentSystem.Data.Models
{
    using System.ComponentModel.DataAnnotations;

    public class StudentSubject
    {
        public int StudentId { get; set; }

        public Student Student { get; set; }

        public int SubjectId { get; set; }

        public Subject Subject { get; set; }

        [Range(2, 6)]
        public double Score { get; set; }
    }
}
