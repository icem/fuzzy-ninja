#include "FuzzyNinja/Examples/ComputePi/SlaveProcess.h"

#include "FuzzyNinja/Objects/Communicator.h"
#include "FuzzyNinja/Objects/Broadcast.h"
#include "FuzzyNinja/Objects/Reduce.h"

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
    double partialValue = 0.0;
    Objects::Broadcast root(0, Objects::Communicator::World);
    Objects::Reduce reduce(0, Objects::Communicator::World, MPI_SUM);

    root >> intervalCount;
    partialValue = computePartially(intervalCount);
    reduce << partialValue;

    return 0;
}

        }
    }
}
