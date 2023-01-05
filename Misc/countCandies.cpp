#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>> t;
	while(t--){
		multiset<long long> s;
		int n;
		int k;
		cin >> n>> k;
		for(int i = 0 ; i<n; ++i){
			long long x;
			cin >> x;
			s.insert(x);
		}
		long long totalCandies = 0;
		for(int i = 0 ; i<k; ++i){
			auto it = (--s.end());
			int candy_ct = *it;
			totalCandies += candy_ct;
			s.erase(it);
			s.insert(candy_ct / 2);
		}
		cout<<totalCandies<<endl;
	}
}