/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Gaussian.h
 * Author: ahmed
 *
 * Created on November 30, 2018, 2:07 PM
 */

#ifndef GAUSSIAN_H
#define GAUSSIAN_H
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


class Gaussian {
public:
    Gaussian(vector< vector<double> > A);
    Gaussian(const Gaussian& orig);
    virtual ~Gaussian();
    void setA(vector< vector< double > > M);
    vector<double> scaled_partial_pivoting();
    double max(double A,double B);
    vector<double> Gauss_Seidel(int num_iterations);
private:
    vector< vector< double > > A;
    
    
    
    

};

#endif /* GAUSSIAN_H */

