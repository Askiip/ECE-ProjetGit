#include <iostream>
#include "conseil.h"

using namespace std;

int main()
{
    Graphe* a;
    cout << "Hello world!" << endl;
    a=new(Graphe());
    a.lirefichier(matrice);
    return 0;
}
