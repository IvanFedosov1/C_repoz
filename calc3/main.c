#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>


int main(void) {
char exit;
    do {
        puts("\n The perform the operation, click Enter.");
        scanf("%c",&exit);
        char operation_type, command_type;
        FILE *in_file; // дескриптор входного файла (откуда возьмем данные, с которыми будем работать)
        FILE *out_file; // дескриптор выходного файла (куда запишем результат)

        in_file = fopen("input.txt","r");
        out_file = fopen("output.txt", "w");
        fscanf(in_file, "%c", &command_type);
        fscanf(in_file, " %c", &operation_type);

        switch (operation_type) {

            case 's': {
                int num1, num2, i;
                float result;

                fscanf(in_file, " %d", &num1);
                fscanf(in_file, " %d", &num2);

                switch (command_type) {
                    case '+':
                        result = num1 + num2;
                        fprintf(out_file, "%d + %d = %.0f", num1, num2, result);
                        break;

                    case '-':
                        result = num1 - num2;
                        fprintf(out_file, "%d - %d = %.0f", num1, num2, result);
                        break;

                    case '*':
                        result = num1 * num2;
                        fprintf(out_file, "%d * %d = %.0f", num1, num2, result);
                        break;

                    case '/':
                        result = num1 / num2;
                        fprintf(out_file, "%d / %d = %.0f", num1, num2, result);
                        break;

                    case '^':
                        result = 1; // нужно задать значение result, чтобы не испортить первый шаг цикла

                        for (i = 0; i < num2; i++) {
                            result = result * num1;
                        }
                        fprintf(out_file, "%d ^ %d = %.0f \n", num1, num2,
                                result);
                        break;

                    case '!':
                        if (num1 == 0) // если number == 0, то факториал считать не нужно, ответ 1
                        {
                            result = 1;
                        } else // если number != 0
                        {
                            result = 1;
                            for (i = 1; i <= num1; i++) {
                                result = result * i;
                            }
                        }
                        fprintf(out_file, "%d! = %.0f \n", num1, result);
                        break;

                    default:
                        puts("error: invalid operation symbol, fix file and try again");
                        break;
                }
                break;
            }
//векторы







            case 'v': {

                float *vector_1; // указатель на первый вектор. В этой переменной хранится адрес начала массива
                float *vector_2; // указатель на второй вектор. В этой переменной хранится адрес начала массива
                float *vector_result; // указатель на вектор, содержащий результат. В этой переменной хранится адрес начала массива
                int size = 0; // размер всех векторов. Прочитаем его из файла

                // выделяем память под векторы
                vector_1 = calloc(size,sizeof(int)); // функция calloc выделяет память для вектора. size - количество элементов, sizeof(int) - размер одного элемента
                vector_2 = calloc(size,sizeof(int)); // функция calloc выделяет память для вектора. size - количество элементов, sizeof(int) - размер одного элемента
                vector_result = calloc(size,sizeof(float)); // функция calloc выделяет память для вектора. size - количество элементов, sizeof(int) - размер одного элемента
                fscanf(in_file, " %d", &size);


                switch (command_type) {
                    case '+': {
                        //первая скобка
                        fprintf(out_file,"(");
                        for (int i = 0; i < size; i++) {
                            fscanf(in_file, "%f", &vector_1[i]);
                            fprintf(out_file," %.0f ", vector_1[i]);
                        }
                        fprintf(out_file,")");
                        fprintf(out_file," + ");


                        //вторая скобка
                        fprintf(out_file,"(");
                        for (int i = 0; i < size; i++) {
                            fscanf(in_file, "%f", &vector_2[i]);
                            fprintf(out_file," %.0f ", vector_2[i]);
                        }
                        fprintf(out_file,")");
                        fprintf(out_file," = ");



                        // результат
                        fprintf(out_file,"(");
                        for (int i = 0; i < size; i++) {
                            vector_result[i] = vector_1[i] + vector_2[i];
                            fprintf(out_file,"%.0f", vector_result[i]);
                            if (i != size - 1) fprintf(out_file," ");
                        }
                        fprintf(out_file,")");
                        break;
                    }
                    case '-':
                    { //первая скобка
                        fprintf(out_file,"(");
                        for (int i = 0; i < size; i++) {
                            fscanf(in_file, "%f", &vector_1[i]);
                            fprintf(out_file," %.0f ", vector_1[i]);
                        }
                        fprintf(out_file,")");
                        fprintf(out_file," - ");


                        //вторая скобка
                        fprintf(out_file,"(");
                        for (int i = 0; i < size; i++) {
                            fscanf(in_file, "%f", &vector_2[i]);
                            fprintf(out_file," %.0f ", vector_2[i]);
                        }
                        fprintf(out_file,")");
                        fprintf(out_file," = ");



                        // результат
                        fprintf(out_file,"(");
                        for (int i = 0; i < size; i++) {
                            vector_result[i] = vector_1[i] - vector_2[i];
                            fprintf(out_file,"%.0f", vector_result[i]);
                            if (i != size - 1) fprintf(out_file," ");
                        }
                        fprintf(out_file,")");
                        break;}




                    case '*':
                    { //первая скобка
                        fprintf(out_file,"(");
                        for (int i = 0; i < size; i++) {
                            fscanf(in_file, "%f", &vector_1[i]);
                            fprintf(out_file," %.0f ", vector_1[i]);
                        }
                        fprintf(out_file,")");
                        fprintf(out_file," * ");


                        //вторая скобка
                        fprintf(out_file,"(");
                        for (int i = 0; i < size; i++) {
                            fscanf(in_file, "%f", &vector_2[i]);
                            fprintf(out_file," %.0f ", vector_2[i]);
                        }
                        fprintf(out_file,")");
                        fprintf(out_file," = ");



                        // результат
                        fprintf(out_file,"(");
                        for (int i = 0; i < size; i++) {
                            vector_result[i] = vector_1[i] * vector_2[i];
                            fprintf(out_file,"%.0f", vector_result[i]);
                            if (i != size - 1) fprintf(out_file," ");
                        }
                        fprintf(out_file,")");
                        break;}



                    case '/':
                    { //первая скобка
                        fprintf(out_file,"(");
                        for (int i = 0; i < size; i++) {
                            fscanf(in_file, "%f", &vector_1[i]);
                            fprintf(out_file," %.0f ", vector_1[i]);
                        }
                        fprintf(out_file,")");
                        fprintf(out_file," / ");


                        //вторая скобка
                        fprintf(out_file,"(");
                        for (int i = 0; i < size; i++) {
                            fscanf(in_file, "%f", &vector_2[i]);
                            fprintf(out_file," %.0f ", vector_2[i]);
                        }
                        fprintf(out_file,")");
                        fprintf(out_file," = ");



                        // результат
                        fprintf(out_file,"( ");
                        for (int i = 0; i < size; i++) {
                            vector_result[i] = vector_1[i] / vector_2[i];
                            fprintf(out_file,"%.0f", vector_result[i]);
                            if (i != size - 1) fprintf(out_file," ");
                        }
                        fprintf(out_file," )");
                        break;}

                    default:
                        puts("error: invalid operation symbol, fix file and try again.");
                        break;
                }

                free(vector_1);
                free(vector_2);
                free(vector_result);
                break; // break относится к case 'v'
            }

            default:
                puts("error: invalid data type.");
                break;
        }
        fclose(in_file);
        fclose(out_file);

        puts("The operation is comleted. Check the file output.txt in the program folder.\n Press 'q' for exit.");

    }while(exit != 'q');
}
