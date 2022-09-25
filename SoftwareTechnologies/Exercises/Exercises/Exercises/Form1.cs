using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Exercises
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Click!");
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.BackColor = Color.Red;
            ChangeFormColor(sender, e);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            this.BackColor = Color.Blue;
            ChangeFormColor(sender, e);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.BackColor = Color.Black;
            label1.Text = "Click buttons to see how they work!";
            label1.Font = new Font("Arial", 14);
            label1.ForeColor = Color.White;
            button4.Text = "+";
            button5.Text = "-";
            button6.Text = "*";
            button7.Text = "/";

        }

        private void ChangeFormColor(object sender, EventArgs e)
        {
            if (sender is Button)
            {
                this.BackColor = (sender as Button).BackColor;
                this.Text = sender.ToString();
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            double a, b;
            try
            {
                a = double.Parse(textBox1.Text);
                b = double.Parse(textBox2.Text);

                Calculator calc = new Calculator(a, b, button4.Text);
                textBox3.Text = calc.Calculate().ToString();
            }
            catch
            {
                MessageBox.Show("Enter valid numbers");
                textBox1.Clear();
                textBox2.Clear();
                textBox3.Clear();
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            double a, b;
            try
            {
                a = double.Parse(textBox1.Text);
                b = double.Parse(textBox2.Text);

                Calculator calc = new Calculator(a, b, button5.Text);
                textBox3.Text = calc.Calculate().ToString();
            }
            catch
            {
                MessageBox.Show("Enter valid numbers");
                textBox1.Clear();
                textBox2.Clear();
                textBox3.Clear();
            }
        }

        private void button6_Click(object sender, EventArgs e)
        {
            double a, b;
            try
            {
                a = double.Parse(textBox1.Text);
                b = double.Parse(textBox2.Text);

                Calculator calc = new Calculator(a, b, button6.Text);
                textBox3.Text = calc.Calculate().ToString();
            }
            catch
            {
                MessageBox.Show("Enter valid numbers");
                textBox1.Clear();
                textBox2.Clear();
                textBox3.Clear();
            }
        }

        private void button7_Click(object sender, EventArgs e)
        {
            double a, b;
            try
            {
                a = double.Parse(textBox1.Text);
                b = double.Parse(textBox2.Text);

                Calculator calc = new Calculator(a, b, button7.Text);
                textBox3.Text = calc.Calculate().ToString();
            }
            catch
            {
                MessageBox.Show("Enter valid numbers");
                textBox1.Clear();
                textBox2.Clear();
                textBox3.Clear();
            }
        }
    }
}
