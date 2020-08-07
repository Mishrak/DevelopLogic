#include "header.h"

int main()
{
   float    l_radius =  0.0;
   float    l_area   =  0.0;
   printf("Enter the radius of the circle\n");
   scanf("%f", &l_radius);
   l_area = 3.14 * (l_radius * l_radius);
   printf("Area of Circle = %g\n", l_area);
   return 0;
}
