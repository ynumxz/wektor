Napisz program w języku C, składający się z dwóch plików:

- wektor.c - zawierającego definicję struktury Wektor oraz implementacje funkcji:
    - `void create(struct Wektor *w, unsigned int size)` - która alokuje tablicę wielkości `size` intów.
    - `void push_back(struct Wektor *w, int element)` - która dodaje element na koniec dynamicznej tablicy, powiększając ją dwukrotnie, jeśli brakuje miejsca.
    - `int get(struct Wektor *w, int index, int *result)` - która pobiera element na podanym indeksie i zapisuje go w result. Zwraca 1 w przypadku sukcesu lub 0, jeśli indeks jest poza zakresem (większy równy niż count lub mniejszy od 0).
    - `int set(struct Wektor *w, int index, int element)` - która ustawia wartość elementu na podanym indeksie, zwracając 1 w przypadku sukcesu lub 0 w przypadku nieprawidłowego indeksu.
    - `void del(struct Wektor *w)` - zwalnia pamięć przypisaną dynamicznie do wektora, oraz ustawia po zwolnieniu wskaźnik na NULL.
- main.c - głównego programu, który wczytuje polecenia od użytkownika, pozwalając na wywołanie funkcji z wektor.c (dołączonego za pomocą `#include "wektor.c"`). Uwaga! Ten plik nie należy pisać, jest on załączony do zadania. Nie należy go również zmieniać!

### Dodatkowy opis

Plik wektor.c zawiera:

- Strukturę Wektor, zawierającą:
    - Dynamicznie alokowaną tablicę liczb całkowitych (`int *data`),
    - Zmienną size przechowującą aktualny rozmiar zaalokowanej tablicy,
    - Zmienną count, która przechowuje bieżącą liczbę elementów w tablicy.
- Funkcję 
- Funkcję `push_back(struct Wektor *w, int element)`, która:
    - Sprawdzi, czy w tablicy jest wystarczająco dużo miejsca na nowy element.
    - Jeśli tak, doda element na końcu tablicy i zwiększy count.
    - Jeśli nie, powiększy tablicę dwukrotnie i przeniesie istniejące elementy, a następnie doda nowy element.
- Funkcję `int get(struct Wektor *w, int index, int *result)`, która:
    - Zwróci element znajdujący się na podanym indeksie poprzez wskaźnik result.
    - Jeśli indeks jest w zakresie $0 \le \text{index} < \text{count}$, ustawi wynik we wskaźniku result i zwróci 1 jako sukces.
    - Jeśli indeks jest poza zakresem, zwróci 0 i nie zmieni wartości wskazywanej przez result.
- Funkcję `int set(struct Wektor *w, int index, int elemnt)`, która:
    - Nadpisze element na podanym indeksie, jeśli indeks jest prawidłowy (w zakresie 0 <= index < count), i zwróci 1.
    - Jeśli indeks jest poza zakresem, zwróci 0, nie modyfikując tablicy.
