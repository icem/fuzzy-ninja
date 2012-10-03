#include "FuzzyNinja/Examples/ComputePi/Program.h"
#include "FuzzyNinja/Examples/ComputePi/ProcessFactory.h"

#include "FuzzyNinja/MpiApplication.h"

namespace FuzzyNinja
{
    namespace Examples
    {
        namespace ComputePi
        {

int Program::Main(int argc, char *argv[])
{
    ::FuzzyNinja::MpiApplication application(&argc, &argv);
    ::FuzzyNinja::Examples::ComputePi::ProcessFactory processFactory;
    return application.run(processFactory);
}

        }
    }
}

int main(int argc, char *argv[])
{
    return ::FuzzyNinja::Examples::ComputePi::Program::Main(argc, argv);
}
