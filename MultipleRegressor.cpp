/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MultipleRegressor.cpp
 * Author: ahmed
 * 
 * Created on December 1, 2018, 2:08 PM
 */

#include "MultipleRegressor.h"
#include "Gaussian.h"

MultipleRegressor::MultipleRegressor(int o,vector<vector<double> > X,vector<double> Y) {
    
    setOrder(o);
    setX(X);
    setY(Y);
    
    
}

MultipleRegressor::MultipleRegressor(const MultipleRegressor& orig) {
}

MultipleRegressor::~MultipleRegressor() {
}

void MultipleRegressor::setX(vector<vector<double> > M)

{
    X=M;
}


void MultipleRegressor ::setY(vector<double> N)

{
    
    Y=N;
    
}

void MultipleRegressor::setOrder(int o)
{
    
    order=o;
}

void MultipleRegressor::fit(){
    
    


    
      
    
    int m = X.size();
    int n = Y.size();
    
    vector< vector< double > > A (m+1,vector< double >(m+2));
    double sum;
    
    A[0][0]=n;
    
    
    vector<double> sums(m);
    double acc;
    double y_acc=0;
    for (int p=0;p<n;p++)
        y_acc=y_acc+Y[p];
    A[0][m+1]=y_acc;
    

    
    
    for (int i=0;i<m;i++)
        
    {
        
        acc=0;
        
            for (int j=0;j<n;j++)
            {
                acc = acc + X[i][j];
            }
       
        sums[i]=acc;
    }
    
    
        int p=0;
    for (int q=1;q<=m;q++ )
    {
        A[p][q]=sums[q-1];
        A[q][p]=sums[q-1];
    }
        
  

    
    for (int i=1;i<=(m);i++)
    {
        for(int j=1;j<=i;j++)
        {
           
             sum=0;
           for (int l=0;l<n;l++)
           {
               sum = sum  + X[i-1][l]* X[j-1][l];
            }
            
           A[i][j]=sum;
           A[j][i]=sum;
            
        }
        
         sum = 0;
         for (int l=0;l<n;l++)
         {
             sum = sum + Y[l]*X[i-1][l];
         }
         
         
         A[i][m+1] = sum;
        
        
  }
        
        
     Gaussian g(A);

    
    vector<double> Coeffs(n);
    
   
    Coeffs = g.scaled_partial_pivoting();
    
    
    cout<<" equation is : \n ";
    
    for (int i=0;i<=order;i++)
    {
        cout<<Coeffs[i]<< " X"<<i <<" + ";
    }
    
    cout<<"\n";
         

 
}

    
    
    


    ////////////////////////////////
    
    
    
    
    
    
