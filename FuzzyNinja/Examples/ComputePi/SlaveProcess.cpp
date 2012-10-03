#include "FuzzyNinja/Examples/ComputePi/SlaveProcess.h"

namespace FuzzyNinja
{
    namespace Examples
    {
        namespace ComputePi
        {

SlaveProcess::SlaveProcess(int aRank, int aProcessCount)
    : Process(aRank, aProcessCount)
{
    // Do nothing.
}

int SlaveProcess::run()
{
    computePartially();
    return 0;
}

        }
    }
}
