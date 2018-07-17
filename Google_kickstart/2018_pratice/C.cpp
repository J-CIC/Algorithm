#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int case_num=1;case_num<=n;case_num++){
		int ticket_num;
		cin>>ticket_num;
		map<string,string> ticket;
		map<string,int> city_show_count;
		for(int i=0;i<ticket_num;i++){
			string start,end;
			cin>>start>>end;
			ticket.insert({start,end});
			if(city_show_count.find(start)==city_show_count.end()){
				city_show_count.insert({start,1});
			}else{
				city_show_count[start] += 1;
			}
			if(city_show_count.find(end)==city_show_count.end()){
				city_show_count.insert({end,1});
			}else{
				city_show_count[end] += 1;
			}
		}
		cout<<"Case #"<<case_num<<": ";
		string ans_start,ans_end;
		for(const auto &item:city_show_count){
			if(item.second==1){
				if(ticket.find(item.first)!=ticket.end()){
					ans_start = item.first;
				}else{
					ans_end = item.second;
				}
			}
		}
		for(int i=0;i<ticket_num;i++){
			cout<<ans_start<<"-"<<ticket[ans_start]<<" ";
			ans_start = ticket[ans_start];
		}
		cout<<endl;
	}
	return 0;
}