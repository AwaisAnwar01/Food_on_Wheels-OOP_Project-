#include <iostream>
#include <string>
using namespace std;
// Base class resturant is created
class Resturant
{
private:
 string Resturant_userName, ResturantName;
 string Resturant_userPassword, ResturantPassword;

public:
 string pick[15];
 string status;
 string menu[15];
 int price[15] = {0};
// create account and login function is created
 void login_info_resturant()
 {
 int loginAttempt = 0;
 while (loginAttempt < 3)
 {
 cout << "Please enter your resturant name: ";
 cin >> Resturant_userName;
 cout << "Please enter your resturant password: ";
 cin >> Resturant_userPassword;
 cout << endl;
 cout << "Enter login name: ";
 cin >> ResturantName;
 cout << "Enter login password: ";
 cin >> ResturantPassword;
 cout << endl;
 if (Resturant_userName == ResturantName && Resturant_userPassword == ResturantPassword)
 {
 cout << "************Welcome TO " << ResturantName << "******************" << endl;
 break;
 }
 else
 {
 cout << "Invalid login attempt. Please try again.\n"
 << '\n';
 loginAttempt++;
 }
 }
 cout << "*************-----------------------------------------****************" << endl;
 }
 // function menu is created in order to take menu as input from resturant
 void menuu()
 {
 cout << "--------------------------ENTER MENU----------------------------" << endl;
 for (int i = 0; i < 15; i++)
 {
 cout << "Enter the item name : " << endl;
 cin >> menu[i];
 cout << "Enter the price of the item : " << endl;
 cin >> price[i];
 }
 }
 // following function is created to display menu
 void display_menu()
 {
 cout << "--------------------DISPLAYING MENU-------------------" << endl;
 for (int i = 0; i < 15; i++)
 {
 cout << " Item name : " << menu[i] << "|"
 << " Price: " << price[i] << "Rs" << endl;
 }
 cout << "*************-----------------------------------****************" << endl;
 }
 // following function is created to update menu
 void update_menu()
 {
 string updation;
 cout << "If you want to update your menu press yes otherwise press no" << endl;
 cin >> updation;
 if (updation == "yes")
 {
 cout << "------------------------Updating Menu-----------------" << endl;
 string updateFood, updatedFood;
 int updatePrice, updatedPrice;
 cout << "Enter the food you want to update " << endl;
 cin >> updateFood;
 cout << "respective price :" << endl;
 cin >> updatePrice;
 cout << "Enter the new food item " << endl;
 cin >> updatedFood;
 cout << "respective price: " << endl;
 cin >> updatedPrice;
 for (int i = 0; i < 2; i++)
 {
 if (updateFood == menu[i] && updatePrice == price[i])
 {
 menu[i] = updatedFood;
 price[i] = updatedPrice;
 }
 }
 }
 else if (updation == "no")
 {
 cout << "There is no need to update menu" << endl;
 }
 }
 // following function is created to display updated menu
 void updated_menu()
 {
 for (int i = 0; i < 15; i++)
 {
 cout << " Item name : " << menu[i] << "|"
 << " Price: " << price[i] << endl;
 }
 cout << "*************-----------------------------------------****************" << endl;
 }
// following function is created to delete unwanted items in menu
 void del_food()
 {
 string Deletion;
 cout << "If you want to delete an item press yes othewise no" << endl;
 cin >> Deletion;
 if (Deletion == "yes")
 {
 cout << "---------------DELETING MENU------------------" << endl;
 string element;
 int price1, total = 15, i, j, found = 0;

 cout << "\nEnter item to Delete: ";
 cin >> element;
 cout << "\nEnter respective price : ";
 cin >> price1;
 for (i = 0; i < total; i++)
 {
 if (menu[i] == element && price[i] == price1)
 {
 for (j = i; j < (total - 1); j++)
 menu[j] = menu[j + 1];
 price[j] = price[j + 1];
 found++;
 i--;
 total--;
 }
 }
 if (found == 0)
 cout << "\nElement doesn't found in the Array!";
 else
 {
 cout << "Element Deleted Successfully!" << endl;
 cout << "Here are the remaining items" << endl;
 for (i = 0; i < total; i++)
 {
 cout << menu[i] << " " << price[i] << endl;
 }
 cout << endl;
 }
 }

 else if (Deletion == "NO")
 {
 cout << "No need of deleting any item" << endl;
 }
 }
// following function is created to show delivery status
 void Food_Delivery_Status()
 {
 cout << "***************Delivery Status*************" << endl;
 cout << "What is the status of food delivery" << endl;
 cin >> status;
 if (status == "ready")
 {
 cout << "Rider is on his way" << endl;
 }
 else if (status == "notready")
 {
 cout << "Food is not cooked yet" << endl;
 }
 }
};
// class customer is created that is derived from parent class resturant
class Customer : virtual public Resturant
{
public:
 string Customer_userName, Customer_loginName;
 string Customer_userPassword, Customer_loginPassword;

 int pricee[15];
// create account and login function is created for customers
 void login_info_customer()
 {
 cout << "*******************Customer's Information***************" << endl;

 int loginAttempt = 0;
 while (loginAttempt < 3)
 {
 cout << "Please enter your user name: ";
 cin >> Customer_userName;
 cout << "Please enter your user password: ";
 cin >> Customer_userPassword;
 cout << endl;

 cout << "Enter login name: ";
 cin >> Customer_loginName;
 cout << "Enter login password: ";
 cin >> Customer_loginPassword;
 cout << endl;

 if (Customer_userName == Customer_loginName && Customer_userPassword == Customer_loginPassword)
 {
 cout << "Welcome" << Customer_loginName << endl;
 break;
 }

 else
 {
 cout << "Invalid login attempt. Please try again.\n"
 << '\n';
 loginAttempt++;
 }
 }
 if (loginAttempt == 3)
 {
 cout << "Too many login attempts! The program will now terminate.";
 }

 cout << "Thank you for logging in.\n";
 }
 // following function is created to display menu for customers
 void display_food_details()
 {
 cout << "*************VIEW FOOD DETAILS*****************" << endl;

 for (int i = 0; i < 15; i++)
 {
 cout << menu[i] << " | " << price[i] << endl;
 }
 }
// following function is created to take user's chosed item that he want to order
 void Place_Order()
 {

 cout << "*****************Place your order here****************" << endl;
 cout << "Enter your order and respective price or press * and 1 to stop" << endl;

 for (int j = 0; j < 15; j++)
 {
 cout << "Item name :" << endl;
 cin >> pick[j];
 cout << " Price: " << endl;
 cin >> pricee[j];
 if (pick[j] == "*" && pricee[j] == 1)
 {
 continue;
 break;
 }
 }
 cout << " ___ Yours Order status___" << endl;
 cout << "*******************************" << endl;
 for (int i = 0; i < 15; i++)
 {

 if (pick[i] == menu[i] && pick[i] != "*" && price[i] == pricee[i])
 {
 cout << "Item : " << pick[i] << " Price :" << pricee[i] << endl;
 }
 else if (pick[i] != menu[i] && pick[i] != "*")
 {
 cout << "Item: " << pick[i] << " Not found in the menu " << endl;
 }
 else if (price[i] != pricee[i] && pick[i] != "*" && pricee[i] != 1)
 {
 cout << " Price doesn't match : " << endl;
 }
 }
 }
 // following function is created to displar cart
 void Cart()
 {
 cout << "**************showing your cart*******************8:" << endl;
 for (int i = 0; i < 15; i++)
 {
 if (pick[i] != "*")
 {

 cout << "Item :" << pick[i] << endl;
 }
 }
 }
// following function is created to update cart
 void update_cart()
 {

 cout << "********************UPDATING CART****************" << endl;
 string updatecart, updatedcart;
 int updatePrice, updatedPrice;
 string updation_of_Cart;
 cout << "If you want to update your Cart press yes otherwise press no" << endl;
 cin >> updation_of_Cart;
 if (updation_of_Cart == "yes")
 {

 cout << "Enter the item you want to update " << endl;
 cin >> updatecart;
 cout << "respective price :" << endl;
 cin >> updatePrice;
 cout << "Enter the new food item " << endl;
 cin >> updatedcart;
 cout << "respective price: " << endl;
 cin >> updatedPrice;
 for (int i = 0; i < 15; i++)
 {
 if (updatecart == pick[i] && updatePrice == pricee[i])
 {
 pick[i] = updatedcart;
 pricee[i] = updatedPrice;
 }
 }
 }
 else if (updation_of_Cart == "no")
 {
 cout << "There is no need to update cart" << endl;
 }
 else
 ;
 {
 cout << " You have no such item in cart! " << endl;
 }
 }
 // following function is created to display updated cart
 void updated_cart()
 {
 cout << "********************UPDATED CART****************" << endl;
 for (int i = 0; i < 15; i++)
 {
 cout << " Item name : " << pick[i] << endl;
 }
 cout << "*************-----------------------------------------****************" << endl;
 }
 // following function is created to cancel order if customer is willing
 void Cancel_Order()
 {
 cout << "******************CANCELLETION OF ORDER****************" << endl;
 string Confirmation;
 cout << "If you want to save order press save order otherwise press cancel order" << endl;
 cin >> Confirmation;
 if (Confirmation == "save_order")
 {
 cout << "Your order has been saved" << endl;
 }
 else if (Confirmation == "cancel")
 {
 cout << "Your order has been cancelled" << endl;
 }
 }
 //// following function is created for checkingout
 void Checkout()
 {
 cout << "********************CHECKING OUT*****************" << endl;
 string choose;
 cout << "IF you want to checkout press checkout otherwise press viewcart" << endl;
 cin >> choose;
 if (choose == "checkout")
 {
 cout << "Your food is ready to cook,moving towards payment method " << endl;
 }
 else if (choose == "viewcart")
 {
 Cart();
 }
 }
// following function is created to user about paying method
 void Mode_Of_Payment()
 {
 cout << "*****************Payment Method******************" << endl;
 string Payment_Mode;
 int Card_Number;
 int Digits;
 cout << "If you want to pay through cash press cash on delivery otherwise press online payment" << endl;
 cin >> Payment_Mode;
 if (Payment_Mode == "Cash_on_Delivery")
 {
 cout << "Rider will recieve cash on delivery" << endl;
 }
 else if (Payment_Mode == "online_payment")
 {
 cout << "Enter your card Information" << endl;
 cout << "Enter your card Number" << endl;
 cin >> Card_Number;
 cout << "Enter 3 digits written on back of your card" << endl;
 cin >> Digits;
 cout << "Payment has been paid,Thank you!" << endl;
 }
 }
 // following function is created to calculate and display bill
 void bill()
 {
 cout << "*********************DISPLAYING BILL********************" << endl;
 int add = 0;
 int sum = 0;
 for (int i = 0; i < 15; i++)
 {
 add = sum + pricee[i];
 sum += pricee[i];
 }
 cout << "********************************" << endl;
 cout << " Dear customer your Bill is : " << add - 1 << "Rs" << endl;
 }
 // following function is created to update about delivery status
 void Delivery_Status()
 {
 if (status == "ready")
 {
 cout << "*******************************" << endl;
 cout << " status of delivery : " << endl;
 cout << " Rider is on his way" << endl;
 }
 else if (status == "notready")
 {
 cout << "*******************************" << endl;
 cout << " Status of delivery : " << endl;
 cout << " kindly Wait! Food is not cooked yet" << endl;
 }
 }
};
// class rider is derived from class customer
class Rider : virtual public Customer
{
public:
 string Rider_userName, RiderName;
 string Rider_userPassword, RiderPassword;
// create account and login function is created for customers
 void login_info_Rider()
 {
 cout << "*****************Rider's Information******************" << endl;
 int loginAttempt = 0;
 while (loginAttempt < 3)
 {
 cout << "Please enter your name: ";
 cin >> Rider_userName;
 cout << "Please enter your password: ";
 cin >> Rider_userPassword;
 cout << endl;
 cout << "Enter login name: ";
 cin >> RiderName;
 cout << "Enter login password: ";
 cin >> RiderPassword;
 cout << endl;
 if (Rider_userName == RiderName && Rider_userPassword == RiderPassword)
 {
 cout << "Welcome " << RiderName << endl;
 break;
 }
 else
 {
 cout << "Invalid login attempt. Please try again.\n"
 << '\n';
 loginAttempt++;
 }
 }
 }
 // following function is created to show customer's order to riders
 void View_Order()
 {
 cout << "********************Showing Order Details************************" << endl;
 updated_cart();
 }
 // following function is created to ask rider whether he is willing to deliver food or not
 void Delivery_Order()
 {
 cout << "*************Acceptance and Rejection of orders**************" << endl;
 string Acceptance, Address;
 cout << " If you want to accept order press yes otherwise press no" << endl;
 cin >> Acceptance;
 if (Acceptance == "yes")
 {
 cout << "Your order is accepted" << endl;
 cout << "ENter customer's address" << endl;
 cin >> Address;
 cout << "Rider is on his way to deliver food" << endl;
 }
 else if (Acceptance == "no")
 {
 cout << "Your order is not accepted" << endl;
 }
 }
 // following function is created to update about delivery status
 void Update_Delivery_Status()
 {
 cout << "**************Updating Delivery Status****************" << endl;
 string Delivery_Status;
 cout << "Updating about Delivery Status" << endl;
 cin >> Delivery_Status;
 if (Delivery_Status == "taken")
 {
 cout << "Rider is leaving from resturant to deliver your food" << endl;
 }
 else if (Delivery_Status == "not_taken")
 {
 cout << "The food is not ready yet" << endl;
 }
 }
// following function is created to update about cash recieved and returned by rider
 void Cash_Delivery_Update()
 {
 cout << "****************Cash_Delivery_Update*******************" << endl;
 bill();
 int Total_Bill, Cash_Taken, Cash_Returned;
 cout << "enter the customer total bill : " << endl;
 cin >> Total_Bill;
 cout << "enter the cash which is given by customer" << endl;
 cin >> Cash_Taken;
 Cash_Returned = Cash_Taken - Total_Bill;
 cout << "Pay back ammount : " << Cash_Returned << "Rs" << endl;
 cout << "Thankyou for availing our service" << endl;
 }
};
// class admin is derived from class rider
class Admin : public Rider
{
private:
 string Admin_userName, AdminName;
 string Admin_userPassword, AdminPassword;

public:
// create account and login function is created for admin
 void login_info_Admin()
 {
 cout << "**********************ADMIN'S DETAILS******************" << endl;
 int loginAttempt = 0;
 while (loginAttempt < 3)
 {
 cout << "Please enter your name: ";
 cin >> Admin_userName;
 cout << "Please enter your password: ";
 cin >> Admin_userPassword;
 cout << endl;
 cout << "Enter login name: ";
 cin >> AdminName;
 cout << "Enter login password: ";
 cin >> AdminPassword;
 cout << endl;
 if (Admin_userName == AdminName && Admin_userPassword == AdminPassword)
 {
 cout << "Welcome " << AdminName << endl;
 break;
 }
 else
 {
 cout << "Invalid login attempt. Please try again.\n"
 << '\n';
 loginAttempt++;
 }
 }
 }
 // following function is created to manage vendors
 void Manage_Vendors()
 {
 cout << "**********************MANAGING VENDORS********************" << endl;
 string Manage;
 string Authentication;
 cout << "If you want to manage vendors press yes otherwise press no" << endl;
 cin >> Manage;
 cout << "Checking if vendor's information is correct or not" << endl;
 cin >> Authentication;
 if (Authentication == "correct")
 {
 cout << "This vendor is eligible for vending on Food On Wheels" << endl;
 }
 else if (Authentication == "notcorrect")
 {
 cout << "This vendor is not eligible for vending on Food On Wheels" << endl;
 }
 }
// following function is created to manage food
 void Manage_Food()
 {
 cout << "********************MANAGING FOOD*******************" << endl;
 string Managefood;
 cout << "If you want to manage food press yes otherwise press no" << endl;
 cin >> Managefood;
 if (Managefood == "yes")
 {
 update_menu();
 del_food();
 }
 else if (Managefood == "no")
 {
 cout << "The food is managed already" << endl;
 }
 }
// following function is created to manage customers
 void Manage_Customers()
 {
 cout << "*******************Managing Customers*****************" << endl;

 string Customer_userName, Customer_loginName;
 string Customer_userPassword, Customer_loginPassword;

 cout << "Please enter your user name: ";
 cin >> Customer_userName;
 cout << "Please enter your user password: ";
 cin >> Customer_userPassword;
 cout << endl;

 cout << "Enter login name: ";
 cin >> Customer_loginName;
 cout << "Enter login password: ";
 cin >> Customer_loginPassword;
 cout << endl;

 if (Customer_userName == Customer_loginName && Customer_userPassword == Customer_loginPassword)
 {
 cout << "Authentication is done , You are allowed to proceed ahead" << endl;
 cout << "Welcome " << Customer_loginName << endl;
 }

 else
 {
 cout << "Invalid account! please provide correct information" << endl;
 }
 }
 // following function is created to manage food order details
 void Manage_food_order_details()
 {
 cout << "**********Managing_food_order_details****************" << endl;
 string Manage_details;
 cout << "If you want to manage food order details press yes otherwise press no" << endl;
 cin >> Manage_details;
 if (Manage_details == "yes")
 {
 update_cart();
 Cancel_Order();
 }
 else if (Manage_details == "no")
 {
 cout << "The food order is managed already" << endl;
 }
 }
 // following function is created to manage payment details
 void Manage_Payment_details()
 {
 cout << "****************Managing payment details*****************" << endl;
 string Manage_Payment;
 cout << "If you want to manage payment details press yes or no" << endl;
 cin >> Manage_Payment;
 if (Manage_Payment == "yes")
 {
 bill();
 Cash_Delivery_Update();
 }
 else if (Manage_Payment == "no")
 {
 cout << "The methods for payment of order is managed already" << endl;
 }
 }
// following function is created to manage riders
 void Manage_Riders()
 {
 cout << "********************Managing Riders*******************" << endl;
 if (Rider_userName == RiderName && Rider_userPassword == RiderPassword)
 {
 cout << "Authentication is done , You are allowed to proceed ahead" << endl;
 }
 else if (Rider_userName != RiderName && Rider_userPassword != RiderPassword)
 {
 cout << "Invalid account! please provide correct information" << endl;
 }
 }
};
//main class
int main()

{
 // Object of class admin is created in order to call all the functions created in base and derived classes
 Admin A;
 A.login_info_resturant();
 A.menuu();
 A.display_menu();
 A.update_menu();
 A.updated_menu();
 A.del_food();
 A.Food_Delivery_Status();
 A.login_info_customer();
 A.display_food_details();
 A.Place_Order();
 A.Cart();
 A.update_cart();
 A.updated_cart();
 A.bill();
 A.Cancel_Order();
 A.Checkout();
 A.Mode_Of_Payment();
 A.Delivery_Status();
 A.login_info_Rider();
 A.View_Order();
 A.Delivery_Order();
 A.Update_Delivery_Status();
 A.Cash_Delivery_Update();
 A.login_info_Admin();
 A.Manage_Vendors();
 A.Manage_Food();
 A.Manage_Customers();
 A.Manage_food_order_details();
 A.Manage_Payment_details();
 A.Manage_Riders();
 return 0;
 // program terminates
}

/*
class resturant is created by Soban Ahmed
class rider is created by Noman Ahmed
class admin is created by Mohammad Faizan Mehmood
class customer creation ,the commenting and the inheritance between the classes is done by Awais Anwar
*/
