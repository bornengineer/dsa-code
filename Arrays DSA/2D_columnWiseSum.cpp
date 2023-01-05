#include <iostream>
using namespace std;

int main()
{
    int arr[100][100];
    int m, n;
    cout << "Enter no. of rows 'm' and no. of columns 'n':" << endl;
    cin >> m >> n;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << endl;

    cout << "Row-wise: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Column-wise: " << endl;
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Column-wise sum: " << endl;
    for (int j = 0; j < n; j++)
    {
        int sum = 0;
        for (int i = 0; i < m; i++)
        {
            sum += arr[i][j];
        }
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}