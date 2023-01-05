#include<iostream>
using namespace std;
void wavePrint(int arr[][100], int m, int n){
    int i = 0, j, cnt = 0;
    while(cnt<n){
        if(cnt%2==0){
            for(j=0; j<m; j++){
                cout << arr[j][i]<<" ";
            }
        }else{
            for(j=m-1; j>=0; j--){
                cout << arr[j][i]<<" ";
            }
        }
        cnt++;
        i++;
    }
}

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

        wavePrint(arr, m, n);
    }

    return 0;
}