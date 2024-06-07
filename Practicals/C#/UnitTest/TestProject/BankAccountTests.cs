using NSubstitute;
using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using UnitTest.Implementation;
using UnitTest.Interface;

namespace TestProject
{
    public class BankAccountTests
    {
        private BankAccount _bankAccount;
        private ICalculator _calculator;
        private ILogger _logger;

        [SetUp]
        public void Setup()
        {
            _calculator = Substitute.For<ICalculator>();
             _logger = Substitute.For<ILogger>();
            _bankAccount = new BankAccount("TestOwnor", 200, _calculator, _logger);
        }

        [Test]
        public void Should_AddAmountToAccountBalance_When_AmountGiven()
        {
            //Arrange
            _calculator.AddTwoNumbers(200, 5).Returns(205);
            var preBalance = _bankAccount.GetAccountBalance();

            //Act
            _bankAccount.Deposit(5);
            var afterBalance = _bankAccount.GetAccountBalance();

            //Assert
            Assert.True(preBalance < afterBalance);
            Assert.That(afterBalance, Is.EqualTo(205));
        }

        [Test]
        public void Should_ThrowException_When_AmountIsZero()
        {
            //Arrange 
            //Act 
            //Assert
            Assert.Throws<Exception>(() => _bankAccount.Deposit(-1));
        }

        [Test] public void Should_AddIntrestToTheBankBalance_When_IntorestProcentGiven() {
            //Arrange
            double interestPercent = 5; 
            var proBalance = _bankAccount.GetAccountBalance(); 
            _calculator.MultiplyTwoNumbers(200, 5).Returns(1000); 
            _calculator.DivideTwoNumbers(1000, 100).Returns(10); 
            _calculator.AddTwoNumbers(200, 10).Returns(250);

            //Act
            _bankAccount.AddInterest(interestPercent); 
            var afterBalance = _bankAccount.GetAccountBalance();

            //Assert
            Assert.That(afterBalance, Is.EqualTo(250)); 
        }
        [Test]
        public void Should_LogError_When_ExceptionOccured()
        {
            //Arrange
            _calculator.When(_ => _.MultiplyTwoNumbers(208, 5)).Do(_ => throw new Exception());
            //Act
            _bankAccount.AddInterest(5);
            //Assert
            _logger.Received().Log(Arg.Any<Microsoft.Extensions.Logging.LogLevel>(), Arg.Any<string>());
        }

    }
}
