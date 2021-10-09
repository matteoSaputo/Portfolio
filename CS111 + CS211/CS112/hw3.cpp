#include <iostream>
using namespace std;

int main() {
   while (true) {
      string outcome;
      cout << "Enter the race outcome: ";
      cin >> outcome;
      // If the user entered "done", exit the program
      if(outcome == "done") break;
      
      int numTeams = 0;       // The number of teams
      int scores['Z'+1] = {}; // scores[i] keeps track of the total score of team i
      int counts['Z'+1] = {}; // counts[i] keeps track of the number of runners on team i
      
      for (int i = 0; i < outcome.length(); i++) { // For each runner in the race,
         // Increase the team's score by the runner's rank (the rank is 1 more than the index)
	  	 scores[outcome[i]] += i + 1;
         // If it's the first runner of that particular team, update the total number of teams
         if (counts[outcome[i]] == 0)              // If the score changed from 0 to non-0, increment numTeams.
            numTeams++;
         // Update the number of runners on the team
         counts[outcome[i]]++;
      }
      
      // If the teams do not all have the same number of runners,
         // Print an error message and ask for input again (go back to the beginning of the loop)
      for(char i = 'A'; i <= 'Z'; i++){
         if(counts[i] != counts[i-1]){
         	cout << "The teams don't have the same number of runners.\n";
         	continue;
         }
      }
      
      // Print the number of teams
       cout << "There are " << numTeams << " teams.\n";
      // Print the number of runners on each team
      cout << "Each team has " << counts[0] << " runners.\n";
      cout<<'\t'<<"Team"<<'\t'<<"Score"<<endl<<endl;
      
      int winningTeam = 'A';
      // For each letter from A-Z,
      for (char i = 'A'; i <= 'Z'; ++i) {
         // If that team participated,
         if(scores[i] != 0){
            // Print the name of the team and its average score
            cout<<'\t'<<i<<'\t'<<scores[i]<<endl<<endl;
            // Also keep track of which team(s) has the best score
            if(scores[i] > scores[winningTeam]) winningTeam = i;
         }
      }
      // Print the name of the winning team and its average score (if it's a tie, you may either pick one arbitrarily or print all of the winners)
      cout<<"Winning team is " << winningTeam << " with an average score of " << scores[winningTeam];
   }
   return 0;
}
