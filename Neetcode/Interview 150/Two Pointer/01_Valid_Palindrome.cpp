// Valid Palindrome

#include<iostream>
#include <string> 
#include <algorithm>
#include <vector> 

using namespace std;

class Solution {
    public:

    bool bruteForce(string s){
        string cleaned = "";
        
        for(char c : s){
            if(isalnum(c)){
                cleaned += tolower(c);
            }
        }

        string temp = cleaned;
        reverse(temp.begin(), temp.end());

        return temp==cleaned;
    }

    bool isPalindrome(string s) {
        int r = s.size();
        if(r==0){
            return true;
        }
        vector<int> ans;
        for(int i=0; i<r; i++){
            if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
                ans.push_back(s[i]);
            }
        }
        int left = 0;
        int right = ans.size();
        while(left<right){
            if(isEqual(ans[left], ans[right-1]) == false){
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }

    bool isEqual(int left, int right){
        if(left==right || (left>='A' && left<='Z' && right == left+32) || (right>='A' && right<='Z' && left==right+32)){
            return true;
        }
        return false;
    }
};

int main(){
    string s = "Was it a car or a cat I saw?";
    Solution sol;
    if(sol.bruteForce(s)){
        cout<<"Valid Palindrome"<<endl;
    }
    else {
        cout<<"Not Valid Palindrome"<<endl;
    }

    return 0;
}