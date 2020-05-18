#ifndef DATARECIEVER_H
#define DATARECIEVER_H
#include <windows.h>
#include <malloc.h>
#include <stdio.h>
#include "TCHAR.h"
#include "pdh.h"

#pragma comment(lib,"pdh.lib")

class datareciever
{
public:

    PDH_HQUERY cpuQuery;
    PDH_HCOUNTER cpuTotal;

    datareciever();
    int NumberOfCores();
    double CPUPercents();

private:

    int getNumberOfCores();
    double getCPUPercents();

    SYSTEM_INFO sysinfo;

};

#endif // DATARECIEVER_H
