#include "FuzzyNinja/Examples/ComputePi/MasterProcess.h"

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
    computePartially();
    return 0;
}

        }
    }
}
