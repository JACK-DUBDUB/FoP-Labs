#ifndef FUNC_H
#define FUNC_H

// Defined constants
#define LIMIT           4
#define FEETPERMILE     5280
#define FEETPERMETER    3.28084

// Declare functions
double getRunnerTimes();
void calculateRunnerTimes(double runnerTimes[]);
void displayRunnertimes(double speedFeet, double speedMeters, double runnerTime, int index);
void pauseExitProgram();

#endif