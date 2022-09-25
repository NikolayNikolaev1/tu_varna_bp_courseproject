namespace StudentSystem.Services
{
    using System.Collections.Generic;

    public interface ISubjectService
    {
        IEnumerable<string> AllShortNames();

        void Create(string name, string shortName);

        bool NameExists(string name);

        bool ShortNameExists(string shortName);
    }
}
