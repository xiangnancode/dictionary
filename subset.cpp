#include <iostream>
#include <vector>

using namespace std;

    void helper(vector<vector<int> > &results, vector<int> subset, vector<int> nums, int start) 
    {
        
        results.push_back(subset);
        
        for (int i = start; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            helper(results, subset, nums, i + 1);
            subset.pop_back();
        }
    }

    void printvector(vector<int> v)
    {
        for (int i = 0; i < v.size(); ++i)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }

int main() {


int s[] = {1,2,3};
vector<int> nums (s,s + sizeof(s)/sizeof(s[0]));
printvector(nums);
vector<vector<int> > results;
vector<int> subset;

helper(results, subset, nums, 0);

for (int i = 0; i < results.size(); ++i)
{
    printvector(results[i]);
}

}