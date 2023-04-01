#include <stdio.h>

   // CHECK FOR GREATEST COMMON DIVIDOR (GCD)
   int gcd(int num1, int num2) {
      if (num2 == 0) {
         return num1;
      } else {
         return gcd(num2, num1 % num2);
      }
   }

   // CHECK FOR LEAST COMMON DIVISOR (LCM)
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

   // CHECK FOR PRIME NUMBERS
   int is_prime(int nums) {
      if (nums <= 1) {
         return 0;
      }
      for (int i = 2; i * i <= nums; i++) {
         if (nums % i == 0) {
            return 0;
         }
      }
      return 1;
   }

int main() {
   int num1, num2;
   char operater;
   int num, n, square=0;

   printf("***************************************************A calculator in C*************************************************** \n");
   printf("To add, multiply, divide or minus enter 1: \n");
   printf("To find GCD enter 2: \n");
   printf("To find LCM enter 3: \n");
   printf("To find Prime numbers enter 4: \n");
   printf("To find square of numbers enter 5: \n");
   printf("************************************************************************************************************************ \n");
   scanf("%d", &num);


   // LOGIC operations
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

   // GCD
   else if (num == 2)
   {
      printf("Enter the first number:\n ");
      scanf("%d", &num1);
      printf("Enter the second number: \n");
      scanf("%d", &num2);

      int results = gcd(num1, num2);

      printf("The GCD of %d and %d is %d\n", num1, num2, results);
   }


   // LCM
   else if (num == 3)
   {
      printf("Enter the first number: ");
      scanf("%d", &num1);
      printf("Enter the second number: ");
      scanf("%d", &num2);

      int result = lcm(num1, num2);

      printf("The LCM of %d and %d is %d\n", num1, num2, result);
   }

   // Prime numbers
   else if (num == 4)
   {
      printf("Enter the lower number limit of the range to get Prime numbers : \n");
      scanf("%d", &num1);
      printf("Enter the upper number limit of the range to get Prime numbers: \n");
      scanf("%d", &num2);

      printf("The prime numbers between %d and %d are:\n", num1, num2);

      for (int nums = num1; nums <= num2; nums++) {
         if (is_prime(nums)) {
            printf("%d, ", nums);
         }
      }
      printf("\n");
   }

   // Square of Numbers
   else if (num == 5)
   {
      printf("Enter the range you want to get squares: \n");
      scanf("%d", &num1);

      for (int i=1; i<=num1;i++)
      {
         n = i;
         square = n * n;
         printf("Square of %d = %d \n", n, square);

      }

   }

   return 0;
}
