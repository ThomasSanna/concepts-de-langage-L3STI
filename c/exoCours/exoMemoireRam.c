#include <stdio.h>

int main() {
	char C = 'a';
	int A = 256;
	int B = 129;

	char *pC = NULL;
	int *pA = NULL;
	int *pB = NULL;
	pC = &C;
	pA = &A;
	pB = &B;

	printf("Adresse de C = %p\n", pC);
	printf("Code ASCII du caractère %c = %i\n", C, C);
	printf("Adresse de A = %p\n", pA);
	printf("Adresse de B = %p\n", pB);


	return 0;
}
