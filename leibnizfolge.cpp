#include <iostream>

/**
 * @brief leibnizFolge: Berechnet PI mit der leibnizfolge
 * @param approx: Startwert der Rechnung sowie annähernd PI/4 (Beginnt mit 1)
 * @param k: Anzhal der zu berechnenden Glieder (Standartwert = 10)
 * @param vz: Der Opperand von "approx -+ (1 / DIV)" als Boolean [0 = "-",1 = "+"] (Beginnt mit 0)
 * @param div: Der Teiler (Beginnt mit 3)
 * @return: Rückgabewert ist die Annäherung an PI
 */
double leibnizFolge(int k = 10, double approx = 1, bool vz = 0, double div = 3){
    double r = 0;
    approx = (vz == 0) ? approx - (1 / div) : approx + (1 / div); //Die formal 1 - (1/3) + (1/5) + ... = (PI/4)
    r = approx * 4; //Da approx = (PI/4) muss der wert mit Vier multipliziert werde um die Annäherung an pi zu erhalten
    return (k == 0) ? r : leibnizFolge(k-1,   //Gibt r zrück wenn k = 0 ansonsten gehe tiefer in die Rekursion
                                       approx,      //Verringere k um 1
                                       (vz == 0), //Tausche das Vorzeichen
                                       div + 2 //Eröhe divident um 2 da nur ungerade zahlen als divident benutzt werden
                                       );
}

int main(){
    double r = leibnizFolge(10000); //Führe funktion aus. Wird ein wert
    std::cout << r << std::endl; //Schreibe ergebnis in das Konsolenfenster
	return 0;
}
