/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.sistemagestionbiblioteca;

import java.util.Scanner;

/**
 *
 * @author Proyecto Diseño
 */
public class Menu {
	private Library library;
	private Scanner scanner;
	
	public Menu(Library library){
		this.library = library;
		scanner = new Scanner(System.in);
	}
	
	public void init(){
		//TODO:crear cosas predeterminadas.
	}
	
	public void showMenu(){
		int option = 0;
		do {
			System.out.println("\n--- Library Management System ---");
			System.out.println("1. Register a new book");
			System.out.println("2. Remove a book");
			System.out.println("3. Register a new user");
			System.out.println("4. Lend a book to a user");
			System.out.println("5. Return a book");
			System.out.println("6. Show all available books");
			System.out.println("7. Show all users");
			System.out.println("8. Show all loans");
			System.out.println("9. Exit");
			System.out.print("Select an option: ");
			option = scanner.nextInt();

			switch(option) {
				case 1:
					// registerNewBook(); //Aqui revisar que el codigo que de no se repita.
					break;
				case 2:
					// removeBook();
					break;
				case 3:
					// registerNewUser(); //Aqui revisar que el id que de no se repita.
					break;
				case 4:
					// lendBookToUser();
					break;
				case 5:
					// returnBook();
					break;
				case 6:
					// showAllAvailableBooks();
					break;
				case 7:
					// showAllUsers();
					break;
				case 8:
					// showAllLoans();
					break;
				case 9:
					System.out.println("Exiting the system.");
					break;
				default:
					System.out.println("Invalid option.");
			}
    
} while(option != 9);
	}
	
	
	
	
	
}
