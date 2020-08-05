#include <iostream>
#include <cstring>
using namespace std;
// DAT 활용하여 횟수 출력
int main() {

	int map[4][3] = {
		3,5,1,
		3,1,2,
		3,4,6,
		5,4,6 };

	int dat[10] = { 0 };

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 3; x++) {
			dat[map[y][x]]++;
		}
	}

	for (int x = 1; x <= 6; x++) {
		cout << x << " ";
		for (int n = 0; n < dat[x]; n++) {
			cout << "* ";
		}
		cout << endl;
	}
	
	return 0;
}