#include "festival.h"
artiste::artiste(){
	id=0;
	nomsc="";
	genremusical="";
	paysorigine="";
	cachet=0.0;
	joursinsc=0;
	moisinsc=0;
	anneeinsc=0;
}
void artiste::saisie(){
	cout << "ID artiste : ";
    cin >> id;
    cout << "Nom de scene : ";
    cin >> nomsc;
    cout << "Genre musical : ";
    cin >> genremusical;
    cout << "Pays d'origine : ";
    cin >> paysorigine;
    cout << "Cachet : ";
    cin >>  cachet;
    cout << "Date inscription (j m a) : ";
    cin >> joursinsc >> moisinsc >> anneeinsc;
}
void artiste::affiche(){
    cout << "Artiste #" << id << " - " << nomsc << " (" << genremusical << "), "
         << paysorigine << ", Cachet: " << cachet << " DH, Inscription : "
         << joursinsc << "/" << moisinsc << "/" << anneeinsc << endl;
}
int artiste ::getid(){
		return id;
}
void artiste::setId(int v){
    id = v; 
}
string artiste:: getnomSc(){
	return nomsc;
}
void artiste:: setnomSc(string &s){
	nomsc=s;
}
int artiste:: getjourInsc(){
	return joursinsc;
}
 int artiste:: getmoisInsc(){
 	return moisinsc;
}
 int artiste:: getanneeInsc(){
 	return anneeinsc;
}
//technicien
technicien::technicien() {
    id = 0;
    nom="";
    prenom="";
    specialite="";
    salaire=0;
    joursem=0;
	moisem=0;
	anneeem=0;
}
void technicien::saisie() {
    cout << "ID technicien : ";
    cin >> id;
    cout << "Nom : ";
    cin >> nom;
    cout << "Prenom : ";
    cin >> prenom;
    cout << "Specialite : ";
    cin >> specialite;
    cout << "Salaire : ";
    cin >> salaire;
    cout << "Date embauche (j m a) : ";
    cin >> joursem >> moisem >> anneeem;
}void technicien::affiche(){
    cout << "Technicien #" << id << " - " << nom << " " << prenom
         << ", " << specialite << ", Salaire : " << salaire << " DH, Date embauche : "
         << joursem << "/" << moisem << "/" << anneeem << endl;
}
int technicien::getid(){
	return id;
}
void technicien::setid(int v){
	id = v;
}
string technicien::getnom(){
	return nom+" "+prenom;
}
//scene
Scene::Scene() {
    code = 0;
    nom="";
    maxArtistes = 0;
    jourServ = 0;
	moisServ =0;
	anneeServ = 0;
}
void Scene::saisir() {
    cout << "Code scene : ";
    cin >> code;
    cout << "Nom scene : ";
    cin >> nom;
    cout << "\n--- Technicien responsable ---\n";
    responsable.saisie();
    cout << "Nombre maximal d'artistes : ";
    cin >> maxArtistes;
    cout << "Date de mise en service (j m a) : ";
    cin >> jourServ >> moisServ >> anneeServ;
}
void Scene::afficher(){
	cout << "\n---- Scène [" << code << "] " << nom << " ----\n";
    cout << "Mise en service: " << jourServ << "/" << moisServ << "/" << anneeServ << "\n";
    cout << "Capacité: " << maxArtistes << "\n";
    cout << "Responsable: "; responsable.affiche();
    for ( auto &a : artistes){
	a.affiche();
	}
}
bool Scene::artisteExiste(int id) {
	 for ( artiste &a : artistes) 
	 if (a.getid() == id)
	 return true;
    return false;
}
bool Scene::ajouterArtiste( artiste &a){
    if ((int)artistes.size() >= maxArtistes) {
        cout << "Erreur: capacité maximale atteinte.\n";
        return false;
    }
    if (artisteExiste(a.getid())) {
        cout << "Erreur: l'artiste existe déjà dans la scène.\n";
        return false;
    }
    artistes.push_back(a);
    cout << "Artiste ajouté avec succès.\n";
    return true;
}
void Scene::changerNom( string &n){
    nom = n;
}
void Scene::afficherRecents() {
    int anneeActuelle = 2025; 

    cout << "Artistes inscrits depuis moins d'un an :\n";
    bool found = false;

    for ( auto &a : artistes) {
        if (a.getanneeInsc() == anneeActuelle) {
            a.affiche();
            found = true;
        }
    }

    if (!found) {
        cout << "(Aucun artiste recent)\n";
    }
}
int Scene::anciennete(int anneeActuelle) {
    return anneeActuelle - anneeServ;
}
bool Scene::supprimerArtiste(int id){
    for (int i = 0; i < artistes.size(); i++) {
        if (artistes[i].getid() == id) {
            artistes.erase(artistes.begin() + i);
            cout << "Artiste supprimé.\n";
            return true;
        }
    }
    cout << "Artiste introuvable.\n";
    return false;
}
vector<artiste> Scene::getartistes(){
	return artistes;
}
int Scene::getcode(){
	return code;
}
void Scene::setcode(int c){
	code=c;
}
string Scene::getNom() {
    return nom;
}
void Scene::setNom( string &n){
	nom=n;
}

technicien Scene::getResponsable() {
    return responsable; 
}
void Scene::setResponsable( technicien &t) { 
     responsable = t; 
}
int Scene::getAnneeServ(){
    return anneeServ; 
}
//festival
Festival::Festival() {}

bool Festival::existeScene(int code) {
    for ( auto &s : scenes)
	if (s.getcode() == code)
	return true;
    return false;
}

void Festival::ajouterScene() {
    Scene s;
    s.saisir();
    if (existeScene(s.getcode())) {
        cout << "Erreur: une scène avec ce code existe déjà.\n";
        return;
    }
    scenes.push_back(s);
    cout << "Scène ajoutée.\n";
}

bool Festival::supprimerScene(int code) {
    for (int i = 0; i < scenes.size(); i++) {
        if (scenes[i].getcode() == code) {
            scenes.erase(scenes.begin() + i);
            cout << "Scène supprimée.\n";
            return true;
        }
    }
    cout << "Scène introuvable.\n";
    return false;
}

bool Festival::modifierScene(int code) {
    for (auto &s : scenes) {
        if (s.getcode() == code) {

            int choix;
            cout << "Modifier la scène (1 = nom, 2 = responsable) : ";
            cin >> choix;
            

            if (choix == 1) {
                string nouveauNom;
                cout << "Nouveau nom : ";
                cin>>nouveauNom;
                s.setNom(nouveauNom);
                cout << "Nom modifié.\n";
            }
            else if (choix == 2) {
                technicien t;
                cout << "Saisir le nouveau technicien responsable :\n";
                t.saisie();
                s.setResponsable(t);
                cout << "Responsable modifié.\n";
            }
            else {
                cout << "Choix invalide.\n";
            }

            return true; 
        }
    }

    cout << "Scène introuvable.\n";
    return false;
}
void Festival::afficherAnciennetes()  {
	if (scenes.empty()){
        cout << "Aucune scène enregistrée.\n";
        return;
    }
    int anneeActuelle = 2025;
    for ( auto &s : scenes) {
        cout << "Scène code = " << s.getcode()
             << " | Nom = " << s.getNom()
             << " | Ancienneté : " << s.anciennete(anneeActuelle)
             << " ans\n";
             s.afficher();
    }
}
vector<Scene> Festival::scenesPlusDe5Ans(int anneeActuelle){
    vector<Scene> result;
    for ( auto &s : scenes) {
        if (s.anciennete(anneeActuelle) > 5) 
		result.push_back(s);
    }
    return result;
}

void Festival::afficherScenesParTechnicien(int idTechnicien) {
    bool found = false;
    for ( auto &s : scenes) {
        technicien t = s.getResponsable();
        if (t.getid() == idTechnicien) {
            s.afficher();
            found = true;
        }
    }
    if (!found) 
	cout << "Aucune scène pour ce technicien.\n";
}