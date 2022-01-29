#include <iostream>
#include <cmath>

#include "remez.hpp"
#include "outils.hpp"
#include "matrice.hpp"


using namespace std;


/*
      exemples pour faire les tests: une fonction f1 et f2.
*/
double  f1  (double x)    { return pow(x, 2) + x; }   // f1(x) = x^2 + x
double  f2  (double x)    { return pow(x, 3) + 2*pow(x, 2) + x - 1; }  // f2(x) = x^3 + 2*x^2 + x - 1





int main() 
{
  


/*
      Initialisation des variables utiles.
*/
  double (*f)(double) = &f1;  // pointeur vers une fonction.
  int n = 5;  // le nombre de points sur l'intervalle, où a et b sont le premièr et le dérnièr points de cet intervalle.
  double a, b;  // les pôles de l'intervalle.
  a = 2;
  b = 6;



/*
      Début des tests:
*/
  cout << "========================================Debut========================================" << endl;
  cout << endl;





/*
      EX2:
*/
  cout << "----------------------------------------------------------------" << endl;
  cout << "       Les points de depart: (X0, X1, ..., Xn)" << endl;
  cout << "----------------------------------------------------------------" << endl;
  cout << endl;

  double *x_i = Div_Intervalle(a, b, n); // créer un tableau de doubles de n cases.

  // Affichage des points X0, X1, ..., Xn
  for (int i=0; i<n-1; i++) {
    cout << x_i[i] << ", ";
  }
  cout << x_i[n-1] << endl;
  





/*
      EX3:
*/
  cout << endl;
  cout << "-------------------------------------------------------------" << endl;
  cout << "       Le point max sur l'intervalle [a, b]" << endl;
  cout << "-------------------------------------------------------------" << endl;
  cout << endl;

  double x = X_i_Max(f, a, b);

  // Affichage le point max sur un intervalle donnée.
  cout << "x = " << x << endl;
  cout << "f(x) = " << f(x) << endl;

/*
  cout << "Methode de Newton: x = " << X_MaxFunc(f, a, b) << endl;
  cout << "Methode de Newton: f(x) = " << f(X_MaxFunc(f, a, b)) << endl;
*/






/*
      EX4:
*/
  cout << endl;
  cout << "------------------------------------------------------" << endl;
  cout << "       Les points: (Z0, Z1, ..., Zn-1)" << endl;
  cout << "------------------------------------------------------" << endl;
  cout << endl;

  double *z_i = Z_i_Max(f, x_i, n); // créer un tableau de doubles de n-1 cases.

  // Affichage des point Z0, Z1, ..., Zn-1
  for (int i=0; i<n-2; i++) {
    cout << z_i[i] << ", ";
  }
  cout << z_i[n-2] << endl;
  





/*
      EX5:
*/
  cout << endl;
  cout << "-------------------------------------" << endl;
  cout << "       La matrice A" << endl;
  cout << "-------------------------------------" << endl;
  cout << endl;

  double *A = construire_Martrice_A(n, n, x_i); // créer la matrice A de "E1", de dimensions (n x n).


  // Afficher la matrice A.
  for (int i=0; i<n*n; i++) {

    if (i%n==0 && i!=0) {   // finir les lignes.
      cout << endl;
      cout << endl;
    }
    cout << A[i] << "  ";
  }
  cout << endl;
  





/*
      EX6:
*/
  cout << endl;
  cout << "-------------------------------------" << endl;
  cout << "       Le vecteur C" << endl;
  cout << "-------------------------------------" << endl;
  cout << endl;

  double *C = construire_Vecteur_C(f, x_i, n);  // construir le vecteur C de taille n.

  // Afficher le vecteur C.
  for (int i=0; i<n; i++) {
    cout << C[i] << endl;
  }





/*
      EX7:
*/
  cout << endl;
  cout << "-------------------------------------" << endl;
  cout << "       Les coefficients: " << endl;
  cout << "-------------------------------------" << endl;
  cout << endl;

  double *B = gauss (A, C, n);

  // Afficher le vecteur B.
  for (int i=0; i<n; i++) {
    cout << "a" << i << " = "  << B[i] << endl;
  }





/*
      EX8:
*/
  cout << endl;
  cout << "===================================================================" << endl;
  cout << "                 Le polynome par la méthode de remez: " << endl;
  cout << "===================================================================" << endl;
  cout << endl;

  double *coeff = new double[n];
  coeff = remez (f, a, b, n);


  // Afficher le vecteur de coefficients.
  cout << "Le vecteur des coefficients est: " << endl;
  cout << endl;

 for (int i=0; i<n; i++) {
    cout << "a" << i << " = "  << coeff[i] << endl;
  }


  // Afficher le polynôme P(x).
  cout << endl;
  cout << "P(X) = ";
  cout << coeff[0] << " + " << coeff[1] << "*X" << " + ";
  if (n>3) {
    for (int i=2; i<n-1; i++) {
      cout << coeff[i] << "*X^" << i << " + ";
    }
  }
  cout << coeff[n-1] << "*X^" << n-1 << endl;
  cout << endl;






  cout << "========================================Fin========================================" << endl;




  /*
      Désallouer les tableaux dynamiques.
  */

  delete(x_i);  
  delete(z_i);
  delete(A);
  delete(B);
  delete(C);
  delete(coeff);
  
  return 0;
}




