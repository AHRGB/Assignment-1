/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Gaussian.cpp
 * Author: ahmed
 * 
 * Created on November 30, 2018, 2:07 PM
 */

#include "Gaussian.h"
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include<math.h>

using namespace std;
Gaussian::Gaussian(vector< vector<double> > A) {
    
    setA(A);
    
    
}

Gaussian::Gaussian(const Gaussian& orig) {
}

Gaussian::~Gaussian() {
}

void Gaussian::setA(vector<vector<double> > M){
    
    A=M;
}

double Gaussian::max(double A, double B){
    
        if (A>B) 
        return A;
    else
        return B;
}
 vector<double> Gaussian::scaled_partial_pivoting(){
     
     
    int n = A.size();
    double smax=0;
    double* s= new double[n];
    
   for (int i=0;i<n;i++)   
 {
    
     smax=0;
     for(int j=0;j<n;j++)
     {
         double temp = A[i][j];
         smax = max(smax,abs(temp));   
     } 
     s[i]=smax;
    
   }
    for (int i=0; i<n; i++) {
        // Search for maximum in this column
        double maxEl = (abs(A[i][i]))/(s[i]);
        int maxRow = i;
        for (int k=i+1; k<n; k++) {
            if ((abs(A[k][i])/(s[i])) > maxEl) {
                maxEl = (abs(A[k][i]))/(s[i]);
                maxRow = k;
            }
        }

        // Swap maximum row with current row (column by column)
        for (int k=i; k<n+1;k++) {
            double tmp = A[maxRow][k];
            A[maxRow][k] = A[i][k];
            A[i][k] = tmp;
        }

        // Make all rows below this one 0 in current column
        for (int k=i+1; k<n; k++) {
            double c = -A[k][i]/A[i][i];
            for (int j=i; j<n+1; j++) {
                if (i==j) {
                    A[k][j] = 0;
                } else {
                    A[k][j] += c * A[i][j];
                }
            }
        }
    }

    // Solve equation Ax=b for an upper triangular matrix A
    vector<double> x(n);
    for (int i=n-1; i>=0; i--) {
        x[i] = A[i][n]/A[i][i];
        for (int k=i-1;k>=0; k--) {
            A[k][n] -= A[k][i] * x[i];
        }
    }
    return x;
 }
 
 vector<double> Gaussian::Gauss_Seidel(int num_iterations){
     
     
    int m = num_iterations;
    int n = A.size();
    vector< vector< double > >a(n,vector< double >(n));
    vector<double> x(n);
    vector<double> b(n);
    vector<double> y(n);

     
     for(int i=0;i<n;i++)
     {
         
         b[i]=A[i][n];
         
         for(int j=0;j<n;j++)
         {
             
             a[i][j]=A[i][j];
           
         }
     }
     
          
     while (m > 0)
    {
        for (int i = 0; i < n; i++)
        {
            y[i] = (b[i] / a[i][i]);
            for (int j = 0; j < n; j++)
            {
                if (j == i)
                    continue;
                y[i] = y[i] - ((a[i][j] / a[i][i]) * x[j]);
                x[i] = y[i];
            }
            
        }
        m--;
      }
    
    return x;
     
    
    }
     
   
           
     


     
     
     
     
     
     
     
   
     
 

