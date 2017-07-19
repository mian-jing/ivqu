using System;
using System.Collections.Generic;

namespace TestCSharp
{
    class WordBreak : Solution
    {
        // Time: O(N^2), Space: O(1)
        public void PrintResult()
        {
            List<string> testList = new List<string>();
            testList.Add("Let");
            testList.Add("Lets");
            testList.Add("Code");
            string testStr = "LetsCode";
            if (HasWordBreak(testStr, testList))
            {
                Console.WriteLine(String.Format("Has word break"));
            }
        }

        public bool HasWordBreak(String s, List<string> dict)
        {
            bool[] t = new bool[s.Length + 1];
            t[0] =  true;
            for (int i=0; i<s.Length; ++i)
            {
                if (!t[i])
                {
                    continue;
                }
                foreach (string a in dict)
                {
                    if (a.Length > (s.Length - i))
                    {
                        continue;
                    }

                    int end = i + a.Length;
                    if (s.Substring(i, a.Length) == a)
                    {
                        t[end] = true;
                        if (end == s.Length)
                        {
                            break;
                        }
                    }
                }
            }
            return t[s.Length];
        }
    }
}