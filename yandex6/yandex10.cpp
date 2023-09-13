#include <iostream>
#include <vector>

int main() {
	int	N, L, tmp;
	std::cin >> N >> L;
	std::vector<std::vector<int>>	v(N);
	std::vector<std::vector<int>>	ans(N);

	for (int i = 0; i < N; ++i) {
		v[i].resize(5);
		for (int j = 0; j < 5; ++j) {
			std::cin >> v[i][j];
		}
	}

	for (int i = 0; i < N; ++i) {
		ans[i].resize(L);
		ans[i][0] = v[i][0];
		for (int j = 1; j < L; ++j) {
			ans[i][j] = v[i][1] + ans[i][j - 1];
			v[i][1] = (v[i][2] * v[i][1] + v[i][3]) % v[i][4];
		}
	}

	for (int i = 0; i < v.size(); ++i) {
		for (int j = i + 1; j < v.size(); ++j) {
			int k = 1, jj = 0, ii = 0;
			while (k != L) {
				if (ans[j][jj] < ans[i][ii])
					++jj;
				else
					++ii;
				++k; 
			}
			if (ans[j][jj] < ans[i][ii])
				std::cout << ans[j][jj] << '\n';
			else
				std::cout << ans[i][ii] << '\n';
		}
	}
}