### pow

> 快速幂

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        long long temp_n = n;
        if(temp_n<0){
            x = 1/x;
            temp_n = (long long)n * -1 ;
        }
        double res = 1;
        while(temp_n>0){
            if(temp_n%2==1){
                res *= x;
            }
            temp_n/=2;
            x *= x;
        }
        return res;
    }
};
```