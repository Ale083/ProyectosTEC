/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.sistemagestionbiblioteca;

/**
 *
 * @author Proyecto Diseño
 */
public class Book {
	private int code;
	private String title;
	private String author;
	private boolean available;

	public Book(int code, String title, String author) {
		this.code = code;
		this.title = title;
		this.author = author;
		available = true;
	}

	public void showDetails() {
		System.out.println("[" + code + "] " + title + " | By: " + author + (available ? " | Is available" : "| Not available"));
	}
	
	public void borrow(){
		if(available){
			available = false;
			System.out.println("Book borrowed successfully.");
		} else {
			System.out.println("Book is already borrowed.");
		}
	}
	
	public void returnBook(){
		if(!available){
			available = true;
			System.out.println("Book returned successfully.");
		} else {
			System.out.println("Book is already available.");
		}
	}


	public int getCode() {
		return code;
	}

	public String getTitle() {
		return title;
	}

	public String getAuthor() {
		return author;
	}

	public boolean isAvailable() {
		return available;
	}
}
