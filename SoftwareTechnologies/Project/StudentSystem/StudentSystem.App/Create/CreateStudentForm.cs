namespace StudentSystem.App.Create
{
    using Services;
    using Services.Implementations;
    using System;
    using System.Windows.Forms;

    public partial class CreateStudentForm : Form
    {
        private IStudentService studentService;

        public CreateStudentForm()
        {
            this.studentService = new StudentService();
            InitializeComponent();
        }

        private void CreateStudentForm_Load(object sender, EventArgs e)
        {
            label1.Text = "Register new student";
            label2.Text = "First Name:";
            label3.Text = "Last Name:";
            label4.Text = "Fac Number:";
            label5.Text = "Course:";
            button1.Text = "Create";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string firstName = textBox1.Text;
            string lastName= textBox2.Text;
            string facNumber = textBox3.Text;


            if (string.IsNullOrEmpty(firstName)
                || string.IsNullOrEmpty(lastName)
                || string.IsNullOrEmpty(facNumber)
                || string.IsNullOrEmpty(textBox4.Text))
            {
                MessageBox.Show("Student first name, last name, fac number and course can not be empty.");
                return;
            }

            int course = int.Parse(textBox4.Text);

            if (facNumber.Length != 8)
            {
                MessageBox.Show("Student fac number must be 8 characters long.");
                return;
            }

            if (this.studentService.FacNumberExists(facNumber))
            {
                MessageBox.Show($"Student with fac number {facNumber} already exists.");
                return;
            }

            if (course < 1 || course > 6)
            {
                MessageBox.Show("Student course must be between 1 and 6.");
                return;
            }

            this.studentService.Create(firstName, lastName, facNumber, course);
            MessageBox.Show("Successfully created student!");
        }
    }
}
