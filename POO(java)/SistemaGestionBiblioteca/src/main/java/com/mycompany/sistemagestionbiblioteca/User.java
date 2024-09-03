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
	
	
}
