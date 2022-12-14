// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Dp table to store the sub-problems
int dp[20][20][20][20];

// Function to find the maximum XOR
// value after rearranging the digits
int maxXorValue(int i, string &s1,
                string &s2, string &s3,
                int ones1, int ones2,
                int ones3, int n)
{
    // Base Case
    if (i >= n)
        return 0;

    // Return if already calculated
    if (dp[i][ones1][ones2][ones3] != -1)
        return dp[i][ones1][ones2][ones3];

    int option1 = 0, option2 = 0,
        option3 = 0, option4 = 0,
        option5 = 0, option6 = 0,
        option7 = 0, option8 = 0;

    // Assigning 1's to all string at
    // position 'i'.
    if (ones1 > 0 && ones2 > 0 && ones3 > 0)

        // 2^(n-1-i) is the value
        // added to the total
        option1 = (1 << ((n - 1) - i)) + maxXorValue(i + 1, s1,
                                                     s2, s3, ones1 - 1,
                                                     ones2 - 1,
                                                     ones3 - 1, n);

    // Assigning 1's to strings 1 & 2
    if (ones1 > 0 && ones2 > 0 && (n - i > ones3))
        option2 = 0 + maxXorValue(i + 1, s1,
                                  s2, s3, ones1 - 1,
                                  ones2 - 1,
                                  ones3, n);

    // Assigning 1's to strings 2 & 3
    if (ones2 > 0 && ones3 > 0 && (n - i > ones1))
        option3 = 0 + maxXorValue(i + 1, s1,
                                  s2, s3,
                                  ones1,
                                  ones2 - 1,
                                  ones3 - 1, n);

    // Assigning 1's to strings 3 & 1
    if (ones3 > 0 && ones1 > 0 && (n - i > ones2))
        option4 = 0 + maxXorValue(i + 1, s1,
                                  s2, s3,
                                  ones1 - 1,
                                  ones2,
                                  ones3 - 1, n);

    // Assigning 1 to string 1
    if (ones1 > 0 && (n - i > ones2) && (n - i > ones3))
        option5 = (1 << ((n - 1) - i)) + maxXorValue(i + 1, s1,
                                                     s2, s3,
                                                     ones1 - 1,
                                                     ones2,
                                                     ones3, n);

    // Assigning 1 to string 2
    if (ones2 > 0 && (n - i > ones3) && (n - i > ones1))
        option6 = (1 << ((n - 1) - i)) + maxXorValue(i + 1, s1,
                                                     s2, s3, ones1,
                                                     ones2 - 1,
                                                     ones3, n);

    // Assigning 1 to string 3.
    if (ones3 > 0 && (n - i > ones2) && (n - i > ones1))
        option7 = (1 << ((n - 1) - i)) + maxXorValue(i + 1, s1,
                                                     s2, s3, ones1,
                                                     ones2,
                                                     ones3 - 1, n);

    // Assigning 0 to all the strings
    if ((n - i > ones2) && (n - i > ones3) && (n - i > ones1))
        option8 = 0 + maxXorValue(i + 1, s1,
                                  s2, s3,
                                  ones1,
                                  ones2,
                                  ones3, n);

    // Take the maximum amongst all of
    // the above solutions
    int decimal = dp[i][ones1][ones2][ones3] = max(option1,
                                                   max(option2,
                                                       max(option3,
                                                           max(option4,
                                                               max(option5,
                                                                   max(option6,
                                                                       max(option7,
                                                                           option8)))))));

    int x = 1, ans = 0;
    while (x <= decimal)
        x *= 2;
    x /= 2;
    while (x > 0)
    {
        int lastdigit = decimal / x;
        decimal -= lastdigit * x;
        x /= 2;
        ans = ans * 10 + lastdigit;
    }
    return ans;
    // return decimalToBinary(decimal);
}

// Function to get the count of ones
// in the string s
int onesCount(string &s)
{
    int count = 0;

    // Traverse the string
    for (auto x : s)
    {
        if (x == '1')
            ++count;
    }

    // Return the count
    return count;
}

// Utility Function to find the maximum
// XOR value after rearranging the digits
void maxXORUtil(string s1, string s2,
                string s3, int n)
{

    // Find the count of ones in
    // each of the strings
    int ones1 = onesCount(s1);
    int ones2 = onesCount(s2);
    int ones3 = onesCount(s3);

    // Initialize dp table with -1
    memset(dp, -1, sizeof dp);

    // Function Call
    cout << maxXorValue(0, s1, s2, s3,
                        ones1, ones2,
                        ones3, n);
}

int decimalToBinary(int n)
{
    int x = 1, ans = 0;
    while (x <= n)
        x *= 2;
    x /= 2;
    while (x > 0)
    {
        int lastdigit = n / x;
        n -= lastdigit * x;
        x /= 2;
        ans = ans * 10 + lastdigit;
    }
    return ans;
}

// Driver code
int main()
{
    string s1 = "11110";
    string s2 = "10101";
    string s3 = "00111";

    int n = s1.size();

    // Function Call
    maxXORUtil(s1, s2, s3, n);

    return 0;
}
