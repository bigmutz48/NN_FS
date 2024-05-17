#ifndef NN_CREATE_TRAINING_DATA_HPP
#define NN_CREATE_TRAINING_DATA_HPP

struct coord {

};

struct training_data{

};

class NN_CREATE_TRAINING_DATA{
    // parameter for initialization
    int num_training_examples;
    double min;
    double max;
    


  public:
    
    NN_CREATE_TRAINING_DATA(

        );
    

    // throw an error if this gets called
    NN_CREATE_TRAINING_DATA();


    training_data get_training_data();


}

#endif
