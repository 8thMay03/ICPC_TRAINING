#include <bits/stdc++.h>

using namespace std;

char fr[20202020];
char pat[1010100];

int main() {
	int x, y;
	scanf("%d %d %s", &x, &y, pat + 1);
	int pz = strlen(pat + 1);
	int sz = 0;
	int v = x / y;
	if (v) {
		while (v) {
			fr[++sz] = (v % 10) + '0';
			v /= 10;
		}
		reverse(fr + 1, fr + sz + 1);
	}
	else {
		fr[++sz] = '0';
	}
	x %= y;
	for (int i = 1; i <= (y << 1) || i <= (pz << 1); ++i) {
		if (x) {
			x += (x << 3) + x;
			while (x < y) {
				x += (x << 3) + x;
				fr[++sz] = '0';
				++i;
			}
			fr[++sz] = (x / y) + '0';
			x %= y;
		}
		else {
			fr[++sz] = '0';
		}
	}
	fr[sz + 1] = 0;
	const char *res = strstr(fr + 1, pat + 1);
	if (res != NULL) {
		cout << res - fr;
	}
	else {
		cout << 0;
	}
}