namespace StudentSystem.Services.Implementations
{
    using Data;
    using Data.Models;
    using System.Collections.Generic;
    using System.Linq;

    public class SubjectService : ISubjectService
    {
        private StudentSystemDbContext dbContext;

        public SubjectService()
        {
            this.dbContext = new StudentSystemDbContext();
        }

        public IEnumerable<string> AllShortNames()
            => this.dbContext
            .Subjects
            .Select(s => s.ShortName)
            .ToList();

        public void Create(string name, string shortName)
        {
            dbContext.Subjects.Add(new Subject
            {
                Name = name,
                ShortName = shortName
            });

            dbContext.SaveChanges();
        }

        public bool NameExists(string name)
            => this.dbContext
            .Subjects
            .Any(s => s.Name == name);

        public bool ShortNameExists(string shortName)
            => this.dbContext
            .Subjects
            .Any(s => s.ShortName == shortName);
    }
}
