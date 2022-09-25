namespace StudentSystem.Data.Models
{
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;

    public class Student
    {
        public int Id { get; set; }

        [Required]
        public string FirstName { get; set; }

        [Required]
        public string LastName { get; set; }

        [Required]
        [StringLength(8)]
        public string FacNumber { get; set; }

        [Required]
        [Range(1, 6)]
        public int Course { get; set; }

        public IEnumerable<StudentSubject> Subjects { get; set; } = new List<StudentSubject>();
    }
}
