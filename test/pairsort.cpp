// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

using namespace std;

bool compare (pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }

class Solution {
private:
    
    bool myfunction (int i,int j) { return (i<j); }
    struct myclass {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }
    } myo;

public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
     
    vector<int> subarraySumClosest(vector<int> nums){
        // write your code here
        int n = nums.size();
        vector<int> ans(2,0);
        if (n == 0) {
            return ans;
        }
        vector< pair<int, int> > prefixsum;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            prefixsum.push_back(make_pair(i, sum));
        }
        sort(prefixsum.begin(), prefixsum.end(), compare);
        int minabs = INT_MAX;
        for (int i = 0; i < n - 1; ++i) {
            if (prefixsum[i + 1].second - prefixsum[i].second < minabs) {
                minabs = prefixsum[i + 1].second - prefixsum[i].second;
                ans[0] = min(prefixsum[i].first, prefixsum[i + 1].first) + 1;
                ans[1] = max(prefixsum[i].first, prefixsum[i + 1].first);
            }
        }
        return ans;
    }
};

int main () {
  int myints[] = {-3, 1, 1, -3, 5};
  std::vector<int> myvector (myints, myints+5);               // 32 71 12 45 26 80 53 33
  vector<int> ans;
  Solution x;
  //std::sort (myvector.begin(), myvector.end(), myfunction);     //(12 26 32 33 45 53 71 80)
  ans = x.subarraySumClosest(myvector);
  // print out content:
  std::cout << "myvector contains:";
   for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  for (std::vector<int>::iterator it=ans.begin(); it!=ans.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}