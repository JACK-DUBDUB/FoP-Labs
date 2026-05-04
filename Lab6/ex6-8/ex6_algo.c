/* EX6
- Write a program that reads a string -> where max length N cannot exceed 100 
- program converts the strings characters to lower case (replaces original string)
-
*/

/* (EX6 only) HIGH LEVEL ALGORITHM (main)
- 
- // Step 1.
- int string_length <- handle_readStringLength(); 
- char user_string[string_length]; 
- 
- // Step 2.
- handle_readUserString(user_string); 
- 
- // Step 3.
- handle_convertToLower(user_string)
-
- // Step 5.
- handle_displayUserString(vowel_string) 
-
- return 0; // Successful exit
*/

/* MODULE read_stringLength
Input:
    - none

Output:
    - value string_length of type Int;

Algorithm
    - integer string_length <- 0;
    - boolean valid <- false;
    - do {
            print ("Please enter a number between 0 and {max}"); // max = 100
            valid <- (read an integer value from user using filter (<- string_length));
            if (!valid) 
                print ("User did not enter a value between 0 and {max}"); // max = 100
        } while (!valid)
    - return string_length;
*/

/* MODULE handle_readUserString
Input:
    - string user_string  (char *);
    - value string_length of type integer (int);

Output:
    - value string_length of type Int;

Algorithm
    - print("Please entere a string: ");
    - fgets(user_string, string_length, stdin); // (Buffer, MaxCount, Stream )
    - return;
*/


/* MODULE handle_convertToLower
Input:
    - value user_string of type string (char*)

Output:
    - none (modification of a string)

Algorithm
    - for (int i <- 0; user_string[i] != '\0'; i++ )
    {
        - user_string[i] <- tolower(user_string[i])
    }
    - return;
*/

/* MODULE handle_displayStrings
Input:
    - value user_string of type string (char*)

Output:
    - none

Algorithm
    - print ("{user_string}");
    - return;
*/




