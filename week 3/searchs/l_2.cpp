#include <iostream>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        long int i,j,mid,s,e;
        s=1;
        e=x;
        while(s<=e)
        {
            mid=(s+e)/2;
            if(mid*mid==x)
            {
                return mid;
            }
            else if(mid*mid<x)
            {
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }     
        }
        return e;
    }
};