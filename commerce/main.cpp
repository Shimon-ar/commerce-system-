#include <iostream>
#include <string>
#include "system.h"
#include "User.h"
#include "DynamicArray.h"
#include "Address.h"
#include "Seller.h"
#include "Items.h"
#include "Item.h"
#include "FeedBack.h"
#include "Buyer.h"
#include "Order.h"
#include "BuyerSeller.h"


using namespace std;

void printMenu();

char *readString();

void sellerOptions(Seller &seller, Items &allItems);

void BuyerOptions(Buyer &buyer, Items &allItems);


int main() {

    System mySystem("mySystem");//initial system with name
    mySystem.uploadUsers();
    bool to_cont = true;
    int option;
    User *user;

    while (to_cont) {
        printMenu();//printing the menu
        cin >> option;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');//clean buffer

        switch (option) {

            case 1: {
                string userName, password;
                cout << "Enter user name: ";
                getline(cin, userName);
                cout << "Enter password: ";
                getline(cin, password);
                user = mySystem.LogIn(userName, password);//get the pointer to user

                if (user == nullptr) {
                    cout << "Incorrect user or password\n";
                    break;
                }//no match

                Buyer *buyer = dynamic_cast<Buyer *>(user);//cast to each type to know what kind of user
                Seller *seller = dynamic_cast<Seller *>(user);
                BuyerSeller *buyer_seller = dynamic_cast<BuyerSeller *>(user);

                if (seller) //seller case
                    sellerOptions(*seller, mySystem.GetAllItems());//seller  options
                else if (buyer)//buyer case
                    BuyerOptions(*buyer, mySystem.GetAllItems());//buyer options
                else if (buyer_seller) {
                    cout << "0 - Buyer options 1 - Seller options\n";//which menu he had like to see
                    int choice;
                    cin >> choice;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (choice)
                        sellerOptions(*buyer_seller, mySystem.GetAllItems());
                    else BuyerOptions(*buyer_seller, mySystem.GetAllItems());
                }
                break;
            }
            case 2: {
                string user_name, password, state, city, street;
                cout << "Enter user name: ";
                getline(cin, user_name);
                if (!User::validUserName(user_name)) {//check the input
                    cout << "Error : space not allowed in user name\n";
                    break;
                }
                if (mySystem.searchUserByName(user_name) != nullptr) {//casting the user to his user name
                    cout << "there is account with this username choose another \n";
                    break;
                }

                cout << "Enter password: ";
                getline(cin, password);
                cout << "Enter state: ";
                getline(cin, state);
                cout << "Enter city: ";
                getline(cin, city);
                cout << "Enter street: ";
                getline(cin, street);
                cout << "Enter number: ";
                int number;
                cin >> number;
                int user_type;//which user
                cout << "0 - Seller  1 - Buyer  2 - Buyer and seller\n";
                cin >> user_type;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                switch (user_type) {
                    case 0:
                        mySystem += Seller(user_name, password, Address(state, city, street, number));//add seller
                        cout << "Account was added\n\n";
                        break;
                    case 1:
                        mySystem += Buyer(user_name, password, Address(state, city, street, number));//add buyer
                        cout << "Account was added\n\n";
                        break;
                    case 2:
                        mySystem += BuyerSeller(user_name, password,
                                                Address(state, city, street, number));//add buyerseller
                        cout << "Account was added\n\n";
                        break;
                    default:
                        cout << "Invalid input\n";
                        break;
                }
                break;
            }
            case 3:
                cout << "Buyers:\n";
                mySystem("Buyer");//print buyers by the operator ()
                break;

            case 4:
                cout << "Sellers:\n";
                mySystem("Seller");
                break;
            case 5:
                cout << "Buyers/sellers\n";
                mySystem("BuyerSeller");
                break;
            case 6: {
                cout << "Enter name of item: ";
                string name;
                getline(cin, name);
                if (mySystem.GetAllItems().ShowItemsByName(name) == false)//show the items that were search
                    cout << "there is no item called: " << name << endl;
                break;
            }
            case 7: {
                string name1, name2;
                cout << "Enter name of first Buyer: \n";
                getline(cin, name1);
                cout << "Enter name of second Buyer: \n";
                getline(cin, name2);
                const Buyer *buyer1 = dynamic_cast<const Buyer *>(mySystem.searchUserByName(name1));//cast to buyer*
                const Buyer *buyer2 = dynamic_cast<const Buyer *>(mySystem.searchUserByName(name2));
                if (buyer1 && buyer2)//if the cast has been succsed
                    cout << "The bigger one is: " << (*buyer1 > *buyer2).GetUserName()
                         << '\n';//compare by operator and print
                else cout << "Invalid input\n";

                break;
            }

            case 0: {
                to_cont = false;//stop loop
                mySystem.saveUsers();


            }

                break;

            default:
                break;
        }
    }

}

void printMenu() {
    cout << "------------------------\n";//the menu
    cout << "Welcome to First System! \n"
         << "Select an option: \n"
         << "1 - Log in\n"
         << "2 - Add new account \n"
         << "3 - Show all buyers \n"
         << "4 - Show all sellers \n"
         << "5 - Show sellers and buyers\n"
         << "6 - Show items by name\n"
         << "7 - Compare between buyers\n"
         << "0 - Exit\n";
    cout << "------------------------\n";
}

char *readString() {
    string myString;
    getline(cin, myString);//get all the input
    int size = myString.size();//get the size
    char *string = new char[size + 1];//allocate memory
    myString.copy(string, size, 0);//copy the string to char*
    string[size] = '\0';//put end char
    return string;
}


void BuyerOptions(Buyer &buyer, Items &allItems) {
    cout << "Welcome: " << buyer.GetUserName() << endl;//all buyer options
    int option = 1;
    while (option) {
        cout << "------------------------\n";
        cout
                << "Select option:\n1 - Show your items\n2 - Add item to your items\n3 - Make an order\n4 - Make an payment\n5 - Add feedback\n";

        BuyerSeller *buyerSeller = dynamic_cast<BuyerSeller *>(&buyer);
        if (buyerSeller)
            cout << "6 - Seller options\n";
        cout << "0 - Log out\n";
        cout << "------------------------\n";
        cin >> option;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (option) {
            case 1:
                buyer.GetItems().showItems();
                break;

            case 2: {
                cout << "This is all items:\n";
                allItems.showItems();//print all items
                cout << "Enter ID item: ";
                int id;
                cin >> id;
                Item *item = allItems.FindItem(id);//get the item by id
                if (item == nullptr) {//case there is no match
                    cout << "Incorrect ID item\n";
                    break;
                }
                buyer += item;//adding the item
                cout << "The item added successfully\n";
                break;
            }
            case 3: {
                int count = 0;
                bool flag = true;
                if (buyer.GetMyOrder().GetItems().GetItems().empty())//checking if there no items at all
                {
                    cout << "You have an empty order\n";
                } else cout << "\nYou already have items in your order\n";
                cout << "\nThis is all your chosen items:\n";//show the items
                if (buyer.GetItems().GetItems().empty()) {
                    cout << "you need to chose items first\n";
                    break;
                }
                buyer.GetItems().showItems();
                int toContinue = 1, itemId;
                Item *item;
                while (toContinue) {//make the order
                    bool flag = true;
                    cout << "\nEnter item ID: ";
                    cin >> itemId;
                    item = buyer.GetItems().FindItem(itemId);//getting the item b y id
                    if (item == nullptr) {//case no match
                        cout << "ID item doesnt match to any of your items\n";
                        flag = false;
                        break;

                    }
                    if (flag) {
                        buyer.GetMyOrder() += item;//adding it
                        count++;
                    }
                    cout << "\n0- To finish \n1- To continue\n";
                    cin >> toContinue;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');//just clean buffer
                }
                if (count > 0)
                    buyer.GetMyOrder().showOrder();//print the order
                break;
            }
            case 4:
                if (buyer.MakingPayment()) {//make the payment
                    cout << "The payment was made!\n";
                    buyer.showPayments();//print payments
                } else cout << "Error with payment";
                break;
            case 5: {
                string nameSeller, feedbackText;
                cout << "\nEnter the seller name: ";
                getline(cin, nameSeller);
                cout << "Type your feedback: ";
                getline(cin, feedbackText);
                if (buyer.AddingFeedback(nameSeller, feedbackText))//add the feedback
                    cout << "The feedback was added\n";
                else
                    cout << "This seller name doesnt match to your sellers\n";

            }
                break;
            case 6:
                sellerOptions(*buyerSeller, allItems);//move the buyer seller to sellers options
                break;

            case 0:
                option = 0;
                break;

           default:
                break;
        }


    }
}

void sellerOptions(Seller &seller, Items &allItems) {//seller options
    cout << "------------------------\n";
    cout << "Welcome: " << seller.GetUserName() << endl;
    int option = 1;
    while (option) {
        cout << "Select option:\n1 - Show your items\n2 - Add new item\n3 - Show all your feedbacks\n";
        BuyerSeller *buyerSeller = dynamic_cast<BuyerSeller *>(&seller);//if the seller is also buyerseller
        if (buyerSeller)
            cout << "4 - Buyer options\n";
        cout << "0 - Log out\n";
        cout << "------------------------\n";
        cin >> option;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (option) {
            case 1: {

                seller.GetMyItems().showItems();//show the items
                break;
            }
            case 2: {
                int price, category;
                string name;
                cout << "Adding item:\n" << "Enter name of item: ";
                getline(cin, name);//get the name of item
                cout << "Enter price: ";
                cin >> price;
                if (!Item::validPrice(price)) {//check the price
                    cout << "Incorrect price\n\n";
                    break;
                }
                cout << "Category: 0- Office , 1- Clothes , 2- Kids , 3- Electricity : ";
                cin >> category;
                if (!Item::validCategory((Item::Category) category)) {//check category
                    cout << "Incorrect category\n\n";
                    break;
                }

                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                seller.AddNewItem(allItems, name, price, category);//add item
                cout << "\n";
                cout << "Item added successfully\n" << endl;
                break;
            }
            case 3:
                seller.showFeedBacks();//show feedbacks
                break;

            case 4:
                BuyerOptions(*buyerSeller, allItems);//move the buyerseller to seller options
                break;

            default:
                option = 0;
                break;


        }
    }
}
