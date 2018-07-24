#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int round;
	cin>>round;
	for(int case_num=0;case_num<round;case_num++){
		int n,k;
		cin>>n>>k;
		vector<double> arr(n);
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		sort(arr.begin(),arr.end());
		double e=accumulate(arr.begin(),arr.end(),0.0)/n;
		for(int i=0;i<k;i++){
			int idx = upper_bound(arr.begin(),arr.end(),e)-arr.begin();
			double before = e*idx/n;
			double after = accumulate(arr.begin()+idx,arr.end(),0.0)/n;
			e = before + after ;
		}
		printf("Case #%d: %.6f\n",case_num+1,e);
	}

}