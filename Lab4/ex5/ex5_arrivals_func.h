#ifndef EX5_FUNC
#define EX5_FUNC

// Defined constants
#define ARRLIMIT    2       // User array limit
#define LOOPLIMIT   3       // For loop limit
#define TWELVE_H    12      // 12 hours
#define SIXTY_M     60      // 60 minutes


// Declared functions
int getTime(const char *CLOCKDISP_S[]);
double getDistanceOrSpeed();
void calculations(int arrivalTime, double dist, double speed, const char *CLOCKDISP_S[]);
void displayTime(int h, int m, const char *disp);
void displayCalculations(int hrs[], int min[], int ampm[], double dist, double speed, const char *CLOCKDISP_S[], int validTime);
void pauseExitProgram();


#endif