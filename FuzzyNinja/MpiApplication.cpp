#include "FuzzyNinja/MpiApplication.h"
#include "FuzzyNinja/MpiEnvironment.h"
#include "FuzzyNinja/Objects/Communicator.h"

#include <mpi.h>

namespace FuzzyNinja
{

MpiApplication::MpiApplication(int *argc, char **argv[])
{
    MpiEnvironment::initialize(argc, argv);
}

int MpiApplication::run(::FuzzyNinja::Interfaces::IProcessFactory &aProcessFactory)
{
    int rank = Objects::Communicator::World->getRank();
    int processCount = Objects::Communicator::World->getSize();
    return aProcessFactory.createProcess(rank, processCount)->run();
}

MpiApplication::~MpiApplication()
{
    MpiEnvironment::finalize();
}

}
