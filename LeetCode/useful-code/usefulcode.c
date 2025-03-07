// sprawdza czy liczba jest parzysta
bool isEven(int n) {
    return (n & 1) == 0;
}

// duplikuje tablice int
int * intdup(int const * src, size_t len) {
   int * p = malloc(len * sizeof(int));
   if(p == NULL) return NULL;
   memcpy(p, src, len * sizeof(int));
   return p;
}

// wyświetla tablicę int
void printArray(int* array, int len) {
    for(int i = 0; i < len; i++) {
        printf("%d, ", array[i]);
    }
    printf("\n");
}

// pokazuje binarną postać w strumieniu wyjściowym
void showbits(unsigned int x) {
    int i = 0;
    for (i = (sizeof(int) * 8) - 1; i >= 0; i--) {
       putchar(x & (1u << i) ? '1' : '0');
    }
    printf("\n");
}

// zlicza bity 1 w liczbie
int hammingWeight(int n) {
    int counter = 0;
    for(int i = 0; i < sizeof(int) * 8; i++) {
        if(n & (1u << i)) counter++;
    }
    return counter;
}