//NCC_31060 Majestic
#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

#define input(a) scanf("%d",&a);
#define print_one_blank printf(" ");

struct Book {
    string name;
    string author;
    int status;//1代表在书架，0代表借出去了，-1代表可以还，但还没有放回去
    Book() {}

    Book(string n, string a) : name(n), author(a), status(1) {}
};

bool operator<(const Book &A, const Book &B) {
    if (A.author != B.author) return A.author < B.author;
    return A.name < B.name;
}

vector<Book> books;

bool Init_Input(string ipt) {
    if (ipt == "END") {
        sort(books.begin(), books.end());
        return true;
    }
    char *s = &ipt[1];
    Book temp_book;
    string temp;
    while (*s != '"') {
        temp += *s;
        ++s;
    }
    temp_book.name = temp;
    temp_book.status = 1;
    temp.clear();
    s += 5;
    while (*s != '\0') {
        temp += *s;
        ++s;
    }
    temp_book.author = temp;
    temp.clear();
    books.push_back(temp_book);
    return false;
}


void Print_Operator(string name_of_book, string pre_name_of_book, int way) {//way代表是放在首位，还是某本书后边
    if (way == 1) {
        printf("Put \"%s\" first\n", name_of_book.c_str());
    } else {
        printf("Put \"%s\" after \"%s\"\n", name_of_book.c_str(), pre_name_of_book.c_str());
    }
}

bool Execute_Order(string ipt) {
    if(ipt == "END")return false;
    string order = ipt.substr(0, 6);
    if (order == "BORROW") {
        char *s = &ipt[8];
        string book_name;
        while (*s != '"') {
            book_name += *s;
            ++s;
        }
        int num_of_books = books.size();
        for (int i = 0; i < num_of_books; ++i) {
            if (books.at(i).name == book_name) {
                books.at(i).status = 0;
                break;
            }
        }
    } else if (order == "RETURN") {
        char *s = &ipt[8];
        string book_name;
        while (*s != '"') {
            book_name += *s;
            ++s;
        }
        int num_of_books = books.size();
        for (int i = 0; i < num_of_books; ++i) {
            if (books.at(i).name == book_name) {
                books.at(i).status = -1;
                break;
            }
        }
    } else if (order == "SHELVE") {
        int num_of_books = books.size();
        for (int i = 0; i < num_of_books; ++i) {
            if (books.at(i).status == -1) {
                int pos_of_pre = i - 1;
                while (pos_of_pre > -1 && books.at(pos_of_pre).status != 1) { pos_of_pre--; }
                if (pos_of_pre == -1) { Print_Operator(books.at(i).name, "", 1); }
                else { Print_Operator(books.at(i).name, books.at(pos_of_pre).name, 0); }
                books.at(i).status = 1;
            }
        }
        printf("END\n");
    }
    return true;
}

int main() {
#ifdef LOCAL
    freopen("IN.txt", "r", stdin);
#endif
    string ipt;
    bool input_over = false;
    while (getline(cin, ipt)) {
        if (input_over) if(Execute_Order(ipt) == false)break;
        if (!input_over) input_over = Init_Input(ipt);
    }
    return 0;
}


/*
 * 咦 居然写了一个多小时😂 纯粹的模拟题，感觉这样的题只要储存结构（结构体之类）写的方便好用了，整个题写下来不会有什么大问题，再就是注意小细节 嗯嗯
 *
 * 这个题第一次写想的太纯粹的模拟了，借出去就是删掉了，不如这一次 用一个变量表示借阅状态，一下子就方便了许多呀
 *
 */