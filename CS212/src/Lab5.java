//import java.io.BufferedReader;
//import java.io.FileInputStream;
//import java.io.FileNotFoundException;
//import java.io.IOException;
//import java.io.InputStreamReader;

import java.io.IOException;

import javax.swing.JOptionPane;

public class Lab5 {

	public static void main(String[] args) throws IOException {
		
		
		String isOrIsNot, inputWord;
		
		//read the input line
		
		TextFileInput text = new TextFileInput("Lab5Input.txt");
		int totalLine = 0;
		String line = text.readLine();
		while(line!=null) {
			totalLine++;
			line = text.readLine();
		}
		text.close();
		text = new TextFileInput("Lab5Input.txt");
		String[] wordArray = new String[totalLine];
		for (int i = 0; i < wordArray.length; i++)
		    wordArray[i] = "";
		for(int i = 0; i<wordArray.length; i++) {
			wordArray[i] = text.readLine();
		}
//		for(int i = 0; i < wordArray.length; i++){
//			System.out.println(wordArray[i]);
//		}
		
		while(true) {
			// This line asks the user for input by popping out a single window
			// with text input
			inputWord = JOptionPane.showInputDialog(null, "Enter a word in all lower case:");
		
			// if the inputWord is contained within wordArray return true
			if (wordIsThere(inputWord, wordArray)) 
				isOrIsNot = "is"; // set to is if the word is on the list
			else
				isOrIsNot = "is not"; // set to is not if the word is not on the list
			
			// Output to a JOptionPane window whether the word is on the list or not
			JOptionPane.showMessageDialog(null, "The word " + inputWord + " " + isOrIsNot + " on the list.");
		}
	} // main

	public static boolean wordIsThere(String findMe, String[] theList) {
		if (findMe.equals("STOP"))
			System.exit(0);
		for (int i = 0; i < theList.length; i++)
			if (findMe.equals(theList[i]))
				return true;
		return false;
	} // wordIsThere

}
