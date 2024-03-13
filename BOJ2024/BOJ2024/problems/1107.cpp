#include "common.h"

#include <stdio.h>



int upper_closest(int pivot, int pivotL, int length, bool* jam) {
	if (length <= 0)
		return -1;
	if (pivotL > length)
		return -1;

	int minI = 0;
	for (int i = 1; i <= 9; i++) {
		if (!jam[i]) {
			minI = i;
			break;
		}
	}

	if (pivotL < length) {

		int lowermax = minI;
		if (jam[0]) {
			for (int i = 1; i < length; i++)
				lowermax = lowermax * 10 + minI;
			return lowermax;

		}
		else {
			for (int i = 1; i < length; i++)
				lowermax = lowermax * 10;
			return lowermax;
		}


	}

	int L10 = 1;
	for (int i = 1; i < pivotL; i++)
		L10 = L10 * 10;
	int topN = pivot / L10;
	int rest = pivot - topN * L10;

	int upper = -1;
	for (int i = topN; i <= 9; i++) {
		if (!jam[i]) {
			upper = i;
			break;
		}
	}
	if (upper != -1) {
		if (pivotL == 1) {
			return upper;
		}
		if (upper > topN) {
			int lowermax = upper;
			if (jam[0]) {
				for (int i = 1; i < pivotL; i++)
					lowermax = lowermax * 10 + minI;
				return lowermax;
			}
			else {
				for (int i = 1; i < pivotL; i++)
					lowermax = lowermax * 10;
				return lowermax;

			}
		}
		int cand = upper_closest(rest, pivotL - 1, pivotL - 1, jam);
		if (cand == -1) {

			int newupper = -1;
			for (int i = upper + 1; i <= 9; i++) {
				if (!jam[i]) {
					newupper = i;
					break;
				}
			}
			if (newupper == -1)
				return -1;
			else {
				int lowermax = newupper;
				if (jam[0]) {
					for (int i = 1; i < pivotL; i++)
						lowermax = lowermax * 10 + minI;
					return lowermax;
				}
				else {
					for (int i = 1; i < pivotL; i++)
						lowermax = lowermax * 10;
					return lowermax;

				}
			}

		}
		else return upper * L10 + cand;
	}


	return -1;
}

int lower_closest(int pivot, int pivotL, int length, bool* jam) {
	if (length <= 0)
		return -1;
	if (pivotL < length)
		return -1;

	int maxI = 10;
	for (int i = 9; i >= 0; i--) {
		if (!jam[i]) {
			maxI = i;
			break;
		}
	}

	if (pivotL > length) {
		int lowermax = maxI;
		for (int i = 1; i < length; i++)
			lowermax = lowermax * 10 + maxI;
		return lowermax;
	}

	int L10 = 1;
	for (int i = 1; i < pivotL; i++)
		L10 = L10 * 10;
	int topN = pivot / L10;
	int rest = pivot - topN * L10;

	int lower = -1;
	for (int i = topN; i >= 0; i--) {
		if (!jam[i]) {
			lower = i;
			break;
		}
	}
	if (lower != -1) {
		if (pivotL == 1) {
			return lower;
		}
		if (lower < topN) {
			int lowermax = lower;
			for (int i = 1; i < pivotL; i++)
				lowermax = lowermax * 10 + maxI;
			return lowermax;
		}

		int cand = lower_closest(rest, pivotL - 1, pivotL - 1, jam);
		if (cand == -1) {
			int newlower = -1;
			for (int i = lower-1; i >= 0; i--) {
				if (!jam[i]) {
					newlower = i;
					break;
				}
			}
			if (newlower == -1)
				return -1;

			int lowermax = newlower;
			for (int i = 1; i < pivotL; i++)
				lowermax = lowermax * 10 + maxI;
			return lowermax;
		}
		else return lower * L10 + cand;
	}



	return -1;
}

int P1107() {

	int N, M;
	bool jam[12] = { 0 };	//0~9,+-
	int buff;
	int L = 0;


	scanf("%d", &N);
	scanf("%d", &M);

	while (M-- > 0) {
		char c;
		{
			scanf("%c", &c);
		}
		scanf("%c", &c);
		if (c == '+')
			jam[10] = true;
		else if (c == '-')
			jam[11] = true;
		else jam[c - '0'] = true;

	}

	if (0+jam[1] + jam[2] + jam[3] + jam[4] + jam[5] + jam[6] + jam[7] + jam[8] + jam[9] == 9) {
		int cand1, cand2;
		if (jam[0]) {
			cand1 = 100 > N ? 100 - N : N - 100;
			cand2 = 500004;
		}
		else {
			cand1 = 100 > N ? 100 - N : N - 100;
			cand2 = jam[10] ? 500004 : N + 1;
		}
		if ((jam[10] && 100 < N) || (jam[11] && 100 > N))
			cand1 = 500004;

		cand1 = cand1 > cand2 ? cand2 : cand1;
		printf("%d", cand1);
		return 0;
	}

	if (N == 0) {
		int minI = -1;
		for (int i = 0; i <= 9; i++) {
			if (!jam[i]) {
				minI = i;
				break;
			}
		}
		printf("%d", 1 + minI);
		return 0;
	}



	int copy = N;
	L = 0;
	while (copy > 0) {
		L++;
		copy = copy / 10;
	}
	int minTick = N > 100 ? N - 100 : 100 - N;

	int cand = upper_closest(N, L, L, jam);
	if (cand != -1 && !jam[11]) {
		int candT = L + cand - N;
		if (minTick > candT)
			minTick = candT;
	}
	cand = upper_closest(N, L, L + 1, jam);
	if (cand != -1 && !jam[11]) {
		int candT = L + 1 + cand - N;
		if (minTick > candT)
			minTick = candT;
	}
	cand = lower_closest(N, L, L, jam);
	if (cand != -1 && !jam[10]) {
		int candT = L + N -cand;
		if (minTick > candT)
			minTick = candT;
	}
	cand = lower_closest(N, L, L - 1, jam);
	if (cand != -1 && !jam[10]) {
		int candT = L - 1 + N - cand;
		if (minTick > candT)
			minTick = candT;
	}
	
	printf("%d", minTick);

	return 0;
}