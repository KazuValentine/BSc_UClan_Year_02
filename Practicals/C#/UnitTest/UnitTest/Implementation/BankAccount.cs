using UnitTest.Interface;
using System;
using Logging = Microsoft.Extensions.Logging;

namespace UnitTest.Implementation
{
    public class BankAccount
    {
        private readonly string accountOwner;
        private double accountBalance;
        private readonly ICalculator _calculator;
        private readonly ILogger _logger;

        public BankAccount(string accountOwner, double accountBalance, ICalculator calculator, ILogger logger)
        {
            this.accountOwner = accountOwner;
            this.accountBalance = accountBalance;
            _calculator = calculator;
            _logger = logger;
        }

        public double GetAccountBalance() { return accountBalance; }
        public string GetAccountOwner() { return accountOwner; }

        public void Deposit(double amount)
        {
            if(amount < 0)
                throw new Exception("Deposit amount is less than 0");

            accountBalance = _calculator.AddTwoNumbers(accountBalance, amount);
            _logger.Log(Logging.LogLevel.Information, $"Amount is deposited successfully to the customer: {accountOwner}");
        }

        public void Withdraw(double amount)
        {
            if (amount < 0)
                throw new Exception("Withdraw amount is less than 0");

            if (_calculator.SubtractTwoNimbers(accountBalance, amount) <= 0)
                throw new Exception("Deposit mount is less than 0");

            accountBalance = _calculator.SubtractTwoNimbers(accountBalance, amount);
            _logger.Log(Logging.LogLevel.Information, $"Amount is withdrawn successfully from the customer: {accountOwner}");
        }

        public void AddInterest(double interestPercentage)
        {
            try
            {
                var interest = _calculator.DivideTwoNumbers(_calculator.MultiplyTwoNumbers(accountBalance, interestPercentage), 100);
                accountBalance = _calculator.AddTwoNumbers(accountBalance, interest);
                _logger.Log(Logging.LogLevel.Information, $"Interest is added successfully to the customer: {accountOwner}");
            }
            catch
            {
                _logger.Log(Logging.LogLevel.Error, $"Error occurd while adding the interest to customer : {accountOwner}");
            }
        }
    }
}