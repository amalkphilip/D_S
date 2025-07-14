#include <stdio.h>

struct poly {
    int coef;
    int expo;
} p1[10], p2[10], p3[20];

int main() {
    int term1, term2, i, j, k = 0;

    printf("FIRST POLYNOMIAL\n");
    printf("Enter the number of terms: ");
    scanf("%d", &term1);
    for (i = 0; i < term1; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &p1[i].coef, &p1[i].expo);
    }

    printf("\nSECOND POLYNOMIAL\n");
    printf("Enter the number of terms: ");
    scanf("%d", &term2);
    for (i = 0; i < term2; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &p2[i].coef, &p2[i].expo);
    }

    i = 0;
    j = 0;

    // Add polynomials
    while (i < term1 && j < term2) {
        if (p1[i].expo == p2[j].expo) {
            p3[k].coef = p1[i].coef + p2[j].coef;
            p3[k].expo = p1[i].expo;
            i++; j++; k++;
        } else if (p1[i].expo > p2[j].expo) {
            p3[k] = p1[i];
            i++; k++;
        } else {
            p3[k] = p2[j];
            j++; k++;
        }
    }

    // Copy remaining terms
    while (i < term1) {
        p3[k++] = p1[i++];
    }

    while (j < term2) {
        p3[k++] = p2[j++];
    }

    // Print result
    printf("\nRESULTANT POLYNOMIAL: ");
    for (int a = 0; a < k; a++) {
        printf("%dX^%d", p3[a].coef, p3[a].expo);
        if (a < k - 1)
            printf(" + ");
    }

    return 0;
}
