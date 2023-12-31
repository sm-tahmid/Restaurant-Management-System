# Restaurant-Management-System
The Restaurant Management System, created by S.M. Tahmid Abir, is a C-based command-line application that simplifies menu management. It enables users to add/remove items, generate money slips, and confirm payments. With file persistence, it ensures seamless data continuity between sessions, offering an efficient solution for restaurant operations.

# Restaurant Management System

## Introduction

The Restaurant Management System is a simple command-line application written in C that allows users to manage a restaurant's menu and perform basic operations like adding items to the cart, removing items from the cart, generating a money slip, and confirming payment.


## Features

1. **Display Full Menu:** View the entire menu with item details such as ID, name, price, and stock availability.

2. **Add Item to Cart:** Select items from the menu and add them to the cart, specifying the desired quantity. The system checks for stock availability.

3. **Remove Item from Cart:** Remove items from the cart, adjusting the quantity. The system updates the menu stock accordingly.

4. **Generate Money Slip:** View a detailed money slip that includes the items in the cart, their prices, quantities, and the total amount.

5. **Confirm Payment from Cart:** Confirm the payment, clear the cart, and provide a thank-you message.

6. **Save and Load Data:** Save the menu and cart data to a file and load it at the start of the program. This ensures persistence between program executions.

7. **Clean Exit:** Save data before exiting the program. Displays a project credit message.


## How to Use

1. **Display Full Menu:**
   - Choose option 1 from the main menu.

2. **Add Item to Cart:**
   - Choose option 2.
   - Enter the ID of the item you want to add.
   - Enter the quantity.

3. **Remove Item from Cart:**
   - Choose option 3.
   - Enter the ID of the item you want to remove.
   - Enter the quantity to remove.

4. **Generate Money Slip:**
   - Choose option 4 to view the money slip.

5. **Confirm Payment from Cart:**
   - Choose option 5 to confirm payment, view the receipt, and clear the cart.

6. **Exit:**
   - Choose option 6 to exit. Data will be saved automatically.


**Project Structure:**

* **rms.c:** The main source code file of the program.
* **rms.o:** Object file generated by the compiler during the compilation process.
* **rms.exe:** The executable file generated after compiling the C source code file.
* **restaurant_data.txt:** Data file where information is stored.


## Note

- Ensure that the menu is initialized before performing any operations.
- Use valid IDs and quantities during item addition and removal.


## Author

This project is authored by S.M. Tahmid Abir.

---



