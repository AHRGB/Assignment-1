/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PolyNomialRegressor.h
 * Author: ahmed
 *
 * Created on December 1, 2018, 12:10 PM
 */

#ifndef POLYNOMIALREGRESSOR_H
#define POLYNOMIALREGRESSOR_H
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class PolyNomialRegressor {
public:
    PolyNomialRegressor(int order ,vector<double> X,  vector<double> Y);
    PolyNomialRegressor(const PolyNomialRegressor& orig);
    virtual ~PolyNomialRegressor();
    void SetOrder(int o);
    void setA (vector< vector<double> > M);
   void  fit();
    void setX(vector<double> M);
    void setY(vector<double> N);
private:
    int order;
    vector< vector<double> > A;
    vector<double> X;
    vector<double> Y;

    

};

#endif /* POLYNOMIALREGRESSOR_H */

