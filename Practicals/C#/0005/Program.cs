using System;
using System.Runtime.ConstrainedExecution;
using Cars;
using Vehicles;

namespace Project_005
{
    internal class Program
    {
        static void Main(string[] args)
        {

            Car c1 = new Car();
            c1.drive();
            c1.convert();


            Console.ReadKey();
        }
    }
}
