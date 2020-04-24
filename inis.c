#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int sim(){

}

int main(void){
  srand(time(NULL));
  double x, y;
  int a = 58;
  x = rand() / (double) RAND_MAX;
  y = 1 / a * exp(-1 * x / a);
  print(y)
}
