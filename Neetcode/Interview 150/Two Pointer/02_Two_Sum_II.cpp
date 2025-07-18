// Valid Palindrome

#include<iostream>
#include <string> 
#include <algorithm>
#include <vector> 
#include <unordered_map> 

using namespace std;

class Solution {
    public:

    vector<int> twoSum(vector<int>& numbers, int target) {
        if(numbers.size() == 0){
            return {0};
        }
        
        for(int i=0; i<numbers.size(); i++){
            for(int j=i+1; j<numbers.size(); j++){
                if(numbers[i] + numbers[j] == target){
                    return {i+1, j+1};
                } 
            }
        }
        return {0};
    }

    vector<int> better(vector<int>& numbers, int target) {
        unordered_map<int, int> mpp;
        for(int i=0; i<numbers.size(); i++){
            int required = target - numbers[i];

            if(mpp.count(required)){
                return {mpp[required] + 1, i+1};
            }
            
            mpp[numbers[i]] = i;
        }
        return {-1, -1};
    }


    vector<int> optimal(vector<int>& numbers, int target) {
        int i=0, j=numbers.size()-1;
        while(i<j){
            if(numbers[i]+numbers[j] < target){
                i++;
            }
            else if(numbers[i]+numbers[j]>target){
                j--;
            }
            else{
                return vector{i+1, j+1};
            }
        }
        return vector{-1, -1};
    }
};

int main(){
    vector<int> numbers = {2,7,11,15};
    int target = 9;
    Solution sol;
    vector<int> ans = sol.optimal(numbers, target);
    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}