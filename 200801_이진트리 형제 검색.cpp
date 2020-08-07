#include <iostream>
#include <cstring>
using namespace std;
// 노드의 이름을 입력받고 그 형제들을 출력
int main() {

	int map[8][8] = {
		0,1,1,1,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,1,1,1,0,
		0,0,0,0,0,0,0,1 };

	char name[9] = "ABHCDGEF";

	char n;
	int indexN;
	cin >> n;
	
	for (int x = 0; x < 9; x++) {
		if (name[x] == n) indexN = x;
	}

	int flag = 1;
	int parent;
	for (int x = 0; x < 8; x++) {
		if (map[x][indexN] == 1) {
			parent = x;
			flag = 0;
		}
	}
	if (flag == 1) cout << "없음";
	else {
		for (int x = 0; x < 8; x++) {
			if (x != indexN && map[parent][x] == 1) cout << name[x] << " ";
		}
	}

	return 0;
}