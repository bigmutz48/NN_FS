test_network.exe: test_network.o read_load_write.o NN_basics.o
	g++ -o test_network.exe test_network.o read_load_write.o NN_basics.o

train_network.exe: train_network.o read_load_write.o NN_basics.o NN_training.o
	g++ train_network.o read_load_write.o NN_basics.o NN_training.o -o train_network.exe

# training
train_network.o: train_network.cpp
	g++ -c train_network.cpp

read_load_write.o: read_load_write.cpp read_load_write.hpp
	g++ -c read_load_write.cpp

NN_basics.o: NN_basics.cpp NN_basics.hpp
	g++ -c NN_training.cpp


NN_training.o: NN_training.cpp NN_training.hpp
	g++ -c NN_training.cpp

#testingi

clean:
