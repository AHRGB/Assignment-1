/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Interpolation.h
 * Author: ahmed
 *
 * Created on December 1, 2018, 8:48 PM
 */

#ifndef INTERPOLATION_H
#define INTERPOLATION_H


#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Interpolation {
public:
    Interpolation(vector<double> X,vector<double> Y);
    Interpolation(const Interpolation& orig);
    virtual ~Interpolation();
    double Predict_newton(double x);
    double Predict_spline(double x);
    void fit_newton( int num_samples );
    void fit_spline(int num_samples);
    void setX(vector<double> M);
    void setY(vector<double> N);
    void setNumTimes(int n);
    vector<double> RandInt (int num_samples,double min, double max);
private:
    
    vector<double> X;
    vector<double> Y;
    int NumTimes;

};

#endif /* INTERPOLATION_H */

