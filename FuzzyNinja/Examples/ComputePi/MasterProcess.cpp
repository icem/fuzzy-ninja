#include "FuzzyNinja/Examples/ComputePi/MasterProcess.h"

#include "FuzzyNinja/MpiEnvironment.h"
#include "FuzzyNinja/Objects/Communicator.h"
#include "FuzzyNinja/Objects/Broadcast.h"
#include "FuzzyNinja/Objects/Reduce.h"

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
    double partialValue = 0.0;
    double result = 0.0;

    double startTime;
    double endTime;

    Objects::Broadcast all(0, Objects::Communicator::World);
    Objects::Reduce reduce(0, Objects::Communicator::World, MPI_SUM);

    fprintf(
        stderr,
        "[%d] intervalCount: %d\n",
        rank,
        intervalCount);

    startTime = MpiEnvironment::getTime();
    all << intervalCount;
    partialValue = computePartially(intervalCount);
    result = reduce << partialValue;
    endTime = MpiEnvironment::getTime();

    fprintf(
        stderr,
        "[%d] result: %.12lf\n",
        rank,
        result);
    fprintf(stderr,
        "[%d] elapsed time: %lfs\n",
        rank,
        endTime - startTime);

    return 0;
}

        }
    }
}
