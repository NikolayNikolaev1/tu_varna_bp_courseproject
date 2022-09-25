namespace StudentSystem.Data
{
    using Data.Models;
    using Microsoft.EntityFrameworkCore;

    public class StudentSystemDbContext : DbContext
    {
        public DbSet<Student> Students { get; set; }

        public DbSet<Subject> Subjects { get; set; }

        public DbSet<StudentSubject> StudentSubjects { get; set; }

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            optionsBuilder.UseSqlServer(@"Server=HP-ELITEBOOK\SQLEXPRESS;Database=StudentSystem;Integrated Security=True;");
            base.OnConfiguring(optionsBuilder);
        }

        protected override void OnModelCreating(ModelBuilder builder)
        {
            builder
                .Entity<StudentSubject>()
                .HasKey(ss => new { ss.StudentId, ss.SubjectId });

            builder
                .Entity<StudentSubject>()
                .HasOne(s => s.Subject)
                .WithMany(s => s.Students)
                .HasForeignKey(s => s.SubjectId)
                .OnDelete(DeleteBehavior.Restrict);

            builder
                .Entity<StudentSubject>()
                .HasOne(s => s.Student)
                .WithMany(s => s.Subjects)
                .HasForeignKey(s => s.StudentId)
                .OnDelete(DeleteBehavior.Restrict);

            builder
                .Entity<Student>()
                .HasIndex(s => s.FacNumber)
                .IsUnique();

            builder
                .Entity<Subject>()
                .HasIndex(s => s.Name)
                .IsUnique();

            builder
                .Entity<Subject>()
                .HasIndex(s => s.ShortName)
                .IsUnique();

            base.OnModelCreating(builder);
        }
    }
}
