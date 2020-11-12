#include "header.h"


Animal *create(string id, float w1, float w2) {
    Animal *p = new Animal();
    p->id = id;
    p->w1 = w1;
    p->w2 = w2;
    p->next = nullptr;
}

void Add(AnimalList *&l, string id, float w1, float w2) {
    Animal *p  =  create(id, w1, w2);
    if (l->first == nullptr) {
        l->first = l->last = p;
        return;
    }
    Animal *cur =  l->first;
    while (cur->next) {
        cur = cur->next;
    }
    cur->next = p;
}

AnimalList* read_file(string input_file){
	AnimalList* animals = new AnimalList();
    ifstream fin(input_file.c_str());
    while (fin.good()) {
        string id;
        float w1, w2;
        fin >> id >> w1 >> w2;
        Add(animals, id, w1, w2);
    }   
	return animals;
}


void print_output(AnimalList* animals, int x){


}


int count(AnimalList* list) {
    Animal *p = list->first;
    int cnt(0);
    while (p) {
        p = p->next;
        ++cnt;
    }
    return cnt;
}

void Traversal(AnimalList *l) {
    Animal *p = l->first;
    while (p) {
        cout << p->id << " " << p->w1 << " " << p->w2  << endl;
        p = p->next;
    }
}


void main_debug(string input_file, int x){
	// MAIN HERE: do whatever you want here
    AnimalList *list = read_file(input_file);
    Animal *p = list->first;
    while (p) {
        cout << p->id << " " << p->w1 << " " << p->w2 << endl;
        p = p->next;
    }
    
    cout << "----------" << endl;
    
    {
    Animal *cur = list->first;
    while (cur) {
        bool ok = true;
        if (cur->id.size() > 9 || cur->id.size() < 0) ok = false;
        if (cur->id[0] == 'P' || cur->id[0] == 'C') {
            int x = (cur->id[2] - '0')* 10 + (cur->id[3] - '0');
            if (x > 12 || x < 0) ok = false;
            if (cur->id[0] == 'P') {
                
                if (cur->w1 <= 50 || cur->w1 >= 100) ok = false;
            }
            else if (cur->id[0] == 'C'){
                if (cur->w1 <= 50 || cur->w1 >= 200) ok = false;
            }
        } else ok = false;
        if (ok == false) cout << cur->id << endl;
        cur = cur->next;
    }   
    }
    cout << "----------" << endl;
   
    for (Animal *p = list->first; p; p = p->next) {
        
        Animal *temp = p;
       
        while (temp->next) {
            if (p->w1 < temp->next->w1) {
                swap(temp->w1, temp->next->w1);
                swap(temp->id, temp->next->id);
                swap(temp->w2, temp->next->w2);
            }
            temp = temp->next;
        }
    }

      for (Animal *p = list->first; p; p = p->next) {
        
        Animal *temp = p;
       
        while (temp->next) {
            if (p->id[0] == 'C' &&  temp->next->id[0] == 'P') {
                swap(temp->w1, temp->next->w1);
                swap(temp->id, temp->next->id);
                swap(temp->w2, temp->next->w2);
            }
            temp = temp->next;
        }
    }

        Animal *cur = list->first;
        while (cur) {
        bool ok = true;
        if (cur->id.size() > 9 || cur->id.size() < 0) ok = false;
        if (cur->id[0] == 'P' || cur->id[0] == 'C') {
            int x = (cur->id[2] - '0')* 10 + (cur->id[3] - '0');
            if (x > 12 || x < 0) ok = false;
            if (cur->id[0] == 'P') {
                
                if (cur->w1 <= 50 || cur->w1 >= 100) ok = false;
            }
            else if (cur->id[0] == 'C'){
                if (cur->w1 <= 50 || cur->w1 >= 200) ok = false;
            }
        } else ok = false;
        if (ok) cout << cur->id << endl;
        cur = cur->next;
    }   
}

int main(int argc, char* argv[]){
	string input_file; int x;
	if (argc > 2) {
		input_file = argv[1]; x = atoi(argv[2]);
		if (argc > 3 && atoi(argv[3]) == 1) {
			main_testcases(input_file, x); return 0; }}
	else {
		cout << "Enter input_file:"; cin >> input_file;
	 	cout << "Enter x:"; cin >> x; }
	main_debug(input_file, x);
	if (!system(NULL)) system("pause"); return 0; }

void main_testcases(string input_file, int x){
	AnimalList* animals = read_file(input_file);
	print_output(animals, x); }