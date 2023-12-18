#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Define global variables
#define MAX_MENU_ITEMS 50
#define MAX_CART_ITEMS 50


struct MenuItem {
    int id;
    char name[50];
    float price;
    int stock;
};


struct CartItem {
    int menuItemId;
    int quantity;
};



struct MenuItem menu[MAX_MENU_ITEMS];
struct CartItem cart[MAX_CART_ITEMS];
int menuSize = 0;
int cartSize = 0;


// Function prototypes
void displayMenu();
void initializeMenu();
void addItemToCart();
void removeItemFromCart();
void confirmPayment();
void generateMoneySlip();
void saveDataToFile();
void readDataFromFile();
void exitProgram();



// Main function
int main() {

    // Read data from file at the beginning of the program
    readDataFromFile();

    // Initialize the menu
    initializeMenu();

    int choice;

    do {
        // Display menu
        printf("\n\n\nRestaurant Management System\n");
        printf("1. Display full menu\n");
        printf("2. Add item to cart\n");
        printf("3. Remove item from cart\n");
        printf("4. Money slip\n");
        printf("5. Confirm payment from cart\n");
        printf("6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayMenu();
                break;
            case 2:
                addItemToCart();
                break;
            case 3:
                removeItemFromCart();
                break;
            case 4:
                generateMoneySlip();
                break;
            case 5:
                confirmPayment();
                break;
            case 6:
                saveDataToFile();
                exitProgram();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}




void initializeMenu() {
    menu[0].id = 1;
    strcpy(menu[0].name, "Chicken Burger");
    menu[0].price = 180.0;
    menu[0].stock = 60;

    menu[1].id = 2;
    strcpy(menu[1].name, "Chicken With Cheese");
    menu[1].price = 200.0;
    menu[1].stock = 45;

    menu[2].id = 3;
    strcpy(menu[2].name, "Chicken Smoky BBQ Cheese");
    menu[2].price = 225.0;
    menu[2].stock = 40;

    menu[3].id = 4;
    strcpy(menu[3].name, "Chicken with Bacok");
    menu[3].price = 230.0;
    menu[3].stock = 55;

    menu[4].id = 5;
    strcpy(menu[4].name, "Chicken with Sausage");
    menu[4].price = 250.0;
    menu[4].stock = 35;

    menu[5].id = 6;
    strcpy(menu[5].name, "Double Decker Beef");
    menu[5].price = 300.0;
    menu[5].stock = 37;

    menu[6].id = 7;
    strcpy(menu[6].name, "French Fries");
    menu[6].price = 100.0;
    menu[6].stock = 150;

    menu[7].id = 8;
    strcpy(menu[7].name, "Chicken Fingers");
    menu[7].price = 130.0;
    menu[7].stock = 120;

    menu[8].id = 9;
    strcpy(menu[8].name, "Naga Drums");
    menu[8].price = 90.0;
    menu[8].stock = 70;

    menu[9].id = 10;
    strcpy(menu[9].name, "Fish Tots");
    menu[9].price = 140.0;
    menu[9].stock = 40;

    menu[10].id = 11;
    strcpy(menu[10].name, "Fish'n Krisp");
    menu[10].price = 280.0;
    menu[10].stock = 35;

    menu[11].id = 12;
    strcpy(menu[11].name, "Cold Coffee");
    menu[11].price = 140.0;
    menu[11].stock = 150;

    menu[12].id = 13;
    strcpy(menu[12].name, "Oreo Shake");
    menu[12].price = 160.0;
    menu[12].stock = 80;

    menu[13].id = 14;
    strcpy(menu[13].name, "Soft Drinks");
    menu[13].price = 40.0;
    menu[13].stock = 200;

    menu[14].id = 15;
    strcpy(menu[14].name, "Mineral Water(500ml)");
    menu[14].price = 20.0;
    menu[14].stock = 250;



    menuSize = 15;
}






//Display menu function
void displayMenu() {


    printf("\n\nMenu List:\n\n");
    printf(" -------------------------------------------------------------\n");
    printf("| %-4s | %-30s | %-10s | %-6s |\n", " ID", "   Item Name", "Price", "Stock");
    printf(" -------------------------------------------------------------\n");

    for (int i = 0; i < menuSize; i++) {
        printf("| %-4d | %-30s | %-10.2f | %-6d |\n", menu[i].id, menu[i].name, menu[i].price, menu[i].stock);
    }

    printf(" -------------------------------------------------------------\n");
}






//Add item to the cart function
void addItemToCart() {
    if (menuSize == 0) {
        printf("Menu is empty. Please add items to the menu first.\n");
        return;
    }

    int itemId, quantity;
    printf("\nEnter the ID of the item you want to add to the cart: ");
    scanf("%d", &itemId);

    // Validate item ID
    if (itemId < 1 || itemId > menuSize) {
        printf("Invalid item ID. Please enter a valid ID.\n");
        return;
    }

    printf("Enter the quantity: ");
    scanf("%d", &quantity);

    // Validate quantity
    if (quantity <= 0) {
        printf("Invalid quantity. Please enter a positive quantity.\n");
        return;
    }

    // Check if there is enough stock
    if (quantity > 0 && quantity <= menu[itemId - 1].stock) {
        // Add item to cart
        cart[cartSize].menuItemId = itemId;
        cart[cartSize].quantity = quantity;
        cartSize++;

        printf("Item added to the cart successfully.\n");

        // Update stock in the menu
        menu[itemId - 1].stock -= quantity;
    } else {
        printf("Insufficient stock. Please choose a lower quantity.\n");
    }
}






//Remove item from cart
void removeItemFromCart() {
    if (cartSize == 0) {
        printf("Cart is empty. There are no items to remove.\n");
        return;
    }

    int itemId, quantity;
    printf("\nEnter the ID of the item you want to remove from the cart: ");
    scanf("%d", &itemId);

    // Validate item ID
    if (itemId < 1 || itemId > cartSize) {
        printf("Invalid item ID. Please enter a valid ID.\n");
        return;
    }

    printf("Enter the quantity to remove: ");
    scanf("%d", &quantity);

    // Validate quantity
    if (quantity <= 0) {
        printf("Invalid quantity. Please enter a positive quantity.\n");
        return;
    }

    // Check if the item is present in the cart
    if (quantity <= cart[itemId - 1].quantity) {
        // Remove item from cart
        cart[itemId - 1].quantity -= quantity;

        printf("Item removed from the cart successfully.\n");

        // If the quantity becomes zero, shift the remaining items
        if (cart[itemId - 1].quantity == 0) {
            for (int i = itemId - 1; i < cartSize - 1; i++) {
                cart[i] = cart[i + 1];
            }
            cartSize--;
        }

        // Update stock in the menu
        menu[cart[itemId - 1].menuItemId - 1].stock += quantity;
    } else {
        printf("Invalid quantity. Please enter a valid quantity to remove.\n");
    }
}






// Function to confirm the payment from the cart
void confirmPayment() {
    float totalAmount = 0.0;
    const float taxRate = 0.03;  // 3% tax
    const float serviceChargeRate = 0.02;  // 2% service charge

    printf("\n\nItems You purchased :\n");
    printf(" ---------------------------------------------------------------\n");
    printf("| %-4s | %-30s | %-10s | %-8s |\n", "ID", "Item Name", "Price", "Quantity");
    printf(" ---------------------------------------------------------------\n");

    for (int i = 0; i < cartSize; i++) {
        int itemId = cart[i].menuItemId;
        printf("| %-4d | %-30s | %-10.2f | %-8d |\n", menu[itemId - 1].id, menu[itemId - 1].name, menu[itemId - 1].price, cart[i].quantity);

        totalAmount += menu[itemId - 1].price * cart[i].quantity;
    }

    // Calculate tax and service charge
    float taxAmount = totalAmount * taxRate;
    float serviceChargeAmount = totalAmount * serviceChargeRate;

    // Add tax and service charge to the total amount
    totalAmount += taxAmount + serviceChargeAmount;

    printf(" ---------------------------------------------------------------\n");
    printf("            Tax (3%%)            : %.2f TK\n", taxAmount);
    printf("            Service Charge (2%%) : %.2f TK\n", serviceChargeAmount);
    printf("            Subtotal            : %.2f TK\n", totalAmount);

    // Clear the cart after payment confirmation
    cartSize = 0;

    printf("\nPayment confirmed......\nThank you for your purchase!\n");
}






// Function to generate a money slip
void generateMoneySlip() {
    float totalAmount = 0.0;
    const float taxRate = 0.03;  // 3% tax
    const float serviceChargeRate = 0.02;  // 2% service charge

    printf("\n\nMoney Slip:\n");
    printf(" ---------------------------------------------------------------\n");
    printf("| %-4s | %-30s | %-10s | %-8s |\n", "ID", "Item Name", "Price", "Quantity");
    printf(" ---------------------------------------------------------------\n");

    for (int i = 0; i < cartSize; i++) {
        int itemId = cart[i].menuItemId;
        printf("| %-4d | %-30s | %-10.2f | %-8d |\n", menu[itemId - 1].id, menu[itemId - 1].name, menu[itemId - 1].price, cart[i].quantity);

        totalAmount += menu[itemId - 1].price * cart[i].quantity;
    }

    // Calculate tax and service charge
    float taxAmount = totalAmount * taxRate;
    float serviceChargeAmount = totalAmount * serviceChargeRate;

    // Add tax and service charge to the total amount
    totalAmount += taxAmount + serviceChargeAmount;

    printf(" ---------------------------------------------------------------\n");
    printf("            Tax (3%%)            : %.2f TK\n", taxAmount);
    printf("            Service Charge (2%%) : %.2f TK\n", serviceChargeAmount);
    printf("            Subtotal            : %.2f TK\n", totalAmount);

    // You can customize the money slip format or add more details here

    printf(" ---------------------------------------------------------------\n");
    printf("Please Confirm the payment....!!!!\n");
}




//save data on the file
void saveDataToFile() {
    FILE *file = fopen("restaurant_data.txt", "w");

    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    // Save menu data
    fprintf(file, "MenuSize: %d\n", menuSize);
    for (int i = 0; i < menuSize; i++) {
        fprintf(file, "%d %s %.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }

    // Save cart data
    fprintf(file, "CartSize: %d\n", cartSize);
    for (int i = 0; i < cartSize; i++) {
        fprintf(file, "%d %d\n", cart[i].menuItemId, cart[i].quantity);
    }

    fclose(file);

    printf("Data saved to file successfully.\n");
}







//Read from file
void readDataFromFile() {
    FILE *file = fopen("restaurant_data.txt", "r");

    if (file == NULL) {
        printf("No existing data file found.\n");
        return;
    }

    // Read menu data
    fscanf(file, "MenuSize: %d", &menuSize);
    for (int i = 0; i < menuSize; i++) {
        fscanf(file, "%d %s %f", &menu[i].id, menu[i].name, &menu[i].price);
    }

    // Read cart data
    fscanf(file, "CartSize: %d", &cartSize);
    for (int i = 0; i < cartSize; i++) {
        fscanf(file, "%d %d", &cart[i].menuItemId, &cart[i].quantity);
    }

    fclose(file);

    printf("Data loaded from file successfully.\n");
}






//Exit
void exitProgram() {
    // Save data to file before exiting
    saveDataToFile();

    // Additional cleanup or closing operations can be added here

    printf("Exiting the program.......\n\nProject By ---\n   Rubaiyat Hasan Lifat  (ID-0242310005191012)\n   MD. Ashraful Miazi    (ID-0242310005191018)\n");
    exit(0);  // or return 0; depending on how you want to exit the program
}


