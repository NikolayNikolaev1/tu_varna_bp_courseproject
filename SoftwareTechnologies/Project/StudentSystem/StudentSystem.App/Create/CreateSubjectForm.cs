namespace StudentSystem.App.Create
{
    using Services;
    using Services.Implementations;
    using System;
    using System.Windows.Forms;

    public partial class CreateSubjectForm : Form
    {
        private ISubjectService subjectService;

        private void CreateSubjectForm_Load(object sender, EventArgs e)
        {
            label1.Text = "Create new subject";
            label2.Text = "Subject Name:";
            label3.Text = "Short Name:";
            button1.Text = "Create";
        }
        public CreateSubjectForm()
        {
            this.subjectService = new SubjectService();
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string name = textBox1.Text;
            string shortName = textBox2.Text;

            if (string.IsNullOrEmpty(name) || string.IsNullOrEmpty(shortName))
            {
                MessageBox.Show("Subject name and short name can not be empty.");
                return;
            }

            if (this.subjectService.NameExists(name))
            {

                MessageBox.Show($"Subject with name {name} already exists.");
                return;
            }

            if (this.subjectService.ShortNameExists(shortName))
            {

                MessageBox.Show($"Subject with short name {shortName} already exists.");
                return;
            }

            this.subjectService.Create(name, shortName);
            MessageBox.Show("Successfully created subject!");
        }
    }
}
