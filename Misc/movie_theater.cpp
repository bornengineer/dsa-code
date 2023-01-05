/* Read input from STDIN. Print your output to STDOUT*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //Write code here
    long long s;
    int t, q;
    cin>>s>>t>>q;


    vector<int> occ;
    for(int i=0; i<t; i++){
        int temp;
        cin>>temp;
        occ.push_back(temp);
    }

    vector<int> fav;
    for(int i=0; i<q; i++){
        int temp;
        cin>>temp;
        fav.push_back(temp);
    }

    map<int, int> mp;
    for(int i=1, j = 0; i<=s; i++){
        if(i == occ[j]){
            mp[i] = 0;
            j++;
        }
        else mp[i] = 1;
    }

    for(int j = 0; j<q; j++){
        if(mp[fav[j]] == 0){
            cout<<"N"<<endl;
        }
        else cout<<"Y"<<endl;
    }

    // for(auto i : mp){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }

    int i = 0;
    int j = 0;

    // while(j < fav.size()){
    //     if(occ[i] == fav[j]){
    //         cout<<"N"<<endl;
    //         i++;
    //         j++;
    //     }
    //     else if(occ[i] != fav[j] && fav[j] > occ[i]){
    //         i++;
    //     }
    //     else if(occ[i] != fav[j] && fav[j]<occ[i]){
    //         cout<<"Y"<<endl;
    //         j++;
    //     }
    // }
}
