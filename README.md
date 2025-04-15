# Bank Management System (C Project)

## Project Description
The Bank Managment System is a simple C program that allows users to Login into their account using the PIN (PIN = 1929). 
It provides functionalities to Deposite Money, Withdraw Money, Check Balance, and Exit from system.
The program runs on the command line (CMD) and stores data using files.

##  Features
-  Deposite  
-  Withdraw   
-  Check balance 
-  Store user Account Information such as Password and Saved Amount information in a file for persistence  

## Technologies Used
- Programming Language: C  
- IDE: Code::Blocks (or any C compiler like GCC)  
- Data Storage: File handling (text file)  

## Installation & Compilation
1️. Clone the Repository

    git clone https://github.com/zena-learngithub/My_C_projects.git
    cd My_C_projects/bank_management_system

2️. Compile the Program
   Using GCC:
   gcc main.c -o bank_management

3️. Run the Program

./bank_management

## File Structure

bank_management_system/
│── src/
│   ├── main.c
│   ├── bank_management_system.c
│── README.md
│── saved_money.txt  (Stores Balance records)
│── bank_user_data.txt (Stores user password records)

##  How to Use
1. Run the program.
2. Choose an option from the menu:
   - '1' to Deposite amount
   - '2' to Withdraw amount
   - '3' to Check balance
   - '4' to Exit
3. Follow the prompts to enter amount of money.
4. The data is saved in 'saved_money.txt' for future use.

##  Contribution
Contributions are welcome! If you want to improve this project, fork the repository and create a pull request.

Created by: Zenawi Zemene (https://github.com/zena-learngithub)  
GitHub Repository: [Bank Management System](https://github.com/zena-learngithub/My_C_projects/bank_management_system)  

