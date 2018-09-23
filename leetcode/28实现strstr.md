### 实现strstr

> KMP算法

```cpp
class Solution {
public:
    int strStr (string haystack,string needle) {
       // if (haystack.size() ==0) return -1;
        if (needle.size() == 0) return 0;

        vector<int> next = getNext(needle);
        int i = 0, j = 0;
        int len_a = needle.size();int len_b = haystack.size();
        while ( i < len_b && j < len_a ) {
            if ( j == -1 || haystack[i] == needle[j] ) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }

        if ( j == needle.size() ) {
            return i - j;
        } else {
            return -1;
        }
    }
    vector<int> getNext(string str) {
        vector<int> next;
        next.push_back(-1);
        int j = 0;
        int k = -1;
        while ( j < str.size()-1 ) {
            if ( k == -1 || str[j] == str[k] ) {
                next.push_back(++k);
                j++;
            } else {
                k = next[k];
            }
        }
        return next;
    }
};
```