/* 
* [WERSJA ROBOCZA!]
* LeetCode - Zadanie 1154. Day of the Year. 
* Ten kod nie przeszedł test case dla daty = * "1900-02-29" na leetcode. 
* Jest to jeden nie poprawny case, pozostałe 10958 przeszedł poprawnie.  
* 1900-02-29 może być niepoprawną datą.
*
* Rozwiązanie te jest trochę "przydługawe" - to dlatego, że chciałem je rozwiązać
* w postaci biblioteki, która może mi się przydać na przyszłość.
* Targetem tej biblioteki mają być mikrokontrolery, a więc w przyszłości
* planuje ją gruntownie przebudować (jeśli w ogóle mi się przyda taka biblioteka). 
*
* Może być przydatne: https://chatgpt.com/c/67c381fb-bca8-8003-9d53-eb1692ca6bcc
*/

typedef enum {
    JANUARY = 1,
    FEBRUARY = 2,
    MARCH = 3,
    APRIL = 4,
    MAY = 5,
    JUNE = 6,
    JULY = 7,
    AUGUST = 8,
    SEPTEMBER = 9,
    OCTOBER = 10,
    NOVEMBER = 11,
    DECEMBER = 12
} Months;

// Tablica okreslająca dni w danych miesiącach (numerowanych od 1 do 12).
// Pierwszy index = -1, aby zaczynać od 1 (JANUARY)
// Tablica ta jest dla roku nieprzęstnepnego!
static int daysInMonth[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int day(const char* date);
int month(const char* date);
int dayOfMonth(const char* date);
int dayOfYear(const char* date);
bool isLeapYear(const char* date);
bool isValidDateFormat(const char* date);

// Zwraca dzień z podanej daty
int day(const char* date) {
    if (!isValidDateFormat(date)) return -1;
    int d = ((date[8] - '0') * 10) + (date[9] - '0');
    int maxDay = dayOfMonth(date); 
    return (d >= 1 && d <= maxDay) ? d : -1; // sprawdzenie czy poprawny zakres
}

// Zwraca miesiąc z podanej daty
int month(const char* date) {
    if (!isValidDateFormat(date)) return -1;
    int m = ((date[5] - '0') * 10) + (date[6] - '0');
    int maxMonth = 12;
    return (m >= 1 && m <= maxMonth) ? m : -1; // sprawdzenie czy poprawny zakres
}

// Zwraca który to dzień w miesiącu
int dayOfMonth(const char* date) {
    if (!isValidDateFormat(date)) return -1;
    int m = month(date);
    if (m == -1) return -1;
    if(isLeapYear(date) && m == FEBRUARY) return 29;
    return daysInMonth[m];
}

// Zwraca który to dzień w roku
int dayOfYear(const char* date) {
    if (!isValidDateFormat(date)) return -1;
    int d = day(date);
    int m = month(date);
    if (d == -1 || m == -1) return -1;

    int result = d;
    for(int i = 1; i < m; i++) 
        result += daysInMonth[i];

    if (isLeapYear(date) && m > 2) result++; 
    return result;
}

// 
bool isLeapYear(const char* date) {
    int year = ((date[0] - '0') * 1000) + ((date[1] - '0') * 100) + ((date[2] - '0') * 10) + (date[3] - '0');
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 
bool isValidDateFormat(const char* date) {
    if (strlen(date) != 10) return false;
    for (int i = 0; i < 10; i++) {
        if ((i == 4 || i == 7) && date[i] != '-') return false;
        if ((i != 4 && i != 7) && !isdigit(date[i])) return false;
    }
    return true;
}