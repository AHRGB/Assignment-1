/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LinearRegressor.cpp
 * Author: ahmed
 * 
 * Created on November 30, 2018, 11:28 PM
 */

#include "LinearRegressor.h"

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

LinearRegressor::LinearRegressor(const LinearRegressor& orig) {
}

LinearRegressor::~LinearRegressor() {
}

LinearRegressor::LinearRegressor(vector<double> X, vector<double> Y) {

    setX(X);
    setY(Y);
}

void LinearRegressor::setX(vector<double> M){
    
    X=M;
    
}
void LinearRegressor::setY(vector<double> N){
    
    Y=N;
    
}
void LinearRegressor::fit(){
    
    double sumx=0,sumy=0,sumxy=0,sumx2=0,st=0,sr=0;
    
    int n=X.size();
    for (int i =0;i<n;i++){
        
        sumx=sumx+X[i];
        sumy=sumy+Y[i];
        sumxy=sumxy+ X[i]*Y[i];
        sumx2=sumx2 + X[i]*X[i];
    }
    
    double xm=sumx/n;
    double ym=sumy/n;
    
    double a1=(n*sumxy - sumx*sumy)/(n*sumx2-sumx*sumx);
    double a0 = ym-a1*xm;
    for (int i=1;i<n;i++){
        
        st=st+(Y[i]-ym)*(Y[i]-ym);
        sr=sr+(Y[i] - (a1*X[i] + a0));
    }
    
    cout<<"\n"<<"y = "<<a1<<"x + "<<a0<<"\n";
    
}