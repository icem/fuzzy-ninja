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
private:
    int intervalCount;
public:
    explicit ProcessFactory(int anIntervalCount);
    virtual ::FuzzyNinja::Interfaces::IProcess::SharedPtr createProcess(
        const int aRank,
        const int aProcessCount);
};

        }
    }
}

#endif
