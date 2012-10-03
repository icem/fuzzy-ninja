#ifndef FUZZY_NINJA_EXAMPLES_COMPUTE_PI_MASTER_PROCESS_H
#define FUZZY_NINJA_EXAMPLES_COMPUTE_PI_MASTER_PROCESS_H

#include "FuzzyNinja/Examples/ComputePi/Process.h"

namespace FuzzyNinja
{
    namespace Examples
    {
        namespace ComputePi
        {

class MasterProcess: public Process
{
private:
    int intervalCount;
public:
    MasterProcess(
        int aRank,
        int aProcessCount,
        int anIntervalCount);
    virtual int run();
};

        }
    }
}

#endif
