using System;

namespace TestCSharp
{
    class Palindrome : Solution
    {
        // Time: O(N^2), Space: O(1)
        public void PrintResult()
        {
            string testStr = "abcded";
            string resultStr = LongestPalindrome(testStr);
            if (!String.IsNullOrEmpty(resultStr))
            {
                Console.WriteLine(String.Format("The Longest Palindrome in '{0}' is '{1}'", testStr, resultStr));
            }
            CheckPalindrome("a");
            CheckPalindrome("aba");
            CheckPalindrome("abba");
        }

        // https://www.hackerearth.com/practice/algorithms/string-algorithm/string-searching/practice-problems/algorithm/palindrome-116/
        public bool CheckPalindrome(string s)
        {
            int end = s.Length - 1;
            int begin = 0;

            while (begin <= end && s[begin] == s[end])
            {
                begin ++;
                end --;
            }
            return (begin > end);
        }

        public string LongestPalindrome(string s)
        {
            if (String.IsNullOrEmpty(s))
            {
                return null;
            }

            if (s.Length == 1)
            {
                return s;
            }

            string longest = s.Substring(0, 1);

            for (int i=0; i < s.Length - 1; ++i)
            {
                // // get longest palindrome with center of i
                string tmp = PalindromeHelper(s, i, i);
                if (tmp.Length > longest.Length)
                {
                    longest = tmp;
                }

                // get longest palindrome with center of i, i+1
                tmp = PalindromeHelper(s, i, i + 1);
                if (tmp.Length > longest.Length)
                {
                    longest = tmp;
                }

            }

            return longest;
        }

        public string PalindromeHelper(string s, int begin, int end)
        {
            while (begin >= 0 && end < s.Length && s.Substring(begin, 1) == s.Substring(end, 1))
            {
                begin--;
                end++;
            }
            int len = end - begin - 1;
            return s.Substring(begin + 1, len);
        }

        public int LongestPalindromeSubseqHelper(int[][] mem, string s, int left, int right)
        {
            int di = s.Length;
            foreach (char ch in s)
            {
                while (left < di)
                {
                    if (s[left] == ch)
                    {
                        break;
                    }
                    left++;
                }
                while (right > 0)
                {
                    if (s[right - 1] == ch)
                    {
                        break;
                    }
                    right--;
                }

                mem[left, right-1] = (left == (right - 1)) ? 1 : 2 + LongestPalindromeSubseqHelper(mem, s, left + 1, right - 1);
            }
            return mem[]
        }
    }
}