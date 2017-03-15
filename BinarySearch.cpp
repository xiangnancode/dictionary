#include <iostream>
#include <vector>

using namespace std;

    int main()
    {
        int arr[] = {1,2,3,3,4,5,10};
        vector<int> array (arr, arr + sizeof(arr)/sizeof(arr[0]) );
        int target = 3;
        // write your code here
        if (array.size() == 0)
        {
            cout << -1 << endl;
        }
        
        int start = 0;
        int end = array.size() - 1;
        int mid;
        
        while (start + 1 < end)
        {
            mid = start + (end - start) / 2;
            if (target <= array[mid]) // first position
            {
                end = mid;
            }
            else if (target > array[mid]) // => for last position
            {
                start = mid;
            }
        }
        
        if (target == array[start])// first position
        {
            cout << start << endl;
            return 0;
        }
        if (target == array[end])// last position
        {
            cout << end << endl;
            return 0;
        }
        cout << -1 << endl;
    }

/*
int bs(vector<int>& arr, int key) {
	int L = 0, R = arr.size() - 1;
	while (L < R) {
		int M = (L + R) / 2;
		if (arr[M] < key) {
			L = M + 1;
		} else {
			R = M;
		}
	}
	return (L == R && arr[L] == key) ? L : -1;
};*/
