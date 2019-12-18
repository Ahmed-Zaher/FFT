class FFT {
private:
	vector<Complex> X0;
	vector<vector<Complex>> W;

	int LOG(int N) {
		int ret = -1;
		while (N)
			++ret, N >>= 1;
		return ret;
	}

	vector<Complex> computeFFT(vector<Complex> X) {

		int N = X.size(), LOGN = LOG(N);

		if (N == 2)
			return vector<Complex>({X[0] + X[1], X[0] - X[1]});


		vector<Complex> E, O;

		for (int i = 0; i < N; i += 2) {
			E.push_back(X[i]);
			O.push_back(X[i + 1]);
		}

		vector<Complex> E_FFT = computeFFT(E);
		vector<Complex> O_FFT = computeFFT(O);

		vector<Complex> ret(N);

		for (int i = 0; i < N; ++i)
			ret[i] = E_FFT[i % (N >> 1)] + W[LOGN][i] * O_FFT[i % (N >> 1)];

		return ret;


	}
public:
	FFT(vector<Complex> _X0) : X0(_X0) {
		int N = X0.size(), LOGN = LOG(N);

		W.assign(LOGN + 1, vector<Complex>(N, Complex(1, 0)));
		W[LOGN][1] = Complex(cos(2 * PI / N), -sin(2 * PI / N));
		for (int i = LOGN; i >= 0; --i) {
			if (i < LOGN)
				W[i][1] = W[i + 1][1] * W[i + 1][1];
			for (int j = 2; j < N; ++j)
				W[i][j] = W[i][j - 1] * W[i][1];
		}

	}
	vector<Complex> computeFFT() {
		return computeFFT(X0);
	}
};

