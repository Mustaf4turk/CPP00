#include <iostream>
#include <string>
#include <cctype>

int main(int ac, char **av) {
    if (ac == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    for (int i = 1; i < ac; i++) {
        std::string s = av[i];
        for (size_t j = 0; j < s.length(); j++)
            s[j] = std::toupper(static_cast<unsigned char>(s[j]));
        std::cout << s;
    }
    std::cout << std::endl;
    return 0;
}

// static_cast<unsigned char> kullanilmasinin nedeni:
// std::toupper() parametresi olarak 'int' bekler ve bu deger
// [0, UCHAR_MAX] araliginda ya da EOF olmalidir.
// 'char' tipinin signed oldugu sistemlerde (cogu x86/x64),
// extended ASCII karakterler (örn. ä, ö, ü) negatif deger tasir.
// Negatif bir 'char' dogrudan 'int'e terfi ettirildiginde
// bu aralik disi kalir ve std::toupper icin undefined behavior olusur.
// kalmasi garanti edilir, boylece UB onlenir.
// unsigned char'a cast yaparak degerin her zaman [0, 255] araliginda