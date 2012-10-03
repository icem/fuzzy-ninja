#include "FuzzyNinja/Examples/ComputePi/ProcessFactory.h"

#include "FuzzyNinja/Examples/ComputePi/MasterProcess.h"
#include "FuzzyNinja/Examples/ComputePi/SlaveProcess.h"

namespace FuzzyNinja
{
    namespace Examples
    {
        namespace ComputePi
        {

::FuzzyNinja::Interfaces::IProcess::SharedPtr ProcessFactory::createProcess(
    const int rank,
    const int processCount)
{
    if (rank == 0)
    {
        return std::make_shared<MasterProcess>(rank, processCount);
    }
    else
    {
        return std::make_shared<SlaveProcess>(rank, processCount);
    }
}

        }
    }
}
