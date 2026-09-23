#include<iostream>
#include<string>
#define MAX 1000
using namespace std;

struct person {
	string m_name;
	int m_sex;
	int m_age;
	string m_phone;
	string m_addr;
};
struct addressbooks {
	struct person personarray[MAX];
	int m_size;
};

void showmenu(void) {
	cout << "*****  1.添加联系人  *****" << endl;
	cout << "*****  2.显示联系人  *****" << endl;
	cout << "*****  3.删除联系人  *****" << endl;
	cout << "*****  4.查找联系人  *****" << endl;
	cout << "*****  5.修改联系人  *****" << endl;
	cout << "*****  6.清空联系人  *****" << endl;
	cout << "*****  0.退出通讯录  *****" << endl;
}

void addperson(addressbooks* abs) {
	if (abs->m_size == MAX) {
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else {
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personarray[abs->m_size].m_name = name;

		cout << "请输入性别：（1男2女）" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personarray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "请重新输入" << endl;
		}

		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->personarray[abs->m_size].m_age = age;

		cout << "请输入联系电话" << endl;
		string phone;
		cin >> phone;
		abs->personarray[abs->m_size].m_phone = phone;

		cout << "请输入家庭住址" << endl;
		string address;
		cin >> address;
		abs->personarray[abs->m_size].m_addr = address;

		abs->m_size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
}

void showperson(addressbooks* abs) {
	if (abs->m_size == 0) {
		cout << "当前记录为空" << endl;
	}
	else {
		for (int i = 0; i < abs->m_size; i++) {
			cout << "姓名：" << abs->personarray[i].m_name << "\t";
			cout << "性别:" << (abs->personarray[i].m_sex == 1 ? "男" : "女") << "\t";
			cout << "电话:" << abs->personarray[i].m_phone << "\t";
			cout << "年龄:" << abs->personarray[i].m_age << "\t";
			cout << "住址:" << abs->personarray[i].m_addr << endl;
		}
	}
	system("pause");
	system("cls");
}

int isexist(addressbooks* abs, string name) {
	for (int i = 0; i < abs->m_size; i++) {
		if (abs->personarray[i].m_name == name) {
			return i;
		}
	}
	return -1;
}

void deleteperson(addressbooks* abs) {
	cout << "请输入你要删除的联系人" << endl;

	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret != -1) {
		for (int i = ret; i < abs->m_size - 1; i++) {
			abs->personarray[i] = abs->personarray[i + 1];
		}
		abs->m_size--;
		cout << "删除成功" << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void findperson(addressbooks* abs) {
	cout << "输入要查找的联系人" << endl;
	string name;
	cin >> name;

	int ret = isexist(abs, name);
	if (ret != -1) {
		cout << "姓名：" << abs->personarray[ret].m_name << "\t";
		cout << "性别：" << (abs->personarray[ret].m_sex == 1 ? "男" : "女") << "\t";
		cout << "电话:" << abs->personarray[ret].m_phone << "\t";
		cout << "年龄:" << abs->personarray[ret].m_age << "\t";
		cout << "住址:" << abs->personarray[ret].m_addr << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void modifyperson(addressbooks* abs) {
	cout << "请输入要修改的联系人姓名" << endl;
	string name;
	cin >> name;

	int ret = isexist(abs, name);
	if (ret != -1) {
		string new_name;
		cout << "请输入新的姓名：" << endl;
		cin >> new_name;
		abs->personarray[ret].m_name = new_name;

		cout << "请输入性别（1男2女）：" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personarray[ret].m_sex = sex;
				break;
			}
			else {
				cout << "输入有误，请重新输入" << endl;
			}
		}

		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personarray[ret].m_age = age;

		cout << "请输入电话：" << endl;
		string phone;
		cin >> phone;
		abs->personarray[ret].m_phone = phone;

		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personarray[ret].m_addr = address;

		cout << "修改成功" << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void clearperson(addressbooks* abs) {
	cout << "确定要清空所有联系人吗？(y/n)" << endl;
	char confirm;
	cin >> confirm;

	if (confirm == 'y' || confirm == 'Y') {
		abs->m_size = 0;
		cout << "已清空所有联系人" << endl;
	}
	else {
		cout << "取消清空操作" << endl;
	}
	system("pause");
	system("cls");
}

int main() {
	addressbooks abs;
	abs.m_size = 0;

	int select = 0;

	while (true) {
		showmenu();
		cin >> select;

		switch (select) {
		case 1:
			addperson(&abs);
			break;

		case 2:
			showperson(&abs);
			break;

		case 3:
			deleteperson(&abs);
			break;

		case 4:
			findperson(&abs);
			break;

		case 5:
			modifyperson(&abs);
			break;

		case 6:
			clearperson(&abs);
			break;

		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;

		default:
			cout << "输入错误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}