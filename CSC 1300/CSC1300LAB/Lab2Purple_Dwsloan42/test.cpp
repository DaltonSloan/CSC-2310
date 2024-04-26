#include <iostream>
using namespace std;

int main(){
int loop = 0;
while(true){
	int count;
    
   

    for (cin >> count; count <=10;count++) {
        cout << "Hello!" << endl;
        cin >> count;
        if (count <= 5) {
            loop++;
        }

        if (loop == 5) {
            break;
        }
        
        
    }
break;
}
   return 0;
}