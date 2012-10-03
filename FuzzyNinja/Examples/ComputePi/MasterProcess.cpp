#include "FuzzyNinja/Examples/ComputePi/MasterProcess.h"

#include <stdio.h>

namespace FuzzyNinja
{
    namespace Examples
    {
        namespace ComputePi
        {

MasterProcess::MasterProcess(int aRank, int aProcessCount, int anIntervalCount)
    : Process(aRank, aProcessCount), intervalCount(anIntervalCount)
{
    // Do nothing.
}

int MasterProcess::run()
{
    printf("intervalCount: %d\n", intervalCount);
    computePartially();
    return 0;
}

        }
    }
}
