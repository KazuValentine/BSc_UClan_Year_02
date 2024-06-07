using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Calculators.Implementation;

namespace Test
{
    public class Tests
    {
        private Calculator _calculator;
        [SetUp]
        public void Setup()
        {
            _calculator = new Calculator();
        }

        [Test]
        public void Should_ReturnAddedValue_When_TwoNumbersGiven()
        {
            //Arrange
            double num1 = 2; double num2 = 6;
            //Act
            var result = _calculator.AddTwoNumbers(num1, num2);
            //Assert
            Assert.That(result, Is.EqualTo(8));
        }
        public void Should_ReturnDividedValue_When_TwoNumbersGiven()
        {
            //Arrange
            double num1 = 2; double num2 = 0;
            //Act
            var result = _calculator.DivideTwoNumbers(num1, num2);
            //Assert
            Assert.That(result, Is.Empty);
        }
    }
}