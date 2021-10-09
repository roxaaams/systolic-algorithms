#include <iostream>
#include <vector>
 
using namespace std;
 
struct Processor {
	int c;
	int ain;
    int aout;
	int bin;
	int bout;

};
 
int n, m, p;
vector<vector<int>> B;
vector<vector<Processor>> P;
vector<vector<int>> A;
 
void resize() {
	P.resize(m + 1);
	for (auto &pr : P) {
        pr.resize(p + 1);
        for (auto &e : pr) {
            e.c = 0;
            e.ain = 0;
            e.aout = 0;
            e.bin = 0;
            e.bout = 0;
        }
	}
 
	A.resize(m + 1);
    for (auto &it : A) {
        it.resize(n + 1);
    }

    B.resize(n + 1);
    for (auto &it : B) {
        it.resize(p + 1);
    }
 
}
 
void read() {
	cin >> m >> n >> p;
 
	resize();
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> A[i][j];
		}
	}
 
	for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
			cin >> B[i][j];
		}
	}
}
 
void solve() {
	for (int i = 0; i < m + n + p - 2; ++i) {
		cout << "\n\n" << "Step " << i << ":\n";

        cout << "\n" << "Propagating:" << "\n";
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < p; ++k) {
                cout << "   P[" << j << "][" << k << "]\n";
                int delayA = m - 1 - j;
                int delayB = p - 1 - k;
                if (k < p - 1) {
                    P[j][k].ain = P[j][k + 1].aout;
                } else {
                    P[j][k].ain = i >= delayA && i < delayA + n ? A[j][i - delayA] : 0;
                }

                if (j < m - 1) {
                    P[j][k].bin = P[j + 1][k].bout;
                } else {
                    P[j][k].bin = i >= delayB && i < delayB + n ? B[i - delayB][k] : 0;
                }
                
                cout << "       ain = " << P[j][k].ain << "\n";
                cout << "       bin = " << P[j][k].bin << "\n";
            }
		}

        cout << "\n" << "Calculating:" << "\n";
		for (int j = 0; j < m; ++j) {
            for (int k = 0; k < p; ++k) {
                P[j][k].c += P[j][k].ain * P[j][k].bin;
                cout << "   C[" << j << "][" << k << "] = " << P[j][k].c << "\n";
                P[j][k].bout = P[j][k].bin;
                P[j][k].aout = P[j][k].ain;
            }
		}
        cout << "\n";
	}
 
 
 
	cout << "\nFinal state of matrix C: \n";
	for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
		    cout << P[i][j].c << " ";
        }
        cout << "\n";
	}
 
}
 
int main() {
	read();
	solve();
	return 0;
}