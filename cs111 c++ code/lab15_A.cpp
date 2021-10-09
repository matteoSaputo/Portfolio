void function1(int i, int &j){ //What have been passed into these parameters? Two intergers, one of which will have its value affected
  cout << i << j;
  i = i + j;
  j = i + j;
}
int main (){
  int x = 2, y = 3;
  cout << x << " " << y << endl; //What is the output? 2 3
  function1(x, y); //What is the output? 23
  cout << x << " " << y << endl; //What is the output? 2 5
  return 0;
}