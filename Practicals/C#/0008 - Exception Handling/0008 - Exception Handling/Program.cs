using System;

namespace ExceptionDemo
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int b = 10;
            int c = 0;
            int answer;
            try
            {
                Console.WriteLine("Before division by 0");
                answer = b / c;
                Console.WriteLine("After division by 0");
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
            }
            Console.ReadKey();
        }
    }
}