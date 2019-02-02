#include <stdio.h>
#include <stdlib.h>

int main() {
  char name[100], age[100], year[100], gender[100], eye_color[100],
      hair_color[100];

  printf("What is your name?\n");
  fgets(name, 100, stdin);

  printf("What is your age?\n");
  fgets(age, 100, stdin);

  printf("What is your year?\n");
  fgets(year, 100, stdin);

  printf("What is your gender?\n");
  fgets(gender, 100, stdin);

  printf("What is your eye color?\n");
  fgets(eye_color, 100, stdin);

  printf("What is your hair color?\n");
  fgets(hair_color, 100, stdin);

  printf("\nName: %sAge: %sYear: %sGender: %sEye Color: %sHair Color: %s", name,
         age, year, gender, eye_color, hair_color);
}