#include "FuzzyNinja/Examples/ComputePi/Program.h"
#include "FuzzyNinja/Examples/ComputePi/ProcessFactory.h"

#include "FuzzyNinja/MpiApplication.h"

#include <stdio.h>

namespace FuzzyNinja
{
    namespace Examples
    {
        namespace ComputePi
        {

void Program::PrintHelp()
{
    printf("Usage: mpiexec -n <process-count> compute-pi <interval-count>\n\n");
}

int Program::Main(int argc, char *argv[])
{
    int intervalCount;

    ::FuzzyNinja::MpiApplication application(&argc, &argv);
    if (argc != 2)
    {
        PrintHelp();
        return 1;
    }

    sscanf(argv[1], "%d", &intervalCount);
    ::FuzzyNinja::Examples::ComputePi::ProcessFactory processFactory(
        intervalCount);
    return application.run(processFactory);
}

        }
    }
}

int main(int argc, char *argv[])
{
    return ::FuzzyNinja::Examples::ComputePi::Program::Main(argc, argv);
}
