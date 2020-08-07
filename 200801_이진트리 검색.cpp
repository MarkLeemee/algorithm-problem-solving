#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char vect[10] = " ADFZCGQH";

	int n;
	char a, b;
	int ai, bi;

	cin >> a >> b;
	n = strlen(vect);

	for (int i = 0; i < n; i++) {
		if (vect[i] == a) ai = i;
		if (vect[i] == b) bi = i;
	}

	if (ai / 2 == bi) cout << "부모자식관계";
	else if (bi / 2 == ai) cout << "부모자식관계";
	else cout << "아님";

	return 0;
}