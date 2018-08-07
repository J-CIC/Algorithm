### 网易笔试题
题目地址
https://www.nowcoder.com/test/11647029/summary

#### A
```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int n;
	cin>>n;
	string input;
	while(n--){
		cin>>input;
		string hour = input.substr(0,2);
		string minute = input.substr(3,2);
		string second = input.substr(6,2);
		if(stoi(hour)>24){
			hour[0] = '0';
		}
		if(stoi(minute)>59){
			minute[0] = '0';
		}
		if(stoi(second)>59){
			second[0] = '0';
		}
		//like 24:01:01
		if(stoi(hour)==24&&(stoi(minute)>0||stoi(second)>0)){
			hour[0] = '0';
		}
		cout<<hour<<":"<<minute<<":"<<second<<endl;
	}
	return 0;
} 
```

#### B
思路：维护链表来解决
```cpp
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct node{
	int value;
	node *next;
};
void insert(node *head,int value){
	node *curr = head;
	node *temp = new node();
	temp->value = value;
	while(curr->next!=NULL){
		//notice the 
		if(curr->next->value==value){
			node *for_delete = curr->next;
			curr->next = curr->next->next;
			delete for_delete;
			break;
		}
		curr = curr->next;
	}
	temp->next = head->next;
	head->next = temp;
}
int main(){
	int round;
	cin>>round;
	while(round--){
		int num;
		cin>>num;
		node *head = new node();
		head->next = NULL;
		for(int i=0;i<num;i++){
			int temp;
			cin>>temp;
			insert(head,temp);
		}
		while(head->next!=NULL){
			head = head->next;
			cout<<head->value<<" ";
		}
		cout<<endl;
	}
	return 0;
}
```

#### C
思路：直接遍历找到可能的点然后遍历三个方向，没什么技术含量
```cpp
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector> 
using namespace std;
int main(){
	int round;
	cin>>round;
	while(round--){
		int count = 0;
		int m,n;
		cin>>m>>n;
		vector<string> arr(m);
		for(int i=0;i<m;i++){
			cin>>arr[i];
		}
		string input;
		cin>>input;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(arr[i][j]==input[0]){
					//right
					bool flag = true;
					if(j+input.size()<=n){
						for(int k=1;k<input.size();k++){
							if(arr[i][j+k]!=input[k]){
								flag = false;
							}
						}
						if(flag)
							count ++;
					}
					//down
					flag = true;
					if(i+input.size()<=m){
						for(int k=1;k<input.size();k++){
							if(arr[i+k][j]!=input[k]){
								flag = false;
							}
						}
						if(flag)
							count ++;
					}
					//right-down
					flag = true;
					if(i+input.size()<=m&&j+input.size()<=n){
						for(int k=1;k<input.size();k++){
							if(arr[i+k][j+k]!=input[k]){
								flag = false;
							}
						}
						if(flag)
							count ++;
					}
				}
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
```