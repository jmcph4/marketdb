#ifndef TS_H_
#define TS_H_

#include <stdio.h>
#include <stdlib.h>

// descriptive statistics and measures of central tendency
double mean(int* series, int n);
int median(int* series, int n);
int mode(int* series, int n);
int min(int* series, int n);
int max(int* series, int n);
int range(int* series, int n);
double stddev(int* series, int n);

// time series functions
double SMA(int* series, int n, int m);
#endif
