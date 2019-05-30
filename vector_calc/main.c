#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main() {
   printf("Vibirite s chem rabotat: 1) 4isla 2) vectori\n") ;
   int logic;
   scanf("%d", &logic);
   switch (logic){

       case 1: {
           float a, b, c = 1, otvet;  //объявляем переменные
           int number;


           int z = 1;
           while (z == 1) {                         //программа заключена в цикл для возможности рестарта
               printf("enter two numbers a i b\n");
               scanf("%f%f", &a, &b);                //ввод и сохранение переменных
               printf("summ: 1\n");
               printf("razn: 2\n");
               printf("umnojenie: 3\n");
               printf("delenie: 4\n");
               printf("stepen(a^b): 5\n");
               printf("factorial(ot a): 6\n");
               printf("enter number of operation\n");
               scanf("%d", &number);
               switch (number) {         //выбор операции реализован переключаетелем switch так как в нашей ситуации это удобнее чем if else
                   case 1:               //поскольку занимает меньше кода
                       printf("otvet %f\n", a + b);
                       break;
                   case 2:
                       printf("otvet %f\n", a - b);
                       break;
                   case 3:
                       printf("otvet %f\n", a * b);
                       break;
                   case 4:
                       printf("otvet %f\n", a / b);
                       break;
                   case 5:
                       otvet =  pow(a, b);
                       printf("otvet %f\n", otvet);
                       break;
                   case 6:
                       while (a != 0) {
                           c = c * a;
                           a = a - 1;
                           if (a==0)
                           {
                               printf("otvet %f\n", c);
                           }
                       }
                       break;
               }
               printf("restart: enter 1, exit: enter 2\n");     //условие выполнения цикла это z = 1 если изменить её на любое другое число, цикл завершится
               scanf("%d", &z);
       }
   }

   case 2: {

       float *vector1, *vector2;
       int size, f;

       printf("Enter razmernost vectora: ");
       scanf("%d", &size);

       vector1 = calloc(size,sizeof(float));
       for (int i = 0; i < size; i++) {
           printf("Enter cords first vector (a): ");
           scanf("%f", &vector1[i]);
       }

       vector2 = calloc(size,sizeof(float));

       for (int i = 0; i < size; i++) {
           printf("Enter cords second vector (b): ");
           scanf("%f", &vector2[i]);
       }

       int k;
       puts("\n select operation:    1) \"+\" - summ\n    2) \"-\" - razn\n    3) \"*\" - skalyar *");
       printf("select command: ");
       scanf("%d", &k);

       f = 0;
       while(f == 0) {
           if(k > 0 && k < 4){
               f = 1;
           }
           else {
               printf("Not have this cammand! Select command from list: ");
               scanf("%d", &k);
           }
       }

       float result = 0;
       switch(k) {
           case 1:
               printf("\n Result: (");
               for (int i = 0; i < size; i++) {
                   printf("%.2f", vector1[i] + vector2[i]);
                   if (i != size-1) printf(" ");
               }
               printf(")\n\n");
               break;
           case 2:
               printf("\n Result: (");
               for (int i = 0; i < size; i++) {
                   printf("%.2f", vector1[i] - vector2[i]);
                   if (i != size-1) printf(" ");
               }
               printf(")\n\n");
               break;
           case 3:
               for (int i = 0; i < size; i++) {
                   result += vector1[i] * vector2[i];
               }
               printf("\n Result: %.2f\n\n", result);
               break;
       }
       free(vector1);
       free(vector2);

       return EXIT_SUCCESS;


        }
    }
}


