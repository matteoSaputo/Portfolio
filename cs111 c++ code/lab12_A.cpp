int function1(int i){ 
  if ( i % 3 == 0 || i % 4 != 0 ) cout << 5;  //Is there output? 
  return i + i;
}
int main (){
  int x = 0, y = 0;
  while (x <= 10) x += 10; //what does this loop do? What happen to x? Adds 10 to x untill x is greater than or equal to 10
  cout << x << y << endl; //What is the output of this line? 100
  function1(y); //Output? 5
  cout << function1(x) << endl; //Output? 0
  return 0;
}