unsigned int inverti(unsigned int i) {
    unsigned int result = 0;
    while (i != 0) {
        unsigned int digit = i % 10;
        result = result * 10 + digit;
        i /= 10;
    }
    return result;
}
