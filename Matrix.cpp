#include "Matrix.hpp"
#include <iostream>
#include <vector>

using namespace std;
namespace zich{

Matrix::Matrix( vector <double> n, int a, int b) {
    
        if (a <= 0 || b <= 0)
        {
             throw invalid_argument("row or col negetive");
        }
        if ((int)n.size() != a * b)
        {
             throw invalid_argument("row or col dosent match matrix size");
        }

    x1 = n;
    y1 = a;
    z1 = b;
};

//sum 2 matrix 
Matrix Matrix::operator+(const Matrix &other) const {
    if(this->y1!=other.y1 || this->z1!=other.z1){
         throw invalid_argument("row or col not equal");
    }
    if(this->y1<1 || this->z1<1 || other.y1<1 || other.z1<1){
         throw invalid_argument("row or col is less then 1 - not good");
    }
     Matrix a = *this;
     for(unsigned int i = 0;i<this->x1.size();i++){
            a.x1[i] = other.x1[i] + a.x1[i];
        }
    return a;
}
//sum 2 matrix
Matrix Matrix::operator+=(const Matrix &other) {
     if(this->y1!=other.y1 || this->z1!=other.z1){
         throw invalid_argument("row or col not equal");
    }
    if(this->y1<1 || this->z1<1 || other.y1<1 || other.z1<1){
         throw invalid_argument("row or col is less then 1 - not good");
    }
    Matrix a= *this;
   for(unsigned int i = 0;i<this->x1.size();i++){
            a.x1[i]+=other.x1[i];
        }
        return a;
}
 
 //sum  onri
Matrix Matrix ::operator++(){
    Matrix a = *this;
    for(unsigned int i =0;i<this->x1.size();i++){
        a.x1[i]++;
    }
    return a;

}



//sub 2 matrix
Matrix Matrix::operator-(const Matrix &other) const {
     if(this->y1!=other.y1 || this->z1!=other.z1){
         throw invalid_argument("row or col not equal");
    }
    if(this->y1<1 || this->z1<1 || other.y1<1 || other.z1<1){
         throw invalid_argument("row or col is less then 1 - not good");
    }
    Matrix a = other;
     for(unsigned int i = 0;i<this->x1.size();i++){
            a.x1[i] = this->x1[i] - a.x1[i];
        }
    return a;

    
}
// sub 2 matrix
Matrix Matrix::operator-=(const Matrix &other) {
     if(this->y1!=other.y1 || this->z1!=other.z1){
         throw invalid_argument("row or col not equal");
    }
    if(this->y1<1 || this->z1<1 || other.y1<1 || other.z1<1){
         throw invalid_argument("row or col is less then 1 - not good");
    }
    Matrix a = *this;
     for( unsigned int i = 0;i<this->x1.size();i++){
            a.x1[i]-=other.x1[i];
        }
        return a;
   

}
//onri sub
Matrix Matrix::operator--() {
    if(this->y1<1 || this->z1<1){
         throw invalid_argument("row or col is less then 1 - not good");
    }
    Matrix a = *this;
    for( unsigned int i =0;i<this->x1.size();i++){
        a.x1[i]--;
    }
    return a;
}



// onri multi -1
Matrix Matrix::operator-() {
    if(this->y1<1 || this->z1<1){
         throw invalid_argument("row or col is less then 1 - not good");
    }
    Matrix a = *this;
     for(unsigned int i = 0;i<this->x1.size();i++){
         if(a.x1[i]!=0){
            a.x1[i] = a.x1[i] * -1;
         }
        }
    return a;
}





/*Matrix Matrix::operator++(int dummy) {
   
}*/
//multi 2 matrix 
 Matrix Matrix::operator*(const Matrix& b){
   
     Matrix temp = *this;
       if(this->y1<1 || this->z1<1 || b.y1<1 || b.z1<1){
         throw invalid_argument("row or col is less then 1 - not good");
    }
    if(this->y1!=b.z1 || this->z1!=b.y1){
         throw invalid_argument("row or col not equal");
    }
      vector <vector<double>>a(3,vector<double>(3));
      vector <vector<double>>other(3,vector<double>(3));
      unsigned int k = 0;
      
            
     for(unsigned int i=0;i<this->y1;i++){
         for(unsigned int j = 0; j<this->z1;j++,k++){
             a[i][j]  = this->x1[k];
         }
     }
     k = 0;
     for(unsigned int i=0;i<b.y1;i++){
         for(unsigned int j = 0; j<b.z1;j++,k++){
             other[i][j]  = b.x1[k];
         }
     }
    
      int p = 0;
    for(unsigned int i=0;i<this->y1;i++){
         for(unsigned int j = 0; j<b.z1;j++,k++,p++){
             int sum = 0;
             for(unsigned int k = 0;k<b.y1;k++){
                 sum+= a[i][k] * other[k][j];
             }
             a[i][j] = sum;
            
         }
     }




   
    return temp;

    

     }
     //
      Matrix Matrix::operator*(const double a){
          if(this->y1<1 || this->z1<1 ){
         throw invalid_argument("row or col is less then 1 - not good");
    }
           for(unsigned int i =0;i<this->x1.size();i++){
        this->x1[i]= this->x1[i]*a;
    }
    return *this;

      }
     //done
     Matrix operator*(const double &c1, const Matrix &c2) {
         if( c2.y1<1 || c2.z1<1){
         throw invalid_argument("row or col is less then 1 - not good");
    }
         Matrix a  = c2;
        for(unsigned int i =0;i<c2.x1.size();i++){
            a.x1[i] = a.x1[i] * c1;
    }
     return a;
     }
     /*Matrix &Matrix::operator*=(const Matrix& b){
           for(int i = 0;i<this->x1.size();i++){
            this->x1[i]*=b.x1[i];
        }
        return *this;

      }*/
     Matrix &Matrix::operator*=(const double a){
         if(this->y1<1 || this->z1<1){
         throw invalid_argument("row or col is less then 1 - not good");
    }
          *this = *this * a;
          return *this;

      }

   

    bool operator==(const Matrix &c1, const Matrix &c2) {
         if(c1.y1!=c1.y1 || c2.z1!=c2.z1){
         throw invalid_argument("row or col not equal");
    }
    if(c1.y1<1 || c1.z1<1 || c2.y1<1 || c2.z1<1){
         throw invalid_argument("row or col is less then 1 - not good");
    }
        for(unsigned i = 0;i<c1.x1.size();i++){
           if(c1.x1[i]!=c2.x1[i]) {
               return false;
           }
        }
        return true;
        
       
    }

    bool operator!=(const Matrix &c1, const Matrix &c2) {
         if(c1.y1!=c1.y1 || c2.z1!=c2.z1){
         throw invalid_argument("row or col not equal");
    }
    if(c1.y1<1 || c1.z1<1 || c2.y1<1 || c2.z1<1){
         throw invalid_argument("row or col is less then 1 - not good");
    }
        if((operator==(c1,c2))==false){
            return true;
        }
        else{
            return false;
        }
        
    }

    bool operator>=(const Matrix &c1, const Matrix &c2) {
         if(c1.y1!=c1.y1 || c2.z1!=c2.z1){
         throw invalid_argument("row or col not equal");
    }
    if(c1.y1<1 || c1.z1<1 || c2.y1<1 || c2.z1<1){
         throw invalid_argument("row or col is less then 1 - not good");
    }
      if (operator>(c1,c2) || operator==(c1,c2))
      {
          return true;
      }
      else{
          return false;
      }
      

    }

    bool operator>(const Matrix &c1, const Matrix &c2) {
         if(c1.y1!=c1.y1 || c2.z1!=c2.z1){
         throw invalid_argument("row or col not equal");
    }
    if(c1.y1<1 || c1.z1<1 || c2.y1<1 || c2.z1<1){
         throw invalid_argument("row or col is less then 1 - not good");
    }
        int sum =0;
        int sum1 =0;
        for(unsigned i = 0;i<c1.x1.size();i++){
            sum += c1.x1[i];
            sum1 += c2.x1[i];

        }
        if(sum>sum1){
            return true;
        }
        else{
            return false;
        }
        
    }

    bool operator<=(const Matrix &c1, const Matrix &c2) {
         if(c1.y1!=c1.y1 || c2.z1!=c2.z1){
         throw invalid_argument("row or col not equal");
    }
    if(c1.y1<1 || c1.z1<1 || c2.y1<1 || c2.z1<1){
         throw invalid_argument("row or col is less then 1 - not good");
    }
        if (operator<(c1,c2) || operator==(c1,c2))
      {
          return true;
      }
      else{
          return false;
      }
      

    }
        

    

    bool operator<(const Matrix &c1, const Matrix &c2) {
         if(c1.y1!=c1.y1 || c2.z1!=c2.z1){
         throw invalid_argument("row or col not equal");
    }
    if(c1.y1<1 || c1.z1<1 || c2.y1<1 || c2.z1<1){
         throw invalid_argument("row or col is less then 1 - not good");
    }
         int sum =0;
        int sum1 =0;
        for(unsigned i = 0;i<c1.x1.size();i++){
            sum += c1.x1[i];
            sum1 += c2.x1[i];

        }
        if(sum<sum1){
            return true;
        }
        else{
            return false;
        }

    }



    ostream &operator<<(ostream &os, const Matrix &c) {
     
      
      unsigned int k = 0;
      int j = 0;
      
       for(unsigned int i =0;i<c.y1;i++){
            os << '[';
           for(unsigned int j =0;j<c.z1;j++,k++){
               os << c.x1[k] <<" ";
           }
            
             os << "]" << '\n';

           }
        
            
        return os ;
        
      
    }

   

}
     


