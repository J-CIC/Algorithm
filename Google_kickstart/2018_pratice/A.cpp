#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> start;
	vector<int> end;
	for(int i=1;i<=n;i++){
		int bus_num;
		cin>>bus_num;
		start.resize(bus_num);
		end.resize(bus_num);
		for(int j=0;j<bus_num;j++){
			cin>>start[j];
			cin>>end[j];
		}
		sort(start.begin(),start.end());
		sort(end.begin(),end.end());
		int test_round;
		cin>>test_round;
		cout<<"Case #"<<i<<": ";
		while(test_round--){
			int city;
			cin>>city;
			int start_num = upper_bound(start.begin(),start.end(),city) - start.begin();
			int end_num = lower_bound(end.begin(),end.end(),city) - end.begin();
			int count = start_num - end_num;
			cout<<count<<" ";
		}
		cout<<endl;
	}
	return 0;
}