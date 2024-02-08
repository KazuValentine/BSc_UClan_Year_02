using Cars;
using Vehicles;
using Aeroplanes;
class Program
{
    static void Main()
    {
        Vehicle v2 = new Car();
        v2.Drive();
        Vehicle v3 = new Aeroplane();
        v3.Drive();

    }
}