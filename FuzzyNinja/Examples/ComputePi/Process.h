#ifndef FUZZY_NINJA_EXAMPLES_COMPUTE_PI_PROCESS_H
#define FUZZY_NINJA_EXAMPLES_COMPUTE_PI_PROCESS_H

#include "FuzzyNinja/Interfaces/IProcess.h"

namespace FuzzyNinja
{
    namespace Examples
    {
        namespace ComputePi
        {

class Process: public ::FuzzyNinja::Interfaces::IProcess
{
private:
    int rank;
    int processCount;
protected:
    void computePartially() const;
public:
    Process(int aRank, int aProcessCount);
    virtual int run() = 0;
};

        }
    }
}

#endif
