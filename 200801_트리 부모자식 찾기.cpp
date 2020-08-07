#include <iostream>
#include <cstring>
using namespace std;
// 노드0번의 부모와 자식 출력
int main() {

	int n;
	int map[10][10000];
	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> map[y][x];
		}
	}

	int boss;
	int under[10] = { 0 };

	for (int x = 0; x < n; x++) {
		if (map[x][0] == 1) boss = x;
		if (map[0][x] == 1) under[x] = 1;
	}

	cout << "boss:" << boss << endl;
	cout << "under:";
	for (int x = 0; x < n; x++) {
		if (under[x] == 1) cout << x << " ";
	}

	return 0;
}