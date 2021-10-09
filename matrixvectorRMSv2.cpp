#include <iostream>
#include <vector>

using namespace std;

struct Processor {
	int v;
	int ain;
	int uin;
	int uout;
};

int n, m;
vector<int> U;
vector<Processor> P;
vector<vector<int>> A;

void resize() {
	P.resize(n + 1);
	for (auto &p : P) {
		p.v = 0;
		p.ain = 0;
		p.uin = 0;
		p.uout = 0;
	}

	A.resize(m + 1);
    for (auto &it : A) {
        it.resize(n + 1);
    }

  U.resize(n + 1);
}

void read() {
	cin >> m >> n;

	resize();
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> A[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		cin >> U[i];
	}

}

void solve() {

	for (int i = 0; i < m + n - 1; ++i) {
		cout << "Step " << i << ":\n";

		 for (int j = 0; j < m; ++j) {
		 	cout << "Processor number  " << j << "\n";
		    int delay = m - 1 - j;
		    P[j].ain = i >= delay && i < delay + n ? A[j][i - delay] : 0;
		    cout << "Current Ain " << P[j].ain << "\n";
		    P[j].uin = j < m - 1 ? P[j + 1].uout : i < n ? U[i] : 0;
		    cout << "Current Uin " << P[j].uin << "\n";
		 }

		for (int j = 0; j < m; ++j) {
			cout << "Processor number  " << j << "\n";
	    	P[j].v += P[j].uin * P[j].ain;
	    	cout << "Current V " << P[j].v << "\n";
			cout << "Current U is ready to be sent to the next processor ";
	    	P[j].uout = P[j].uin;
		}
	}

	cout << "Final state of V: \n";
	for (int i = 0; i < m; ++i) {
		cout << P[i].v << " ";
	}

}

int main() {
	read();
	solve();
	return 0;
}
