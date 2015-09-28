#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libpq-fe.h>

#include "db.h"
#include "ts.h"

#define TOTAL 7394

int main(int argc, char** argv)
{
  if(argc != 2)
  {
    printf("Usage: %s ticker\n", argv[0]);
    
    return EXIT_SUCCESS;
  }
  
  int res = 0;
  
  long long* timestamp;
  int* open;
  int* high;
  int* low;
  int* close;
  int* volume;
  char name[128];
  char ticker[128];
  
  /***************************************************************************/
  
  res = load_ts(get_id_from_ticker(argv[1]), &timestamp, &open, &high, &low, 
                &close, &volume);
  
  if(res == EXIT_FAILURE)
  {
    return EXIT_FAILURE;
  }
  
  get_name_from_id(5, name);
  get_ticker_from_id(5, ticker);
  
  printf("--- QUOTE FOR %s ---\n", ticker);
  printf("Name:         %s\n", name);
  printf("Latest Price: $%.2f\n", (float)(close[0]/100));
  printf("Mean Price:   $%.2f\n", mean(close, TOTAL)/100);
  printf("Min. Price:   $%.2f\n", (float)min(close, TOTAL)/100);
  printf("Max. Price:   $%.2f\n", (float)max(close, TOTAL)/100);
  printf("Std. Dev.:    $%.2f\n", stddev(close, TOTAL)/100);
  printf("\n\n\n");
  
  if(close[0] < mean(close, TOTAL/100))
  {
    printf("Security is currently trading $%.2f below historical averages.\n", 
           (mean(close, TOTAL)/100) - ((float)(close[0]/100)));
  }
  else if(close[0] >= mean(close, TOTAL/100))
  {
    printf("Security is currently trading $%.2f above historical averages.\n", 
           ((float)(close[0]/100)) - (mean(close, TOTAL)/100));
  }
  
  /***************************************************************************/
  
  free(timestamp);
  free(open);
  free(high);
  free(low);
  free(close);
  free(volume);
  
  
  return EXIT_SUCCESS;
}