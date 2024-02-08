using System;
using Vehicles;
using Interfaces;

namespace Cars
{
    public class Car : Vehicle, TestInterface
    {
        public override void drive()
        {
            Console.WriteLine("Im Driving a car");
        }
        public void convert()
        {
            Console.WriteLine("Convert the car");
        }
    }
}
