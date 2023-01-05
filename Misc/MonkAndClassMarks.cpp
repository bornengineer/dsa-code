// #include <bits/stdc++.h>
// using namespace std;
// int main() {
// 	map<int, multiset<string>> m;
// 	int n;
// 	cin>> n;
// 	for(int i = 0 ; i<n ; ++i){
// 		string name;
// 		int marks;
// 		cin>> name >> marks;
// 		m[marks].insert(name);
// 	}
// 	auto it = (--m.end());
// 	while(true){
// 		auto &students = (*it).second;
// 		int marks = (*it).first;
// 		for(auto student : students){
// 			cout<< student <<" "<< marks<<endl;
// 		}
// 		if(it == m.begin())break;
// 		it--;
// 	}
// }

// shorter version without iterators
#include <bits/stdc++.h>
using namespace std;
int main() {
	map<int, multiset<string>> m;
	int n;
	cin>> n;
	for(int i = 0 ; i<n ; ++i){
		string name;
		int marks;
		cin>> name >> marks;
		m[-1 * marks].insert(name);
	}
	for(auto &marks_students_pr : m){
		auto &students = marks_students_pr.second;
		int marks = marks_students_pr.first;
		for(auto student : students){
			cout<< student <<" "<<-1 * marks<<endl;
		}
	}
}