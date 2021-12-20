#include<stdio.h>
#include<time.h>

void main()
{
  time_t rawtime;
  struct tm * timeinfo;
  time( &rawtime );
  timeinfo = localtime( &rawtime );
  printf("%02d", timeinfo->tm_hour);
}