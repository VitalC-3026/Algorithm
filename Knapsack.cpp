#include <iostream>
using namespace std;

int Knapsack(int n, int w, int value[][2]) {
	int** opt = new int* [n + 1];
	for (int i = 0; i < n + 1; i++) {
		opt[i] = new int[w + 1];
		opt[i][0] = 0;
	}
	for (int i = 0; i < w + 1; i++) {
		opt[0][i] = 0;
	}
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < w + 1; j++) {
			if (value[i - 1][1] > j) {
				opt[i][j] = opt[i - 1][j];
			}
			else {
				if (opt[i - 1][j] > opt[i - 1][j - value[i - 1][1]] + value[i - 1][0]) {
					opt[i][j] = opt[i - 1][j];
				}
				else {
					opt[i][j] = opt[i - 1][j - value[i - 1][1]] + value[i - 1][0];
				}

			}
		}
		
	}
	int res = opt[n][w];
	for (int i = 0; i < n + 1; i++) {
		delete[] opt[i];
	}
	delete[] opt;
	return res;
}


int main()
{
  // 背包的价值和重量
	int value[][2] = {1, 1,  6, 2, 22, 5,18, 6, 28, 7};
  // 背包的总个数n，允许的最大载重量w
	int n = 5, w = 11;
	int res = Knapsack(5, 11, value);
	cout << res << endl;
	return 0;
}
