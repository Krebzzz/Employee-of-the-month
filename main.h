#ifndef MAINH
#define MAINH

#define SIZE 50
typedef struct{

    char name[SIZE];
    float mark1;
    float mark2;
    float mark3;
    float mark4;
    float somme;
    float moyenne;

}Employee;

//----------------------------------------------

void showMenu();
void Menu();
void create_employee(Employee *e,int i);
void moyenne_notes(float *mark1, float *mark2, float *mark3, float *mark4, Employee *e);
void boucle_principal();

#endif