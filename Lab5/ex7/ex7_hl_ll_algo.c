//** HIGH LEVEL (main) ALGORITHM
//  - // Where [3]:  [0] = kelvin, [1] = celsius, [2] = fahrenheit
//  - // Where [10]: number of samples  
//  - float temperatureSamples[3][10];
//  -
//  - handle_readSamples(temperatureSamples, 10);       // Get 10 kelvin samples and insert converted celsius and fahrenheit values into corresponding position
//  - handle_getStates(temperatureSamples[1], 10);      // Returns the state of water using celsius temp type
//  - handle_getMinMax(temperatureSamples[0], 10);      // We only need one array for this
//  - handle_getAverage(temperatureSamples, 10);        // Get the average of each unique temp scale
//  - handle_searchModule(temperatureSamples[0], 10);   // search the kelvin array to display a number of values
//  - 
//  - print("Press enter to quit program...");
//  - getchar();
//  - return;
// */


//** MODULE NAME: handle_readSamples 
//  LOW LEVEL ALGORITHM
//  ---- INPUT ----
//  - float temperatureSamples[][] 2D array 
//  - integer arrayLength (the limit)
// 
//  ---- OUTPUT ----
//  - 3x10 Different values are inserted into an array of arrays  
// 
//  ---- ALGORITHM ----
//  - float usersample <- 0;
//  - int   selectedIndex <- 0;
//  - bool  isValid <- 0;
//  
//  - While (index != arrayLength) 
//      - print ("Enter a  positive float value for sample {selectedIndex}: ");
//
//      - isValid <- read_SampleValue(usersample <- (reads a filtered float value from the user));
//      - 
//      - if (isValid == true)
//          - temperatureSamples[0][selectedindex]  <- usersample;
//          - temperatureSamples[1][selectedindex]  <- (usersample - 273.15);
//          - temperatureSamples[2][selectedindex]  <- (((usersample - 273.15) * 9/5) + 32);
//          - selectedIndex++;
//      - else
//          - print ("Cannot enter values below zero kelvin");
//  - 
//  - return;
// */

//** MODULE NAME: read_sampleValue
//  LOW LEVEL ALGORITHM
//  ---- INPUT ----
//  - float fuserValue
//  ---- OUTPUT ----
//  - float fuserValue
//  - bool isValid
// 
//  ---- ALGORITHM ----
//  - if (fuserValue <- (read a filtered float value from the user) != 1)
//      - print ("User did not enter a valid value");
//      - return false;
//  - if (fuserValue < 0)
//      - print ("User entered a value below 0");
//      - return false;
//  -
//  - return true;
// */



//** MODULE NAME: handle_getStates
//  LOW LEVEL ALGORITHM
//  ---- INPUT ----
//  - float celsiusSamples[] array
//  - integer arrayLength (the limit)
//  ---- OUTPUT ----
//  - none
//  ---- ALGORITHM ----
//  - for (int i <- 0; i < arrayLength; i++)
//      - 
//      - print ("Sample [{i + 1}]: ");
//      - print ("Temperature: {celsiusSamples[i]} C");
//      - print ("State: ");
//      - 
//      - if (celsiusSamples[i] <= 0)
//          - print ("Solid");
//      - else if (celsiusSamples[i] >= 100)
//          - print ("Gas");
//      - else
//          - print ("Liquid");
//      - 
//  - 
//  - return;
// */

//** MODULE NAME: handle_getMinMax
//  LOW LEVEL ALGORITHM
//  ---- INPUT ----
//  - float kelvinSamples[] array
//  - integer arrayLength
//  ---- OUTPUT ----
//  - none
//  ---- ALGORITHM ----
//  - int min <- 0;
//  - int max <- 0;
//  - 
//  - for (int i <- 0; i < arrayLength; i++)
//      - 
//      - if (kelvinSamples[min] > kelvinSamples[i])
//          - min <- i; 
//      - if (kelvinSamples[max] < kelvinSamples[i])
//          - max <- i;
//      - 
//  -
//  - print("Highest temp sample{min}: {kelvinSamples[min]}") 
//  -
//  - return;
// */

//** MODULE NAME: handle_getAverages
//  LOW LEVEL ALGORITHM
//  ---- INPUT ----
//  - float temperatureSamples[][] 2D array
//  - integer arrayLength
//  ---- OUTPUT ----
//  - none
//  ---- ALGORITHM ----
//  - float kel <- 0;
//  - float cel <- 0;
//  - float fah <- 0;
//  -
//  - for (int i <- 0; i < arrayLength; i++)
//      - 
//      - kel += temperatureSamples[0][i];
//      - cel += temperatureSamples[1][i];
//      - fah += temperatureSamples[2][i];
//      - 
//  -
//  - print ("Kelvin sample average: {kel / arrayLength}");
//  - print ("Celius sample average: {cel / arrayLength}"); 
//  - print ("Fahrenheit sample average: {fah / arrayLength}"); 
//  - 
//  - return;
// */

//** MODULE NAME: handle_searchModule
//  LOW LEVEL ALGORITHM
//  ---- INPUT ----
//  - float kelvinSamples[] array
//  - integer arrayLength
//  ---- OUTPUT ----
//  - none
//  ---- ALGORITHM ----
//  - float searchVal <- 0;
//  - int count;
//  - char quit <- 0;
//  - 
//  - do
//      - count <- 0;
//      - searchVal <- read_SampleValue((reads a filtered float value from the user));
//      - 
//      - count <- get_numberOfSamples();
//      - print ("Number of samples found below search value: {count}");
//      -
//      - quit <- (read a filtered char value from the user between "R and Q")
//      - if (quit == 'R')
//          - print ("User chose to retry search");
//      - else 
//          - print ("User chose to quit search");
//      - while(quit != 'Q');
//  -
//  - return;
// */

//** MODULE NAME: read_searchValue
//  LOW LEVEL ALGORITHM
//  ---- INPUT ----
//  - 
//  ---- OUTPUT ----
//  - float searchVal;
//  ---- ALGORITHM ----
//  - bool isValid <- false;
//  - float searchVal <- 0;
//  - do
//      - 
//      - print ("Please enter a non-nega")
//      - isValid <- read_SampleValue( searchVal <- (reads a filtered float value from the user))
//      - if (!isValid)
//          - print ("Please enter a valid search value. ")
//      - 
//  - while(isValid != false);
//  -
//  - return count;
// */

//** MODULE NAME: get_numberOfSamples
//  LOW LEVEL ALGORITHM
//  ---- INPUT ----
//  - float kelvinSamples[] array
//  - integer arrayLength
//  - float searchValue
//  ---- OUTPUT ----
//  - int count;
//  ---- ALGORITHM ----
//  - int count <- 0;
//      - for (int i <- 0; i < arrayLength; i++)
//          -  if (kelvinSample[i] < searchVal)
//              - count++;
//  -
//  - return count;
// */
