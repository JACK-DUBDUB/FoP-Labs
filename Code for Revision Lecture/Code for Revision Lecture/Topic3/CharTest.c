//
//  CharTest.c
//  
//
//  Created by Robert Herne on 8/3/2026.
//

#include <stdio.h>

int main ()
{
    char var1;  // var1 is a variable that can hold characters
    var1 = 'a'; // Now var1 will have the value a, i.e., its content is character a
    char var2;
    var2 = ';'; // Now the value of var2 is the semicolon character
    char var3;
    var3 = '7'; // Now var3 has the character 7 not the number 7
    printf("%c\n", var1);  // to print characters, use %c
    printf("%d\n", var1); // what do you notice??
}
