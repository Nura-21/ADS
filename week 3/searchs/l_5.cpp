#include <iostream>
using namespace std;
class Solution {
    bool isPerfectSquare(int num){
        if(num == 1){
        return true;
        }

        long long aux;
            
            for(long long i=1;(aux = i*i) <= num;i++){
                if(aux == num){
                    return true;
                }
            }
            
            return false;
        }
};