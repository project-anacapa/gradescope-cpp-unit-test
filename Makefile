# Makefile for lab00, YOUR NAME(S) HERE, CS32, S15

# CXX=clang++
CXX=g++ -I/usr/include/jsoncpp -std=c++11



all: helloTest

helloTest: helloTest.o tddFuncs.o
	${CXX} helloTest.o tddFuncs.o -o helloTest -ljsoncpp

clean:
	/bin/rm -f *.o helloTest

