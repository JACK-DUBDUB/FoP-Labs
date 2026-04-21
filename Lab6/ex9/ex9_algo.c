


/* EX9
- Write a program that reads a string -> max length cannot exceed 100 
-
- Requires: 2 char arrays (strings), string_1, string_2
- 1. Read an number from the user that is n > 0 && n < 100
- 2. Read a string from the user -> string_1
- 3. Count the number of vowels of string_1
- 4. Copy the vowels from string_1 into string_2
- 5. Display string_2
- 6. Count the number of times each vowel appears in the string
-    Display the index of first occurrence - if no occurrence display a suitable message

*/

/* HIGH LEVEL ALGORITHM (main)
- 
- // Step 1.
- int string_length <- handle_readStringLength(); 
- char user_string[string_length]; 
- 
- // Step 2.
- handle_readUserString(user_string); 
- 
- // Step 3.
- int user_string_vowels[5][string_length];
- int vowel_count <- handle_countVowels(user_string, user_string_vowels); 
-
- // Step 4.
- char vowel_string[vowel_count];
- handle_insertVowels(user_string, vowel_string); 
-
- // Step 5.
- handle_displayUserString(vowel_string) 
-
- // Step 6.
- handle_displayUserVowels(user_string_vowels);
-
- return 0; // Successful exit
*/


