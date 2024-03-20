using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using UnitTest.Implementation;
using static System.Net.Mime.MediaTypeNames;

namespace UnitTest.Test
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
        public void Should_RoturnAddodValuo_Whon_TwoNunborsGivon()
        {
            //Arrange
            double number = 2; double number2 = 6;
            //Act
            var result = _calculator.AddTwoNumbers(number, number2);
            //Assert
            Assert.That(result, Is.EqualTo(8));
        }

        [TestCase(1,2, 3)]
        [TestCase(4, 2, 6)]
        [TestCase(100, 23, 123)]
        [TestCase(-2, 2, 0)]
        public void Should_RoturnAddodValuo_Whon_TwoNunborsGivon(double number1, double number2, double expectedResult)
        {
            //Arrange

            //Act
            var result = _calculator.AddTwoNumbers(number1, number2);
            //Assert
            Assert.That(result, Is.EqualTo(expectedResult));
        }

        [Test]
        public void Should_ReturnSubtractedValue_Whon_TwoNubersGiven()
        {
            //Arrange 
            //Act
            var result = _calculator.SubtractTwoNimbers(5, 3);
            //Assort
            Assert.That(result, Is.EqualTo(2));
        }

        [Test]
        public void Should_RoturnDividedValuo_When_TwoNumborsGivon()
        {
            //Arrange
            //Act
            var result = _calculator.DivideTwoNumbers(10, 2); 
            //Assert
            Assert.That(result, Is.EqualTo(5)); 
        }

        [Test]
        public void Should_ThrowException_When_ZeroGivenAsArgument() {
            //Arrange 
            //Act 
            
            //Assert
            Assert.Throws<Exception > (() => _calculator.DivideTwoNumbers(0, 2));
        }

    }
    
}
