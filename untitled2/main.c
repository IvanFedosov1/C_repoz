#include <stdio.h>
#include <stdlib.h>

main () {
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