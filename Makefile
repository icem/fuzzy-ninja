#!/usr/bin/make -f

CXX = clang++
CXX_FLAGS = -Wall -O3
MPI_INCLUDE_PATH = /usr/include/mpi

LIB_FUZZY_NINJA_TARGETS = \
	obj/FuzzyNinja/MpiException.o \
	obj/FuzzyNinja/MpiApplication.o \
	obj/FuzzyNinja/MpiEnvironment.o \
	obj/FuzzyNinja/Interfaces/IProcess.o

COMPUTE_PI_TARGETS = \
	obj/FuzzyNinja/Examples/ComputePi/Program.o

# Main targets.

build: bin/libfuzzyninja.a bin/compute-pi
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
		-IFuzzyNinja \
		-c $< \
		-o $@

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
