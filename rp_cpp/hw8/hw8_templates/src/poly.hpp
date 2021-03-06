#ifndef POLY_HPP_
#define POLY_HPP_

#include <stdlib.h>
#include <vector>

template<typename T>
class Poly {
public:

  /* Default constructor */
  Poly();

  /* Constructor for a poly that's a constant number */
  Poly( T constant );

  /* Given a vector of coefficients */
  Poly( const std::vector<T> & coeffs );

  /* Given an rvalue reference of a vector of coefficients */
  Poly( std::vector<T> && coeffs );

  /* Given an array of coefficients with size of the array*/
  Poly( T * coeffs, size_t numberCoeffs );

  /* Given an initializer_list */
  Poly( std::initializer_list<T> coeffs );

  virtual ~Poly();

  /* Copying constructor */
  Poly( const Poly<T> & poly );

  /* Copying constructor with rvalue reference */
  Poly( Poly<T> && poly );

  /* Assignment operator */
  Poly<T>& operator=( const Poly<T> & poly );
  
  /* Assignment operator with rvalue reference */
  Poly<T>& operator=( Poly<T> && poly );

  /*
   * Below are operations of polynomials.
   * They are quite self-explanatory.
   */

  Poly<T> operator+( const Poly<T> & rhs ) const;
  Poly<T> operator-( const Poly<T> & rhs ) const;
  Poly<T> operator*( const Poly<T> & rhs ) const;

  Poly<T> & operator+=( const Poly<T> & rhs );
  Poly<T> & operator-=( const Poly<T> & rhs );
  Poly<T> & operator*=( const Poly<T> & rhs );

  /* 
   * This function evaluates the polynomial at "param",
   * and returns the value of evaluation.
   * For example, evaluating x+3 at param=7 gives 10. 
   */
  T eval( T param ) const;

  /* 
   * This function takes the derivative of the polynomial,
   * and returns a new polynomial of its derivative.
   * For example, calling this function for x^2
   * will return a polynomial 2x.
   */
  Poly<T> der() const;

  /*
  * This function returns a pair of:
  * 1. the value (evaluation) of the polynomial at "param".
  * 2. the value of the first-order derivative of the polynomial at "param".
  * For example, calling this operator for x^2-2x at "param"=4
  * will return (8, 6).
  */
  std::pair<T,T> operator()( T param ) const;

private:
  std::vector<T> _coeffs;
};


#endif