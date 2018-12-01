/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "PolyNomialRegressor.h"


/* 
 * File:   PolyNomialRegressor.cpp
 * Author: ahmed
 * 
 * Created on December 1, 2018, 12:10 PM
 */

#include "PolyNomialRegressor.h"
#include"math.h"
#include"Gaussian.h"

PolyNomialRegressor::PolyNomialRegressor(int o ,vector<double> X,  vector<double> Y) {
    
    SetOrder(o);
    
    setX(X);
    setY(Y);
}

PolyNomialRegressor::PolyNomialRegressor(const PolyNomialRegressor& orig) {
}

PolyNomialRegressor::~PolyNomialRegressor() {
}

void PolyNomialRegressor::SetOrder(int o){
    
    order=o;
}

void PolyNomialRegressor::setA(vector<vector<double> > M){
    
    
    A=M;
}

void PolyNomialRegressor::setX(vector<double> M)
{
    X=M;
}

void PolyNomialRegressor::setY(vector<double> N)
{
    
    Y=N;
}

void PolyNomialRegressor::fit(){
    int k;
    double sum;
    int n = X.size();
    int m=order+1;
    vector< vector< double > > A (m,vector< double >(m+1));
    for( int i=0;i<(m);i++ )
    {
        for(int j=0;j<(i+1);j++)
        {
            
            k=i+j;
            sum=0;
            for(int l=0;l<n;l++)
            {
                
                sum = sum + pow(X[l],k);
            }
            A[i][j]=sum;
            A[j][i]=sum;

            
            
        }
                 sum=0;
            for (int l=0;l<n;l++)
            {

                sum =sum + Y[l]*(pow(X[l],(i)));
            }
            
            A[i][m] = sum;
    }
    
    
    Gaussian g(A);

    
    vector<double> Coeffs(n);
    
   
    Coeffs = g.scaled_partial_pivoting();
    
    
    cout<<" coeffecients are : \n ";
    
    for (int i=0;i<=order;i++)
    {
        cout<<Coeffs[i]<<"\n";
    }
    

}