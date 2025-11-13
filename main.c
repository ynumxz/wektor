// TEN PLIK NIE JEST DO EDYCJI!!!
// DO NOT EDIT!!!
#include "wektor.c"
#include <stdio.h>
#include <string.h>

void printVector(struct Wektor *w) {
  printf("Wektor: ");
  for (int i = 0; i < w->count; i++) {
    int value;
    if (get(w, i, &value)) {
      printf("%d ", value);
    }
  }
  printf("\n");
}

int main() {
  struct Wektor wektor;
  create(&wektor, 2);

  char command[20];
  int value, index;

  while (1) {
    fprintf(stderr, "\nDostępne komendy: push, get, set, print, exit\n");
    fprintf(stderr, "Wprowadź komendę: ");
    scanf("%19s", command);

    if (strcmp(command, "push") == 0) {
      fprintf(stderr, "Podaj wartość do dodania: ");
      scanf("%d", &value);
      push_back(&wektor, value);
    } else if (strcmp(command, "get") == 0) {
      fprintf(stderr, "Podaj indeks: ");
      scanf("%d", &index);
      if (get(&wektor, index, &value)) {
        printf("Wartość na miejscu %d: %d\n", index, value);
      } else {
        printf("Błąd: nieprawidłowy indeks.\n");
      }
    } else if (strcmp(command, "set") == 0) {
      fprintf(stderr, "Podaj indeks: ");
      scanf("%d", &index);
      fprintf(stderr, "Podaj wartość do ustawienia: ");
      scanf("%d", &value);
      if (set(&wektor, index, value)) {
        printf("Ustawiono wartość %d na miejscu %d.\n", value, index);
      } else {
        printf("Błąd: nieprawidłowy indeks.\n");
      }
    } else if (strcmp(command, "print") == 0) {
      printVector(&wektor);
    } else if (strcmp(command, "exit") == 0) {
      break;
    } else {
      printf("Nieznana komenda.\n");
    }
  }

  del(&wektor);
  return 0;
}
