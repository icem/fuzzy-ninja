#ifndef FUZZY_NINJA_EXAMPLES_COMPUTE_PI_PROCESS_FACTORY_H
#define FUZZY_NINJA_EXAMPLES_COMPUTE_PI_PROCESS_FACTORY_H

#include "FuzzyNinja/Interfaces/IProcess.h"
#include "FuzzyNinja/Interfaces/IProcessFactory.h"

namespace FuzzyNinja
{
    namespace Examples
    {
        namespace ComputePi
        {

class ProcessFactory: public ::FuzzyNinja::Interfaces::IProcessFactory
{
public:
    virtual ::FuzzyNinja::Interfaces::IProcess::SharedPtr createProcess(const int rank);
};

        }
    }
}

#endif
