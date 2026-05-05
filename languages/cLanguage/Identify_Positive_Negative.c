#include "header.h"

int main()
{
   int   l_var1   =  0;
   int   l_temp   =  0;
   printf("Enter the value of local variable1\n");
   scanf("%d", &l_var1);
   do
   {
      /*
      if(l_var1 != 0)
      {
         if (l_var1 > 0)
         {
            printf("%d is Positive number\n", l_var1);
            break;
         }
         else
         {
            printf("%d is Negative number\n", l_var1);
            break;
         }
      }
      else
      {
         printf("%d is neither Positive nor Negative. It's ZERO\n", l_var1);
      }
      */
      if((((l_var1 >> ((sizeof(int) * 8) - 1)) & 1)) == 1)
      {
         printf("%d is Negative number\n", l_var1);
         break;
      }
      else
      {
         for(l_temp = 0; l_temp <= ((sizeof(int) * 8) - 1); l_temp++)
         {
            if (((1 << l_temp) && l_var1) == l_var1)
            {
               printf("%d is Positive Number\n", l_var1);
               break;
            }
            else
            {
               printf("%d is neither Positive nor Negative. It's ZERO\n", l_var1);
               break;
            }
         }

      }
   }while(0);
   return 0;
}

