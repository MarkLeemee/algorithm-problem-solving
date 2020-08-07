#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> map;
int n;

struct Node {
	int y, x;
};

int bfs(int dy, int dx) {
	int head = 0;
	int tail = 1;
	map[dy][dx] = '0';
	int dataNum = 1;
	Node queue[10000] = { {dy,dx} };

	int direct[4][2] = { -1,0,1,0,0,-1,0,1 };

	while (head != tail) {
		Node now = queue[head++];
			for (int i = 0; i < 4; i++) {
			int dy = now.y + direct[i][0];
			int dx = now.x + direct[i][1];

			if (dy < 0 || dx < 0 || dy >= n || dx >= n) continue;
			if (map[dy][dx] == '0') continue;

			map[dy][dx] = '0';
			dataNum++;
			queue[tail++] = { dy, dx };
		}
	}
	return dataNum;
}

int main() {
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		map.push_back(a);
	}


	int cnt = 0;
	vector<int> result;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (map[y][x] == '1') {
				result.push_back(bfs(y, x));
				cnt++;
			}
		}
	}

	cout << cnt << endl;

	sort(result.begin(), result.end(), greater<int>());
	while(!result.empty()){
		cout << result.back() << endl;
		result.pop_back();
	}

	return 0;
}