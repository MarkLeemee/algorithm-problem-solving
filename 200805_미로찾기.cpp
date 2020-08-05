#include <iostream>
#include <string>
using namespace std;
// 미로 찾기 문제
string map[101];

int n;
int m;

struct Node {
	int dy, dx;
	int level;
};

int visit[101][101];
Node queue[100000];

int head = 0;
int tail = 1;

int main() {

	cin >> n>>m;
	for(int y=0;y<n;y++){
			cin>>map[y];
	}

	queue[0] = (struct Node) {0,0,1};
	int direct[4][2] = { -1,0,1,0,0,1,0,-1 };

	while (head != tail) {
		Node now = queue[head++];
		for (int t = 0; t < 4; t++) {
			int dy = now.dy + direct[t][0];
			int dx = now.dx + direct[t][1];

			if (dy < 0 || dx < 0 || dy >= n || dx >= m) continue;
			if (map[dy][dx] == '0') continue;
			if (visit[dy][dx] == 1) continue;

			visit[dy][dx] = 1;
			queue[tail++] = (struct Node) { dy, dx, now.level+1 };

			if (dy == n-1 && dx == m-1) {
				cout << now.level+1;
				return 0;
			}
		}
	}
	return 0;
}