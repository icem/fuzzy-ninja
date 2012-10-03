#ifndef FUZZY_NINJA_EXAMPLES_COMPUTE_PI_SLAVE_PROCESS_H
#define FUZZY_NINJA_EXAMPLES_COMPUTE_PI_SLAVE_PROCESS_H

#include "FuzzyNinja/Examples/ComputePi/Process.h"

namespace FuzzyNinja
{
    namespace Examples
    {
        namespace ComputePi
        {

class SlaveProcess: public Process
{
public:
    SlaveProcess(int aRank, int aProcessCount);
    virtual int run();
};

        }
    }
}

#endif
