/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Interpolation.cpp
 * Author: ahmed
 * 
 * Created on December 1, 2018, 8:48 PM
 */

#include "Interpolation.h"
#include<vector>
#include <random>

Interpolation::Interpolation(vector<double> X,vector<double> Y) {
    
    setX(X);
    setY(Y);
    
}

Interpolation::Interpolation(const Interpolation& orig) {
}

Interpolation::~Interpolation() {
}

void Interpolation::setX(vector<double> M){
    
    
    X=M;
}

void Interpolation::setY(vector<double> N){
    
    Y=N;
}

void Interpolation::setNumTimes(int n){
    
    
    NumTimes=n;
    
    
}

double Interpolation::Predict_newton(double a){
    
 vector<double> f=Y;  
 
    
int n=Y.size();
int i,j;

double sum=0,mult;


 for(j=0;j<n-1;j++)
    {
        for(i=n-1;i>j;i--)
            f[i]=(f[i]-f[i-1])/(X[i]-X[i-j-1]);
    }
    for(i=n-1;i>=0;i--)
    {
        mult=1;
        for(j=0;j<i;j++)
            mult*=(a-X[j]);
            
        mult*=f[j];
        sum= sum + mult;
    }
return sum;
}


void Interpolation::fit_newton(int n ){
    
 setNumTimes(n);
 int numrows = Y.size();
 vector<double> X_Interpolated ;
 
 for(int i =0;i<(X.size()-1);i++)
 {
     
     
     vector<double> new_points = RandInt(n,X[i],X[i+1]);
     
     for(int j=0;j<new_points.size();j++)
     {
     X_Interpolated.push_back(new_points[j]);
     
     }
     
 }
 
      vector<double> new_points = RandInt(n,X[X.size()-1],X[X.size()-1 ] +1 );
     
     for(int j=0;j<new_points.size();j++)
     {
     X_Interpolated.push_back(new_points[j]);
     
     }
 
 for (int i =0;i<X_Interpolated.size();i++)
 {

 }
       vector<double>Y_Interpolated(X_Interpolated.size()) ;

      cout<<"----------------- Interpolated points using Newton are ------------------\n";
      for (int i=0;i<X_Interpolated.size();i++)
      {
          
          Y_Interpolated[i] = Predict_newton(X_Interpolated[i]);
          
          cout<<X_Interpolated[i]<<","<<Y_Interpolated[i]<<"\n";
          
          
      }
 
  

    
}

vector<double> Interpolation::RandInt (int num_samples,double min, double max)
{
    
    std::random_device rd; 
    std::mt19937 gen(rd()); 
    std::uniform_real_distribution<> d{min, max};
    vector<double> result(num_samples);
    for (int i=0;i<num_samples;i++)
    {
     result[i]=d(gen);
    }
    
    return result;

}

double  Interpolation::Predict_spline(double p){
    
    
    int n,i,j,k;
    n=X.size();    
    double a,b,c,d,sum,temp;

    vector<double> h(n),s(n),F(n);
    vector<double> f = Y;
    vector<double> x=X;
    vector<vector<double>> m(n,vector<double>(n));

    for(i=n-1;i>0;i--)
    {
        F[i]=(f[i]-f[i-1])/(x[i]-x[i-1]);
        h[i-1]=x[i]-x[i-1];
    }

    //*********** formation of h, s , f matrix **************//
    for(i=1;i<n-1;i++)
    {
    m[i][i]=2*(h[i-1]+h[i]);
    if(i!=1)
    {
        m[i][i-1]=h[i-1];
        m[i-1][i]=h[i-1];
    }
    m[i][n-1]=6*(F[i+1]-F[i]);
    }

    //***********  forward elimination **************//

    for(i=1;i<n-2;i++)
    {
        temp=(m[i+1][i]/m[i][i]);
        for(j=1;j<=n-1;j++)
            m[i+1][j]-=temp*m[i][j];
    }

    //*********** back ward substitution *********//
    for(i=n-2;i>0;i--)
    {
        sum=0;
        for(j=i;j<=n-2;j++)
            sum+=m[i][j]*s[j];
        s[i]=(m[i][n-1]-sum)/m[i][i];
    }
    
     
    
        for(i=0;i<n-1;i++)
            if(x[i]<=p&&p<=x[i+1])
            {
            a=(s[i+1]-s[i])/(6*h[i]);
            b=s[i]/2;
            c=(f[i+1]-f[i])/h[i]-(2*h[i]*s[i]+s[i+1]*h[i])/6;
            d=f[i];
            sum=a*pow((p-x[i]),3)+b*pow((p-x[i]),2)+c*(p-x[i])+d;
            }
return sum;    
    
    
    
    
}



void Interpolation::fit_spline(int n ){
    
 setNumTimes(n);
 int numrows = Y.size();
 vector<double> X_Interpolated ;
 
 for(int i =0;i<(X.size()-1);i++)
 {
     
     
     vector<double> new_points = RandInt(n,X[i],X[i+1]);
     
     for(int j=0;j<new_points.size();j++)
     {
     X_Interpolated.push_back(new_points[j]);
     
     }
     
 }
 
      vector<double> new_points = RandInt(n,X[X.size()-1],X[X.size()-1 ] +1 );
     
     for(int j=0;j<new_points.size();j++)
     {
     X_Interpolated.push_back(new_points[j]);
     
     }
 
 for (int i =0;i<X_Interpolated.size();i++)
 {

 }
       vector<double>Y_Interpolated(X_Interpolated.size()) ;

      cout<<"----------------- Interpolated points using cubic spline are ------------------\n";
      for (int i=0;i<X_Interpolated.size();i++)
      {
          
          Y_Interpolated[i] = Predict_spline(X_Interpolated[i]);
          
          cout<<X_Interpolated[i]<<","<<Y_Interpolated[i]<<"\n";
          
          
      }
 
  

    
}
