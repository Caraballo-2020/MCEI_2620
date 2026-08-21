#include <stdlib.h>
#include <stdio.h>


int main(){
  int a = 0;
  long b = 0;
  float c = 0.;
  double d = 0.;
  
  d = 3.*6.+5.;
  printf("El resultado es: %f\n\r", d);
  printf("Y su tamaño es: %ld\n\r", sizeof(a));
  printf("Y su tamaño es: %ld\n\r", sizeof(b));
  printf("Y su tamaño es: %ld\n\r", sizeof(c));
  printf("Y su tamaño es: %ld\n\r", sizeof(d));

  return 0;
}
