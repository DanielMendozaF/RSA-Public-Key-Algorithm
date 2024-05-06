#include <iostream>
#include <algorithm>
using namespace std;

// This function checks to see if a value is prime number and returns status
bool Prime(int val)
{
    if (val < 2)
        return false;
    for (int i = 2; i <= val/2; i++){
        if (val % i == 0){
            return false;
        }
    }
    return true;
}

// This function calculates the modulus value --> n and returns 'n'
int Mod(int val1, int val2)
{
    // n = p * q
    int modulus = val1 * val2;
    return modulus;
}

// This function calculates the totient value --> O and returns 'O'
int Totient(int val1, int val2)
{
    // O = (p-1)*(q-1)
    int phi = ((val1-1)*(val2-1));
    return phi;
}

// This function calculates the greatest common divisor between two values and returns GCD
int GCD(int num1, int num2)
{
    if (num1 == 0){
        return num2;
    }
    return GCD(num2 % num1, num1);
}

// This function generates the public key --> e and returns 'e' or an error if there is not a valid e
int PublicKey(int phi)
{
    // Loop to check valid public keys
    for (int e = 2; e < phi; e++){
        // Condition to check if the public key is a relative prime of totient value
        if (GCD(e, phi) == 1){
            return e;
        }
    }
    // If no valid public key, return an error
    return -1;
}

// This function generates the private key --> d and returns 'd'
int PrivateKey(int e, int phi){
    int d = 2;
    // Loop to generate a private key that is valid
    while ((d * e) % phi != 1) {
        d++;
    }
    return d;
}

// This function verifies that the keys are multiplicative inverse of totient value or if they are not
void verifyKeys(int e, int d, int phi){
    // Condition with multiplicative inverse algorithm
    if ((e * d) % phi == 1){
        cout << "The keys are mulitplicative inverse of " << phi << endl;
    }
    else{
        cout << "The keys are not multiplicative inverse of " << phi << endl;
    }
}

int main(){
    // User input for two prime numbers --> p & q
    int p;
    int q;
    cout << "Enter a prime number in the range of 5,000 to 10,000: " << endl;
    cin >> p;
    cout << "Enter another prime number in the range of 5,000 to 10,000: " << endl;
    cin >> q;

    // Validate user input range between 5000 - 10000. 
    if ((p < 5000 || p > 10000) || (q < 5000 || q > 10000)){
        cout << "Error: Both values must be inside the specified range " << endl;
        return -1;
    }
    // Validate user input values are prime 
    else if ((Prime(p) == false) || (Prime(q) == false)){
        cout << "Error: Both values must be prime " << endl;
        return -1;
    }
    else{
        cout << "Both values are inside the specified range and are prime " << endl;
    }

    // Call Mod function and display modulus value --> n
    int n = Mod(p,q);
    cout << "The modulus is : " << n << endl;

    // Call Totient function and display totient function value --> O
    int O = Totient(p,q);
    cout << "The totient value is : " << O << endl;

    // Call PublicKey function and display the public key --> e
    int e = PublicKey(O);
    cout << "The public key is: <" << e << ", " << n << ">" << endl;

    // Call PrivateKey function and display the private key --> d
    int d = PrivateKey(e, O);
    cout << "The private key is: <"  << d << ", " << n << ">" << endl;

    // Call verifyKeys function to verify keys 'e' and 'd' are multiplicative inverses for O
    verifyKeys(e, d, O);

    return 0;
}