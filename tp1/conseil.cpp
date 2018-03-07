#include <iostream>
#include <vector>
#include "conseil.h"

Graphe::Graphe(){}
Graphe::~Graphe(){}

void Graphe::lirefichier(vector<vector<int*>> matrice)
{
    ifstream fichier("conseil.txt",ios::in);
    if(fichier)
    {
        //variables temporaires pour les constructeurs
        int nombre;
        string nom;
        int influences;
        int influe;
        string ligne;

        //infos en tete de fichier
        getline(fichier,ligne);
        nombre = atoi(chara.c_str());
        cout<< ligne<<nombre;

/*
       for(int i=0;i<*INFOS[0];i++)//cartes energie
        {
            getline(fichier,nom);
            nom.erase(nom.size()-1);
            getline(fichier,description);
            getline(fichier,chara);
            domaine=chara[0];
            ensemblecartes.push_back(new Energie(nom,description,domaine));

        }

        for(int i=*INFOS[0];i<*INFOS[0]+*INFOS[1];i++)//cartes etudiant
        {
            getline(fichier,nom);
            nom.erase(nom.size()-1);
            getline(fichier,description);
            getline(fichier,chara);
            points=atoi(chara.c_str());

            getline(fichier,pat.m_nom);
            getline(fichier,chara);
            pat.m_lettre1=chara[0];
            pat.m_lettre2=chara[1];
            getline(fichier,chara);
            pat.m_HP=atoi(chara.c_str());

            getline(fichier,sat.m_nom);
            getline(fichier,chara);
            sat.m_lettre1=chara[0];
            sat.m_lettre2=chara[1];
            getline(fichier,chara);
            sat.m_HP=atoi(chara.c_str());
            ensemblecartes.push_back(new Creature(nom,description,points, pat, sat));

        }
        for(int i=*INFOS[0]+*INFOS[1];i<*INFOS[0]+*INFOS[1]+*INFOS[2];i++)//cartes speciales
        {
            getline(fichier,nom);
            nom.erase(nom.size()-1);
            getline(fichier,description);
            getline(fichier,chara);
            recyclage=atoi(chara.c_str());
            getline(fichier,chara);
            usage=atoi(chara.c_str());
            getline(fichier,chara);
            refus=atoi(chara.c_str());
            ensemblecartes.push_back(new Speciale(nom,description,recyclage,usage,refus));

        }

        for (int i=0;i<*INFOS[3];i++)//infos joueurs
        {
            deck.clear();
            collection.clear();
            getline(fichier,nom);
            nom.erase(nom.size()-1);
            getline(fichier,chara);
            points=atoi(chara.c_str());

            getline(fichier,chara);
            nbcartes=atoi(chara.c_str());
            for(int k=0;k<6;k++)
            {
                getline(fichier,chara);
                deck.push_back(atoi(chara.c_str()));

            }
            for(int k=0;k<nbcartes;k++)
            {
                getline(fichier,chara);
                collection.push_back(atoi(chara.c_str()));

            }
            ensemblejoueurs.push_back(new Joueur(nom,points,nbcartes,deck,collection));
        }*/
    }
    else cerr<<"Pb fichier"<<endl;


    fichier.close();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
void Menu::fermer_fichier(vector<Carte*>&ensemblecartes,vector<Joueur*>&ensemblejoueurs,
                vector<int*>&INFOS)
{
    ofstream fichier2("fichier2.txt",ios::out|ios::trunc);
    if(fichier2)
    {

        //infos en tete de fichier
        fichier2<<*INFOS[0]<<endl;
        fichier2<<*INFOS[1]<<endl;
        fichier2<<*INFOS[2]<<endl;
        fichier2<<*INFOS[3]<<endl;

       for(int i=0;i<*INFOS[0];i++)//cartes energie
        {
            fichier2<<ensemblecartes[i]->getnom()<<endl;
            fichier2<<ensemblecartes[i]->getdescription()<<endl;
            fichier2<<dynamic_cast<Energie*>(ensemblecartes[i])->getdomaine()<<endl;

        }

        for(int i=*INFOS[0];i<*INFOS[0]+*INFOS[1];i++)//cartes creatures
        {
            fichier2<<ensemblecartes[i]->getnom()<<endl;
            fichier2<<ensemblecartes[i]->getdescription()<<endl;
            fichier2<<dynamic_cast<Creature*>(ensemblecartes[i])->getAtt1nom()<<endl;
            fichier2<<dynamic_cast<Creature*>(ensemblecartes[i])->getAtt1l1();
            fichier2<<dynamic_cast<Creature*>(ensemblecartes[i])->getAtt1l2()<<endl;
            fichier2<<dynamic_cast<Creature*>(ensemblecartes[i])->getAtt1HP()<<endl;

            fichier2<<dynamic_cast<Creature*>(ensemblecartes[i])->getAtt2nom()<<endl;
            fichier2<<dynamic_cast<Creature*>(ensemblecartes[i])->getAtt2l1();
            fichier2<<dynamic_cast<Creature*>(ensemblecartes[i])->getAtt2l2()<<endl;
            fichier2<<dynamic_cast<Creature*>(ensemblecartes[i])->getAtt2HP()<<endl;

        }

        for(int i=*INFOS[0]+*INFOS[1];i<*INFOS[0]+*INFOS[1]+*INFOS[2];i++)//cartes speciales
        {
            fichier2<<ensemblecartes[i]->getnom()<<endl;
            fichier2<<ensemblecartes[i]->getdescription()<<endl;
            fichier2<<dynamic_cast<Speciale*>(ensemblecartes[i])->getrecyclage()<<endl;
            fichier2<<dynamic_cast<Speciale*>(ensemblecartes[i])->getutilisation()<<endl;
            fichier2<<dynamic_cast<Speciale*>(ensemblecartes[i])->getrefus()<<endl;

        }

        for (int i=0;i<*INFOS[3];i++)//infos joueurs
        {
            fichier2<<ensemblejoueurs[i]->getnom()<<endl;
            fichier2<<ensemblejoueurs[i]->getargent()<<endl;
            fichier2<<ensemblejoueurs[i]->getnbcartes()<<endl;
            for(int j=0;j<6;j++)
                fichier2<<ensemblejoueurs[i]->getdeck(j)<<endl;
            for(int j=0;j<ensemblejoueurs[i]->getnbcartes();j++)
                fichier2<<ensemblejoueurs[i]->getcollection(j)<<endl;


        }


    }
    else cerr<<"Pb fichier"<<endl;

    fichier.close();
}

    ////////
