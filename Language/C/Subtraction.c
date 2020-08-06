#include "header.h"

int main()
{
   int   l_var1   =  0;
   int   l_var2   =  0;
   printf("Enter the value of local variable1 and local variable 2 = \n");
   scanf("%d %d", &l_var1, &l_var2);
   printf("Subtraction Result: %d - %d = %d\n", l_var1, l_var2, (l_var1 - l_var2));

   return 0;
}
