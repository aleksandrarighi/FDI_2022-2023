#include <stdio.h>

struct person {
    char name[256];
    unsigned int age;
};

void person_read(FILE* f, struct person* pp) {
    if (fscanf(f, "%255s %u", pp->name, &pp->age) != 2) {
        fprintf(stderr, "Errore nella lettura del file\n");
    }
}

/*int main() {
    FILE* file1 = fopen("person1.txt", "r");
    if (file1 == NULL) {
        perror("Errore nell'apertura del file person1.txt");
        return 1;
    }

    struct person person1;
    person_read(file1, &person1);

    printf("Persona 1:\nNome: %s\nEtà: %u\n", person1.name, person1.age);

    fclose(file1);

    FILE* file2 = fopen("person2.txt", "r");
    if (file2 == NULL) {
        perror("Errore nell'apertura del file person2.txt");
        return 1;
    }

    struct person person2;
    person_read(file2, &person2);

    printf("\nPersona 2:\nNome: %s\nEtà: %u\n", person2.name, person2.age);

    fclose(file2);

    return 0;
}*/
