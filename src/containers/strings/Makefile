CXX := clang++
CXXFLAGS := -std=c++20 -pedantic -g -Wall -Wextra

SRC := $(wildcard *.cpp)
TARGETS := $(subst .cpp,,$(SRC))


all: $(TARGETS)


clean:
	@-echo cleaning: `find . -type f -executable`
	@-find . -type f -executable | xargs --no-run-if-empty rm


.PHONY: clean all
