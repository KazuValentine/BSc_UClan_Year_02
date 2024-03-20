using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SingletonSpace
{
    internal class Singleton
    {
        Singleton() { }
        private static Singleton _instance = null;
        int _count = 0;
        public void IncrementCount()
        { _count++; }
        public int GetCount() { return _count; }
        public static Singleton GetInstance()
        {
            if (_instance == null)
                _instance = new Singleton();
            return _instance;
        }
    }
}