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
		
		library.registerUser(new User(1, "Carlos García"));
		library.registerUser(new User(2, "María Rodríguez"));
		library.registerUser(new User(3, "José Martínez"));
		library.registerUser(new User(4, "Ana Sánchez"));
		library.registerUser(new User(5, "Juan López"));
		library.registerUser(new User(6, "Lucía Fernández"));
		library.registerUser(new User(7, "Pedro Gómez"));
		library.registerUser(new User(8, "Laura Díaz"));
		library.registerUser(new User(9, "Santiago Pérez"));
		library.registerUser(new User(10, "Elena Morales"));
		library.registerUser(new User(11, "Miguel Torres"));
		library.registerUser(new User(12, "Carmen Ruiz"));
		library.registerUser(new User(13, "Luis Jiménez"));
		library.registerUser(new User(14, "Isabel Mendoza"));
		library.registerUser(new User(15, "Francisco Ortega"));
		library.registerUser(new User(16, "Patricia Castro"));
		library.registerUser(new User(17, "Diego Ramírez"));
		library.registerUser(new User(18, "Rosa Herrera"));
		library.registerUser(new User(19, "Jorge Vargas"));
		library.registerUser(new User(20, "Alicia Romero"));
		
		library.createLoan(library.findUserByCode(1), library.findBookByCode(1));
		library.createLoan(library.findUserByCode(2), library.findBookByCode(2));
		library.createLoan(library.findUserByCode(3), library.findBookByCode(3));
		library.createLoan(library.findUserByCode(4), library.findBookByCode(4));
		library.createLoan(library.findUserByCode(5), library.findBookByCode(5));
		library.createLoan(library.findUserByCode(6), library.findBookByCode(6));
		library.createLoan(library.findUserByCode(7), library.findBookByCode(7));
		library.createLoan(library.findUserByCode(8), library.findBookByCode(8));
		library.createLoan(library.findUserByCode(9), library.findBookByCode(9));
		library.createLoan(library.findUserByCode(10), library.findBookByCode(10));
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
			option = getInt();

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
			bookCode = getInt();
			codeRepeated = false; //asumir que es falso antes de buscar.
			Book book = library.findBookByCode(bookCode);
			if (book != null){
				System.out.println("Code matches with an already existing book, try again.");
				codeRepeated = true;
			}
		}
		
		bookName = getValidString("Enter the book name: ");
		authorName = getValidString("Enter the author name: ");

		library.addBook(new Book(bookCode, bookName, authorName));
		System.out.println("Book registered succesfully!");
	}
	
	private void removeBook(){
		System.out.print("Enter the book ID: ");
		int bookCode = getInt();
		library.removeBook(bookCode);
	}
	
	private void registerNewUser(){
		String userName = "";
		int userId = 0;
		boolean idRepeated = true;
		while (idRepeated){
			System.out.print("Enter the user ID: ");
			userId = getInt();;
			idRepeated = false; //asumir que es falso antes de buscar.
			for (int i = 0; i< library.getUsers().size();i++){
				if (userId == library.getUsers().get(i).getId()){
					System.out.println("ID matches with an already existing user, try again.");
					idRepeated = true;
					break;
				}
			}
		}
		userName = getValidString("Enter the user name: ");
		library.registerUser(new User(userId,userName));
		System.out.println("User registered succesfully!");
	}
	
	private void lendBookToUser(){
		System.out.print("Enter the book code: ");
		int bookCode = getInt();
		Book bookFound = library.findBookByCode(bookCode);
		if (bookFound == null){
			System.out.println("Book wasn't found, try again later.");
			return;
		}
		System.out.print("Enter the user id: ");
		int userId = getInt();
		User userFound = library.findUserByCode(userId);
		if (userFound == null){
			return;
		}
		library.createLoan(userFound, bookFound);
		System.out.println(bookFound.getTitle() + " was lent to " + userFound.getName() + " successfully");
	}
	
	private void returnBook(){
		System.out.print("Enter the book code: ");
		int bookCode = getInt();
		Book bookFound = library.findBookByCode(bookCode);
		if (bookFound == null){
			System.out.println("Book wasn't found, try again later.");
			return;
		}
		System.out.print("Enter the user id: ");
		int userId = getInt();
		User userFound = library.findUserByCode(userId);
		if (userFound == null){
			return;
		}
		
		Loan loanFound = library.findLoanByBookAndUser(bookFound, userFound);
		if (loanFound == null){
			return;
		}
		library.returnLoan(loanFound);
		System.out.println("Book returned successfully");
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
	
	public int getInt() {
        int input = -1;
        while (true) {
            if (scanner.hasNextInt()) {
                input = scanner.nextInt();
                scanner.nextLine();
                break;
            } else {
                System.out.println("Invalid input. Enter a valid number.");
                scanner.nextLine(); 
            }
        }
        return input;  // Return the valid integer
    }
	
	public String getValidString(String prompt) {
        String input = "";

        while (true) {
            System.out.print(prompt);
            input = scanner.nextLine();

            if (!input.trim().isEmpty()) {
                break; 
            } else {
                System.out.println("Input cannot be empty. Please enter a valid value.");
            }
        }

        return input;
    }
}
