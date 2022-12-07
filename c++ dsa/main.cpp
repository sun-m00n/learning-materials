#include <iostream>
using namespace std;

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    // int row, col;
    // cin >> row >> col;
    int n;
    cin >> n;
    // Pattern_Zigzag(n);
    // invertedHalfPrimaid(n);
    return 0;
}

void Pattern_Rectangle(int row, int col)
{
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
            cout << "* ";
        cout << endl;
    }
}
void Pattern_Hollow_Rectangle(int row, int col)
{
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            if (i == 1 || j == 1 || i == row || j == col)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}
void Pattern_Inverted_Half_Prymaid(int n)
{
    for (int i = n; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
            cout << "* ";
        cout << endl;
    }
}
void Pattern_Half_Prymaid_After_180(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            if (j <= n - i)
                cout << "  ";
            else
                cout << "* ";
        cout << endl;
    }
}
void Pattern_Half_Prymaid_Number(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << i;
        cout << endl;
    }
}
void Pattern_Floyds_Trianle(int n)
{
    int num = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
}
void Pattern_Butterfly(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << "* ";
        int space = 2 * n - 2 * i;
        for (int j = 1; j <= space; j++)
            cout << "  ";
        for (int j = 1; j <= i; j++)
            cout << "* ";
        cout << endl;
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
            cout << "* ";
        int space = 2 * n - 2 * i;
        for (int j = 1; j <= space; j++)
            cout << "  ";
        for (int j = 1; j <= i; j++)
            cout << "* ";
        cout << endl;
    }
}
void Pattern_Inverted(int n)
{
    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= n + 1 - row; col++)
            cout << col << " ";
        cout << endl;
    }
}
void Pattern_0_1(int n)
{
    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= row; col++)
            if ((col + row) % 2 == 0)
                cout << 1 << " ";
            else
                cout << 0 << " ";
        cout << endl;
    }
}
void Pattern_Rhombus(int n)
{
    for (int row = 1; row <= n; row++)
    {
        for (int j = 1; j <= n - row; j++)
            cout << "  ";
        for (int j = 1; j <= n; j++)
            cout << "* ";
        cout << endl;
    }
}
void Pattern_Number(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
            cout << " ";
        for (int j = 1; j <= i; j++)
            cout << j << " ";
        cout << endl;
    }
}
void Pattern_Palindromic(int n)
{
    for (int i = 1; i <= n; i++)
    {
        int j;
        for (j = 1; j <= n - i; j++)
            cout << "  ";
        int k = i;
        for (; j <= n; j++)
            cout << k-- << " ";
        k = 2;
        for (; j <= n + i - 1; j++)
            cout << k++ << " ";
        cout << endl;
    }
}
void Pattern_Star(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
            cout << "  ";
        for (int j = 1; j <= 2 * i - 1; j++)
            cout << "* ";
        cout << endl;
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n - i; j++)
            cout << "  ";
        for (int j = 1; j <= 2 * i - 1; j++)
            cout << "* ";
        cout << endl;
    }
}
void Pattern_Zigzag(int n)
{
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= n; j++)
            if (((i + j) % 4 == 0) || (i == 2 && j % 4 == 0))
                cout << "* ";
            else
                cout << "  ";
        cout << endl;
    }
}
