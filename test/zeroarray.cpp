#include <iostream>
#include <vector>

using namespace std;

int main() {
	int m,n;
	

	cin >> m >> n;

	cout << "m = " << m << ", n = " << n << endl;

	//vector<int> a(n,0);
	vector< vector<int> > arr(m, vector<int> (n,0) );

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	//cout << endl;
}