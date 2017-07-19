using System;

namespace TestCSharp
{
    interface Solution
    {
        void PrintResult();
    }
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            Solution test = new Palindrome();
            test.PrintResult();

            test = new WordBreak();
            test.PrintResult();
        }
    }
}
