#include "header.h"

int main()
{
   int      l_var1   =  0;
   float    l_var2   =  0;
   printf("Enter the value of local variable1 and local variable 2 = \n");
   scanf("%d %f", &l_var1, &l_var2);
   printf("Subtraction Result: %d / %f = %f\n", l_var1, l_var2, (float)(l_var1 / l_var2));

   return 0;
}
