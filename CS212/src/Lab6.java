import java.io.IOException;

import javax.swing.JOptionPane;

public class Lab6 {

	public static void main(String[] args) throws IOException {
		
		//read the input line
		TextFileInput text = new TextFileInput("Lab6Input.txt");
		
		//get number of lines
		int totalLine = 0;
		String line = text.readLine();
		while(line!=null) {
			totalLine++;
			line = text.readLine();
		}
		text.close();
		
		text = new TextFileInput("Lab6Input.txt");
		int[] numArray = new int[totalLine];
		for(int i = 0; i<numArray.length; i++) {
			numArray[i] = Integer.parseInt(text.readLine());
		}
		//for(int i = 0; i < totalLine; i++) { System.out.println(numArray[i]);}
		
		JOptionPane.showMessageDialog(null, "The sum is " + sum(numArray, totalLine) + ". The Average is " + average(numArray, totalLine));
	} // main
	
	public static int sum (int[] myArray, int myArraySize) {
		int sum = 0;
		for(int i = 0; i < myArraySize; i++)
			sum+=myArray[i];
		return sum;
	}
	
	public static int average (int[] myArray, int myArraySize) {
		return sum(myArray, myArray.length)/myArraySize;
	}
	
}
