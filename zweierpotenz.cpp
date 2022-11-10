#include <iostream>

// Entferne "//" in der nächsten Zeile um UNIT tests anstatt dem Hauptprogram zu benutzen
//#define doUnitTest 1
double zweierpotenz(int n){
    if(n == 0){
        return 1;
    }else if(n == 1){
        return 2;
    }
    int o = n;
    double Ergebnis = 2;

    if(o > 0){
        while(n > 1){
            Ergebnis *= 2;
            n -= 1;
        }
    }else if(o < 0){
        while(n < -1){
            Ergebnis *= 2;
            n += 1;
        }
        Ergebnis = 1/Ergebnis;
    }else{
        //Wie bin ich hierhergekommen?
        std::cout << "Wie bin ich hierhergekeommen?";
    }
    return Ergebnis;
}
#ifdef doUnitTest
void test(){
    std::cout << "UNIT TEST:" << std::endl;
    std::cout << "zweierpotenz(3) == 8" <<std::endl;
    _ASSERT(zweierpotenz(3) == 8);
    std::cout << "PASSED" <<std::endl;
    std::cout << "zweierpotenz(-1) == 00.5" <<std::endl;
    _ASSERT(zweierpotenz(-1) == 0.5);
    std::cout << "PASSED" <<std::endl;
    std::cout << "zweierpotenz(1) == 2" <<std::endl;
    _ASSERT(zweierpotenz(1) == 2);
    std::cout << "PASSED" <<std::endl;
    std::cout << "zweierpotenz(0) == 1" <<std::endl;
    _ASSERT(zweierpotenz(0) == 1);
    std::cout << "PASSED" <<std::endl;
    std::cout << "zweierpotenz(3) == 9" <<std::endl;
    _ASSERT(zweierpotenz(3) == 9); //Wenn _Assert hier nicht das program terminiert ist etwas schiefgelaufen
}
int main()
{
    test();
    return 0;
}
#else
int main()
{
    int n=5;
    std::cout << zweierpotenz(n) << std::endl;
    return 0;
}
#endif
