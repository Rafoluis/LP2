#include <iostream>
#include <cmath>
#include <cstdio>
#define EPS 1e-8
using namespace std;



int p, q, r, s, t, u;

double ecu(double x) {
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

double binario() {
	double inicio = 0, cont = 1;
	while (inicio + EPS < cont) {
		double x = (inicio + cont) / 2;
		if (ecu(inicio) * ecu(x) <= 0)
			cont = x;
		else
			inicio = x;
	}
}

int main(void) {
	while (cin >> p >> q >> r >> s >> t >> u) {
		if (ecu(0) * ecu(1) > 0)
			cout << "No solution" << endl;
		else
			printf("%.4f\n", binario());
	}

	return 0;
}
