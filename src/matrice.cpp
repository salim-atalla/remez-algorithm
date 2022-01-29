#include <cmath>
#include <cassert>

#include "matrice.hpp"




/*

  EX5_a:
  Rôle: créer une matrice A de n lignes et m colonnes.
  @param int n : le nombre de lignes.
  @param int m : le nombre de colonnes.
  @return la matrice A de dimensions (n x m)

*/
double * creer_Matrice_Vide (int n, int m) 
{
  assert(n>0 && m>0); 
  return new double[n * m]; 
}





/*
  EX5_b:
  Rôle: créer une matrice A de (E1), de n lignes et m colonnes.
  @param int n : le nombre de lignes.
  @param int m : le nombre de colonnes.
  @return la matrice A de dimensions (n x m)
*/
double * construire_Martrice_A(int n, int m, double *x_i)
{
  double *A = creer_Matrice_Vide(n, m); // allouer la matrice.
  
  for (int i=0; i<n; i++) {     // i représent les lignes.
    for (int j=0; j<m; j++) {   // j représent les colonnes.

      if (j%(m-1) == 0 && j%m != 0) {   // remplir les cases de la dérnière colonne par 1 et -1

        if (i%2 == 0){
          A[m*i+j] = 1;
        }else{
          A[m*i+j] = -1;
        } 

      }else{  // remplir les autres cases de la matrice.
        A[m*i+j] = pow(x_i[i], j);
      } 
    }
  }
  return A;
}





/*

  EX6_a:
  Rôle: créer un vecteur V vide de taille n.
  @param int n : le nombre de lignes. 
  @return le vecteur V.
  
*/
double * creer_Vecteur_Vide (int n)  
{ 
  assert(n>0);
  return new double[n]; 
}





/*

  EX6_b:
  Rôle: créer un vecteur C à partir d'un tableau de points z_i de taille n.
  @param int n : la taille du tableau z_i. 
  @return le vecteur C.
  
*/
double * construire_Vecteur_C (double (*f)(double), double *x_i, int n) 
{
  double *C = creer_Vecteur_Vide(n);
  
  for (int i=0; i<n; i++) {
    C[i] = f(x_i[i]);
  }
  return C;
}





/*
  Rôle: multiplication de deux matrices.
  @param double *A, double *B :  deux matrices.
  @param int n : Le nombre de lignes.
  @param int m : Le nombre de colonnes.
  @return La matrice (A*B) de taille n.
*/
double * mult_Matrice (double *A, double *B, int n, int m)
{
  assert(n>0); 

  double *S = new double[n*n];

  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      
      S[n*i+j]=0;

      for(int k=0; k<m; k++) {
        S[n*i+j] += A[n*i+k] * B[n*k+j];
      }
    }
  }
  return S;
}





/*
  Rôle: soustraction de deux matrices (A-B).
  @param double *A:  Matrice de taille (n x m).
  @param double *B : Matrice de taille (n x m).
  @param int n : Le nombre de lignes.
  @param int m : Le nombre de colonnes.
  @return La matrice (A-B).
*/
double * sub_Matrice (double *A, double *B, int n, int m)
{
  assert(n>0 && m>0); 

  double *S = new double[n*m];

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {

      S[i*m+j] = A[i*m+j] - B[i*m+j];
		}
	}
  return S;
}





/*
    Rôle: résoudre un système linéaire par la méthode de pivot de gauss.
    @param double *A : matrice de dimensions (n x n).
    @param double *V : vecteur de taille n représente les solutions du système linéaire.
    @param int n : la taille du vecteur V.
    @return le vecteur B qui représente les solutions du système.
*/
double * gauss (double *A, double *V, int n) 
{
  assert(n>0);

  double *z = new double[n];
  double pivot, p, sol;

  // pivotation
  for (int i=0; i<n-1; i++) {
    pivot = A[n*i + i];

    for (int j=i+1; j<n; j++) {
      p = -A[n*j +i] / pivot;

      for (int k=0; k<n; k++) {
        A[n*j + k] = A[n*j + k] + p*A[n*i + k];
      }
      V[j] = V[j] + p*V[i];
    }
  }


  //Résolution
  for (int i=n-1; i>=0; i--) {
    sol = 0;

    for (int j=i+1; j<n; j++) {
      sol = sol + A[n*i+j] * z[j];
      z[i] = (V[i] - sol) / A[n*i+i];
    }
  }
  return z;
}

