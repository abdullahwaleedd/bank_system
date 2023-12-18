#include <iostream>
using namespace std;
struct holder
{
    string ID;
    string name;
    string adress;
    double balance;
    holder *next;
};
struct branch
{
    string ID;
    string name;
    string manager;
    branch *next;
};
branch *head = NULL;
holder *head2 = NULL;
void InsertB(string id, string name, string manger) // Insert in the Beginning
{
    branch *temp = new branch;
    temp->ID = id;
    temp->name = name;
    temp->manager = manger;
    temp->next = head;
    head = temp;
}
void display()
{   
    if(head == NULL){
        cout<<"List is Empty\n";
    }
    branch *temp = head;
    while (temp != NULL)
    {
        cout << temp->ID << "\n " << temp->name << " \n"
             << temp->manager << "\n";
        temp = temp->next;
    }
}
bool search(string id)
{
    if (head == NULL)
        cout << "List is Empty\n";
    else
    {
        {
            branch *temp = head;
            while (temp != NULL)
            {
                if (temp->ID == id)
                {
                    cout << temp->ID << " " << temp->name << " " << temp->manager << "\n";
                    return true;
                }
                temp = temp->next;
            }
        }
        cout << "Handler ID not found\n";
        return false;
    }
}
void insertBh(string idd, string namee, string adresss, double balancee = 0.0)
{
    holder *temp = new holder;
    temp->ID = idd;
    temp->name = namee;
    temp->adress = adresss;
    temp->balance = balancee;
    temp->next = head2;
    head2 = temp;
}
void displayh()
{
    if (head2 == NULL)
        cout << "List is Empty\n";
    else
    {
        holder *temp = head2;
        while (temp != NULL)
        {
            cout << temp->ID << " " << temp->name << " " << temp->adress << " " << temp->balance << "\n";
            temp = temp->next;
        }
    }
}
bool searchhN(string namee)
{
    if (head2 == NULL)
        cout << "List is Empty\n";
    else
    {
        holder *temp = head2;
        while (temp != NULL)
        {
            if (temp->name == namee)
            {
                cout << temp->ID << " " << temp->name << " " << temp->adress << " " << temp->balance << "\n";
                return true;
            }
            temp = temp->next;
        }
        cout << "Handler Name not found\n";
        return false;
    }
}
bool searchhI(string idd)
{
    if (head2 == NULL)
        cout << "List is Empty\n";
    else
    {
        holder *temp = head2;
        while (temp != NULL)
        {
            if (temp->ID == idd)
                return true;
            temp = temp->next;
        }
        cout << "Handler ID not found\n";
        return false;
    }
}
void sort()
{

    struct holder *i, *j;
    double temp;
    for (i = head2; i->next != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->balance > j->balance)
            {
                temp = i->balance;
                i->balance = j->balance;
                j->balance = temp;
            }
        }
    }
}
void updateh(string idd, string namee, string adresss, double balancee)
{
    if (head2 == NULL)
        cout << "List is Empty\n";
    else if (searchhI(idd) == false)
        return;
    else
    {
        holder *temp = head2;
        while (temp != NULL)
        {
            if (temp->ID == idd)
            {
                temp->name = namee;
                temp->adress = adresss;
                temp->balance = balancee;
                return;
            }
            temp = temp->next;
        }
    }
    return;
}
void deleteitemh(string idd)
{
    if (head2 == NULL)
        cout << "List is Empty\n";
    else if (searchhI(idd) == false)
        return;
    else
    {
        holder *temp1 = head2;
        if (head2->ID == idd)
        {
            head2 = head2->next;
            delete temp1;
        }
        else
        {
        holder *temp2 = NULL;
            while (temp1->ID != idd && temp1 != NULL)
            {
                temp2 = temp1;
                temp1 = temp1->next;
            }
            temp2->next = temp1->next;
            delete (temp1);
            cout << "Item Deleted\n";
        }
    }
}
void ln()
{
    cout << "###############################################\n";
}
void rr()
{
    cout << "###############################################"
         << "\n";
    cout << "#                                             #"
         << "\n";
    cout << "#        Modern Academy CS Department         #"
         << "\n";
    cout << "#                                             #"
         << "\n";
    cout << "###############################################"
         << "\n";
    cout << "#  #####     ######     #########     ######  #"
         << "\n";
    cout << "# #     #   #      #   #         #   #      # #"
         << "\n";
    cout << "##  Joe  # # Hanafi # # AbduAllah # #  Ziad  ##"
         << "\n";
    cout << "# #     #   #      #   #         #   #      # #"
         << "\n";
    cout << "#  #####     ######     #########     ######  #"
         << "\n";
}
void abdo()
{
    ln();
    cout << "Enter '1' to Add new branch.\n";
    cout << "Enter '2' to Display Branch.\n";
    cout << "Enter '3' to Search for Branch by ID.\n";
    cout << "Enter '4' to Add new holder.\n";
    cout << "Enter '5' to Remove a holder.\n";
    cout << "Enter '6' to Display holder data.\n";
    cout << "Enter '7' to Search for holder by Name.\n";
    cout << "Enter '8' to Update Holder Information.\n";
    cout << "Enter '9' to to sort the holerd by balance.\n";
    cout << "Enter 'x' to Exit.\n";
    ln();
}
int main()
{
       rr();
    string id, manager, name, address;
    int balance = 0;
    while (true)
    {
        abdo();
        char x;
        cout << "Enter the number of the process : ";
        cin >> x;
        switch (x)
        {
        case '1':
            cout << "Enter Branch's ID : ";
            cin >> id;
            cout << "Enter Branch's Name : ";
            cin >> name;
            cout << "Enter Branch's Manager : ";
            cin >> manager;
            InsertB(id, name, manager);
            break;
        case '2':
            display();
            break;
        case '3':
            cout << "Enter Branch's ID : ";
            cin >> id;
            search(id);
            break;
        case '4':
            cout << "Enter Holder's ID : ";
            cin >> id;
            cout << "Enter Holder's Name : ";
            cin >> name;
            cout << "Enter Holder's Address : ";
            cin >> address;
            cout << "Enter Holder's Balance : ";
            cin >> balance;
            insertBh(id, name, address, balance);
            break;
        case '5':
            cout << "Enter Holder's ID : ";
            cin >> id;
            deleteitemh(id);
            break;
        case '6':
            displayh();
            break;
        case '7':
            cout << "Enter Holder's Name : ";
            cin >> name;
            searchhN(name);
            break;
        case '8':
            cout << "Enter Holder's ID : ";
            cin >> id;
            cout << "Enter Holder's Name : ";
            cin >> name;
            cout << "Enter Holder's Address : ";
            cin >> address;
            cout << "Enter Holder's Balance : ";
            cin >> balance;
            updateh(id, name, address, balance);
            break;
        case 'x':
            return 0;
            break;
        default:
            cout << "Error! Try Again : ";
            break;
        }
    }
    return 0;
}
// void displayHolders(branch *branch)
// {
//    holder *temp = branch->head;
//    while (temp != NULL)
//    {
//        cout << temp->ID << "\n " << temp->name << " \n"
//             << temp->adress << "\n"
//             << temp->balance << "\n";
//        temp = temp->next;
//    }
// }
