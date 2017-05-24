/*
 * Filename: Square_matrix_multiply.cpp 
 * 
 * 两个n*n的矩阵相乘的暴力求解法
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > Square_matrix_multiply1(const vector<vector<int> >& arr, const vector<vector<int> >& brr)
{
	vector<int> iv(arr.size());
	vector<vector<int> > ret(arr.size(), iv);
	for (int i = 0; i < arr.size(); ++i)
	{
		for (int j = 0; j < arr.size(); ++j)
		{
			for (int k = 0; k < arr.size(); ++k)
			{
				ret[i][j] = ret[i][j] + arr[i][k] * brr[k][j];
			}
		}
	}
	return ret;
}

int main()
{
	vector<vector<int> > arr = {{1, 2}, {2, 1}}, brr = {{3, 1}, {0, 3}};
	vector<vector<int> > ret1 = Square_matrix_multiply1(arr, brr);
	cout << "ret1: " << ret1[0][0] << " " << ret1[0][1] << " " << ret1[1][0] << " " << ret1[1][1] << endl;

	return 0;
}

