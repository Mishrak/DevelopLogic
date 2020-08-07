#include "header.h"

int main()
{
   float    l_base      =  0.0;
   float    l_height    =  0.0;
   float    l_area      =  0.0;

   printf("Enter the base value and height of the triangle\n");
   scanf("%f %f", &l_base, &l_height);
   l_area = 0.5 * l_base * l_height;
   printf("Area of Triangle = %g\n", l_area);

   return 0;
}
