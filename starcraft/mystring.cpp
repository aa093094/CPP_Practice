#include <iostream>

class string {
    char* str;
    int len;

    public:
        string(char c);
        string (const char* s);
        ~string();

        int strlen();
        void add_string(const string s);
        void copy_string(const string &s);
        void include_string(const string s);
        void equal_string(const string s);
        void compare_string(const string s);
        void show_string();
};

string::string(char c) {
    str = new char[2];
    len = 1;
    str[0] = c;
    str[1] = '\0';
}

string::string(const char* s) {
    int cnt = 0;

    while (s[cnt] != '\0') {
        cnt++;
    }

    str = new char[cnt + 1];
    for (int i = 0; i < cnt ; i++) {
        str[i] = s[i];
    }

    str[cnt] = '\0';
    len = cnt;
}

int string::strlen() {
    return len;
}

void string::add_string(const string s) {
    char* big_str = new char[len + s.len + 1];

    for (int i = 0; i < len; i++) {
        big_str[i] = str[i];
    }

    for (int j = 0; j < s.len; j++) {
        big_str[j + len] = s.str[j];
    } 

    big_str[len + s.len] = '\0';

    copy_string(big_str);

    delete[] big_str;
}

void string::copy_string(const string &s) {
    if (str) delete[] str;

    str = new char[s.len + 1];
    for (int i = 0; i < s.len; i++) {
        str[i] = s.str[i];
    }
    str[s.len] = '\0';
    len = s.len;
}

void string::include_string(const string s) {
    int bp = 1;

    if (len < s.len) {
        for (int i = 0; i < s.len; i++) {
            if (s.str[i] == str[0]) {
                for (int j = 1; j < len; j++) {
                    if (s.str[i + j] != str[j] || s.len <= i + j) {
                        bp = 0;
                        break;
                    }
                    bp = 1;
                }
                if (bp == 1) break;
            }
        }
    } else if (len == s.len) {
        for (int i = 0; i < len; i++) {
            if (str[i] != s.str[i]) {
                bp = 0;
                break;
            }
        }
    } else {
        for (int i = 0; i < len; i++) {
            if (str[i] == s.str[0]) {
                for (int j = 1; j < s.len; j++) {
                    if (str[i + j] != s.str[j] || len <= i + j) {
                        bp = 0;
                        break;
                    }
                    bp = 1;
                }
                if (bp == 1) break;
            }
        }
    }

    if (bp == 1 && len < s.len) {
        std::cout << "s includes string" << std::endl;
    } else if(bp == 1) {
        std::cout << "string includes s" << std::endl;
    } else {
        std::cout << "string not includes s" << std::endl;
    }
}

void string::equal_string (const string s) {
    int bp = 1;

    for (int i = 0; i < len; i++) {
        if (str[i] != s.str[i]) {
            bp = 0;
            break;
        }
    }

    if (bp == 1) {
        std::cout << "s equals string" << std::endl;
    } else {
        std::cout << "s not equals string" << std::endl;
    }
}

void string::compare_string (const string s) {
    int bigger = -1;

    if (len < s.len) {
        for (int i = 0; i < len; i++) {
            if (str[i] != s.str[i]) {
                if (str[i] < s.str[i]) {
                    bigger = 1;
                    break;
                }
                else {
                    bigger = 0;
                    break;
                }
            }
        }
        if (bigger == -1) bigger = 1;
    } else if (len > s.len) {
        for (int i = 0; i < s.len; i++) {
            if (str[i] != s.str[i]) {
                if (str[i] < s.str[i]) {
                    bigger = 1;
                    break;
                }
                else {
                    bigger = 0;
                    break;
                }
            }
        }
        if (bigger == -1) bigger = 0;
    }

    if (bigger == 1) {
        std::cout << "s is bigger than string" << std::endl;
    } else if (bigger == 0) {
        std::cout << "string is bigger than s" << std::endl;
    } else {
        std::cout << "string and s are equal" << std::endl;
    }


}

void string::show_string()
{
	std::cout << str << std::endl;
}

string::~string() {
    if (str) delete[] str;
}

int main()
{
	string s1('a');
    string s2("hello");
    string s3=s1;
    string s4('b');
    
    s1.show_string();//aaa
    s2.show_string();//hello
    s3.show_string();//aaa
    s4.show_string();//bbbb
    
    s1.add_string(s2);
    s1.show_string();//aaahello
    
    s1.copy_string(s4);
    s1.show_string();//bbbb
    
    return 0;
}
