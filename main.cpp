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
#include <iostream>
#include <fstream>
#include"Gaussian.h"
#include"LinearRegressor.h"
#include"PolyNomialRegressor.h"
#include"MultipleRegressor.h"
#include "Interpolation.h"
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
    
// vector< vector< double > > A =
// {{ 1,  -1,2,1,1},
//  {3,2,1,4,1},
//  {5,8,6,3,1},
//  {4,2,5,3,-1}};
// 
//  int n = A.size();
// print(A);
//
//    // Calculate solution
//    vector<double> x(n);
//    vector<double> x2(n);
//   // x = gauss(A);
//    Gaussian g1(A),g2(A);
//    x=g1.scaled_partial_pivoting();
//    x2=g2.Gauss_Seidel(100);
//
//    // Print result
//    cout << "Gaussian elimination with scaled partial pivoting\n";
//    for (int i=0; i<n; i++) {
//        cout << x[i] << " ";
//        //-0.247361 0.660417 0.984167 0.266667 
//    }
//    cout<<"\n";
//    cout<<"Gauss Seidel \n";
//     for (int i=0; i<n; i++) {
//        cout << x2[i] << " ";
//        //-0.247361 0.660417 0.984167 0.266667 
//    }
////    
////    
    
 cout<<"\n ####################### Part two  Regression  #######################################\n";

    
    vector<double> X1 ;
    vector<double> Y1 ;
    ifstream ip("reg1.csv");

    if(!ip.is_open()) std::cout << "ERROR: File Open" << '\n';

    string  x;
    string y;    

    while(ip.good()){
        
        getline(ip,x,',');
        getline(ip,y,'\n');
        X1.push_back(atof(x.c_str()));
        Y1.push_back(atof(y.c_str()));
    }
    ip.close();
    
    
   LinearRegressor R1(X1,Y1);
    cout <<"\n  ---------------fitted linear model for R1  -------------------\n";
    

    
    R1.fit();
    
    
    
    
    PolyNomialRegressor PR1(2,X1,Y1);
    cout <<"\n ----------- fitted second degree polynomial model for R1 --------- \n";
    PR1.fit();
    
    
    
  
    
    
    
    
    vector<double> X2 ;
    vector<double> Y2 ;
    ifstream ip2("reg2.csv");

    if(!ip2.is_open()) std::cout << "ERROR: File Open" << '\n';


    while(ip2.good()){
        
        getline(ip2,x,',');
        getline(ip2,y,'\n');
        X2.push_back(atof(x.c_str()));
        Y2.push_back(atof(y.c_str()));
    }
    ip2.close();
    LinearRegressor R2(X2,Y2);
    cout <<"\n ------------------fitted linear model for R2 ------------------ \n";
    R2.fit();
    
    PolyNomialRegressor PR2 (2,X2,Y2);
    
    cout<<"\n ------------- fitted second degree polynomial model for R2 ----------------- \n";
    
    PR2.fit();

    vector<double> X3_1 ;
    vector<double> X3_2 ;


    vector<double> Y3;
    
     ifstream ip3("reg3.csv");

    if(!ip3.is_open()) std::cout << "ERROR: File Open" << '\n';
     
     string x1;
     string x2;


    while(ip3.good()){
        
        getline(ip3,x1,',');
        getline(ip3,x2,',');
        getline(ip3,y,'\n');
        X3_1.push_back(atof(x1.c_str()));
        X3_2.push_back(atof(x2.c_str()));
        Y3.push_back(atof(y.c_str()));
    }
    ip3.close();
    
    
    vector<vector<double>> X3={X3_1,
    X3_2};
    
 
 
 
 
   MultipleRegressor R3(2,X3,Y3);
   
   
   
   
   cout<<"\n --------------- fitted multiple linear regression for R3--------------- \n";

   

   R3.fit();
           
           
 cout<<"\n ####################### Part three Interpolation ################################## \n";

 
    
 vector<double> X4;
 vector<double> Y4;
ifstream ip4("sp1.csv");
    if(!ip4.is_open()) std::cout << "ERROR: File Open" << '\n';
    while(ip4.good()){
        getline(ip4,x,',');
        getline(ip4,y,'\n');
        X4.push_back(atof(x.c_str()));
        Y4.push_back(atof(y.c_str()));
    }
    ip4.close();
 Interpolation IN(X4,Y4);
   
   
   cout<<"\n %%%%%%%%%%% Newton Interpolation for Sp1 %%%%%%%%%%%%%%%\n ";
   cout<<"\n 2 times \n ";
   IN.fit_newton(2);
   
   cout<<"\n 4 times \n ";
   IN.fit_newton(4);
   cout<<"\n 8 times \n ";
   IN.fit_newton(8);

   cout<<"\n Cubic spline Interpolation for Sp1 \n ";
   
   cout<<"\n 2 times \n ";
   IN.fit_spline(2);
   cout<<"\n 4 times \n ";
   IN.fit_spline(4);
   cout<<"\n 8 times \n ";
   IN.fit_spline(8);
   
   
   
    vector<double> X5;
    vector<double> Y5;
    ifstream ip5("sp2.csv");
    if(!ip5.is_open()) std::cout << "ERROR: File Open" << '\n';
    while(ip5.good()){
        getline(ip5,x,',');
        getline(ip5,y,'\n');
        X5.push_back(atof(x.c_str()));
        Y5.push_back(atof(y.c_str()));
        }
    ip5.close();
    Interpolation IN2(X5,Y5);
   
   
   cout<<"\n %%%%%%%%%%% Newton Interpolation for Sp2 %%%%%%%%%%%%%%%\n ";
   cout<<"\n 2 times \n ";
   IN2.fit_newton(2);
   
   cout<<"\n 4 times \n ";
   IN2.fit_newton(4);
   cout<<"\n 8 times \n ";
   IN2.fit_newton(8);

   cout<<"\n Cubic spline Interpolation for Sp2\n ";
   
   cout<<"\n 2 times \n ";
   IN2.fit_spline(2);
   cout<<"\n 4 times \n ";
   IN2.fit_spline(4);
   cout<<"\n 8 times \n ";
   IN2.fit_spline(8);
   
   
   
   
   
    vector<double> X6;
    vector<double> Y6;
    ifstream ip6("sp3.csv");
    if(!ip6.is_open()) std::cout << "ERROR: File Open" << '\n';
    while(ip6.good()){
        getline(ip6,x,',');
        getline(ip6,y,'\n');
        X6.push_back(atof(x.c_str()));
        Y6.push_back(atof(y.c_str()));
        }
    ip6.close();
    Interpolation IN3(X6,Y6);
   
   
   cout<<"\n %%%%%%%%%%% Newton Interpolation for Sp3 %%%%%%%%%%%%%%%\n ";
   cout<<"\n 2 times \n ";
   IN3.fit_newton(2);
   
   cout<<"\n 4 times \n ";
   IN3.fit_newton(4);
   cout<<"\n 8 times \n ";
   IN3.fit_newton(8);

   cout<<"\n Cubic spline Interpolation for Sp3\n ";
   
   cout<<"\n 2 times \n ";
   IN3.fit_spline(2);
   cout<<"\n 4 times \n ";
   IN3.fit_spline(4);
   cout<<"\n 8 times \n ";
   IN3.fit_spline(8);
   
   
   
   
    vector<double>X7;
    vector<double>Y7;
    ifstream ip7("sp4.csv");
    if(!ip7.is_open()) std::cout << "ERROR: File Open" << '\n';
    while(ip7.good()){
        getline(ip7,x,',');
        getline(ip7,y,'\n');
        X7.push_back(atof(x.c_str()));
        Y7.push_back(atof(y.c_str()));
        }
    ip7.close();
    Interpolation IN4(X7,Y7);
   
   
   cout<<"\n %%%%%%%%%%% Newton Interpolation for Sp4 %%%%%%%%%%%%%%%\n ";
   cout<<"\n 2 times \n ";
   IN4.fit_newton(2);
   
   cout<<"\n 4 times \n ";
   IN4.fit_newton(4);
   cout<<"\n 8 times \n ";
   IN4.fit_newton(8);

   cout<<"\n Cubic spline Interpolation for Sp3\n ";
   
   cout<<"\n 2 times \n ";
   IN4.fit_spline(2);
   cout<<"\n 4 times \n ";
   IN4.fit_spline(4);
   cout<<"\n 8 times \n ";
   IN4.fit_spline(8);

   
   
   
   return 0;
}
