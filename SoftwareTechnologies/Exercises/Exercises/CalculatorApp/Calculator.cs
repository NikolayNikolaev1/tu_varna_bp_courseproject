using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CalculatorApp
{
    public class Calculator
    {
        private double firstNum;
        private double secondNum;
        private string operation;
        private double result;

        public Calculator(double firstNum, double secondNum, string operation)
        {
            this.firstNum = firstNum;
            this.secondNum = secondNum;
            this.operation = operation;
        }

        public double Calculate()
        {
            switch (this.operation)
            {
                case "+":
                    this.result = (this.firstNum + this.secondNum);
                    break;
                case "-":
                    this.result = (this.firstNum - this.secondNum);
                    break;
                case "*":
                    this.result = (this.firstNum * this.secondNum);
                    break;
                case "/":
                    this.result = (this.firstNum / this.secondNum);
                    break;
            }

            return this.result;
        }
    }
}
