#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Ces lignes incluent les biblioteques standard necessaires pour le programme, telles que 'stdio.h'
//pour les entrees sortie, 'stdlib.h' pour les fonctions de gestion de la memoire, et 'string.h'
//pour les oparations sur les chaines de carcteres.
#define MAX_PASSENGERS 100
#define MAX_BUSES 50
#define MAX_SEATS 50
//ces lignes definissent des constantes pour le nombre maximum de passagers ,de bus et de sieges dans le syst�me.
typedef struct {
    char nom[50];
    char telephone[11];
    int numReservation;
} Passager;
//Cette structure definit les informations d'un passager, avec son nom, son numero de telephone et son numero de
//reservation
typedef struct{
    char nomOperateur[20];
    char numUtilisateur[14];
    char motDePasse[5];
    float montant;
}Operateur;
typedef struct {
    int numBus;
    int numSiege;
    Operateur operateur;
    Passager passager;
} Reservation;
//Cette structure definit les informations d'une reservation,  avec le numero du bus, le numero du siege,l'oparateur
// mobile money, le montant a payer et les informations du passager.
Reservation reservations[MAX_PASSENGERS];
int nbReservations = 0;
//ces lignes declarent un tableau de resrvations pour stocker toutes les reservations, ainsi qu'une variable
//pour garder la trace du nombre de reservations.
void afficherMenu() {
    printf("\t\t\t\t\t+---------------------------------------+\n");

    printf("\t\t\t\t\t|*** Systeme de reservation de bus ***  |\n");
    printf("\t\t\t\t\t+---------------------------------------+\n");

    printf("\t\t\t\t\t|1. Reserver un billet                  |\n");
    printf("\t\t\t\t\t|2. Rechercher une reservation          |\n");
    printf("\t\t\t\t\t|3. Afficher toutes les reservations    |\n");
    printf("\t\t\t\t\t|4. Quitter                             |\n");

    printf("\t\t\t\t\t+---------------------------------------+\n");
    printf("\t\t\t\t\t|                 Votre choix :         |\n");
    printf("\t\t\t\t\t+---------------------------------------+\n");

}
//Fonction pour afficher le menu principal
//Cette fonction affiche le menu principal du systeme de reservation.
void reserverBillet() {
    if (nbReservations >= MAX_PASSENGERS) {
        printf("Desole, le nombre maximum de reservations a ete atteint.\n");
        return;
    }

    Reservation r;
    printf("Entrez les informations du passager :\n");
    printf("Nom : ");
    scanf("%s", r.passager.nom);
    printf("Telephone : ");
    scanf("%s", r.passager.telephone);

    printf("Entrez les informations du bus :\n");
    printf("Numero du bus : ");
    scanf("%d", &r.numBus);

    // Vérifier si le siège est déjà réservé dans ce bus
    int siegeLibre = 1;
    for (int i = 0; i < nbReservations; i++) {
        if (reservations[i].numSiege == r.numSiege) {
            siegeLibre = 0;
            printf("Le siege %d dans le bus %d est deja reserve.\n", r.numSiege, r.numBus);
            break;
        }
    }

    if (!siegeLibre) {
        printf("Le siege %d dans le bus %d est deja reserve.\n", r.numSiege, r.numBus);
        return;
    }

    printf("Numero du siege : ");
    scanf("%d", &r.numSiege);

    printf("Operateur mobile money : ");
    scanf("%s", r.operateur.nomOperateur);

    printf("Mot de passe : ");
    scanf("%s", r.operateur.motDePasse);

    printf("Montant a payer : ");
    scanf("%f", &r.operateur.montant);
    reservations[nbReservations] = r;
    nbReservations++;
    printf("Reservation effectuee avec succes !\n");

}

void rechercherReservation() {
    char nom[50];
    printf("Entrez le nom du passager : ");
    scanf("%s", nom);

    int i, trouve = 0;
    for (i = 0; i < nbReservations; i++) {
        if (strcmp(reservations[i].passager.nom, nom) == 0) {
            printf("Reservation n%d :\n", reservations[i].passager.numReservation);
            printf("Nom : %s\n", reservations[i].passager.nom);
            printf("Telephone : %s\n", reservations[i].passager.telephone);
            printf("Numero du bus : %d\n", reservations[i].numBus);
            printf("Numero du siege : %d\n", reservations[i].numSiege);
            printf("Operateur mobile money : %s\n", reservations[i].operateur.nomOperateur);
            printf("Montant a payer : %.2f\n", reservations[i].operateur.montant);
            trouve = 1;
        }
    }

    if (!trouve) {
        printf("Aucune reservation trouvee pour le nom %s.\n", nom);
    }
}
//Fonction pour rechercher une reservation
//Cette fonction permet � l'utilsateur  de rechercher une reservation en entrant le nom du passager.
void afficherReservations() {
    if (nbReservations == 0) {
        printf("Aucune reservation pour le moment.\n");
        return;
    }
// Fonction pour afficher toutes les reservations
//cette fonction affiche toutes les reservation enregistrees dans le systeme.
    int i;
    for (i = 0; i < nbReservations; i++) {
        printf("Reservation n%d :\n", reservations[i].passager.numReservation);
        printf("Nom : %s\n", reservations[i].passager.nom);
        printf("Telephone : %s\n", reservations[i].passager.telephone);
        printf("Numero du bus : %d\n", reservations[i].numBus);
        printf("Numero du siege : %d\n", reservations[i].numSiege);
        printf("Operateur mobile money : %s\n", reservations[i].operateur.nomOperateur);
        printf("Montant a payer : %.2f\n", reservations[i].operateur.montant);
        printf("---------------------------\n");
    }
}

int main() {
    int choix;
    do {
        afficherMenu();
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                reserverBillet();
                break;
            case 2:
                rechercherReservation();
                break;
            case 3:
                afficherReservations();
                break;
            case 4:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
                break;
        }
    } while (choix != 4);
    return 0;
}
//Fonction principale du programme
//cette fonction principal du programme g�re le menu
//principal et appelle les differentes fonctions en fonction des choix des l'utilisateur.

