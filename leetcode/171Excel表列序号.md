### Excel表列序号

> 26进制

```cpp
class Solution {
public:
    int titleToNumber(string s) {
        long long res = 0;
        for(int i=0;i<s.size();i++){
            res *= 26;
            res += s[i]-'A'+1;
        }
        return res;
    }
};
```