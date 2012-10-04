#include "FuzzyNinja/Examples/ComputePi/MasterProcess.h"

#include "FuzzyNinja/Objects/Communicator.h"
#include "FuzzyNinja/Objects/Broadcast.h"

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
    Objects::Broadcast all(0, Objects::Communicator::World);

    fprintf(
        stderr,
        "[%d] intervalCount: %d\n",
        rank,
        intervalCount);
    all << intervalCount;
    computePartially(intervalCount);
    return 0;
}

        }
    }
}
