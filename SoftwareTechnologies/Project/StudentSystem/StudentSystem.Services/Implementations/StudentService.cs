namespace StudentSystem.Services.Implementations
{
    using Data;
    using Data.Models;
    using Microsoft.EntityFrameworkCore;
    using StudentSystem.Services.Models;
    using System.Collections.Generic;
    using System.Linq;

    public class StudentService : IStudentService
    {
        private StudentSystemDbContext dbContext;

        public StudentService()
        {
            this.dbContext = new StudentSystemDbContext();
        }

        public void AddStudentScore(string studentFacNum, string subjectShortName, double score)
        {
            int studentId = this.dbContext
                .Students
                .FirstOrDefault(s => s.FacNumber == studentFacNum)
                .Id;

            int subjectId = this.dbContext
                .Subjects
                .FirstOrDefault(s => s.ShortName == subjectShortName)
                .Id;

            var hasStudentSubject = this.dbContext
                .StudentSubjects
                .FirstOrDefault(ss => ss.StudentId == studentId && ss.SubjectId == subjectId);

            if (hasStudentSubject != null)
            {
                this.dbContext.StudentSubjects.Remove(hasStudentSubject);
            }

            this.dbContext
                .StudentSubjects
                .Add(new StudentSubject
                {
                    StudentId = studentId,
                    SubjectId = subjectId,
                    Score = score
                });

            this.dbContext.SaveChanges();
        }

        public IEnumerable<Student> All()
            => this.dbContext
            .Students
            .ToList();

        public void Create(string firstName, string lastName, string facNumber, int course)
        {
            this.dbContext.Students.Add(new Student
            {
                FirstName = firstName,
                LastName = lastName,
                FacNumber = facNumber,
                Course = course
            });

            this.dbContext.SaveChanges();
        }

        public bool FacNumberExists(string facNumber)
            => this.dbContext
            .Students
            .Any(t => t.FacNumber == facNumber);

        public StudentDetailsViewModel GetByFacNum(string facNum)
        {
            var student = this.dbContext
                .Students
                .Include(s => s.Subjects)
                .ThenInclude(ss => ss.Subject)
                .FirstOrDefault(s => s.FacNumber == facNum);

            return new StudentDetailsViewModel()
            {
                FirstName = student.FirstName,
                LastName = student.LastName,
                FacNumber = student.FacNumber,
                Course = student.Course,
                Scores = student.Subjects.ToDictionary(s => s.Subject.Name, x => x.Score)
            };
        }
    }
}
