#ifndef CONSEIL_H_INCLUDED
#define CONSEIL_H_INCLUDED


using namespace std;

class Sommet
{
    //constructeurs/destructeurs
    public:
        string nom;
        Sommet();
        Sommet(string _nom);
        ~Sommet();

};
class Arete
{
    //constructeurs/destructeurs
    public:
        int sommet1, sommet2;
        Arete();
        Arete(string _nom);
        ~Arete();
};
class Graphe
{
    //constructeurs/destructeurs
    public:
        int ordre;
        int nb_aretes;

        Graphe();
        Graphe());
        ~Graphe();

        vector<vector<int>> matrice;

};




#endif // CONSEIL_H_INCLUDED


#endif // CONSEIL_H_INCLUDED
