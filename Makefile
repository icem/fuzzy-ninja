#!/usr/bin/make -f

CC = gcc
CC_FLAGS = -Wall -Werror -O3 -flto
CXX = g++
CXX_FLAGS = -Wall -Werror -O3 -flto
MPI_INCLUDE_PATH = /usr/include/mpi
MPIXX = mpic++
MPIXX_FLAGS = -Wall -Werror -O3 -flto

LIB_FUZZY_NINJA_TARGETS = \
	obj/FuzzyNinja/MpiException.o \
	obj/FuzzyNinja/MpiApplication.o \
	obj/FuzzyNinja/MpiEnvironment.o \
	obj/FuzzyNinja/Interfaces/IProcess.o \
	obj/FuzzyNinja/Interfaces/IProcessFactory.o \
	obj/FuzzyNinja/Objects/Communicator.o \
	obj/FuzzyNinja/Objects/Broadcast.o \
	obj/FuzzyNinja/Objects/Reduce.o

COMPUTE_PI_TARGETS = \
	obj/FuzzyNinja/Examples/ComputePi/Program.o \
	obj/FuzzyNinja/Examples/ComputePi/ProcessFactory.o \
	obj/FuzzyNinja/Examples/ComputePi/Process.o \
	obj/FuzzyNinja/Examples/ComputePi/MasterProcess.o \
	obj/FuzzyNinja/Examples/ComputePi/SlaveProcess.o

# Main targets.

build: \
	bin/libfuzzyninja.a \
	bin/compute-pi \
	bin/compute-pi-old \
	bin/compute-pi-boosted
	@echo '[ Built. ]'

clean:
	@echo '[ Removing build output ... ]'
	@rm --recursive --force obj/
	@rm --recursive --force bin/
	@echo '[ Cleaned up. ]'

# Shared.

obj/%.o: %.cpp
	@echo '[ Compiling $< ... ]'
	@mkdir --parents $(@D)
	@$(CXX) $(CXX_FLAGS) \
		-I$(MPI_INCLUDE_PATH) \
		-I. \
		-c $< \
		-o $@ \
		-std=c++0x

# Projects.

bin/libfuzzyninja.a: $(LIB_FUZZY_NINJA_TARGETS)
	@echo '[ Making library $@ ... ]'
	@mkdir --parents $(@D)
	@ar rcs $@ $^
	@ranlib $@

bin/compute-pi: \
		bin/libfuzzyninja.a \
		$(COMPUTE_PI_TARGETS)
	@echo '[ Making executable $@ ... ]'
	@mkdir --parents $(@D)
	@$(CXX) $(CXX_FLAGS) \
		$(COMPUTE_PI_TARGETS) \
		-Lbin \
		-lfuzzyninja \
		-lmpi \
		-o $@
	@echo '[ Done $@. ]'

bin/compute-pi-old:
	@echo '[ Making executable $@ ... ]'
	@mkdir --parents $(@D)
	@$(CC) $(CC_FLAGS) \
		OldSchool/compute-pi-old.c \
		-I$(MPI_INCLUDE_PATH) \
		-lmpi \
		-o $@
	@echo '[ Done $@. ]'

obj/Boosted/compute-pi-boosted.o:
	@echo '[ Compiling $< ... ]'
	@mkdir --parents $(@D)
	@$(MPIXX) $(MPIXX_FLAGS) \
		-I$(MPI_INCLUDE_PATH) \
		-I. \
		-c Boosted/compute-pi-boosted.cpp \
		-o $@ \

bin/compute-pi-boosted: obj/Boosted/compute-pi-boosted.o
	@echo '[ Making executable $@ ... ]'
	@mkdir --parents $(@D)
	@$(MPIXX) $(MPIXX_FLAGS) \
		$< \
		-lboost_mpi \
		-lboost_serialization \
		-o $@
	@echo '[ Done $@. ]'
