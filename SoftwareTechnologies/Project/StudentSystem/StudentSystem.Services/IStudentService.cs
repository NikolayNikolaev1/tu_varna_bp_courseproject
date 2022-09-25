namespace StudentSystem.Services
{
    using Data.Models;
    using Models;
    using System.Collections.Generic;

    public interface IStudentService
    {
        IEnumerable<Student> All();

        void AddStudentScore(string studentFacNum, string subjectShortName, double score);

        void Create(string firstName, string lastName, string facNumber, int Course);

        bool FacNumberExists(string facNumber);

        StudentDetailsViewModel GetByFacNum(string facNum);
    }
}
