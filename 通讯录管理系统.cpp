#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<cstdlib>
#define MAX 1000 //最大人数
using namespace std;
void mainMenu(){
	cout << "------------------------" << endl;
	cout << "***** 1.增加联系人 *****" << endl;
	cout << "***** 2.显示联系人 *****" << endl;
	cout << "***** 3.删除联系人 *****" << endl;
	cout << "***** 4.查找联系人 *****" << endl;
	cout << "***** 5.修改联系人 *****" << endl;
	cout << "***** 6.清空联系人 *****" << endl;
	cout << "***** 0.退出通讯录 *****" << endl;
	cout << "------------------------" << endl;
}
struct Person {
	string m_Name;
	int m_Age;
	int m_Sex;
	string m_Phone;
	string m_Addr;
};
struct AddressBooks {
	struct Person personArray[MAX];
	int m_Size;
};
void addPerson(struct AddressBooks *abs) {
	if (abs->m_Size == MAX){
		cout<<"对不起，超过最大通讯录存储容量，无法存储" << endl;
	}
	else{
		//添加联系人
		//姓名
		cout << "请输入姓名：" << endl;
		string name;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//性别
		cout << "请输入性别：" << endl;
		cout << "1----男" << endl;
		cout << "2----女" << endl;
		int sex = 0;
		while (true){   //排除非法输入
			cin >> sex;
			if (sex == 1 || sex == 2){
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}
		//年龄
		cout << "请输入年龄：" << endl;
		int age;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		//电话
		cout << "请输入电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//住址
		cout << "请输入住址：" << endl;
		string addr;
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;
		
		abs->m_Size++; //更新系统人数
		cout<<"添加成功！" << endl;
		system("pause");  // 按任意键退出
		system("cls");
	}
}
void showPerson(struct AddressBooks* abs) {
	if (abs->m_Size == 0){
		cout << "当前记录为空。" << endl;
	}
	else{
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "姓名： " << abs->personArray[i].m_Name << "\t";
			cout << " 年龄： " << abs->personArray[i].m_Age << "\t";
			cout << " 性别： " << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";  //三目运算符
			cout << " 电话： " << abs->personArray[i].m_Phone << "\t";
			cout<<" 住址： " <<abs->personArray[i].m_Addr<< endl;
		}
	}
	system("pause");
	system("cls");
}
int isExist(struct AddressBooks* abs,string name) {
	for (int i = 0; i < abs->m_Size; i++){
		if (abs->personArray[i].m_Name == name) {
			return i;  // 找到这个人，就返回他的数组下标
		}
	}
	//遍历完数组都没有找到，就返回 -1
	return -1;
}
void deletePerson(struct AddressBooks* abs) {
	cout<<"请输入你要删除的对象：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1){ // 查到了
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		cout<<"删除成功！" << endl;
		abs->m_Size--;
	}
	else{
		cout<<"查无此人" << endl;
	}
	system("pause");
	system("cls");
}
void findPerson(struct AddressBooks *abs) {
	cout<<"请输入你要查找的联系人姓名：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs,name);
	if (ret != -1){ //查到了
		cout << "姓名： " << abs->personArray[ret].m_Name << "\t";
		cout << " 年龄： " << abs->personArray[ret].m_Age << "\t";
		cout << " 性别： " << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";  //三目运算符
		cout << " 电话： " << abs->personArray[ret].m_Phone << "\t";
		cout << " 住址： " << abs->personArray[ret].m_Addr << endl;
	}
	else{
		cout<<"查无此人！" << endl;
	}
	system("pause");
	system("cls");
}
void modifyPerson(struct AddressBooks *abs) {
	cout<<"请输入要修改联系人的姓名：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1){
		//修改联系人信息
		//姓名
		cout << "请输入姓名：" << endl;
		string name;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//性别
		cout << "请输入性别：" << endl;
		cout << "1----男" << endl;
		cout << "2----女" << endl;
		int sex = 0;
		while (true) {   //排除非法输入
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}
		//年龄
		cout << "请输入年龄：" << endl;
		int age;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		//电话
		cout << "请输入电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//住址
		cout << "请输入住址：" << endl;
		string addr;
		cin >> addr;
		abs->personArray[ret].m_Addr = addr;

		system("pause");  // 按任意键退出
		system("cls");
	}
	else{
		cout<<"查无此人" << endl;
	}
}
void clearPerson(struct AddressBooks *abs) {
	cout<<"是否真的要清空？" << endl;
	cout << "1----是" << endl;
	cout<<"2----否" << endl;
	char ans = '0';
	while (true){
		cin >> ans;
		if (ans == '1' || ans == '2'){
			if (ans == 1){
				abs->m_Size = 0; //直接置零 清空
				cout << "通讯录已清空" << endl;
			}
				cout << "已取消清空操作！" << endl;
			break;
		}
		cout<<"输入有误，请重新输入！" << endl;
	}
	system("pause");
	system("cls");
}
int main() {
	struct AddressBooks abs;  // 通讯录变量
	abs.m_Size = 0;

	int select = 0;
	while (true){
		mainMenu(); //主菜单

		cin >> select;
		switch (select){
		case 1://添加联系人
			addPerson(&abs);
			break;
		case 2://显示联系人
			showPerson(&abs);
			break;
		case 3://删除联系人
			deletePerson(&abs);
		//{
		//	cout<<"请输入你要删除对象的姓名：" << endl;
		//	string name;
		//	cin >> name;
		//	if ( isExist(&abs,name) == -1){
		//		cout<<"查无此人" << endl;
		//	}
		//	else{
		//		cout << "已查到,下标为：" << isExist(&abs, name) << endl;
		//	}
		//}// 封装防止报错
			//isExist(&abs, name);
			break;
		case 4://查找联系人
			findPerson(&abs);
			break;
		case 5://修改联系人
			modifyPerson(&abs);
			break;
		case 6://清空联系人
			clearPerson(&abs);
			break;
		case 0://退出通讯录
			cout<<"欢迎下次使用！" << endl;
			system("pause");
			return 0;
		default:
			cout<<"请输入正确操作！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	return 0;
}