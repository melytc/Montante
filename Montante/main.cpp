//
//  main.cpp
//  Montante
//
//  Created by Melissa Trevino on 3/3/16.
//
//  Collaborators:
//  Melissa Janet Treviño Caballero     A00816715
//  María Paula Anastás Benavides       A00817285
//  Luis Felipe Salazar Valenzuela      A00817158
//
//  Copyright © 2016 Melissa Trevino.
//  All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int iCoeficientes[10][10];
int iMIdentidad[10][10];
int iMAumentada[20][20];

// Función que obtiene el determinante, lo cual hace con programación dinámica.
int determinante (int iA, int iB, int iC, int iD)
{
    return (iA * iB) - (iC * iD);
}

// Función que crea una matriz identidad según el tamño dado.
void crearMIdentidad (int iTam)
{
    for (int iReng = 0; iReng < iTam; iReng++)
    {
        for (int iCol = 0; iCol < iTam; iCol++)
        {
            if (iCol == iReng)
                iMIdentidad[iReng][iCol] = 1;
            else
                iMIdentidad[iReng][iCol] = 0;
        }
    }
}

// Función para desplegar una matriz de cualquier tamaño.
void mostrarMatriz (int iTamR, int iTamC)
{
    for (int iReng = 0; iReng < iTamR; iReng++)
    {
        for (int iCol = 0; iCol < iTamC; iCol++)
        {
            cout << iMAumentada[iReng][iCol] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

// Función que crea una matriz aumentada
void creaMatrizAumentada(int iTam)
{
    // Primero llena la matriz de coeficientes la parte izquierda.
    for (int iReng = 0; iReng < iTam; iReng++)
    {
        for (int iCol = 0; iCol < iTam; iCol++)
            iMAumentada[iReng][iCol] = iCoeficientes[iReng][iCol];
    }
    
    // Despúes crear la matriz identidad.
    crearMIdentidad(iTam);
    
    // Por último, agregar esa matriz identidad al lado izquierdo de la matriz aumentada.
    for (int iReng = 0; iReng < iTam; iReng++)
    {
        for (int iCol = iTam; iCol < iTam * 2; iCol++)
            iMAumentada[iReng][iCol] = iMIdentidad[iReng][iCol - iTam];
    }
    
    mostrarMatriz(iTam, iTam * 2);
}

// Función que obtiene la matriz aumentada modificada después del método de Montante.
void MatrizMontante(int iTamR, int iTamC)
{
    int iPivote;
    for (int iReng = 0; iReng < iTamR; iReng++)
    {
        for (int iCol = 0; iCol < iTamC; iCol++)
        {
            // Para tomar la diagonal.
            if (iReng == iCol)
            {
                iPivote = iMAumentada[iReng][iCol];
                // Primero hacer ceros hasta la columna del pivote.
                // Copiar el renglón del pivote igual, menos los ceros de la izquierda ya obtenidos.
                // Hacer dos funciones: uno para el cuadrante I, y otro para el cuadrante IV.
            }
            
        }
    }
}

int main() {
    
    int iEcuaciones, iIncognitas;
    cout << "   MÉTODO MONTANTE" << endl;
    cout << "Ingrese el número de ecuaciones: ";
    cin >> iEcuaciones;
    cout << "Ingrese el número de incógnitas: ";
    cin >> iIncognitas;
    
    // Validación de que es una matriz cuadrada.
    while (iEcuaciones != iIncognitas)
    {
        cout << "El número de ecuaciones-incógnitas no coinciden." << endl;
        cout << "Ingrese el número de ecuaciones: ";
        cin >> iEcuaciones;
        cout << "Ingrese el número de incógnitas: ";
        cin >> iIncognitas;
    }
    
    // Ingreso de coeficientes.
    cout << "Por favor ingrese" << endl;
    for (int iReng = 0; iReng < iEcuaciones; iReng++)
    {
        for (int iCol = 0; iCol < iIncognitas; iCol++)
        {
            cout << "El coeficiente #"<< iCol + 1 <<" de la ecuación " << iReng + 1 << ": ";
            cin >> iCoeficientes[iReng][iCol];
        }
    }
    
    // Creo la matriz aumentada donde tiene la matriz identidad.
    creaMatrizAumentada(iEcuaciones);
    
    return 0;
}
