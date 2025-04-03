#include <bits/stdc++.h>
using namespace std;

class DisjoinedSet {
public:
	vector<int> size, par;

	DisjoinedSet(int n) {
		size = vector<int>(n + 1, 1);
		par = vector<int>(n + 1);

		for (int i = 0; i <= n; i++)par[i] = i;
	}

	// find parent by path compression
	int findUPar(int u) {
		if (par[u] == u)return u;

		int uPar = findUPar(par[u]);
		par[u] = uPar;
		return uPar;
	}

	void unionBySize(int u, int v) {
		int pu = findUPar(u);
		int pv = findUPar(v);

		if (pu == pv)return;

		if (size[pu] > size[pv]) {
			par[pv] = pu;
			size[pu] += size[pv];
		} else {
			par[pu] = pv;
			size[pv] += size[pu];
		}
	}

};

int32_t main()
{
	DisjoinedSet ds(7);

	ds.unionBySize(1, 2);

  // same
	if (ds.findUPar(1) == ds.findUPar(2)) cout << "same" << endl;
	else cout << "not-same" << endl;

	ds.unionBySize(3, 2);
	ds.unionBySize(4, 5);
	ds.unionBySize(6, 7);
	ds.unionBySize(5, 6);
	ds.unionBySize(3, 7);

  // same
	if (ds.findUPar(3) == ds.findUPar(7)) cout << "same" << endl;
	else cout << "not-same" << endl;

}
