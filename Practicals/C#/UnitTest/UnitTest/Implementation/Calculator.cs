using System;
using UnitTest.Interface;

namespace UnitTest.Implementation
{
    public class Calculator
    {
        public double AddTwoNumbers(double number1, double number2) { return number1 + number2; }

        public double SubtractTwoNimbers(double number1, double number2) { return number1 - number2; }

        public double MultiplyTwoNumbers(double number1, double number2) { return number1 * number2; }

        public double DivideTwoNumbers(double number1, double number2) 
        {
            if (number1 == 0 || number2 == 0)
                throw new Exception("Number can not be 0");
            return number1 / number2; 
        }
    }
}