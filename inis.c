#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <SFMT.h>



int sim(){

}

int main(void){
  srand(time(NULL));
  double x, y, z, w;
  double a = 54;
  double b = 60 / 4 + 48;
  x = rand() / (double) RAND_MAX;
  y = 1 / a * log(x);
  z = rand() / (double) RAND_MAX;

}
