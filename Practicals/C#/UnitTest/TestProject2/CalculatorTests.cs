using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using UnitTest.Implementation;

namespace TestProject2
{
    public class CalculatorTests
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
            double number = 2; double number2 = 6;
            //Act
            var result = _calculator.AddTwoNumbers(number, number2);
            //Assert
            Assert.That(result, Is.EqualTo(8));
        }
    }
}
