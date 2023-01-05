#include <bits/stdc++.h>
using namespace std;
void maxRowColumnSum(int arr[][100], int m, int n){
    int maxSum1 = 0, maxSum2 = 0;
        for (int i = 0; i < m; i++)
        {
            int sum = 0;
            for(int j = 0; j < n; j++){
                sum+= arr[i][j];
            }
            maxSum1 = max(sum, maxSum1);
        }

        for (int j = 0; j < n; j++)
        {
            int sum = 0;
            for(int i = 0; i < m; i++){
                sum+= arr[i][j];
            }
            maxSum2 = max(sum, maxSum2);
        }

        if(maxSum1 >= maxSum2){
            cout<<"row: "<<maxSum1<<endl;
        }else{
            cout<<"column: "<<maxSum2<<endl;
        }
};

int main(){ 
    int t;
    cin>>t;
    while (t--)
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

        maxRowColumnSum(arr, m, n);
    }

    return 0;
}