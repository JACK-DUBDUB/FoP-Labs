#include "statistics.h"

float ComputeDiffMaxMean(float A, float B, float C)
{
    float max, mean, res;
    
    max = ComputeMax(A, B, C);
    mean = ComputeMean(A, B, C);
    res = ComputeDiff(max, mean);
    
    return res;
}

float ComputeMax(float A, float B, float C)
{
    float res = A;
    
    if (B > res)
    {
        res = B;
    }
    
    if (C > res)
    {
        res = C;
    }
    
    return res;
}

float ComputeMean(float A, float B, float C)
{
    float res;
    
    res = ((A + B + C) / 3);
    
    return res;
}

float ComputeDiff(float A, float B)
{
    float res;
    
    res = A - B;
    
    return res;
}
