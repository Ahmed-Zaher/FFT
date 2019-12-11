#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1);

#include "Complex.h"
#include "FFT.h"


int main() {
	ios::sync_with_stdio(false);
	cout.precision(3);
	cout << fixed;

	int N;

	cout << "Enter the number of points (must be a power of 2)...\n";

	cin >> N;

	vector<Complex> P(N);

	cout << "Enter the " << N << " points...\n";

	for (int i = 0; i < N; ++i)
		cin >> P[i].Re;

	FFT fft(P);


	vector<Complex> ans = fft.computeFFT();


	cout << "DFT in complex form: {" << ans[0];


	for (int i = 1; i < N; ++i)
		cout << ", " << ans[i];


	cout << "}\n";

	cout << "DFT magnitude:       {" << setw(8) << ans[0].mag();


	for (int i = 1; i < N; ++i)
		cout << ", " << setw(8) << ans[i].mag();

	cout << "}\n";

	cout << "DFT angle:           {" << setw(8) << ans[0].angle();


	for (int i = 1; i < N; ++i)
		cout << ", " << setw(8) << ans[i].angle();

	cout << "}\n";

    return 0;

}
