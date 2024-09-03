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
		available = false;
	}
	
	public void returnBook(){
		available = true;
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
