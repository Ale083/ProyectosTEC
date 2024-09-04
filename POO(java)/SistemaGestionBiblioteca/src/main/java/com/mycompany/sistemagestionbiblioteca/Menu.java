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
			option = scanner.nextInt();//TODO: caso que ponga algo que no es int.

			switch(option) {
				case 1:
					registerNewBook(); //Aqui revisar que el codigo que de no se repita.
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
	
	private void registerNewBook(){
		String bookName = "";
		String authorName = "";
		int bookCode = 0;
		boolean codeRepeated = true;
		while (codeRepeated){
			System.out.print("Enter the book code: ");
			bookCode = scanner.nextInt();
			scanner.nextLine();
			codeRepeated = false; //asumir que es falso antes de buscar.
			for (int i = 0; i< library.getBookCount();i++){
				if (bookCode == library.getBooks()[i].getCode()){
					System.out.println("Code matches with an already existing book, try again.");
					waiting();
					codeRepeated = true;
					break;
				}
			}
		}
		while (bookName.trim().equals("")){
			System.out.print("Enter the book name (If you input spaces/nothing, this will be prompted again): ");
			bookName = scanner.nextLine();
		}
		
		while (authorName.trim().equals("")){
			System.out.print("Enter the author name (If you input spaces/nothing, this will be prompted again): ");
			authorName = scanner.nextLine();
		}
		library.addBook(new Book(bookCode, bookName, authorName));
	}
	
	public void waiting(){
		System.out.print("Press enter to continue...");
		scanner.nextLine();
		System.out.println("---------------");
	}
	
	
	
}
