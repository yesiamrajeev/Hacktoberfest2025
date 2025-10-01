#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums,int& start,int& end) {
        int s=0;
        int e=0;
        int maxi = INT_MIN;
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if(sum>maxi){
                maxi=sum;
                start=s;
                end=i;
            }
            if (sum < 0) {
                sum = 0;
                s=i+1;
            }
        }
        return maxi;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int start=0;
    int end=0;
    int result = sol.maxSubArray(nums,start,end);
    cout << "Maximum Subarray Sum = " << result << endl;
    cout << "Length of the subarray is = "<<(end - start + 1) <<endl;
    vector<int> subarray;
    for(int i=start;i<=end;i++){
        subarray.push_back(nums[i]);
    }
    cout<<"Element of the maximum subarray is [";
    for(int i=0;i<subarray.size();i++){
        cout << subarray[i];
        if (i != subarray.size() - 1) cout << ", ";
    }
    cout<<"]"<<endl;
    cout<<"starting point of subarray is "<<start<<endl;
    cout<<"ending point of subarray is "<<end<<endl;

    return 0;
}
