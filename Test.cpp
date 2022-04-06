#include "doctest.h"
#include "Matrix.hpp"

using namespace zich;

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
using namespace std;
std::vector<double> v1 = {1, 0, 0,
                                   0, 1, 0, 
                                   0, 0, 1};
    std::vector<double> v2 = {3, 0, 0, 
                              0, 3, 0, 
                              0, 0, 3};
    std::vector<double> v3 = {-3, 0, 0, 
                              0, -3, 0, 
                              0, 0, -3};   
    std::vector<double> v4 = {4, 0, 0, 
                              0, 4, 0, 
                              0, 0, 4};  
    std::vector<double> v5 = {-2, 0, 0, 
                              0, -2, 0, 
                              0, 0, -2};
    std::vector<double> v6 = {27, 0, 0, 
                              0, 27, 0, 
                              0, 0, 27}; 
    std::vector<double> v7 = {4, 1, 1, 
                              1, 4, 1, 
                              1, 1, 4};   
    std::vector<double> v8 = {4, 1, 1, 
                              1, 4, 1, 
                              1, 1, 4};
    std::vector<double> v9 = {4, 1, 1,0 ,
                              1, 4, 1,0 ,
                              1, 1, 4,0}; 
    
    std::vector<double> v10 = {1, 1, 1,
                              1, 1, 1};
    std::vector<double> v11 = {1, 1, 
                              1, 1, 
                              1, 1};                          
    std::vector<double> v12 = {1,1,1,1,
                               1,1,1,1,
                               1,1,1,1, 
                               1,1,1,1};  
    std::vector<double> v13 = {1};
                                                                                                                                                                                                                                                                                                                           
   Matrix m1{v1, 3, 3};
   Matrix m2{v2, 3, 3};
   Matrix m3{v3, 3, 3};
   Matrix m4{v4, 3, 3};
   Matrix m5{v5, 3, 3};
   Matrix m6{v6, 3, 3};
   Matrix m7{v7, 3, 3};
   Matrix m8{v8, 3, 3};
   Matrix m9{v9, 3, 4};
   Matrix m10{v10, 2, 3};
   Matrix m11{v11, 3, 2};
   Matrix m12{v12, 4, 4};


   std::vector<Matrix> mat = {m1,m2,m3,m4,m5,m6,m7,m8,m9,m10,m11,m12};
  
TEST_CASE("Good input") {
  SUBCASE("arithmetic"){
   CHECK(3*m1 == m2);
   CHECK(-m2 == m3);
   CHECK((m1+m2) == m4);
   CHECK((m1-m2) == m5);
   CHECK((m11*m10) == m12);
   CHECK(++m2 == m7);
    m2 *= 9;
   CHECK(m2 == m6);
    }


    SUBCASE("equal/not equal"){
     CHECK((m1<m2) == true); 
     CHECK((m1<=m2) == true); 
     CHECK((m2>m3) == true); 
     CHECK((m2>=m3) == true);
     CHECK((m7==m8) == true); 
     CHECK((m1!=m2) == true); 
     CHECK((m7<=m8) == true);
     CHECK((m7>=m8) == true);
     CHECK((m5>=m4) == false); 
     CHECK((m5>m4) == false);
     CHECK((m6<m4) == false);
     CHECK((m6<=m4) == false);
     CHECK((m1==m2) == false); 
     CHECK((m7!=m8) == false); 
    }
    SUBCASE("DONT TROW"){
      size_t j;
      for (size_t i = 0; i < 11; i++)
      {
        j=i+1;
       
        CHECK_NOTHROW(-mat[i]);
        CHECK_NOTHROW(++mat[i]);
        CHECK_NOTHROW(-mat[j]);
        CHECK_NOTHROW(++mat[j]);
        CHECK_NOTHROW(i*mat[i]);
        CHECK_NOTHROW(i*mat[j]);

      }
      

    }

}

  TEST_CASE("bad input") {
    SUBCASE("arithmetic between 2 matrix - col or row dosent match"){
       CHECK_THROWS((m1+m9));
        CHECK_THROWS((m10+m12));
       CHECK_THROWS((m10+m11));
        CHECK_THROWS((m10-m12));
       CHECK_THROWS(m1-m9);
       CHECK_THROWS((m10-m11));
       CHECK_THROWS(m1*m9);
        CHECK_THROWS((m10*m12));
      

    }
    SUBCASE("0=> row or col"){
    for(int i = 0;i>-100;i--) {
      CHECK_THROWS(Matrix(v12, 4, i));
      CHECK_THROWS(Matrix(v12, i, 4));
     }
    }
    SUBCASE("row or col dosent match matrix size"){
      for(int i = 2;i<100;i++){
         CHECK_THROWS(Matrix(v13,i,1));
         CHECK_THROWS(Matrix(v13,1,i));
         CHECK_THROWS(Matrix(v13,i,i));
      }
  
      
    }
}

  






