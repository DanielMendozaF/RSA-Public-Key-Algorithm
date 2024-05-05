#include <iostream>
#include <algorithm>
using namespace std;

// This function checks to see if a value is prime 
bool Prime(int x){
    if (x < 2)
        return false;
    for (int i = 2; i <= x/2; i++){
        if (x % i == 0){
            return false;
        }
    }
    return true;
}

// This function calculates the modulus value --> n
int Mod(int x, int y){
    int n = x * y;
    return n;
}

// This function calculates the totient value --> O
int Totient(int x, int y){
    int phi = ((x-1)*(y-1));
    return phi;
}

// This function generates the public key --> e
int PublicKey(int phi){
    int e;
    for (e = 2; e < phi; e++){
        if (__algo_gcd(e, phi) == 1){
            return e;
        }
    }
    return -1;
}

// This function generates the private key --> d
int PrivateKey(int e, int phi){
    int d = 2;
    while ((d * e) % phi != 1) {
        d++;
    }
    return d;
}

// This function verifies that the keys are multiplicative inverse of totient value
void verifyKeys(int e, int d, int phi){
    if ((e * d) % phi == 1){
        cout << "The keys are mulitplicative inverse of " << phi << endl;
    }
    else{
        cout << "The keys are not multiplicative inverse of " << phi << endl;
    }
}

int main(){
    // User input for two prime numbers: p & q
    int p;
    int q;
    cout << "Enter a prime number in the range of 5,000 to 10,000: " << endl;
    cin >> p;
    cout << "Enter another prime number in the range of 5,000 to 10,000: " << endl;
    cin >> q;

    // Validate user input range between 5000 - 10000
    if ((p < 5000 || p > 10000) || (q < 5000 || q > 10000)){
        cout << "Error: Both values are not inside the specified range" << endl;
        return -1;
    }
    // Validate user input values are prime 
    else if (!Prime(p) || !Prime(q)){
        cout << "Error: Both values must be prime. " << endl;
        return -1;
    }

    // Display modulus value --> n
    int n = Mod(p,q);
    cout << "n: " << n << endl;

    // Display totient function value --> O
    int O = Totient(p,q);
    cout << "O: " << O << endl;

    // Generate and display the public key --> e
    int e = PublicKey(O);
    cout << "The public key is: <" << e << ", " << n << ">" << endl;

    // Generate and display the private key --> d
    int d = PrivateKey(e, O);
    cout << "The private key is: <"  << d << ", " << n << ">" << endl;

    // Verify keys e and d are multiplicative inverses for O
    verifyKeys(e, d, O);

    return 0;
}