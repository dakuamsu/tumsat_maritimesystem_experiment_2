#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double sig(double b){
  double k;
  int i = 0;
  double ave = 0;
  int sum = 0;
  srand(time(NULL));
  while (ave == b){
  k = rand() / (double) RAND_MAX;
  i ++;
  sum += k;
  ave = sum / i;
  }
}

int sim(){

}

int main(void){
  srand(time(NULL));
  double x, y;
  double a = 54;
  double b = 60 / 4 + 48;
  x = rand() / (double) RAND_MAX;
  y = 1 / a * log(x);
  printf("%f\n",y);
}
