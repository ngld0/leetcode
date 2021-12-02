# Daily Leetcode. I will explain each solutions when I have time!!!
# Daily Leetcode
## 1. Fast I/O for Competitive Programing (C++)
``` 
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
//or
static const auto speedup = [](){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    return NULL;
}();
```
## 2. Ternary Operator c/C++
```
result = condition ? first : second;
//Example
    int result = i % 2 == 0 ? i * 10 : i * 20;
```
## 3. 1+3+5 + ...
```
Using the arithmetic series formula :
    1 + 3 + 5…. is an arithmetic series with common difference 2. We can find out the sum of arithmetic series using the below formula :
        (n/2)*[2a+(n−1)d]
    Where:
    *n is the total number of elements starting from first, 
    *a is the first element and d is a common difference. 
    For our example, we have a = 1 and d = 2. We can take the value of n from the user as input and calculate the sum :
        sum = (n/2)*(2 + (n-1)*2);
```
