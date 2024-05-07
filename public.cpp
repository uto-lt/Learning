#include <iostream>
using namespace std;

 
class base
{
    protected:
        int x;
        void  fun()
        {
            return 2 * x;
        }
     
};
 
// main function
int main()
{
    // creating object of the derived class
    base obj;
     
    // accessing public data members outside class
    obj.x = 9;
    
    cout << obj.x << endl;
    cout << obj.fun();
}
 
