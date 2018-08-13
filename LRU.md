### LRU算法实现

最近最长未使用的Cache，LeetCode：https://leetcode.com/problems/lru-cache/description/

get操作非最优，可以加map优化

```cpp
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
class Node{
public:
    int key;
    int value;
    Node *next;
};
class LRUCache {
public:
    int size;
    int max_size;
    Node *head;
    LRUCache(int capacity) {
        size = 0;
        max_size = capacity;
        head = new Node();
        head->next = NULL;
    }
    
    int get(int key) {
        Node *curr = head;
        while(curr->next!=NULL){
            //notice the order here
            if(curr->next->key==key){
            	int value = curr->next->value;
            	put(key,value);
                return value;
            }
            curr = curr->next;
        }
        return -1;
    }
    
    void put(int key, int value) {
        Node *curr = head;
        Node *temp = new Node();
        temp->next = NULL;
        temp->value = value;
        temp->key = key;
        while(curr->next!=NULL){
            //notice the order here
            if(curr->next->key==key){
                Node *for_delete = curr->next;
                curr->next = curr->next->next;
                delete for_delete;
                size--;
                break;
            }
            curr = curr->next;
        }
        temp->next = head->next;
        head->next = temp;
        size++;
        curr = head;
        if(size>max_size){
            for(int i=0;i<max_size;i++){
                curr = curr->next;
            }
            curr->next = NULL;
            size = max_size;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
 int main(){
 	
 	LRUCache cache(2);

	cache.put(1, 1);
	cache.put(2, 2);
	cache.get(1);       // returns 1
	cache.put(3, 3);    // evicts key 2
	cache.get(2);       // returns -1 (not found)
	cache.put(4, 4);    // evicts key 1
	cache.get(1);       // returns -1 (not found)
	cache.get(3);       // returns 3
	cache.get(4);       // returns 4
	return 0;
 }
```