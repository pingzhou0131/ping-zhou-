#include <iostream>
#include <set>
#include <map>
using namespace std;
set<string>a;
map<string, int>b;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		a.insert(s);     
	}
	int m;
	cin >> m;
	int sum=0;
	double avg;
	for (int i = 0; i < m; i++) {
		string s;
		int num;
		cin >> s >> num;
		sum += num;
		if (a.find(s) == a.end()) {
			 b.insert(map<string,int>::value_type(s,num));
		}
	}
	avg = (double)sum / m;
	int flag = 0;
	map<string, int>::iterator it;
	for (it = b.begin(); it != b.end(); it++) {
		if ((double)it->second > avg) {
			cout << it->first << endl;
			flag = 1;
		}
	}
	if (flag == 0) cout << "Bing Mei You";
	return 0;
}
