#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <chrono>
#include "tri_tri_intersect.c"
#include <iostream>
#include <chrono>
#include "datatype.h"
/*---------------------------------*/
using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;
/*---------------------------------*/
void Test(){
  double v0[PAIR_NUMBER][3], v1[PAIR_NUMBER][3], v2[PAIR_NUMBER][3];
  double u0[PAIR_NUMBER][3], u1[PAIR_NUMBER][3], u2[PAIR_NUMBER][3];
  int i, j;
  int nResult, nNumber;
  int nCount = 0;
  // __int64 time;
  // Load test data
  FILE * lf1 = fopen("data/intersected.txt", "r");
  if (lf1 == NULL)
  {
    printf("Make sure if the data sets has been generated successfully.");
    return;
  }
  FILE * lf2 = fopen("data/separated.txt", "r");
  if (lf1 == NULL)
  {
    printf("Make sure if the data sets has been generated successfully.");
    fclose(lf1);
    return;
  }
  nNumber = PAIR_NUMBER * INTERSECTION_RATIO;
  for (i=0; i<nNumber; i++) {
    fscanf(lf1, "%lf %lf %lf", &v0[i][0], &v0[i][1], &v0[i][2]);
    fscanf(lf1, "%lf %lf %lf", &v1[i][0], &v1[i][1], &v1[i][2]);
    fscanf(lf1, "%lf %lf %lf", &v2[i][0], &v2[i][1], &v2[i][2]);
    fscanf(lf1, "%lf %lf %lf", &u0[i][0], &u0[i][1], &u0[i][2]);
    fscanf(lf1, "%lf %lf %lf", &u1[i][0], &u1[i][1], &u1[i][2]);
    fscanf(lf1, "%lf %lf %lf", &u2[i][0], &u2[i][1], &u2[i][2]);
  }
  for (i=nNumber; i<PAIR_NUMBER; i++) {
    fscanf(lf2, "%lf %lf %lf", &v0[i][0], &v0[i][1], &v0[i][2]);
    fscanf(lf2, "%lf %lf %lf", &v1[i][0], &v1[i][1], &v1[i][2]);
    fscanf(lf2, "%lf %lf %lf", &v2[i][0], &v2[i][1], &v2[i][2]);
    fscanf(lf2, "%lf %lf %lf", &u0[i][0], &u0[i][1], &u0[i][2]);
    fscanf(lf2, "%lf %lf %lf", &u1[i][0], &u1[i][1], &u1[i][2]);
    fscanf(lf2, "%lf %lf %lf", &u2[i][0], &u2[i][1], &u2[i][2]);
  }
  fclose(lf2);
  fclose(lf1);
  //
  // Test performance
  // CStopwatch watch;
  auto t1 = high_resolution_clock::now(); 
  for (j=0; j<LOOP_NUMBER; j++){
    for (i=0; i<PAIR_NUMBER; i++){
      // nResult = tri_tri_intersect(u0[i], u1[i], u2[i], v0[i], v1[i], v2[i]);
      nResult = tri_tri_intersection_test_3d(u0[i], u1[i], u2[i], v0[i], v1[i], v2[i]);
      nCount+=nResult;
    }
  }
  auto t2 = high_resolution_clock::now();
  auto ms_int = duration_cast<milliseconds>(t2 - t1);
  duration<double, std::milli> ms_double = t2 - t1;
  // time = watch.Now(MICROSECOND);
  cout << "nCount = " <<nCount <<endl;
  cout << "Time taken =" << ms_int.count() << "ms\n";
  cout << "Time taken = " << ms_double.count() << "ms\n";
  cout << "Intersection ratio=" << (double) nCount/(LOOP_NUMBER*PAIR_NUMBER) << endl;
}
int main(){
  Test();
}