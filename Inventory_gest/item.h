#ifndef _ITEM_INCLUDED
#define _ITEM_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class InventoryList
{
    public:
    std::string name;
    int quantity;
    int symbol;
    InventoryList* next = nullptr;

    InventoryList(const std::string& nom, int quantity, int symbol):name(nom), quantity(quantity), symbol(symbol){};

    void add_item(std::string nom, int quantite, int symbole){
        InventoryList* Newitem = new InventoryList(nom, quantite, symbole);
        InventoryList* head = this;
        if (this->quantity == -1)
        {
            head->name = Newitem->name;
            head->quantity = Newitem->quantity;
            head->symbol = Newitem->symbol;
        }else
        {
            while (head->next != nullptr)
            {
                head = head->next;   
            }
            head->next = Newitem;
        }
    }

    void remove_element(std:: string nom){
        InventoryList* current = this;  
        int position = 0;
        if (this->quantity == -1)
        {
            std::cout << "la liste est vide aucun element a supprimer" << std::endl;
            return;
        }
        while (current != nullptr)
        {
            if (current->name == nom)
            {
                current->name = current->next->name;
                current->quantity = current->next->quantity;
                current->symbol = current->next->symbol;
                current->next = current->next->next;
            }
            current = current->next;
            position++;
        }
    }

    void afficher_item(){
        InventoryList* current = this;
        if (this->quantity == -1)
        {
            std::cout << "aucun n'item dans votre inventaire" << std::endl;
            return;
        }
        while (current != nullptr)
        {
            std::cout<<"symbol: "<< (char)current->symbol;
            std::cout<<" name: "<< current->name;
            std::cout<<" quantity: "<< current->quantity << std::endl;
            current = current->next;   
            std::cout << "----------------" << std::endl;
        }
    }

    //vider l'entierete de la liste
    void remove_all(){
        InventoryList* next = this->next; 
        InventoryList* head = this; 
        if (this->quantity == -1)
        {
            std::cout << "aucun n'item dans votre inventaire" << std::endl;
            return;
        }
        head->quantity = -1;
        head->symbol = -1;
        head->name = "\0";
        while (next != nullptr)
        {
            InventoryList* temp = next;
            next = next->next;   
            delete temp;
        }
        head->next = nullptr;
    }

    //nettoyage de la memoire
    void clean_inventory(){
        InventoryList* current = this; 
        while (current != nullptr)
        {
            InventoryList* temp = current;
            current = current->next;   
            delete temp;
        }
    }
};

#endif