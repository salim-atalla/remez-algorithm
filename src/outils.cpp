#include <iostream>
#include <cmath>
#include <cassert>

#include "outils.hpp"





/*
  Fonctions pour obtenir la 1er et la 2ème dérivée d'une fonction f par la méthode de la sécante.
*/
double  df  (double (*f)(double), double X)   { return (f(X)-f(X-eps))/eps; }
double  ddf (double (*f)(double), double X)   { return ((df(f, X)-df(f, X-eps))/eps); }





/*

  EX2: 
  Rôle : construir un tableau de n points équidistants sur un intervalle [a, b] donnée.
  @param double a, double b : représentant les pôles de l'intervalle.
  @param int n : représentant le nombre de points.
  @return un tableau x_i de n points de départ.

*/
double * Div_Intervalle (double a, double b, int n)
{
  assert(n>=3 && b>a);

  double *x_i = new double[n];  // allocation du tableau x_i

  for (int i=0; i<n; i++) {
    x_i[i] = a+(b-a)/(n-1)*i;
  }
  return x_i;
}





/*

  EX3_a: 
  Rôle: Chercher le point max sur l'axe des abscisses.
  @param double (*f)(double) : pointeur vers une une fonction donnée.
  @param double a, double b : représentant l'intervalle donnée.
  @return le point extrême sur l'axe des abscisses.

*/
double X_i_Max (double (*f)(double), double a, double b)
{
  assert(b>a);

  double max, x;
  x = a;
  max = x;

  while (x <= b) {
    if (f(x) > f(max)) {
      max = x;
    }
    x = x + eps;
  }
  return max;
}





/*

  EX3_b: 
  Rôle:   Rôle: Chercher le point max sur l'axe des ordonnées.
  @param double (*f)(double) : pointeur vers une une fonction donnée.
  @param double a, double b : représentant l'intervalle donnée.
  @return le point extrême sur l'axe des abscisses.

*/
double  Fx_i_Max (double (*f)(double), double a, double b) { return f(X_i_Max(f, a, b)); }





/*

  Rôle : Chercher le point extrême d'une fonction sur un intervalle [a, b] par la méthode de Newton.
  @param double (*f)(double) : pointeur vers une une fonction donnée.
  @param double a, double b : représentant l'intervalle donnée.
  @return le point extrême sur l'axe des abscisses.

*/

double X_MaxFunc (double (*f)(double), double a, double b)
{
  assert(a<b && df(f, a)*df(f, b) < 0);
    
  double X, Xi;
  X = a;
  
  do{
    X = Xi;
    Xi = X - df(f, X) / ddf(f, X); 

  } while (abs(Xi-X)>=eps);

  return Xi;  
}





/*

  EX4:
  Rôle: construir un tableau de n-1 points d'extremes sur des sous-intervalles [x_i, x_i+1] données.
  @param double (*f)(double) : pointeur vers une une fonction donnée.
  @param double *x_i : pointeur vers un tableau de doubles.
  @param int n : la taille du tableau x_i
  @return un tableau de double z_i de taille n-1

*/
double * Z_i_Max (double (*f)(double), double *x_i, int n)
{
  assert(n>=3);
  double *z_i = new double[n-1];
  
  for (int i=0; i<n-1; i++) { 
    z_i[i] = Fx_i_Max(f, x_i[i], x_i[i+1]);
  }
  return z_i;
}





