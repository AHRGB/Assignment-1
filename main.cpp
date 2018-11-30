/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: ahmed
 *
 * Created on November 21, 2018, 8:08 PM
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include"Gaussian.h"
#include"LinearRegressor.h"
using namespace std;

/*
 * 
 */

void print(vector< vector<double> > A){
    int n = A.size();
    for (int i=0; i<n; i++) {
        for (int j=0; j<n+1; j++) {
            cout << A[i][j] << "\t";
            if (j == n-1) {
                cout << "| ";
            }
        }
        cout << "\n";
    }
    cout << endl;
}
int main(int argc, char** argv) {
    
 vector< vector< double > > A =
 {{ 3,  -0.1,-0.2,7.85},
  {0.1,7,-0.3,-19.3},
  {0.3,-0.2,10,71.3}};
 
  int n = A.size();
 print(A);

    // Calculate solution
    vector<double> x(n);
    vector<double> x2(n);
   // x = gauss(A);
    Gaussian g1(A),g2(A);
    x=g1.scaled_partial_pivoting();
    x2=g2.Gauss_Seidel(5);

    // Print result
    cout << "Gaussian elimination with scaled partial pivoting\n";
    for (int i=0; i<n; i++) {
        cout << x[i] << " ";
        //-0.247361 0.660417 0.984167 0.266667 
    }
    cout<<"\n";
    cout<<"Gauss Seidel \n";
     for (int i=0; i<n; i++) {
        cout << x2[i] << " ";
        //-0.247361 0.660417 0.984167 0.266667 
    }
    
    
    vector<double> X1 = {0,1,2,3,4,5,6,7,8,9};
    vector<double> Y1 = {1.12216568306072,4.68496378068898,10.1815539757734,11.349972200827,14.604868613903,
                         17.6538856058074,22.665233707456,25.535452456051,30.5389745350096,31.5440565808718};
    LinearRegressor R1(X1,Y1);
    cout <<"\nfitted model for R1 \n";
    R1.fit();
    
    
    
    
    vector<double> X2 = {0,1,2,3,4,5,6,7,8,9};
    vector<double> Y2 = {-5.90923401837195,-0.254211137049468,25.7005693810185,33.9124577420548,61.7703624638093,
                        94.5169676622323,162.316032488064,208.975148836975,303.945853535382,325.112753130996};
    LinearRegressor R2(X2,Y2);
    cout <<"\nfitted model for R2 \n";
    R2.fit();
   return 0;
}
