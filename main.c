#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_DESTINATION_LENGTH 100

struct Trip {
  char name[MAX_NAME_LENGTH];
  char destination[MAX_DESTINATION_LENGTH];
  int start_date;
  int end_date;
  int price;
  struct Trip *next;
};

struct Trip *first_trip = NULL;

// Ajoute un voyage à la liste chaînée
void add_trip(struct Trip trip) {
  struct Trip *new_trip;
  new_trip = (struct Trip*)malloc(sizeof(struct Trip));
  *new_trip = trip;
  new_trip->next = first_trip;
  first_trip = new_trip;
}

// Affiche la description d'un voyage
void display_trip(char *name) {
  struct Trip *current_trip;
  current_trip = first_trip;
  while (current_trip != NULL) {
    if (strcmp(current_trip->name, name) == 0) {
      printf("Nom : %s\n", current_trip->name);
      printf("Destination : %s\n", current_trip->destination);
      printf("Dates : %d - %d\n", current_trip->start_date, current_trip->end_date);
      printf("Prix : %d\n", current_trip->price);
      break;
    }
    current_trip = current_trip->next;
  }
}

// Supprime un voyage de la liste chaînée
void delete_trip(char *name) {
  struct Trip *current_trip;
  struct Trip *prev_trip;
  current_trip = first_trip;
  prev_trip = NULL;
  while (current_trip != NULL) {
    if (strcmp(current_trip->name, name) == 0) {
      if (prev_trip == NULL) {
        first_trip = current_trip->next;
      } else {
        prev_trip->next = current_trip->next;
      }
      free(current_trip);
      break;
    }
    prev_trip = current_trip;
    current_trip = current_trip->next;
  }
}

// Modifie un voyage de la liste chaînée
void modify_trip(char *name) {
  struct Trip *current_trip;
  current_trip = first_trip;
  while (current_trip != NULL) {
    if (strcmp(current_trip->name, name) == 0) {
      printf("Entrez les nouvelles informations sur le voyage :\n");
      printf("Nom : ");
      scanf("%s", current_trip->name);
      printf("Destination : ");
      scanf("%s", current_trip->destination);

  printf("Date de début (jjmmaaaa) : ");
  scanf("%d", &current_trip->start_date);
  printf("Date de fin (jjmmaaaa) : ");
  scanf("%d", &current_trip->end_date);
  printf("Prix : ");
  scanf("%d", &current_trip->price);
  break;
}
current_trip = current_trip->next;
}
}

// Recherche les voyages disponibles entre deux dates
void search_trips(int start_date, int end_date) {
  struct Trip *current_trip;
  current_trip = first_trip;
  while (current_trip != NULL) {
    if (current_trip->start_date >= start_date && current_trip->end_date <= end_date) {
      printf("Nom : %s\n", current_trip->name);
      printf("Destination : %s\n", current_trip->destination);
      printf("Dates : %d - %d\n", current_trip->start_date, current_trip->end_date);
      printf("Prix : %d\n", current_trip->price);
    }
    current_trip = current_trip->next;
  }
}

// Affiche la liste de tous les voyages de la liste chaînée
void display_all_trips() {
  struct Trip *current_trip;
  current_trip = first_trip;
  while (current_trip != NULL) {
    printf("Nom : %s\n", current_trip->name);
    printf("Destination : %s\n", current_trip->destination);
    printf("Dates : %d - %d\n", current_trip->start_date, current_trip->end_date);
    printf("Prix : %d\n", current_trip->price);
    current_trip = current_trip->next;
  }
}

int main() {
  int choice;
  do {
    printf("Menu :\n");
    printf("1. Ajouter un voyage\n");
    printf("2. Afficher la description d'un voyage\n");
    printf("3. Supprimer un voyage\n");
    printf("4. Modifier un voyage\n");
    printf("5. Rechercher des voyages disponibles entre deux dates\n");
    printf("6. Afficher la liste de tous les voyages\n");
    printf("7. Quitter\n");
    printf("Entrez votre choix : ");
    scanf("%d", &choice);
    switch (choice) {
      case 1: {
        struct Trip trip;
        printf("Entrez les informations sur le voyage à ajouter :\n");
        printf("Nom : ");
        scanf("%s", trip.name);
        printf("Destination : ");
        scanf("%s", trip.destination);
        printf("Date de début (jjmmaaaa) : ");
        scanf("%d", &trip.start_date);
        printf("Date de fin (jjmmaaaa) : ");
        scanf("%d", &trip.end_date);
        printf("Prix : ");
        scanf("%d", &trip.price);
        add_trip(trip);
        break;
      }
      case 2: {
        char name[MAX_NAME_LENGTH];
                printf("Entrez le nom du voyage à afficher : ");
        scanf("%s", name);
        display_trip(name);
        break;
      }
      case 3: {
        char name[MAX_NAME_LENGTH];
        printf("Entrez le nom du voyage à supprimer : ");
        scanf("%s", name);
        delete_trip(name);
        break;
      }
      case 4: {
        char name[MAX_NAME_LENGTH];
        printf("Entrez le nom du voyage à modifier : ");
        scanf("%s", name);
        modify_trip(name);
        break;
      }
      case 5: {
        int start_date, end_date;
        printf("Entrez la date de début (jjmmaaaa) : ");
        scanf("%d", &start_date);
        printf("Entrez la date de fin (jjmmaaaa) : ");
        scanf("%d", &end_date);
        search_trips(start_date, end_date);
        break;
      }
      case 6: {
        display_all_trips();
        break;
      }
      case 7: {
        printf("Au revoir !\n");
        break;
      }
      default: {
        printf("Choix incorrect.\n");
        break;
      }
    }
  } while (choice != 7);
  return 0;
}


