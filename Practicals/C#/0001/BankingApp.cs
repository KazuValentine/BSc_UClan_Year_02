using System;

namespace BankingApp
{
    public class CBankAccount
    {
        string mName = "";
        string mAccountNumber = "";
        double mAccountBalance = 0;

        public void SetName(string name)
        {
            mName = name;
        }
        public void SetAccNum(string accountNumber)
        {
            mAccountNumber = accountNumber;
        }
        public void SetAccBal(double accountBalance)
        {
            mAccountBalance = accountBalance;
        }
        public string GetName()
        {
            return mName;
        }
        public string GetAccNum()
        {
            return mAccountNumber;
        }
        public double GetAccBal()
        {
            return mAccountBalance;
        }
        public void Withdraw(double amount)
        {
            mAccountBalance -= amount;
        }
        public void Deposit(double ammount)
        {
            mAccountBalance += ammount;
        }
        public void PrintInfo()
        {
            Console.WriteLine($"Name: {mName}");
            Console.WriteLine($"Account Number: {mAccountNumber}");
            Console.WriteLine($"Account Balance: {mAccountBalance}");
        }
        public CBankAccount(string name, string accountNumber, double accountBalance)
        {
            mName = name;
            mAccountNumber = accountNumber;
            mAccountBalance = accountBalance;
        } 
    }
}