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
