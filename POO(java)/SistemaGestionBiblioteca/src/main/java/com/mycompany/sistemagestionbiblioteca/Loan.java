/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.sistemagestionbiblioteca;

import java.time.LocalDate;

/**
 *
 * @author Proyecto Diseño
 */
public class Loan {
	private User user;
	private Book book;
	private String loanDate;
	private String returnDate; //Cuando pregunté, como nunca se va a usar porque quitó ahi algo de las instrucciones el profe dijo que nada más lo deje como null.

	public Loan(User user, Book book) {
		this.user = user;
		this.book = book;
		LocalDate currentDate = LocalDate.now();
        loanDate = currentDate.toString();
	}

	public void showLoanDetails() {
		System.out.println("Loan from [" + user.getId() + "] " + user.getName() + ":  " + "[" + book.getCode() + "]" + book.getTitle() + " | By: " + book.getAuthor());
		System.out.println("\tLoan date: " + loanDate);
	}

	public User getUser() {
		return user;
	}

	public Book getBook() {
		return book;
	}
	
	
	
}
