#include "FuzzyNinja/Examples/ComputePi/ProcessFactory.h"

#include "FuzzyNinja/Examples/ComputePi/Process.h"

namespace FuzzyNinja
{
    namespace Examples
    {
        namespace ComputePi
        {

::FuzzyNinja::Interfaces::IProcess::SharedPtr ProcessFactory::createProcess(const int rank)
{
    return std::make_shared<Process>();
}

        }
    }
}
