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
		library.addBook(new Book(1, "Cien Años de Soledad", "Gabriel García Márquez"));
		library.addBook(new Book(2, "Don Quijote", "Miguel de Cervantes"));
		library.addBook(new Book(3, "El Principito", "Antoine de Saint-Exupéry"));
		library.addBook(new Book(4, "La Odisea", "Homero"));
		library.addBook(new Book(5, "Moby Dick", "Herman Melville"));
		library.addBook(new Book(6, "Crimen y Castigo", "Fiódor Dostoyevski"));
		library.addBook(new Book(7, "Orgullo y Prejuicio", "Jane Austen"));
		library.addBook(new Book(8, "Fahrenheit 451", "Ray Bradbury"));
		library.addBook(new Book(9, "1984", "George Orwell"));
		library.addBook(new Book(10, "El Señor de los Anillos", "J.R.R. Tolkien"));
		library.addBook(new Book(11, "El Hobbit", "J.R.R. Tolkien"));
		library.addBook(new Book(12, "La Divina Comedia", "Dante Alighieri"));
		library.addBook(new Book(13, "Hamlet", "William Shakespeare"));
		library.addBook(new Book(14, "El Conde de Montecristo", "Alejandro Dumas"));
		library.addBook(new Book(15, "Drácula", "Bram Stoker"));
		library.addBook(new Book(16, "Guerra y Paz", "León Tolstói"));
		library.addBook(new Book(17, "Los Miserables", "Victor Hugo"));
		library.addBook(new Book(18, "El Nombre de la Rosa", "Umberto Eco"));
		library.addBook(new Book(19, "Rayuela", "Julio Cortázar"));
		library.addBook(new Book(20, "El Padrino", "Mario Puzo"));
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
					registerNewBook();
					break;
				case 2:
					removeBook();
					break;
				case 3:
					registerNewUser(); 
					break;
				case 4:
					lendBookToUser();
					break;
				case 5:
					returnBook();
					break;
				case 6:
					showAllAvailableBooks();
					break;
				case 7:
					showAllUsers();
					break;
				case 8:
					showAllLoans();
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
			Book book = library.findBookByCode(bookCode);
			if (book != null){
				System.out.println("Code matches with an already existing book, try again.");
				waiting();
				codeRepeated = true;
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
	
	private void removeBook(){
		System.out.print("Enter the book ID: ");
		int bookCode = scanner.nextInt();
		scanner.nextLine();
		library.removeBook(bookCode);
	}
	
	private void registerNewUser(){
		String userName = "";
		int userId = 0;
		boolean idRepeated = true;
		while (idRepeated){
			System.out.print("Enter the user ID: ");
			userId = scanner.nextInt();
			scanner.nextLine();
			idRepeated = false; //asumir que es falso antes de buscar.
			for (int i = 0; i< library.getUsers().size();i++){
				if (userId == library.getUsers().get(i).getId()){
					System.out.println("ID matches with an already existing user, try again.");
					waiting();
					idRepeated = true;
					break;
				}
			}
		}
		while (userName.trim().equals("")){
			System.out.print("Enter the user name (If you input spaces/nothing, this will be prompted again): ");
			userName = scanner.nextLine();
		}
		library.registerUser(new User(userId,userName));
	}
	
	private void lendBookToUser(){
		System.out.print("Enter the book code: ");
		int bookCode = scanner.nextInt();
		scanner.nextLine();
		Book bookFound = library.findBookByCode(bookCode);
		if (bookFound == null){
			return;
		}
		System.out.print("Enter the user id: ");
		int userId = scanner.nextInt();
		scanner.nextLine();
		User userFound = library.findUserByCode(userId);
		if (userFound == null){
			return;
		}
		library.createLoan(userFound, bookFound);
	}
	
	private void returnBook(){
		System.out.print("Enter the book code: ");
		int bookCode = scanner.nextInt();
		scanner.nextLine();
		Book bookFound = library.findBookByCode(bookCode);
		if (bookFound == null){
			return;
		}
		System.out.print("Enter the user id: ");
		int userId = scanner.nextInt();
		scanner.nextLine();
		User userFound = library.findUserByCode(userId);
		if (userFound == null){
			return;
		}
		
		Loan loanFound = library.findLoanByBookAndUser(bookFound, userFound);
		if (bookFound == null){
			return;
		}
		library.returnLoan(loanFound);
	}
	
	private void showAllAvailableBooks(){
		library.showAvailableBooks();
	}
	
	private void showAllUsers(){
		library.showUsers();
	}
	
	private void showAllLoans(){
		library.showLoans();
	}
	
	public void waiting(){
		System.out.print("Press enter to continue...");
		scanner.nextLine();
		System.out.println("---------------");
	}
	
	
	
}
