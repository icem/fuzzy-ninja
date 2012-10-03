#include "Program.h"

#include "MpiApplication.h"

namespace FuzzyNinja
{
    namespace Examples
    {
        namespace ComputePi
        {

        }
    }
}

int main(int argc, char *argv[])
{
    ::FuzzyNinja::MpiApplication application(&argc, &argv);
    return application.run();
}
