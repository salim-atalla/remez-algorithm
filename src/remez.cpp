#include "remez.hpp"
#include "outils.hpp"
#include "matrice.hpp"
#include <iostream>



/*
    Rôle: Déterminer l'approximation d'un polynôme par la méthode de Remez.
*/
double * remez (double (*f)(double), double a, double b, int n)
{

    double *x_i = new double[n];
    double *z_i = new double[n-1];
    double *A   = new double[n*n];
    double *C   = new double[n];
    double *B   = new double[n];


    x_i = Div_Intervalle(a, b, n); // créer un tableau de doubles de n cases.
    z_i = Z_i_Max(f, x_i, n); // créer un tableau de doubles de n-1 cases.
    A   = construire_Martrice_A(n, n, x_i); // créer la matrice A de "E1", de dimensions (n x n).
    C   = construire_Vecteur_C(f, x_i, n);  // construir le vecteur B de taille n.
    B   = gauss (A, C, n);  //  Résoudre le système:  A*B=C par la méthode de gauss.



    /*
        Désallouer les tableaux dynamiques.
    */
        delete(x_i);  
        delete(z_i);
        delete(A);
        delete(C);

    return B;   // retourner les coefficients du polynôme d'approximation.
}



