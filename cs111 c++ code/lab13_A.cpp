void function1(int i, int j){ //What have been passed into these parameters? x and y which are both 0			
  if ( i % 3 == 0 || i % 4 != 0 ) i = 5;  //What does this line mean?  Is i changed? Is x changed? i is set to 5 if it is either a factor of 3 or not a factor of 4. i is changed, thus x is changed
  else i = 2;  // Is i changed here? Is x changed? i and x are changed
  j = 10; //Is y changed? y is changed
}
int main (){
  int x = 0, y = 0;
  while (x <= 10) x += 10; //what does this loop do? What happen to x? adds 10 to x until x is greater than 10
  cout << x << y << endl; //What is the output of this line? 200
  function1(x, y); //What is this line? sets i to 2 and y to 10
  cout << x << " " << y << endl; //What is the output? 2 10
  return 0;
}