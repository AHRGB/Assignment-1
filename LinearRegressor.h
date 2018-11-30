/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LinearRegressor.h
 * Author: ahmed
 *
 * Created on November 30, 2018, 11:28 PM
 */

#ifndef LINEARREGRESSOR_H
#define LINEARREGRESSOR_H
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class LinearRegressor {
public:
    LinearRegressor(vector<double> X,vector<double> Y);
    LinearRegressor(const LinearRegressor& orig);
    virtual ~LinearRegressor();
    void fit();
    void setX(vector<double> M);
    void setY(vector<double> N);
private:
    
    vector<double> X;
    vector<double> Y;

};

#endif /* LINEARREGRESSOR_H */

