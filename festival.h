#include<iostream>
#include<string>
#include <vector>
#pragma once
using namespace std;
class artiste{
	private:
		int id;
		string nomsc;
		string genremusical;
		string paysorigine;
		double cachet;
		int joursinsc,moisinsc,anneeinsc;
		public:
			artiste();
			void saisie();
			void affiche();
		int getid();
		void setId(int v);
		string getnomSc();
		void setnomSc(string &s);
		int getjourInsc();
        int getmoisInsc();
        int getanneeInsc();
};
class technicien{
	private:
		int id;
		string nom;
		string prenom;
		string specialite;
		double salaire;
		int joursem,moisem,anneeem;
		public:
			technicien();
			void saisie();
			void affiche();
			int getid();
			void setid(int v);
			string getnom();
};
class Scene {
private:
    int code;
    string nom;
    technicien responsable;
    int maxArtistes;
    vector<artiste> artistes;
    int jourServ, moisServ, anneeServ;
    public:
    	Scene();
    void saisir();
    void afficher();
    bool artisteExiste(int id) ;
    bool ajouterArtiste( artiste &a);
    void changerNom(  string &n);
    void afficherRecents()  ;
    int anciennete(int anneeActuelle)  ;
    bool supprimerArtiste(int id);
    vector<artiste> getartistes();
    
    int getcode();
    void setcode(int c);
    string getNom();
    void setNom(  string &n);
    
    technicien getResponsable();
    void setResponsable(  technicien &t);
    int getAnneeServ();
};  
class Festival {
private:
    vector<Scene> scenes;

public:
    Festival();
    bool existeScene(int code); 
    void ajouterScene();
    bool supprimerScene(int code);
    bool modifierScene(int code); 
    void afficherAnciennetes() ;
    vector<Scene> scenesPlusDe5Ans(int anneeActuelle);
    void afficherScenesParTechnicien(int idTechnicien);
   
};
    