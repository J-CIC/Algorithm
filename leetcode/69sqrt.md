### sqrt

> 二分

```cpp
static const auto x=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int mySqrt(int x) {
        int l = 0 , r = x;
        while(l<r){
            long long mid = (l+r)/2;
            long long t = mid*mid;
            if(t<x){
                l = mid+1;
            }else if(t>x){
                r = mid-1;
            }else{
                return mid;
            }
        }
        if(l*l>x){
            l--;
        }
        return l;
    }
};
```