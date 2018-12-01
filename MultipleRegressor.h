/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MultipleRegressor.h
 * Author: ahmed
 *
 * Created on December 1, 2018, 2:08 PM
 */

#ifndef MULTIPLEREGRESSOR_H
#define MULTIPLEREGRESSOR_H

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class MultipleRegressor {
public:
    MultipleRegressor(int order ,vector< vector< double > > X ,vector<double> Y  );
    MultipleRegressor(const MultipleRegressor& orig);
    virtual ~MultipleRegressor();
    void fit();
    void setX(vector< vector< double > > M);
    void setY(vector<double> N);
    void setOrder(int o);
private:
    int order;
    vector< vector< double > > X;
    vector< vector<double> > A;
    vector<double> Y;
    

};

#endif /* MULTIPLEREGRESSOR_H */

