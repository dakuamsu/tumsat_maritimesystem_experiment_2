#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _USER_MATH_DEFINES
#include <math.h>

double in(double a){
  double x, y;
  srand(time(NULL));
  x = rand() / (double) RAND_MAX;
  y = -1 / a * log(x);
  return y;
}

double out(double pi, double sig, double b){
  double s, t, o;
  srand(time(NULL));
  s = rand() / (double) RAND_MAX;
  t = rand() / (double) RAND_MAX;
  o = sqrt(-2 * log(s)) * cos(2 * pi * t)* sig;
  return o;
}

int main(void){
  srand(time(NULL));
  double x, y, s, t;
  double a = 54;
  double b = 60 / 4 + 48;
  double sig = 0.01;
  double pi = 3.14159265358979323846;
  double time = 0;
  int yard = 0;
  int done = 0;
  s = t = 0;
  x = in(a);
  yard += 1;
  s += x;
  t += s;
  y = out(pi,sig,b);
  t += y;
  int i = 0;
  while(i != 100){
      i += 1;
      printf("%d個目入場 ヤードには%d個 %f時間経過\n", i, yard, s);
      x = in(a);
      s += x;
      if(s > t){
          yard -= 1;
          done += 1;
          y = out(pi,sig,b);
          printf("%f\n",y);
          printf("%d個目捌いた ヤードには%d個 %f時間経過\n", done, yard, t);
          if(yard == 0){
              t += s;
          }
          else{
              t += y;
          }
      }
      else{
          x = in(a);
          yard += 1;
          s += x;
          i+= 1;
          printf("%d個目入場 ヤードには%d個 %f時間経過\n", i, yard, s);
      }
      yard += 1;
  }
  yard -= 1;
  while (yard >0){
      y = out(pi,sig,b);
      t += y;
      done++;
      yard -= 1;
      printf("%d個目捌いた ヤードには%d個 %f時間経過\n", done, yard, t);
  }
  printf("\n%d個捌くまでにかかった時間は%f時間\n", done, t);
}