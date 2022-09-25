namespace StudentSystem.App
{
    using Create;
    using Data;
    using Services;
    using Services.Implementations;
    using System;
    using System.Windows.Forms;
    using View;

    public partial class MainForm : Form
    {
        private StudentSystemDbContext dbContext;
        private IStudentService studentService;

        public MainForm()
        {
            this.studentService = new StudentService();
            InitializeComponent();
        }

        private void Main_Load(object sender, EventArgs e)
        {
            this.dbContext = new StudentSystemDbContext();
            this.dbContext.Database.EnsureCreated();

            button1.Text = "Create new subject";
            button2.Text = "Create new student";
            button3.Text = "Search student by FAC";
            button4.Text = "Add score to student by FAC";
            label1.Text = "Student fac number:";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form form = new CreateSubjectForm();
            form.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form form = new CreateStudentForm();
            form.Show();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            string facNum = textBox1.Text;

            if (!this.studentService.FacNumberExists(facNum))
            {
                MessageBox.Show($"Student with fac number {facNum} does not exist.");
                return;
            }

            Form form = new ViewStudentDetailsForm(facNum);
            form.Show();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            string facNum = textBox1.Text;

            if (!this.studentService.FacNumberExists(facNum))
            {
                MessageBox.Show($"Student with fac number {facNum} does not exist.");
                return;
            }

            Form form = new AddScoreForm(facNum);
            form.Show();
        }
    }
}
