#include "FuzzyNinja/Examples/ComputePi/MasterProcess.h"

namespace FuzzyNinja
{
    namespace Examples
    {
        namespace ComputePi
        {

MasterProcess::MasterProcess(int aRank, int aProcessCount)
    : Process(aRank, aProcessCount)
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
