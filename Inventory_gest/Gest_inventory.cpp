#include <iostream>
#include <stdlib.h>
#include "item.h"
#include <string>

using namespace std;

int main(){
    std::string nom;
    int q = -1;
    int symbol = -1;
    int choice;
    InventoryList inventaire(nom, q, symbol);
    std::cout << "Bienvenue dans votre inventaire" << std::endl;
    while (1)
    {
        inventaire.afficher_item();
        std::cout << "Que voulez vous faire:" << std::endl;
        std::cout << "1-Ajouter un item" << std::endl;
        std::cout << "2-liberer toute la liste" << std::endl;
        std::cout << "3-Supprimer un item" << std::endl;
        std::cin >> choice;
        if (choice == 1)
        {
            std::cout << "Entrer le nom: " << std::endl;
            std::cin >> nom;
            std::cout << "Entrer le nombre d'element: " << std::endl;
            std::cin >> q;
            std::cout << "Entrer le symbol: " << std::endl;
            std::cin >> symbol;
            inventaire.add_item(nom, q, symbol);
        }else if (choice == 2)
        {
            inventaire.remove_all();
        }else if (choice == 3)
        {
            std::cout << "Entrer le nom de l'item à supprimer: " << std::endl;
            std::cin >> nom;
            inventaire.remove_element(nom);
        }
        else
        {
            break;
        }
        system("cls");
    }
    inventaire.clean_inventory();
    return 0;
}