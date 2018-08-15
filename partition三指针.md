### partition三指针

input:
>包含RGB三个字符的字符串

output:
>R在左，G在中，B在右

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
	string input="RGBGRBGBRBRBGBRBGBGBBRGBRGBRGRBG";
	int begin = 0,current = 0,end = input.size()-1;
	while( current<=end )        
	{             
		if( input[current] == 'R' )             
		{                 
			swap(input[current],input[begin]);                  
			current++;                  
			begin++;            
		}             
		else if( input[current] == 'G' )            
		{                 
			current++;            
		}   
		
		else //When array[current] =2   
		{               
			swap(input[current],input[end]);                
			end--;            
		}
	}
	cout<<input<<endl;
}
```