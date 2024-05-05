#include <iostream>
#include <algorithm>
using namespace std;

// Prime number validation function
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

// Modulus function 
int Mod(int x, int y){
    int n = x * y;
    return n;
}

// Totient function 
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

    // Validate if values are prime 
    if (!Prime(p) || !Prime(q)){
        cout << "Error: Both values must be prime. " << endl;
        return -1;
    }

    // Display modulus value --> n
    int n = Mod(p,q);
    cout << "n: " << n << endl;

    // Display totient function value --> O
    int O = Totient(p,q);
    cout << "O: " << O << endl;

    // Generate and display the public key by calling the PublicKey function
    int e = 11;
    cout << "The public key is: <" << e << ", " << n << ">" << endl;

    // Generate and display the private key by calling the PrivateKey function
    int d = PrivateKey(e, O);
    cout << "The private key is: <"  << d << ", " << n << ">" << endl;

    // Verify keys are multiplicative inverses of each other based on O
    verifyKeys(e, d, O);

    return 0;
}