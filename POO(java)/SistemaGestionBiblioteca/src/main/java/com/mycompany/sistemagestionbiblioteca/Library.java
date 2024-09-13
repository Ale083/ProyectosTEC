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
		users = new ArrayList<User>();
		loans = new ArrayList<Loan>();
	}
	
	public void addBook(Book book){
		books[bookCount++] = book;
	}
	
	public void removeBook(int code){
		boolean bookFound = false;
		for (int i = 0; i < bookCount; i++) {
			if (books[i].getCode() == code){
				Loan loanAssociated = findLoanByBook(books[i]);
				if(loanAssociated != null) 
					returnLoan(loanAssociated); //Si hay algún loan con ese libro, entonces quita el Loan tambien.
				books[i] = null; 
				for (int j = i; j < bookCount-1; j++) {
					books[j] = books[j+1];
				}
				bookFound = true;
				bookCount--;
			}
		}
		if(!bookFound){
			System.out.println("Book wasn't found, try again later.");
		}
	}
	
	public Book findBookByCode(int code){
		for (int i = 0; i < bookCount; i++) {
			if (books[i].getCode() == code){
				return books[i];
			}
		}
		return null;
	}
	
	public User findUserByCode(int id){
		for (int i = 0; i < users.size(); i++) {
			if (users.get(i).getId() == id){
				return users.get(i);
			}
		}
		System.out.println("User wasn't found, try again later.");
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
		if (!book.isAvailable()){
			System.out.println("Book is not available at this moment, try again at another time.");
		} else{
			loans.add(new Loan(user,book));
			user.addBorrowedBook(book);
		}
	}
	
	public void returnLoan(Loan loan){
		loan.getUser().returnBorrowedBook(loan.getBook()); 
	}
	
	public Loan findLoanByBookAndUser(Book book, User user){
		for (int i = 0; i < loans.size(); i++) {
			Loan get = loans.get(i);
			if (get.getBook().equals(book) && get.getUser().equals(user)){
				return get;
			}
		}
		System.out.println("No loan found that matches the provided book and user.");
		return null;
	}
	
	public Loan findLoanByBook(Book book){
		for (int i = 0; i < loans.size(); i++) {
			Loan get = loans.get(i);
			if (get.getBook().equals(book)){
				return get;
			}
		}
		return null;
	}
	
	public void showLoans(){
		for (int i = 0; i < loans.size(); i++) {
			loans.get(i).showLoanDetails();
		}
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

