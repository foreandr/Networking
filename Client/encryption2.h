std::string lenCeaser(std::string string) {
    char ch;
    for (int i = 0; string[i] != '\0'; ++i) {
        ch = string[i];
        //encrypt for lowercase letter
        if (ch >= 'a' && ch <= 'z') {
            ch = ch + string.length();
            if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
            string[i] = ch;
        }
        //encrypt for uppercase letter
        else if (ch >= 'A' && ch <= 'Z') {
            ch = ch + string.length();
            if (ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }
            string[i] = ch;
        }
    }
    return string;
}