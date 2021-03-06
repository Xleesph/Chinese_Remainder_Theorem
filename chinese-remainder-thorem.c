//Matthaios Chouliaras icsd12207
#include <stdio.h>

int mul_inv(int a, int b){
	int b0 = b, t, q;
	int x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b; t = b; b = a % b; a = t;
		t = x0; x0 = x1 - q * x0; x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}

int CRT(int *n, int *a, int len)
{
	int p, i, prod = 1, sum = 0;

	for (i = 0; i < len; i++) prod *= n[i];

	for (i = 0; i < len; i++) {
		p = prod / n[i];
		sum += a[i] * mul_inv(p, n[i]) * p;
	}

	return sum % prod;
}

int main(void)
{
	int n[] = { 7, 6, 5 };
	int a[] = { 6, 2, 0 };

	printf("oi ravdoi xrysou einai: %d\n", CRT(n, a, sizeof(n)/sizeof(n[0])));
	return 0;
}
