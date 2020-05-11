#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _USER_MATH_DEFINES
#include <math.h>
#include "SFMT.h"

/* 入ってくるコンテナの関数 */
double in(double a){
  double x, y;
  srand(time(NULL));
  x = sfmt_genrand_real2(&sfmt) ;
  y = -1 / a * log(x);
  return y;
}

/* 裁くコンテナの関数 */
double out(double pi, double sig, double b){
  double s, t, o;
  s = sfmt_genrand_real2(&sfmt) ;
  t = sfmt_genrand_real2(&sfmt) ;
  o = sqrt(-2 * log(s)) * cos(2 * pi * t)* sig;
  return o;
}

int main(void){
  sfmt_t sfmt;
  int seed = time(NULL);
  sfmt_init_gen_rand(&sfmt, seed);
  double x, y, s, t;
  double a = 54;  /* 18 * 3 */
  double b = 60 / 4 + 48;  /* 学籍番号下二桁のやつ */
  double sig = 0.01; /* 標準偏差わからんから適当に入れる */
  double pi = 3.14159265358979323846;  /* 円周率の定義 */
  double time = 0;  /* 時間の初期化 */
  int yard = 0;  /* ヤードにあるコンテナの数の初期化 */
  int done = 0;  /* 捌いた数の初期化 */
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
