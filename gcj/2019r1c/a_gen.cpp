#include <cstdio>

int main() {
	printf("2\n");
	printf("2\n");
	for (int i = 0 ; i < 500 ; ++i)
		printf("P");
	printf("\n");
	for (int i = 0 ; i < 500 ; ++i)
		printf("S");
	printf("\n");

	printf("2\n");
	for (int i = 0 ; i < 499 ; ++i)
		printf("P");
	printf("\n");
	for (int i = 0 ; i < 499 ; ++i)
		printf("S");
	printf("\n");

	return 0;
}

