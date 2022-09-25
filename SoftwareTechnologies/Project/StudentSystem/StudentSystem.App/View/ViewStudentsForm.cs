namespace StudentSystem.App.View
{
    using Services;
    using Services.Implementations;
    using System;
    using System.Drawing;
    using System.Windows.Forms;

    public partial class ViewStudentsForm : Form
    {
        private string facNum;
        private IStudentService studentService;

        public ViewStudentsForm(string facNum)
        {
            this.facNum = facNum;
            this.studentService = new StudentService();
            InitializeComponent();
        }

        private void ViewStudentsForm_Load(object sender, EventArgs e)
        {
            var students = this.studentService.All();

            int counter = 0;

            //foreach (var student in students)
            //{
            //    Label label = new Label();
            //    label.Name = $"label{counter}";
            //    label.Text = student.FirstName;
            //    label.Location = new Point(100 + counter, 100 + counter);
            //    this.Controls.Add(label);

            //    counter++;
            //}

            dataGridView1.DataSource = students;
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
        }
    }
}
