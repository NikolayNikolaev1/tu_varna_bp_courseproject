namespace StudentSystem.App.View
{
    using Services;
    using Services.Implementations;
    using System;
    using System.Data;
    using System.Linq;
    using System.Windows.Forms;
    public partial class ViewStudentDetailsForm : Form
    {

        private string facNum;
        private IStudentService studentService;

        public ViewStudentDetailsForm(string facNum)
        {
            this.facNum = facNum;
            this.studentService = new StudentService();
            InitializeComponent();
        }
        public ViewStudentDetailsForm()
        {
            InitializeComponent();
        }

        private void ViewStudentDetailsForm_Load(object sender, EventArgs e)
        {
            label1.Text = "First Name:";
            label3.Text = "Last Name:";
            label5.Text = "Fac Num:";
            label7.Text = "Course:";

            var student = this.studentService.GetByFacNum(facNum);

            label2.Text = student.FirstName;
            label4.Text = student.LastName;
            label6.Text = student.FacNumber;
            label8.Text = student.Course.ToString();

            DataTable dt = new DataTable();
            dt.Columns.Add("Subject", typeof(string));
            dt.Columns.Add("Score", typeof(string));

            student.Scores
                .ToList()
                .ForEach(kvp => dt.Rows.Add(new object[] { kvp.Key, kvp.Value }));

            dt.Constraints.Add("keyconstraint", dt.Columns[0], true);
            dataGridView1.DataSource = dt;
        }
    }
}
