// Longest Consecutive Sequence
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>

using namespace std;

// Brute Force Solution 

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int ans = 1;
        int curr = 1;
        
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == nums[i-1]){
                continue;
            }
            if(nums[i] == nums[i - 1] + 1){
                curr++;
            }
            else {
                ans = max(ans, curr);
                curr = 1;
            }
        }

        return max(ans, curr);
    }


    // Time Complexity: O(n)
    // Space Complexity: O(n)

    int better(vector<int> &nums){
        int n = nums.size();
        if(n == 0){
            return 0;
        }

        unordered_set<int> temp(nums.begin(), nums.end());
        int ans = 0;

        for(int num:temp){
            
            if(!temp.count(num-1)){
                int curr = num;
                int count = 1;

                while(temp.count(curr+1)){
                    curr++;
                    count++;
                }

                ans = max(ans, count);
            }
        }
        return ans;
    }
};


int main(){
    vector<int> nums = {100,4,200,1,3,2};
    Solution sol;
    int ans = sol.better(nums);
    cout<<"The Count of Longest Sequence is :"<<ans<<endl;
    return 0;
}