namespace StudentSystem.Data.Models
{
    using System.Collections.Generic;

    public class Subject
    {
        public int Id { get; set; }

        public string Name { get; set; }

        public string ShortName { get; set; }

        public IEnumerable<StudentSubject> Students { get; set; } = new List<StudentSubject>();
    }
}
