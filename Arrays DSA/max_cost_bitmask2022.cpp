// #include <bits/stdc++.h>
// using namespace std;


// int main() {
//     int t;
//     cin>>t;
//     while(t--){
//         long SIZE = 10E9;
//         long long int N;
//         cin>> N;
//         long long int arr[SIZE];
//         for(int i = 0; i<N ; i++){
//             cin>>arr[i];
//         }
//         sort(arr, arr+N);
//         int max = INT_MIN;
//         do{
//             // cout<<"array:"<<endl;
//             // for(int i = 0; i<N ; i++){
//             // cout<<arr[i]<<" ";
//             // }
//             // cout<<endl;
//             int ans = arr[0];
//             for(int i = 1; i<N; i++){
//                 ans = ans % arr[i];
//             }
//             if(max <= ans){max=ans;}
//         }while(std::next_permutation(arr, arr+N));
        
//         std::cout<<max;
//     }
//     return 0;
// }

// this one's easy and pass all the test cases
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int a[N];
        for (int i = 0; i < N; i++)
        {
            cin>>a[i];
        }
        sort(a,a+N);
        int first = a[0];
        int last = a[N-1];
        cout<<first%last<<endl;

    }
    return 0;
}

