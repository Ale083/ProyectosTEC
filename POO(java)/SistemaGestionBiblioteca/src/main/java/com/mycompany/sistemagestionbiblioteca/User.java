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
public class User {
	private int id;
	private String name;
	private ArrayList<Book> borrowedBooks;

	public User(int id, String name) {
		this.id = id;
		this.name = name;
		borrowedBooks = new ArrayList<Book>();
	}
	
	public void addBorrowedBook(Book book){
		borrowedBooks.add(book);
	}
	
	public void returnBorrowedBook(Book book){
		borrowedBooks.remove(book);
		book.returnBook();
	}
	public void showBorrowedBooks(){
		System.out.println("Books borrowed by [" + id + "] " + name);
		for (int i = 0; i < borrowedBooks.size(); i++) {
			borrowedBooks.get(i).showDetails();
		}
	}
	public void userDetails(){
		System.out.println("[" + id + "] " + name);
	}
	
}
