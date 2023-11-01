#include <iostream>
#include <math.h>
using namespace std;

//unsigned long long fact(unsigned long long f)
//{
//    unsigned long long res = 1;
//    for (unsigned long long i = 1; i <= f; i++)
//    {
//        res = res * i;
//    }
//    return res;
//}
//
//void equa(unsigned long long n)
//{
//    unsigned long long end;
//    end = 1 - (fact(n) / (fact(1) * fact(n - 1)));
//
//    for (unsigned long long i = 2; i <= n; i++)
//    {
//        if (i % 2 == 0)
//        {
//            end = end + (fact(n) / (fact(i) * fact(n - i)));
//        }
//        else if (i % 2 == 1)
//        {
//            end = end - (fact(n) / (fact(i) * fact(n - i)));
//        }
//    }  
//
//    cout << end << endl;
//}

int main() {
    unsigned long long t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n != 0) { cout << "0" << endl; }
        else { cout << "1" << endl; }
        //equa(n);
    }
    return 0;}