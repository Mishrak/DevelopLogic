#include "header.h"

int main()
{
   float    l_principle       =  0.0;
   int      l_time            =  0;
   float    l_rate            =  0;
   float    l_simple_interest =  0.0;

   printf("Enter the principle amount\n");
   scanf("%f", &l_principle);
   printf("Enter the time period involed\n");
   scanf("%d", &l_time);
   printf("Enter the rate of interest per year\n");
   scanf("%f", &l_rate);

   l_simple_interest = ((l_principle * l_time * l_rate) / 100);
   printf("Simple Interest = %f\n", l_simple_interest);

   return 0;
}
