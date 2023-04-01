#include <stdio.h>


   int gcd(int num1, int num2) {
      if (num2 == 0) {
         return num1;
      } else {
         return gcd(num2, num1 % num2);
      }
   }

   int least(int num1, int num2) {
      while (num2 != 0) {
         int temp = num2;
         num2 = num1 % num2;
         num1 = temp;
      }
      return num1;
   }

   int lcm(int num1, int num2) {
      return (num1 * num2) / least(num1, num2);
   }

int main() {
   int num1, num2;
   char operater;
   int num;

   printf("***************************************************A calculator in C*************************************************** \n");
   printf("To add, multiply, divide or minus enter 1: \n");
   printf("To find GCD enter 2: \n");
   printf("To find LCM enter 3: \n");
   scanf("%d", &num);


   if (num == 1) {
      printf("Enter the first number: ");
      scanf("%d", &num1);
      printf("Enter the second number: ");
      scanf("%d", &num2);

      printf("Enter an operator (+, -, *, /): ");
      scanf(" %c", &operater);


      if (operater == '+') {
         printf("%d + %d = %d\n", num1, num2, num1+num2);
      } 
      else if (operater == '-') {
         printf("%d - %d = %d\n", num1, num2, num1-num2);
      } 
      else if (operater == '*') {
         printf("%d * %d = %d\n", num1, num2, num1*num2);
      } 
      else if (operater == '/') {
         if (num2 == 0) {
            printf("Error: Cannot divide by zero\n");
         } else {
            printf("%d / %d = %d\n", num1, num2, num1/num2);
         }
      }
      else {
         printf("Invalid operator\n");
      }
   }
   else if (num == 2)
   {
      printf("Enter the first number:\n ");
      scanf("%d", &num1);
      printf("Enter the second number: \n");
      scanf("%d", &num2);

      int results = gcd(num1, num2);

      printf("The GCD of %d and %d is %d\n", num1, num2, results);
   }
   else if (num == 3)
   {
      printf("Enter the first number: ");
      scanf("%d", &num1);
      printf("Enter the second number: ");
      scanf("%d", &num2);

      int result = lcm(num1, num2);

      printf("The LCM of %d and %d is %d\n", num1, num2, result);
   }

   return 0;
}
