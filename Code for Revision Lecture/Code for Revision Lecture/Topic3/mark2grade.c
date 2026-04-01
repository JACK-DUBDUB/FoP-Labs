#include<stdio.h>

int main()
{
    float mark;
    
    const float threshold1 = 100;
    const float threshold2 = 80;
    const float threshold3 = 70;
    const float threshold4 = 60;
    const float threshold5 = 50;
    const float supThreshold = 40;
    
    printf("What is the mark of this student?: ");
    scanf("%f", &mark);
    
    /* First check whether the mark is out of the valid range. */
    if ((mark < 0) || (mark > threshold1))
    {
        printf("The mark is not valid. The mark should be between 0 and 100.\n");
    }
    /* Then check if it falls between any of the thresholds. */
    else if (mark >= threshold2)
    {
        printf("The student has been awarded the grade: HD.\n");
    }
    else if (mark >= threshold3)
    {
        printf("The student has been awarded the grade: D.\n");
    }
    else if (mark >= threshold4)
    {
        printf("The student has been awarded the grade: C.\n");
    }
    else if (mark >= threshold5)
    {
        printf("The student has been awarded the grade: P.\n");
    }
    else if (mark >= supThreshold)
    {
        printf("The student has been awarded the grade: SX.\n");
    }
    else /* Mark must be below minimum passing threshold. */
    {
        printf("The student has been awarded the grade: F.\n");
    }
    
    return 0;
}
