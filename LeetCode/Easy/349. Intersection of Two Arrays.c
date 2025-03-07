/**
 * LeetCode - Zadanie 349. Intersection of Two Arrays. Rozwiązanie zadania z
 * użyciem tablicy hash (hash set).
 * Link do rozwiązania: https://leetcode.com/submissions/detail/1566286670/
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size,
                  int* returnSize) {
    // Maksymalny rozmiar zwracanej tablicy - nie przekroczy on ilości elementów
    // mniejszej tablicy nums.
    int size = (nums1Size < nums2Size) ? nums1Size : nums2Size;

    // Alokacja pamięci dla zwracanej tablicy. Calloc automatycznie inicjalizuje
    // elementy tablicy zerami.
    int* result = calloc(sizeof(int), size);

    // Zabezpieczenie w przypadku jeśli alokacja się nie powiedzie
    if (result == NULL)
        return NULL;

    // Stworzenie hash setu - ustalenie 1001 elementów, gdzie 1001 to maksymalna
    // wartość nums1[i] oraz nums2[i]. Będzie ona przechowywała tylko dwie
    // wartości: 1 - element istnieje oraz 0 - element nie istnieje bądź
    // się powtarza. Można by także użyć typu char, który także zajmuje 1 bajt.
    bool hash[1001] = {0};

    // Zapisanie indexów tablicy hash, gdzie index określa wartość i-tego
    // elementu nums1 bez powtórzeń.
    for (int i = 0; i < nums1Size; i++) {
        hash[nums1[i]] = 1;
    }

    // Zmienna iterowana w przypadku znalezienia wspólnego elementu
    int j = 0;

    for (int i = 0; i < nums2Size; i++) {
        // Jeśli element z tablicy hash o indexie o wartości i-tego elementu z
        // tablicy nums2 == 1, czyli element ten znajduje się w tablicy nums1.
        if (hash[nums2[i]] == 1) {
            result[j++] = nums2[i];

            // Ustawienie tego elementu na 0, aby pominąć go przy następnych
            // iteracjach (dla tych samych liczb - bez powtórzeń)
            hash[nums2[i]] = 0;
        }
    }

    // Ustawienie realnego rozmiaru zwracanej tablicy jako j - czyli liczbę
    // znalezionych elementów wspólnych
    *returnSize = j;

    return result;
}