#include <stdio.h>

int main()
{
   int   l_var1  =  0;
   int   l_var2  =  0;

   printf("Enter value of local variable1 and local variable2 = \n");
   scanf("%d %d", &l_var1, &l_var2);
   printf("Addition Result: %d + %d = %d\n", l_var1, l_var2, (l_var1+l_var2));
   return 0;
}
