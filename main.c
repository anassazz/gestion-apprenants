#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Définition de la structure Adresse
typedef struct {
    char rue[100];
    char ville[50];
    char code_postal[10];
} Adresse;

// Définition de la structure Apprenant
typedef struct {
    char nom[50];
    char prenom[50];
    int age;
    float note;
    Adresse adresse;
} Apprenant;

// Prototypes des fonctions
void creer_apprenant(Apprenant *apprenant);
void afficher_apprenant(const Apprenant *apprenant);
void mettre_a_jour_apprenant(Apprenant *apprenant);
void supprimer_apprenant(Apprenant *apprenants, int *taille, int index);

int main() {
    int choix, index, taille = 0;
    Apprenant apprenants[100]; // Tableau pour stocker jusqu'à 100 apprenants

    do {
        printf("\nMenu des options :\n");
        printf("1. Ajouter un apprenant\n");
        printf("2. Afficher tous les apprenants\n");
        printf("3. Mettre à jour un apprenant\n");
        printf("4. Supprimer un apprenant\n");
        printf("5. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                if (taille < 100) {
                    creer_apprenant(&apprenants[taille]);
                    taille++;
                } else {
                    printf("Capacité maximale atteinte !\n");
                }
                break;

            case 2:
                if (taille == 0) {
                    printf("Aucun apprenant à afficher.\n");
                } else {
                    for (int i = 0; i < taille; i++) {
                        printf("\nApprenant #%d :\n", i + 1);
                        afficher_apprenant(&apprenants[i]);
                    }
                }
                break;

            case 3:
                printf("Entrez l'index de l'apprenant à mettre à jour (1 à %d) : ", taille);
                scanf("%d", &index);
                if (index > 0 && index <= taille) {
                    mettre_a_jour_apprenant(&apprenants[index - 1]);
                } else {
                    printf("Index invalide.\n");
                }
                break;

            case 4:
                printf("Entrez l'index de l'apprenant à supprimer (1 à %d) : ", taille);
                scanf("%d", &index);
                if (index > 0 && index <= taille) {
                    supprimer_apprenant(apprenants, &taille, index - 1);
                    printf("Apprenant supprimé avec succès.\n");
                } else {
                    printf("Index invalide.\n");
                }
                break;

            case 5:
                printf("Au revoir !\n");
                break;

            default:
                printf("Choix invalide, réessayez.\n");
        }
    } while (choix != 5);

    return 0;
}

// Fonction pour créer un apprenant
void creer_apprenant(Apprenant *apprenant) {
    printf("Entrez le nom : ");
    scanf("%s", apprenant->nom);
    printf("Entrez le prénom : ");
    scanf("%s", apprenant->prenom);
    printf("Entrez l'âge : ");
    scanf("%d", &apprenant->age);
    printf("Entrez la note : ");
    scanf("%f", &apprenant->note);
    printf("Entrez la rue : ");
    scanf(" %[^\n]", apprenant->adresse.rue); // %[^\n] permet de lire une ligne complète
    printf("Entrez la ville : ");
    scanf("%s", apprenant->adresse.ville);
    printf("Entrez le code postal : ");
    scanf("%s", apprenant->adresse.code_postal);
}

// Fonction pour afficher un apprenant
void afficher_apprenant(const Apprenant *apprenant) {
    printf("Nom : %s\n", apprenant->nom);
    printf("Prénom : %s\n", apprenant->prenom);
    printf("Âge : %d\n", apprenant->age);
    printf("Note : %.2f\n", apprenant->note);
    printf("Adresse : %s, %s, %s\n", apprenant->adresse.rue, apprenant->adresse.ville, apprenant->adresse.code_postal);
}

// Fonction pour mettre à jour un apprenant
void mettre_a_jour_apprenant(Apprenant *apprenant) {
    printf("Mise à jour des informations pour %s %s :\n", apprenant->prenom, apprenant->nom);
    creer_apprenant(apprenant); // Réutilise la fonction de création
}

// Fonction pour supprimer un apprenant
void supprimer_apprenant(Apprenant *apprenants, int *taille, int index) {
    for (int i = index; i < *taille - 1; i++) {
        apprenants[i] = apprenants[i + 1];
    }
    (*taille)--;
}
