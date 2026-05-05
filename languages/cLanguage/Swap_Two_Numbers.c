#include "header.h"

int main()
{
   float    l_var1      =  0.0;
   float    l_var2      =  0.0;
   float    l_temp      =  0.0;

   printf("Enter the value of local variable1\n");
   scanf("%g", &l_var1);
   printf("Enter the value of local variable2\n");
   scanf("%g", &l_var2);

   printf("Before Swapping:\nl_var1 = %g : l_var2 = %g\n", l_var1, l_var2);
   l_temp = l_var1;
   l_var1 = l_var2;
   l_var2 = l_temp;
   printf("After Swapping:\nl_var1 = %g : l_var2 = %g\n", l_var1, l_var2);

   return 0;
}
