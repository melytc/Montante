//
//  main.cpp
//  Montante
//
//  Created by Melissa Treviño on 3/3/16.
//
//  Collaborators:
//  Melissa Janet Treviño Caballero     A00816715
//  María Paula Anastás Benavides       A00817285
//
//  Copyright © 2016 Melissa Treviño. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    // Declaración de variables.
    int  iMat2[10][10], iMat[10][10], iPivote, iPivoteAnt = 1, iIter = 0;
    int iRenglon[10];
    double dRespuestas[10];
    bool bStat = true;
    
    // Ingresamos los valores en la matriz
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
    
    cout << endl;
    iIncognitas++;
    
    // Ingreso de coeficientes y constantes.
    cout << "Por favor ingrese" << endl;
    for (int iReng = 0; iReng < iEcuaciones; iReng++) {
        for (int iCol = 0; iCol < iIncognitas - 1; iCol++) {
            cout << "El coeficiente #"<< iCol + 1 <<" de la ecuación " << iReng + 1 << ": ";
            cin >> iMat[iReng][iCol];
        }
        cout << "La constante de la ecuación " << iReng + 1 <<": ";
        cin >> iMat[iReng][iIncognitas-1];
        cout << endl;
    }
    
    int iREN = iEcuaciones;
    int iCOL = iIncognitas;
    
    // Se hace una iteracion por cada renglon de la matriz (cada ecuacion)
    while(iIter < iREN)
    {
        
        // Sacamos el pivote
        iPivote = iMat[iIter][iIter];
        
        // Mientras el pivote valga 0, intercambiamos renglones
        while (iPivote == 0)
        {
            // Se intercambian renglones
            for(int iC = 0; iC < iCOL; iC++) {
                iRenglon[iC] = iMat[iIter + 1][iC];
                iMat[iIter + 1][iC] = iMat[iIter][iC];
                iMat[iIter][iC] = iRenglon[iC];
            }
            
            // Volvemos a sacar pivote
            iPivote = iMat[iIter][iIter];
            
            // Si no se encuentra un pivote diferente a 0, solución única no tiene.
            if(iPivote == 0)
            {
                // Aquí checamos si no tiene solución o tiene un número infinito de soluciones.
                for(int i = 0; i < iEcuaciones; i++)
                {
                    double resp;
                    if (iMat[i][i] == 0)
                    {
                        if (iMat[i][i+1] != 0)
                            break;
                        cout << "No hay solución." << endl;
                        return 0;
                    }
                    resp = iMat[i][iCOL-1] * 1.0 / iMat[i][i];
                    dRespuestas[i] = resp;
                }
                
                cout << "Hay número infinito de soluciones" << endl;
                bStat = false;
                return 0;
            }
        }
        
        // Pasamos el renglón de la matriz a una matriz nueva.
        for(int iC = 0; iC < iCOL; iC++)
            iMat2[iIter][iC] = iMat[iIter][iC];
        
        // Ponemos 0s en lo faltante de la columna del pivote.
        for(int iR = 0; iR < iREN; iR++)
        {
            if(iIter != iR)
                iMat2[iR][iIter] = 0;
        }
        
        // Sacar el valor de la posición según la matriz anterior.
        for(int iR = 0; iR < iREN; iR++)
        {
            for(int iC = 0; iC < iCOL; iC++)
            {
                if(iR != iIter)
                {
                    if( iC != iIter)
                        iMat2[iR][iC] = (((iMat[iR][iC] * iPivote) - (iMat[iIter][iC] * iMat[iR][iIter])) / iPivoteAnt);
                }
            }
        }
        
        iIter++;
        iPivoteAnt = iPivote;
        
        // Actualizamos la matriz copiando la auxiliar.
        for(int iR = 0; iR < iREN; iR++)
        {
            for(int iC = 0; iC < iCOL; iC++)
                iMat[iR][iC] = iMat2[iR][iC];
        }
    }
    
    
    if(bStat)
    {
        cout << "Solución única" << endl;
        for(int i = 0; i < iEcuaciones; i++)
        {
            double resp;
            resp = iMat[i][iCOL-1] * 1.0 / iMat[i][i];
            cout << "x" << i+1 << " = " << resp << endl;
        }
    }
    
    
    return 0;
}
