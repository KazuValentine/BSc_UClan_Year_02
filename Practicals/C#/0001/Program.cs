using BankingApp;
class Program
{
    static void Main()
    {
        CBankAccount acc1 = new("Kasun Dodanwala", "3000745", 123456.78);
        acc1.PrintInfo();
    }
}