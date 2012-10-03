#!/usr/bin/make -f

CXX = clang++
CXX_FLAGS = -Wall -O3
MPI_INCLUDE_PATH = /usr/include/mpi

# Main targets.

build: libfuzzyninja
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
	@$(CXX) $(CXX_FLAGS) -I$(MPI_INCLUDE_PATH) -c $< -o $@

# Projects.

libfuzzyninja: \
		obj/FuzzyNinja/MpiApplication.o \
		obj/FuzzyNinja/MpiEnvironment.o
	@echo '[ Making libfuzzyninja.a ... ]'
	@mkdir --parents bin
	@ar rcs bin/libfuzzyninja.a $^
