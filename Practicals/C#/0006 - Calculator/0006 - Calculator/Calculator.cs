using System;
using Calculators;

namespace Calculators.Implementation
{
    public class Calculator : ICalculator
    {
        public double AddTwoNumbers(double num1, double num2) { return num1 + num2; }
        public double SubtractTwoNumbers(double num1, double num2) { return num1 - num2; }
        public double MultiplyTwoNumbers(double num1, double num2) { return num1 * num2; }
        public double DivideTwoNumbers(double num1, double num2)
        {
            if( num2 == 0 )
            {
                throw new Exception("Cannot divide by 0");
            }
            return num1 / num2;
        }

    }
}
