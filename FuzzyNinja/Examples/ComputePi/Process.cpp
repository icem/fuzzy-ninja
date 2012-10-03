#include "FuzzyNinja/Examples/ComputePi/Process.h"

#include "FuzzyNinja/Objects/Communicator.h"

#include <stdio.h>

namespace FuzzyNinja
{
    namespace Examples
    {
        namespace ComputePi
        {

int Process::run()
{
    printf(
        "Running %d of %d ...\n",
        Objects::Communicator::World.getRank(),
        Objects::Communicator::World.getSize());
    return 0;
}

        }
    }
}
