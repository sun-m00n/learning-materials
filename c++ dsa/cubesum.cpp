/**
--input
3
2
1 1
3
1 2 1
5
8 5 6 2 3

--output
10
128
42621

--hint
Test case 22: F(1, 1) = 1, F(1, 2) = 1+2=3, F(1, 3) = 1+2+1 =4, F(2, 2) = 2, F(2, 3) = 2+1=3, F(3, 3) = 1F(1,1)=1,F(1,2)=1+2=3,F(1,3)=1+2+1=4,F(2,2)=2,F(2,3)=2+1=3,F(3,3)=1.

Thus, \sum_{i=1}^{N} \sum_{j=i}^{N} F^3(i,j) = 1^3 + 3^3 + 4^3+2^3+3^3+1^3 = 128∑
i=1
N
​
 ∑
j=i
N
F3(i,j)=1+3+4+2+3+1=128.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= n; j++)
            {
                int sum = 0;
                for (int k = i; k < j; k++)
                    sum += a[k];
                ans += pow(sum, 3);
            }
        cout << ans << endl;
    }
    return 0;
}
