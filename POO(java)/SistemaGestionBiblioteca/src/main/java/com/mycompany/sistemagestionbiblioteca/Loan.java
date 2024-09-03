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
	private String returnDate;

	public Loan(User user, Book book) {
		this.user = user;
		this.book = book;
		LocalDate currentDate = LocalDate.now();
        String loanDate = currentDate.toString();
	}

	public void showLoanDetails() {
		System.out.println("Loan{" + "user=" + user + ", book=" + book + ", loanDate=" + loanDate + ", returnDate=" + returnDate + '}');
	}

	public User getUser() {
		return user;
	}

	public Book getBook() {
		return book;
	}
	
	
	
}
