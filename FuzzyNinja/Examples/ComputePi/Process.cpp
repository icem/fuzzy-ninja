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

void Process::computePartially() const
{
    printf("computePartially\n");
}

        }
    }
}
