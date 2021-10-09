
void sum(int x, int z, int& y);
int mystery(string st);
double fun(double x);
double trick();

int main(){
   int x = 5, y;
   string st = "Hello";
   sum(x, 20, y); //set last parameter to the sum of the previous two
   if(mystery(st) == y) fun(y + 2.5);
   double a = fun(trick());
   return 0;
}