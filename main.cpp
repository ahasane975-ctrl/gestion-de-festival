#include <iostream>
#include "festival.h"

using namespace std;
int main() {
    Festival fest;
    int choix = -1;

    while (choix != 0) {
        cout << "\n====== MENU FESTIVAL ======\n";
        cout << "1. Ajouter une scene\n";
        cout << "2. Supprimer une scene (par code)\n";
        cout << "3. Modifier une scene (par code)\n";
        cout << "4. Ajouter un artiste a une scene (par code)\n";
        cout << "5. Supprimer un artiste d'une scene (par code)\n";
        cout << "6. Afficher artistes recents d une scene (par code)\n";
        cout << "7. Afficher anciennetes des scenes\n";
        cout << "8. Afficher scenes en service > 5 ans\n";
        cout << "9. Afficher scenes d un technicien (id)\n";
        cout << "0. Quitter\n";
        cout << "Choix: "; 
		cin >> choix;
        if (choix == 1) {
            fest.ajouterScene();
        }else if (choix == 2){
            int code;
			cout << "Code: ";
			cin >> code;
            fest.supprimerScene(code);
		}else if (choix == 3) {
            int code;
			cout << "Code: ";
			cin >> code;
            fest.modifierScene(code);
        } else if (choix == 4) {
            int code;
			cout << "Code de la scene: "; 
			cin >> code;
            if (!fest.existeScene(code)){ 
			cout << "Scene introuvable.\n";
			}
			Scene s;
            artiste a;
			a.saisie();
            s.ajouterArtiste(a);
        } else if (choix == 5) {
            int code;
			cout << "Code de la scene: ";
			cin >> code;
            if (!fest.existeScene(code)) {
			cout << "Scene introuvable.\n"; 
			}
            int id; 
            Scene s;
			cout << "ID artiste a supprimer: "; 
			cin >> id;
            s.supprimerArtiste(id);
        } else if (choix == 6) {
            int code;
            Scene s;
			cout << "Code de la scene: "; 
			cin >> code;
            if (!fest.existeScene(code)) { 
			cout << "Scene introuvable.\n"; 
			}
            s.afficherRecents();
        } else if (choix == 7) {
            fest.afficherAnciennetes();
        } else if (choix == 8) {
            int anneeActuelle;
            cout << "Entrez l annee actuelle : ";
            cin >> anneeActuelle;
            vector<Scene> vec = fest.scenesPlusDe5Ans(anneeActuelle);
            if (vec.empty()) 
			cout << "Aucune scene > 5 ans.\n";
            else {
                cout << "Scenes en service > 5 ans:\n";
                for ( auto &s : vec){
				s.afficher();
				}
            }
        } else if (choix == 9) {
            int idt; 
			cout << "ID technicien: ";
			cin >> idt;
            fest.afficherScenesParTechnicien(idt);
            
			}else if(choix==10){
				Scene s;
				s.getartistes();
			}
			else if (choix == 0) {
            cout << "Au revoir!\n";
        } else {
            cout << "Choix invalide.\n";
        }
    }

    return 0;
}