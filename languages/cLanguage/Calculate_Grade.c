#include "header.h"
int main()
{
   int   l_var1      =  0;
   int   l_num       =  0;
   float l_arr[10]   =  {0.0};
   float l_average   =  0.0;
   float l_total     =  0.0;
   char  l_name[50]  =  "0";

   do
   {
      printf("Enter Your Name\n");
      scanf("%s", l_name);
      printf("Enter the Total Subjects:");
      scanf("%d", &l_num);
      for(l_var1 = 1; l_var1 <= l_num; l_var1++)
      {
         printf("Enter Marks of subject %d\n", l_var1);
         scanf("%g", &l_arr[l_var1]);
         l_total = l_total + l_arr[l_var1];
      }
      l_average = l_total / l_num;
      if (l_average >= 60.0)
      {
         printf("%s got Grade A\nCongratulations!\n", l_name);
         break;
      }
      else if ((l_average >= 50) && (l_average < 60))
      {
         printf("%s got Grade B\nCongratulations!\n", l_name);
         break;
      }
      else if ((l_average >= 40) && (l_average < 50))
      {
         printf("%s got Grade C\nCongratulations!\n", l_name);
         break;
      }
      else
      {
         printf("%s got Grade F\nI am Sorry\n", l_name);
      }
   }while(0);

   return 0;
}
