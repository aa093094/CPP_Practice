#include <string.h>
#include <iostream>

class string {
    char *str;
    int len;

    public:
        string(char c, int n);
        string(const char *s);
        string(const string &s);
        ~string();

        void add_string(const string &s);
        void copy_string(const string &s);
        void show_string();
        int strlen();
};

string::string(char c, int n) {
    str = new char[n + 1];
    for (len = 0; len < n; len++) {
        str[len] = c;
    }
    str[len] = '\0';
}

string::string(const char *s) {
    int cnt = 0;

    while (s[cnt] != '\0') {
        cnt++;
    }

    str = new char[cnt + 1];
    for (int i = 0; i < cnt; i++) {
        str[i] = s[i];
    }
    str[cnt] = '\0';
    
    len = cnt;
}

string::string(const string &s) {
    copy_string(s);
}

void string::add_string(const string &s) {
    char *big_str = new char[len + s.len + 1];
    for (int i = 0; i < len; i++) {
        big_str[i] = str[i];
    }
    
    for (int j = 0; j < s.len; j++) {
        big_str[len + j] = s.str[j];
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

void string::show_string()
{
	std::cout << str << std::endl;
}

int string::strlen() {
    return len;
}

string::~string() {
    if (str) delete[] str;
}

int main()
{
	string s1('a', 3);
    string s2("hello");
    string s3=s1;
    string s4('b', 4);
    
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
