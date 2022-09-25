namespace StudentSystem.App.Create
{
    using Services;
    using Services.Implementations;
    using System;
    using System.Collections.Generic;
    using System.Windows.Forms;

    public partial class AddScoreForm : Form
    {
        private string facNum;
        private IStudentService studentService;
        private ISubjectService subjectService;

        public AddScoreForm(string facNum)
        {
            this.facNum = facNum;
            this.studentService = new StudentService();
            this.subjectService = new SubjectService();
            InitializeComponent();
        }

        private void AddScoreForm_Load(object sender, EventArgs e)
        {
            label1.Text = "Subject:";
            label2.Text = "Score:";
            numericUpDown1.Minimum = 2;
            numericUpDown1.Maximum = 6;
            numericUpDown1.DecimalPlaces = 2;
            button1.Text = "Add Score";

            IEnumerable<string> subjectShortNames  = this.subjectService.AllShortNames();

            foreach (var shortName in subjectShortNames)
            {
                comboBox1.Items.Add(shortName);
            }
            comboBox1.SelectedIndex = 0;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string subjectShortName = comboBox1.SelectedItem.ToString();
            double score = (double)numericUpDown1.Value;

            this.studentService.AddStudentScore(this.facNum, subjectShortName, score);
            MessageBox.Show("Successfully created score for student!");
        }
    }
}
