#include <iostream>
#include <cstring>
using namespace std;

int main() {

	char arr[11];
	cin >> arr;

	char result[11] = { 0 };
	int n = 0;
	for (int y = 0; y < 10; y++) {
		for (int x = y + 1; x < 9; x++) {
			if (arr[y] == arr[x]) {
				result[n] = arr[y];
				n++;
			}
		}
	}

	cout << result;
	
	return 0;
}