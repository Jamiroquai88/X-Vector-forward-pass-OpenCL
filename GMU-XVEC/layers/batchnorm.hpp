//
//  batchnorm.hpp
//  GMU-XVEC
//
//  Created by Jan Profant on 01/12/2018.
//  Copyright © 2018 Jan Profant. All rights reserved.
//

#ifndef batchnorm_h
#define batchnorm_h

#include <iostream>
#include <string>
#include <vector>

#include "nnet.hpp"


class BatchNormLayer : public Layer {
public:
    BatchNormLayer(std::string name, float *mean, float *variance, float epsilon) : Layer(name), mean(mean), variance(variance), epsilon(epsilon) {};
    
private:
    float *mean;
    float *variance;
    float epsilon;
};


#endif /* batchnorm_h */