#include <iostream>
#include <string>
#include <vector>

#include <map>

using namespace std;
  
namespace zich {
    class Matrix {        // The class
  public:          // Access specifier
   /* vector<double> x1;  // Attribute
    int y2;  // Attribute
    int z3;      // Attribute
    Matrix(vector<double> x, int y, int z) { // Constructor with parameters
      x1 = x;
      y2 = y;
      z3 = z;
    }*/
    vector<double> x1;
    int y1;
    int z1;
    Matrix(vector<double> x, int y, int z);

    Matrix operator+=(const Matrix &other);
    Matrix operator+(const Matrix &other) const;
    

    Matrix operator-();
    Matrix operator-(const Matrix &other) const;
    Matrix operator-=(const Matrix &other);
    Matrix operator--();
   

      Matrix operator*(const Matrix& b);
      Matrix operator*(const double a);
      Matrix& operator*=(const Matrix& b);
      Matrix& operator*=(const double a);
      friend Matrix operator*(const double &c1, const Matrix &c2);

    Matrix operator++();
    Matrix operator++(int dummy);
    

    friend bool operator==(const Matrix &c1, const Matrix &c2);
    friend bool operator!=(const Matrix &c1, const Matrix &c2);
    friend bool operator>=(const Matrix &c1, const Matrix &c2);
    friend bool operator>(const Matrix &c1, const Matrix &c2);
    friend bool operator<=(const Matrix &c1, const Matrix &c2);
    friend bool operator<(const Matrix &c1, const Matrix &c2);

    friend Matrix operator*(const Matrix &c1, const double &c2);
    
    friend ostream &operator<<(ostream &os, const Matrix &c);
    

};

}