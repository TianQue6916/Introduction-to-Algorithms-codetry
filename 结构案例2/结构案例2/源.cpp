#include<iostream>
using namespace std;
#include<string>

struct hero {
	string name;
	int age;
	string sex;
};
//Ã°ÅİÅÅĞòÀ´Ò»¸öÄêÁäÅÅĞò
void bubblesort(struct hero heroarray[], int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - 1; j++) {
			if (heroarray[j].age > heroarray[j + 1].age) {
				struct hero temp = heroarray[j];
				heroarray[j] = heroarray[j + 1];
				heroarray[j + 1] = temp;
			}
		}
	}
}


void printhero(hero heroarray[], int len) {
	for (int i = 0; i < len; i++) {
		cout << heroarray[i].age
			<< heroarray[i].name
			<< heroarray[i].sex
			<< endl;
	}
}





int main() {
	struct hero heroarray[5] = {
		{"1",5,"1"},
		{"2",4,"2"},
		{"3",3,"3"},
		{"4",2,"4"},
		{"5",1,"5"},
	};
	
	int len = sizeof(heroarray) / sizeof(heroarray[0]);
	bubblesort(heroarray, len);
	/*for (int i = 0; i < len; i++) {
		cout << heroarray[i].age 
			<< heroarray[i].name 
			<< heroarray[i].sex 
			<< endl;
	}*/
	printhero(heroarray, len);
	system("pause");
	return 0;
}