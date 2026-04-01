#include<stdio.h>

int main()
{
    /* Thresholds for different grades. */
    const float threshold1 = 100;
    const float threshold2 = 80;
    const float threshold3 = 70;
    const float threshold4 = 60;
    const float threshold5 = 50;
    const float supThreshold = 40;
    const float maxComponentMark = 50;
    const float examPassMark = 25;
    
    float pracMark;     // The mark out of 50 for the student's practical component of the marks.
    float examMark;     // The mark out of 50 for the student's exam component of the marks.
    float finalMark;    // The total mark out of 100 for both components.
    
    printf("What is the practical mark of this student (out of 50)?: ");
    scanf("%f", &pracMark);
    
    if ((pracMark < 0) || (pracMark > maxComponentMark))
    {
        printf("The practical mark is not valid. The mark component should be between 0 and 50.\n");
        return 0;
    }
    
    printf("What is the exam mark of this student (out of 50)?: ");
    scanf("%f", &examMark);
    
    if ((examMark < 0) || (examMark > maxComponentMark))
    {
        printf("The exam mark is not valid. The component mark should be between 0 and 50.\n");
        return 0;
    }
    
    /* If all input is valid - calculate the final mark. */
    finalMark = pracMark + examMark;
    printf("The student's final mark is: %f\n", finalMark);
        
    if (finalMark < supThreshold) /* Check whether the student has failed outright. */
    {
        printf("The student has been awarded the grade: F.\n");
    }
    /* Check whether the student needs to do a supplementary exam. */
    else if (examMark < examPassMark)
    {
        printf("The student has been awarded the grade: SX.\n");
    }
    /* Exam has been passed, therefore check which threshold the mark falls under. */
    /* Check whether it is an HD. */
    else if (finalMark >= threshold2)
    {
        printf("The student has been awarded the grade: HD.\n");
    }
    /* Check whether it is an D. */
    else if (finalMark >= threshold3)
    {
        printf("The student has been awarded the grade: D.\n");
    }
    /* Check whether it is an C. */
    else if (finalMark >= threshold4)
    {
        printf("The student has been awarded the grade: C.\n");
    }
    /* Check whether it is an P. */
    else if (finalMark >= threshold5)
    {
        printf("The student has been awarded the grade: P.\n");
    }
    else /* The student falls into the supplementary range. */
    {
        printf("The student has been awarded the grade: SA.\n");
    }
    
    return 0;
}
