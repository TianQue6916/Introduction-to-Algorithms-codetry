#include<iostream>
using namespace std;
#include <string>
#include<ctime>

\


struct student {
	string sname;
	int score = 0;
};




struct teacher {
	string tname;
	struct student sarray[5];
};





string nameseed = "ABCDE";


void allocatespace(struct teacher tarray[], int len) {
	for (int i = 0; i < len; i++) {
		tarray[i].tname = "teacher_";
		tarray[i].tname += nameseed[i];
		for (int j = 0; j < 5; j++) {
			tarray[i].sarray[j].sname = "student_";
			tarray[i].sarray[j].sname = nameseed[j];

			int random = rand() % 101;//0-59  +41
			tarray[i].sarray[j].score = random;
			
		}
		
	}
}





void printinfo(struct teacher tarray[], int len) {
	for (int i = 0; i < len; i++) {
		cout << "tname" << tarray[i].tname << endl;
		for (int j = 0; j < 5; j++) {
			cout << "\tsname" << tarray[i].sarray[j].sname 
				<<" score"<< tarray[i].sarray[j].score << endl;
		}
	}

}




int main() {
	//随机数种子
	srand((unsigned int)time(NULL));

	struct teacher tarray[3];
	int len = sizeof(tarray) / sizeof(tarray[0]);
	allocatespace(tarray, len);


	printinfo(tarray,len);

	system("pause");
	return 0;
}