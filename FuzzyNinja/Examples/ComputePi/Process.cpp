#include "FuzzyNinja/Examples/ComputePi/Process.h"

#include "FuzzyNinja/Objects/Communicator.h"

#include <stdio.h>

namespace FuzzyNinja
{
    namespace Examples
    {
        namespace ComputePi
        {

Process::Process(int aRank, int aProcessCount)
    : rank(aRank), processCount(aProcessCount)
{
    // Do nothing.
}

double Process::computePartially(int anIntervalCount) const
{
    int i;
    double partialValue = 0.0;
    double h;
    double sum = 0.0;
    double x;

    fprintf(
        stderr,
        "[%d] computePartially %d\n",
        rank,
        anIntervalCount);

    h = 1.0 / anIntervalCount;
    for (i = rank + 1; i <= anIntervalCount; i += processCount)
    {
        x = h * ((double)i - 0.5);
        sum += 4.0 / (1.0 + x*x);
    }
    partialValue = h * sum;

    fprintf(stderr, "[%d] partialValue: %.12lf\n", rank, partialValue);
    return partialValue;
}

        }
    }
}
