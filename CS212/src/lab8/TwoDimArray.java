package lab8;
import java.util.*;

public class TwoDimArray {

	public static int[][] myArray = fillArray("lab8Input.txt");
	
	public static void main(String[] args) {
		printArray(myArray);
		printArrayEven(myArray);
	}
	private static void printArray (int[][] theArray) {
		for (int i=0; i<theArray.length; i++) {
			for (int j=0; j<theArray[i].length;j++)
				display(theArray[i][j]);
			System.out.println();
		}
	}
	private static void display (int num){
		System.out.print(num+" ");
	}
	private static void printArrayEven(int[][] theArray){
		for (int i=0; i<theArray.length; i++) {
			for (int j=0; j<theArray[i].length;j++)
				if(theArray[i][j] % 2==0) display(theArray[i][j]);
				else System.out.print("* ");
			System.out.println();
		}
	}
	
	public static int[][] fillArray(String myFile){
		TextFileInput text = new TextFileInput(myFile);
		StringTokenizer dimensions = new StringTokenizer(text.readLine(), ",");
		int length = Integer.parseInt(dimensions.nextToken());
		int width = Integer.parseInt(dimensions.nextToken());
		int [][] output = new int[length][width];
		for(int i = 0; i < length; i++) {
			StringTokenizer line = new StringTokenizer(text.readLine(), ","); 
			for(int j = 0; j < width; j++)
				output[i][j] = Integer.parseInt(line.nextToken());
		}
		return output;
	}
}
