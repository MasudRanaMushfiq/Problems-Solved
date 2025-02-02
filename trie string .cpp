#include <bits/stdc++.h>
using namespace std;

struct node {
    bool endmark;
    node* next[26 + 1];
    node()
    {
        endmark = false;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
} * root;

void insert(char* str, int len){
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
    curr->endmark = true;
}

bool search(char* str, int len){
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            return false;
        curr = curr->next[id];
    }
    return curr->endmark;
}

void del(node* cur){
    for (int i = 0; i < 26; i++)
        if (cur->next[i])
            del(cur->next[i]);

    delete (cur);
}

int main()
{

    root = new node();
    int num_word;
    cin >> num_word;
    for (int i = 1; i <= num_word; i++) {
        char str[50];
        cin>>str;
        insert(str, strlen(str));
    }

    int query;
    cin >> query;
    for (int i = 1; i <= query; i++) {
        char str[50];
        cin>>str;
        if (search(str, strlen(str)))
            cout<<"FOUND"<<endl;
        else
            cout<<"NOT FOUND"<<endl;
    }
    
    del(root); //ট্রাইটা ধ্বংস করে দিলাম
    return 0;
}
