#include <string.h>
#include <math.h>

#include "ts.h"

double mean(int* series, int n)
{
  int i = 0;
  int sum = 0;
  double mean = 0.0;

  for(i=0;i<n;i++)
  {
    sum += series[i];
  }
  
  mean = sum / n;
  
  return mean;
}

int min(int* series, int n)
{
  int i = 0;
  int min = 0;
  
  for(i=0;i<n;i++)
  {
    if(i == 0)
    {
      min = series[i];
    }
    
    if(series[i] < min)
    {
      min = series[i];
    }
  }
  
  return min;
}

int max(int* series, int n)
{
  int i = 0;
  int max = 0;
  
  for(i=0;i<n;i++)
  {
    if(i == 0)
    {
      max = series[i];
    }
    
    if(series[i] > max)
    {
      max = series[i];
    }
  }
  
  return max;
}

int range(int* series, int n)
{
  int range = 0;
  
  range = max(series, n) - min(series, n);
  
  return range;
}

double stddev(int* series, int n)
{
  int i = 0;
  double average = mean(series, n);
  
  int* deviations = malloc(n * sizeof(int));
  
  for(i=0;i<n;i++)
  {
    deviations[i] = abs(series[i] - average);
  }
  
  double variance = mean(deviations, n);
  
  double sigma = sqrt(variance);
  
  return sigma;
}

double SMA(int* series, int n, int m)
{
  int i = 0;
  int sum = 0;
  double sma = 0.0;
  
  if(m <= n && m > 0)
  {
    for(i=0;i<m;i++)
    {
      sum += series[i];
    }  
    
    printf("%d\n", sum);
  
    sma = sum / m;
  }
  
  return sma;
}