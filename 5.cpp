#include <iostream>
#include "mystring.h"

int main() {
    String a;
    a = String("asfasfa");
    String b("DEF");
    a = b;
    a.append(b);
    std::cout << b;
    return 0;
}
