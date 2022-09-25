namespace StudentSystem.Services.Models
{
    using System.Collections.Generic;

    public class StudentDetailsViewModel
    {
        public string FirstName { get; set; }

        public string LastName { get; set; }

        public string FacNumber { get; set; }

        public int Course { get; set; }

        public IDictionary<string, double> Scores { get; set; } = new Dictionary<string, double>();
    }
}
