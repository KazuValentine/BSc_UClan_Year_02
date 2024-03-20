using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using SingletonSpace;

namespace _0007___Singleton_Pattern
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Singleton s = Singleton.GetInstance();
            s.IncrementCount();
            s.IncrementCount();
            Console.WriteLine(s.GetCount().ToString());
            Singleton s2 = Singleton.GetInstance();
            Console.WriteLine(s2.GetCount().ToString());
            Console.ReadLine();
        }
    }
}
