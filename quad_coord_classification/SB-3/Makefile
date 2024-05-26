# this is going to be the make file for all the executables


test_on_batch.exe: test_on_batch.o NN_training.o NN.o 
	g++ -o test_on_batch.exe test_on_batch.o NN_training.o NN.o 

test_on_batch.o: test_on_batch.cpp
	g++ -c test_on_batch.cpp

test_one_example_at_a_time.exe: test_one_example_at_a_time.o NN.o NN_training.o 
	g++ -o test_one_example_at_a_time.exe test_one_example_at_a_time.o NN_training.o NN.o 

test_one_example_at_a_time.o: test_one_example_at_a_time.cpp
	g++ -c test_one_example_at_a_time.cpp 


train.exe: train.o 
	g++ -o train.exe train.o NN.o NN_training.o

NN_training.o: NN_training.cpp NN_training.hpp
	g++ -c NN_training.cpp


init.exe: init.o NN.o
	g++ -o init.exe init.o NN.o

init.o: init.cpp
	g++ -c init.cpp

NN.o: NN.cpp NN.hpp
	g++ -c NN.cpp
