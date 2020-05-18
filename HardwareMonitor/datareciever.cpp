#include "datareciever.h"



datareciever::datareciever()
{
    PdhOpenQuery(NULL, NULL, &cpuQuery);
    PdhAddEnglishCounter(cpuQuery, L"\\Processor(_Total)\\% Processor Time", NULL, &cpuTotal);
    PdhCollectQueryData(cpuQuery);
}

int datareciever::NumberOfCores()
{
    return getNumberOfCores();
}

double datareciever::CPUPercents()
{
    return getCPUPercents();
}

int datareciever::getNumberOfCores(){

    GetSystemInfo(&sysinfo);
    int numCPU = sysinfo.dwNumberOfProcessors;

    if(numCPU <= 0){
        return 0;
    }else{
        return numCPU;
    }

}
double datareciever::getCPUPercents(){

    PDH_FMT_COUNTERVALUE counterVal;

       PdhCollectQueryData(cpuQuery);
       PdhGetFormattedCounterValue(cpuTotal, PDH_FMT_DOUBLE, NULL, &counterVal);

    return counterVal.doubleValue;
}
