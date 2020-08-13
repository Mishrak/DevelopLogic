#include "header.h"

int main()
{
   float    l_var1      =  0.0;
   float    l_var2      =  0.0;
   float    l_var3      =  0.0;
   float    l_Total     =  0.0;
   float    l_Average   =  0.0;

   printf("Enter the value of local variable1\n");
   scanf("%f", &l_var1);
   printf("Enter the value of local variable2\n");
   scanf("%f", &l_var2);
   printf("Enter the value of local variable3\n");
   scanf("%f", &l_var3);
   l_Total = l_var1 + l_var2 + l_var3;
   l_Average = l_Total / 3;
   printf("Total: %f + %f + %f = %g\n", l_var1, l_var2, l_var3, l_Total);
   printf("Average: %f + %f + %f = %g\n", l_var1, l_var2, l_var3, l_Average);

   return 0;
}
