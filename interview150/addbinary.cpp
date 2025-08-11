/**
 * xiebaoma
 * 2025-08-11
 */

#include<string>
using namespace std;


//11 + 1
class Solution {
public:
    string addBinary(string a, string b) {
        int i =a.size()-1;
        int j =b.size()-1;
        int carry=0;
        string ans = "";
        while(i>=0 || j>=0){
            char vala = i>=0? a[i]:'0'; i--;
            char valb = j>=0? b[j]:'0'; j--;
            int num = (vala-'0') + (valb - '0') + carry;
            carry = num/2;
            if(num%2==0){
                ans='0'+ans;
            }else{
                ans='1'+ans;
            }
        }
        if(carry==1){
            ans='1'+ans;
        }
        return ans;
    }
};