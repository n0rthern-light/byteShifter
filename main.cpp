#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

#define __ROL__(x, y) _rotl(x, y)
inline unsigned int __ROL4__(unsigned int value, int count) { return __ROL__((unsigned int)value, count); }
inline unsigned int __ROR4__(unsigned int value, int count) { return __ROL__((unsigned int)value, -count); }

void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;
    
    for (i = size-1; i >= 0; i--) {
	for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
       }

	printf(" ");
    }
}

int main(int argc, char** argv) {
	
	if (argc != 2) {
		printf("1 params required input");
		return 1;
	}

	char* input = argv[1];
	unsigned int length = strlen(input);

	printf("%s (%u)\n\n", input, length);

	unsigned int i = 0;
	int result = 0;

	printf("-1 (4_) -> ");
	printBits(4, &result);
	printf(" -> %i", result);

	for(i = 0; i < length; ++i) {
		result = __ROR4__(result, 9);
		printf("\n%u (ror) -> ", i);
		printBits(4, &result);
		printf(" -> %i", result);
		char c = *(char*)(i + input);
		printf("\n%u (x_%c) -> ", i, c);
		result = result ^ c;
		printBits(4, &result);
		printf(" -> %i", result);
	}

	int wanted_result = 422115604;

	printf("\nX (exp) -> ");
	printBits(4, &wanted_result);
	printf(" -> %i", wanted_result);


	return 0;
}
