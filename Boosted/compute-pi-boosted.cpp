#include <iostream>

#include <boost/mpi/environment.hpp>
#include <boost/mpi/communicator.hpp>

void print_help()
{
    ::std::cout << "Usage: mpiexec compute-pi-boosted <interval count>"
                << ::std::endl;
}

int main(int argc, char *argv[])
{
    ::boost::mpi::environment env(argc, argv);
    ::boost::mpi::communicator world;

    if (argc != 2)
    {
        print_help();
        return 1;
    }

    return 0;
}
