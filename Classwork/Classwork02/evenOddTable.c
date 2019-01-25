#include <stdio.h>

const char* isEvenOrOdd(int num){
  if(num % 2 == 0){
    return "Even";
  } else {
    return "Odd";
  }
}

int main( int argc, char * argv[] ) {
  int i;

  for(i = -10; i < 11; i++){
    printf("%d \t %d \t %s \n", i, (i * i), isEvenOrOdd(i));
  }
}
