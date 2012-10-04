#include "FuzzyNinja/Examples/ComputePi/SlaveProcess.h"

#include "FuzzyNinja/Objects/Communicator.h"
#include "FuzzyNinja/Objects/Broadcast.h"

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
    int intervalCount = 0;
    Objects::Broadcast root(0, Objects::Communicator::World);

    root >> intervalCount;
    computePartially(intervalCount);
    return 0;
}

        }
    }
}
