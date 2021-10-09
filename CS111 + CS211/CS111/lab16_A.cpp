int function1(int x){ //In plain English, what does function 1 do? 
   if (x == 1) return 1;
   return x + function1(x - 1);
}
//function 1 returns a factorial of x
int main (){
  cout << function1(3) << endl; //What is the output?
  return 0;
}
//the output is 7