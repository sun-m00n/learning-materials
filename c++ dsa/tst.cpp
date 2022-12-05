#include <iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int rows, columns;

    cout << "Rows : ";
    cin >> rows;
    cout << "\nColumns : ";
    cin >> columns;

    for (int i = rows - 1; i >= 0; i--)
    {
        cout << endl;
        for (int j = columns - 1; j >= 0; j--)
        {
            cout << "* ";
        }
    }

    return 0;
}
