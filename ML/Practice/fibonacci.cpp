#include <bits/stdc++.h>
using namespace std;
int fibonacci(int n)
{
    int a = 0;
    int b = 1;
    int c;
    for (int i = 1; i < n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
int fib(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }

    return fib(n-1)+fib(n-2);
}
int main()
{
    cout << fib(7) << endl;
}