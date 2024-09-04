/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.sistemagestionbiblioteca;

import java.util.ArrayList;

/**
 *
 * @author Proyecto Diseño
 */
public class Library {
	private Book books[] = new Book[200];
	private ArrayList<User> users;
	private ArrayList<Loan> loans;
	int bookCount;
	
	public Library(){
		bookCount = 0;
	}
	
	public void addBook(Book book){
		books[bookCount++] = book;
	}
	
	public void removeBook(int code){
		for (int i = 0; i < bookCount; i++) {
			if (books[i].getCode() == code){
				books[i] = null; 
				for (int j = i; j < bookCount-1; j++) {
					books[i] = books[i+1];
				}
				bookCount--;
			}
		}
	}
	
	public Book findBookByCode(int code){
		for (int i = 0; i < bookCount; i++) {
			if (books[i].getCode() == code){
				return books[i];
			}
		}
		System.out.println("Book wasn't found.");
		return null;
	}
	
	public void registerUser(User user){
		users.add(user);
	}
	
	public void showAvailableBooks(){
		for (int i = 0; i < bookCount; i++) {
			if (books[i].isAvailable()){
				books[i].showDetails();
			}
		}
	}
	
	public void showUsers(){
		for (int i = 0; i < users.size(); i++) {
			users.get(i).userDetails();
		}
	}
	
	public void createLoan(User user, Book book){
		loans.add(new Loan(user,book));
		user.addBorrowedBook(book);
		book.borrow();
	}
	
	public void returnLoan(Loan loan){
		loan.getUser().returnBorrowedBook(loan.getBook());
		loan.getBook().returnBook(); //TODO poner return date.
		loans.remove(loan);
	}

	public Book[] getBooks() {
		return books;
	}

	public ArrayList<User> getUsers() {
		return users;
	}

	public ArrayList<Loan> getLoans() {
		return loans;
	}

	public int getBookCount() {
		return bookCount;
	}
	
}

