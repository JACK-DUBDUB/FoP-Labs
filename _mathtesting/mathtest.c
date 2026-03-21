








#include <stdio.h>
#include <math.h>



///
#define LIMIT 11

int main()
{

    int tn_0 = 3;

    printf("Where Tn = {2n^2 + n} , n >= 1\n\n");

    for (int i = 0; i < LIMIT; i++)
    {
        int n1 = i;
        int n2 = n1 + 1;
        double nSquared = (pow(n1, 2));
        double answer1 = (2 * nSquared + (n1));

        printf("T_%d = 2(%.lf) + %d + %.lf =  %.lf    \n", n1, nSquared , n1, 3, answer1);

        double constant1 = (4.0 * i);
        double constant2 = (3.0);
        double answer2 = (answer1 + constant1 + constant2);
        printf("T_%d = %.lf + %.lf + %.lf =  %.lf    \n\n", n1, answer1, constant1, constant2, answer2);

    }




    return 0;
}
