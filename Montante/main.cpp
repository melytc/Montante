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

// Función que obtiene el determinante de una matriz de 2 x 2.
int determinante (int iA, int iB, int iC, int iD)
{
    return (iA * iB) - (iC * iD);
}

// Función para desplegar una matriz de cualquier tamaño.
void mostrarMatriz (int iTamR, int iTamC)
{
    for (int iReng = 0; iReng < iTamR; iReng++)
    {
        for (int iCol = 0; iCol < iTamC; iCol++)
        {
            cout << iCoeficientes[iReng][iCol] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

// Función que obtiene la matriz aumentada modificada después del método de Montante.
<<<<<<< Updated upstream
void MatrizMontante (int iTamR, int iTamC) {
    int iPivote;
    for (int iReng = 0; iReng < iTamR; iReng++) {
        for (int iCol = 0; iCol < iTamC; iCol++) {
=======
void MatrizMontante (int iTamR, int iTamC, int iMatAct[iTamR][iTamC])
{
    int iPivote= iMatAct[0][0], iPivoteAnt=1;
    int iPivoteReng, iPivoteCol;
    int iMatAnt[iTamR][iTamC];
    int iter=0;
    
    
    for (int iReng = 0; iReng < iTamR; iReng++)
    {
        for (int iCol = 0; iCol < iTamC; iCol++)
        {
>>>>>>> Stashed changes
            // Para tomar la diagonal.
            if (iReng == iCol) {
                iPivote = iCoeficientes[iReng][iCol];
                // Primero hacer ceros hasta la columna del pivote.
                for ( int iC = 0; iC < iPivoteCol ; iC++)
                {
                    if(iC==iTamR)
                    {
                    }
                    else{
                        iMatAct[iReng][iCol] = 0;
                    }
                }
                // Copiar en la diagonal principal el pivote hasta la columna del pivote.
                for (int iC=0; iC < iPivoteCol; iC++)
                {
                        if(iReng==iCol)
                            iMatAct[iReng][iCol]=iPivote;
                }
                // Copiar el renglón del pivote igual, menos los ceros de la izquierda ya obtenidos.
                for(int iC=0; iC < iPivoteReng; iC++)
                {
                    if(iC>=iPivoteReng)
                    iMatAnt[iReng][iC]=iMatAct[iC][iCol];
                }
                // Hacer dos funciones: uno para el cuadrante I, y otro para el cuadrante IV.
                //Cuadrante I
                for(int iR= iPivoteReng ; iR<iTamR; iR++)
                {
                    for( int iC = iPivoteCol ; iC > iTamC ; iC++)
                    {
            
                        iMatAct[iR][iC] = ( ((iMatAnt[iR][iC]*iPivote)-(iMatAnt[iter][iC]* iMatAnt[iR][iter]) ) / iPivoteAnt );
                        iMatAct[iR][iC] = -1*( iMatAct[iR][iC]);
                        
                    }
                    
                }
                    
                //Cuadrante IV
                for(int iR= iPivoteReng ; iR>iTamR; iR++)
                {
                    for( int iC = iPivoteCol ; iC > iTamC ; iC++)
                    {
                        
                        iMatAct[iR][iC] = ( ((iMatAnt[iR][iC]*iPivote)-(iMatAnt[iter][iC]* iMatAnt[iR][iter]) ) / iPivoteAnt );
                        
                    }
                    
                }
            }
            
        }

    }
}


// Función que resuelve un SEL dada en una matriz.
<<<<<<< Updated upstream
void SolucionSEL (int iTamR, int iTamC) {
    for (int iReng = iTamR - 1; iTamR >= 0; iTamR--) {
        for (int iCol = ) {
            
        }
=======
void SolucionSEL (int iTamR, int iTamC)
{
    for (int iReng = iTamR - 1; iTamR >= 0; iTamR--)
    {
       
>>>>>>> Stashed changes
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
    while (iEcuaciones != iIncognitas) {
        cout << "El número de ecuaciones-incógnitas no coinciden." << endl;
        cout << "Ingrese el número de ecuaciones: ";
        cin >> iEcuaciones;
        cout << "Ingrese el número de incógnitas: ";
        cin >> iIncognitas;
    }
    
    // Ingreso de coeficientes.
    cout << "Por favor ingrese" << endl;
<<<<<<< Updated upstream
    for (int iReng = 0; iReng < iEcuaciones; iReng++) {
        for (int iCol = 0; iCol < iIncognitas; iCol++) {
=======
    for (int iReng = 0; iReng < iEcuaciones; iReng++)
    {
        for (int iCol = 0; iCol < iIncognitas+1; iCol++)
        {
>>>>>>> Stashed changes
            cout << "El coeficiente #"<< iCol + 1 <<" de la ecuación " << iReng + 1 << ": ";
            cin >> iCoeficientes[iReng][iCol];
        }
    }
    
    return 0;
}
