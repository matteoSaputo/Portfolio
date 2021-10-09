import javax.swing.JOptionPane;

public class Project0 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		while(true) {
			//input sentence from user and store into the inputSentence variable
			String inputSentence = JOptionPane.showInputDialog(null, "Please Enter a Sentence: ");
			int numE = 0; int nume = 0; //int variables to keep track of the number of e's
			
			//terminates the program if the user inputs the word stop in any capitalization
			if(inputSentence.equalsIgnoreCase("STOP"))
				System.exit(0);
			
			//loop through the user's sentence string
			for(int i = 0; i < inputSentence.length(); i++) {
				if(inputSentence.charAt(i) == 'E') //add 1 to the E counter if an E is found
					numE++;
				if(inputSentence.charAt(i) == 'e') //add 1 to the e counter if an e is found
					nume++;
			}
			
			//display the number of E's and e's
			JOptionPane.showMessageDialog(null, "Number of lower case e's: " + nume + "\nNumber of upper case e's: " + numE); 
		}
	}

}
