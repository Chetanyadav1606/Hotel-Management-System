#include <stdio.h>
#include<string.h>
#include<time.h>   // header file for current time
void displayCurrentTime() //function's declaration and definition
{
time_t currentTime;
struct tm *localTime;
currentTime = time(NULL);
localTime = localtime(&currentTime);
printf("\t    \033[1;36m%s\033[0m", asctime(localTime));
}
void BILL()
{
int total;
int *address = &total; // Get the address of the variable x
printf("\t      \033[5;36mBILL NO:\033[0m%p\n",(void *)address);
displayCurrentTime();
}
int main() 
{
 int no[6],CVV[3];
int choice;
double total = 0;
double discount = 0; 
double finalTotal=0;
double price;
int quantity;// Initialize discount to zero

// Define arrays to store product details
char productname[100][50]; // Array to store product names
double productPrices[100];
int productQuantities[100];
int productRemoved[100] = {0}; // 0 means product is not removed
int productCount = 0;

char username[20];
char password[20];

printf("\033[1;33mEnter your username: \033[0m");
gets(username);
printf("\033[1;33mEnter your password: \033[0m");
scanf("%s", password);
char correctUsername[] = "tcet";
char correctPassword[] = "ganesh.com";
if (strcmp(username, correctUsername) == 0 && strcmp(password, correctPassword) == 0)
{
      printf("\033[1;35mLogin successful!\n\033[0m");
      printf("\033[1;35mWelcome to the Shopping Bill Calculator!\n\033[0m");

while (1) 
{
printf("\n\033[1;33mMenu:\n\033[0m");
printf("\033[1;31m1.Add Product\n\033[0m");
printf("\033[1;31m2.Remove Product\n\033[0m");
printf("\033[1;31m3.Apply Discount\n\033[0m");
printf("\033[1;31m4.Calculate Total\033[0m\n"); 
printf("\033[1;31m5.Exit\033[0m\n"); 
printf("\033[1;31mEnter your choice: \033[0m");
scanf("%d", &choice);

switch (choice) 
{
case 1:


printf("\033[1;33mEnter the name of the product: \033[0m");
scanf(" %[^\n]%*c", productname[productCount]); // Store the product name in the array
printf("\033[1;33mEnter Price: \033[0m");
scanf("%lf", &price);
printf("\033[1;33mEnter Quantity: \033[0m");
scanf("%d", &quantity);

// Store product details in arrays
productPrices[productCount] = price;
productQuantities[productCount] = quantity;

total += price * quantity;
printf("\033[1;35mProduct added to the bill.\033[0m");
productCount++;
break;

case 2:
if (productCount > 0) 
{
printf("\033[1;33mEnter the product number to remove: \033[0m");
int index;
scanf("%d", &index);
index = index -1;
if (index >= 0 && index < productCount && !productRemoved[index]) 
{
// Calculate the total without this product
total -= productPrices[index] * productQuantities[index];

// Mark the product as removed
productRemoved[index] = 1;

printf("\033[1;35mProduct removed from the bill.\n\033[0m");
} 
else 
{
printf("\033[1;35mInvalid product number,Please enter a valid product index.\033[0m\n");
}
}
else 
{
      printf(" \033[1;35mNO product to remove.\033[0m\n");
}
break;

case 3:
printf("\033[1;33mEnter Discount percentage =\033[0m");
double discountPercentage;
scanf("%lf", &discountPercentage);
discount = (total * discountPercentage) / 100;
printf("\033[1;35mDiscount applied , you save = %.2lf\n\033[0m", discount);
break;

case 4:
 finalTotal = total - discount;
printf("\n\033[1;34m =========================================\n\033[0m");
printf("\t\t   \033[5;36mE - MART\033[0m");
printf("\n \033[1;34m=========================================\n\033[0m");
printf("              \033[5;36mAvenue Super Market\033[0m           \n");
printf("              \033[5;36mYour Shopping Bill\033[0m              ");
printf("\n \033[1;34m_\n\033[0m");
printf("                 \033[5;36mTAX INVOICE\033[0m                \n");
BILL();
printf(" \033[1;34m_\n\033[0m");
printf("\n \033[5;32mIndex\tProduct\t\tPrice\tQuantity\033[0m\n");

for (int i = 0; i < productCount; i++) 
{
if (!productRemoved[i]) 
{
printf(" %d\t%s\t\t%.2lf\t%d\n", i+1, productname[i], productPrices[i], productQuantities[i]);
}
}
printf(" \033[1;34m-----------------------------------------\n\033[0m");
printf(" \033[1;32mSubtotal:\033[0m\t%.2lf\n", total);
printf(" \033[1;32mDiscount:\033[0m\t%.2lf\n", discount);
printf(" \033[1;32mTotal:\033[0m\t\t%.2lf\n", finalTotal);
while (1) 
{
printf("\033[1;31m\nPAYMENT METHOD:\n\033[0m");
printf("\033[1;31m1.CARD\n");
printf("\033[1;31m2.QR ONLINE\n\033[0m");
printf("\033[1;31m3.CASH\n\033[0m");
printf("\033[1;31mEnter your choice: \033[0m");
scanf("%d", &choice);

switch (choice) 
{
case 1:
       printf("enter the card number=");
       scanf("%d", no);
       printf("enter the CCV of the card =");
       scanf("%d", CVV);
       printf("\033[1;35mPAYMENT done successfully , Thank you for shopping with us!!!\n\033[0m");
       return 0;
       break;
case 2:
       printf("\033[1;35:::::::::::\n::::::::::\n::::::::::\n::::::::::\n::::::::::\033[0m");// pattern
       return 0;
       break;
case 3:
       printf("\033[1;35mPAYMENT done successfully , Thank you for shopping with us!!!\n\033[0m");
       return 0;
       break;
default:
       printf("\033[1;35mInvalid choice. Please select a valid option.\033[0m");
}
}       
case 5:
       printf("\033[1;35mThank you for shopping with us!\n\033[0m");// result of the bill
       return 0;

default:
       printf("\033[1;35mInvalid choice. Please select a valid option.\033[0m");
}
}
}
else
       printf("\033[1;35mLogin failed!! , please input correct id and password\033[0m");
       return 0;
}
