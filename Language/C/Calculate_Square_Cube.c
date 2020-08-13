#include "header.h"

int main()
{
   float    l_var1      =  0.0;
   float    l_square    =  0.0;
   float    l_cube      =  0.0;

   printf("Enter the value of local variable\n");
   scanf("%f", &l_var1);
   l_square = powf(l_var1, 2);
   l_cube = powf(l_var1, 3);
   printf("Square of %f = %g\n", l_var1, l_square);
   printf("Cube of %f = %g\n", l_var1, l_cube);

   return 0;
}
