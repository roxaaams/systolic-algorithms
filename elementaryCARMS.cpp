#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
 
using namespace std;
 
int n;
vector<int> generation;
 
void read();
void printGeneration(vector<int> &gen, int &contor);
int getRule(int &prev, int &curr, int &next);
void solve();
 
int main() {
	read();
	solve();
	return 0;
}

void read() {
	cin >> n;
}

void printGeneration(vector<int> &gen, int &contor) {
    cout << "\n Generation " << contor << "\n";
	for (auto &g : gen) {
		cout << (g == 0 ? "*" : "@") << " ";
	}
	cout << "\n";
}
 
int getRule(int &prev, int &curr, int &next) {
	int sum = prev + next;
	return (sum % 2) ? 1 : 0;
}
 
void solve() {
	generation.resize(n);
	srand (time(NULL));
	for (auto &g : generation) {
		g = rand() % 2;
	}

	int contor = 0;
	printGeneration(generation, contor);
 
	while (contor < n) {
	    vector<int> newGeneration(generation.size());
 
	    newGeneration[0] = getRule(generation[generation.size() - 1], generation[0], generation[1]);
	    for (int i = 1; i < newGeneration.size() - 1; ++i) {
	       newGeneration[i] = getRule(generation[i - 1], generation[i], generation[i + 1]);
	    }
	    newGeneration[newGeneration.size() - 1] = getRule(generation[newGeneration.size() - 2], generation[newGeneration.size() - 1], generation[0]);
 
	    contor++;
	    generation = newGeneration;
	    printGeneration(generation, contor);
	}
}
