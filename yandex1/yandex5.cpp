#include <iostream>

void	check(int k1, int m, int k2, int p2, int n2, int k, int& tmpP1, int& tmpN1) {
	
	int floors_before = (k2 - 1) / k;
	int tmpp2 = floors_before / m + 1;
	int tmpn2 = floors_before % m + 1;
	if (tmpp2 == p2 && tmpn2 == n2) {
		floors_before = (k1 - 1) / k;
		tmpP1 = floors_before / m + 1;
		tmpN1 = floors_before % m + 1;
	} else {
		tmpP1 = -1;
		tmpN1 = -1;
	}

}

int main() {
	int K1, M, K2, P2, N2;
	std::cin >> K1 >> M >> K2 >> P2 >> N2;
	
	int	P1 = -1, N1 = -1;
	int tmpP1, tmpN1;
	bool	goodflag = false;

	for (int k = 1; k < 1'000'001; ++k) {
		check(K1, M, K2, P2, N2, k, tmpP1, tmpN1);
		if (tmpN1 != -1) {
			goodflag = true;
			if (P1 == -1) {
				P1 = tmpP1;
				N1 = tmpN1;
			} else if (P1 != tmpP1 && P1 != 0) {
				P1 = 0;
			} else if (N1 != tmpN1 && N1 != 0) {
				N1 = 0;
			}
		}
	}
	if (goodflag == true) {
		std::cout << P1 << ' ' << N1;
	} else {
		std::cout << "-1 -1";
	}
}