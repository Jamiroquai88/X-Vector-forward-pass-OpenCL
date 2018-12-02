//
//  nnet.hpp
//  GMU-XVEC
//
//  Created by Jan Profant on 28/11/2018.
//  Copyright © 2018 Jan Profant. All rights reserved.
//

#ifndef nnet_hpp
#define nnet_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>

#define MAC
#ifdef MAC
    #include <OpenCL/cl.h>
#else
    #include <CL/cl.h>
#endif


class Layer {
public:
    
    virtual void foo() {};
    
    std::string name;
};


class NNet {
public:
    NNet(std::string nnet_path);
    float * forward(std::string fea_path, cl_device_id device, cl_context context);
    
private:
    std::vector<Layer*> layers;
    std::vector<std::string> layers_types;
    
    std::unordered_map<std::string, std::string> ParseNodeAttributes(std::vector<std::string> attributes, std::string type);
    std::string ParseNodeAttributeValue(std::string value, std::vector<std::string> &offsets);
    std::unordered_map<std::string, std::string> ParseComponentAttributes(                                                                          std::vector<std::string> line_split, std::string &matrix_key, bool &end, std::unordered_map<std::string, std::vector<float>> &matrix_attrs);
    void ParseFloatsLine(std::vector<float> &matrix, std::vector<std::string> line_split, bool &matrix_end);
    
    void InitLayersFromNode(std::unordered_map<std::string, std::string> &node_attrs, std::unordered_map<std::string, std::vector<float>> &matrix_attrs);
};

#endif /* nnet_hpp */
