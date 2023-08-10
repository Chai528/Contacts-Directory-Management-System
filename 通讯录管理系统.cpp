#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<cstdlib>
#define MAX 1000 //�������
using namespace std;
void mainMenu(){
	cout << "------------------------" << endl;
	cout << "***** 1.������ϵ�� *****" << endl;
	cout << "***** 2.��ʾ��ϵ�� *****" << endl;
	cout << "***** 3.ɾ����ϵ�� *****" << endl;
	cout << "***** 4.������ϵ�� *****" << endl;
	cout << "***** 5.�޸���ϵ�� *****" << endl;
	cout << "***** 6.�����ϵ�� *****" << endl;
	cout << "***** 0.�˳�ͨѶ¼ *****" << endl;
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
		cout<<"�Բ��𣬳������ͨѶ¼�洢�������޷��洢" << endl;
	}
	else{
		//�����ϵ��
		//����
		cout << "������������" << endl;
		string name;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1----��" << endl;
		cout << "2----Ů" << endl;
		int sex = 0;
		while (true){   //�ų��Ƿ�����
			cin >> sex;
			if (sex == 1 || sex == 2){
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "�����������������룡" << endl;
		}
		//����
		cout << "���������䣺" << endl;
		int age;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		//�绰
		cout << "������绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//סַ
		cout << "������סַ��" << endl;
		string addr;
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;
		
		abs->m_Size++; //����ϵͳ����
		cout<<"��ӳɹ���" << endl;
		system("pause");  // ��������˳�
		system("cls");
	}
}
void showPerson(struct AddressBooks* abs) {
	if (abs->m_Size == 0){
		cout << "��ǰ��¼Ϊ�ա�" << endl;
	}
	else{
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "������ " << abs->personArray[i].m_Name << "\t";
			cout << " ���䣺 " << abs->personArray[i].m_Age << "\t";
			cout << " �Ա� " << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";  //��Ŀ�����
			cout << " �绰�� " << abs->personArray[i].m_Phone << "\t";
			cout<<" סַ�� " <<abs->personArray[i].m_Addr<< endl;
		}
	}
	system("pause");
	system("cls");
}
int isExist(struct AddressBooks* abs,string name) {
	for (int i = 0; i < abs->m_Size; i++){
		if (abs->personArray[i].m_Name == name) {
			return i;  // �ҵ�����ˣ��ͷ������������±�
		}
	}
	//���������鶼û���ҵ����ͷ��� -1
	return -1;
}
void deletePerson(struct AddressBooks* abs) {
	cout<<"��������Ҫɾ���Ķ���" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1){ // �鵽��
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		cout<<"ɾ���ɹ���" << endl;
		abs->m_Size--;
	}
	else{
		cout<<"���޴���" << endl;
	}
	system("pause");
	system("cls");
}
void findPerson(struct AddressBooks *abs) {
	cout<<"��������Ҫ���ҵ���ϵ��������" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs,name);
	if (ret != -1){ //�鵽��
		cout << "������ " << abs->personArray[ret].m_Name << "\t";
		cout << " ���䣺 " << abs->personArray[ret].m_Age << "\t";
		cout << " �Ա� " << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";  //��Ŀ�����
		cout << " �绰�� " << abs->personArray[ret].m_Phone << "\t";
		cout << " סַ�� " << abs->personArray[ret].m_Addr << endl;
	}
	else{
		cout<<"���޴��ˣ�" << endl;
	}
	system("pause");
	system("cls");
}
void modifyPerson(struct AddressBooks *abs) {
	cout<<"������Ҫ�޸���ϵ�˵�������" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1){
		//�޸���ϵ����Ϣ
		//����
		cout << "������������" << endl;
		string name;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1----��" << endl;
		cout << "2----Ů" << endl;
		int sex = 0;
		while (true) {   //�ų��Ƿ�����
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "�����������������룡" << endl;
		}
		//����
		cout << "���������䣺" << endl;
		int age;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		//�绰
		cout << "������绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//סַ
		cout << "������סַ��" << endl;
		string addr;
		cin >> addr;
		abs->personArray[ret].m_Addr = addr;

		system("pause");  // ��������˳�
		system("cls");
	}
	else{
		cout<<"���޴���" << endl;
	}
}
void clearPerson(struct AddressBooks *abs) {
	cout<<"�Ƿ����Ҫ��գ�" << endl;
	cout << "1----��" << endl;
	cout<<"2----��" << endl;
	char ans = '0';
	while (true){
		cin >> ans;
		if (ans == '1' || ans == '2'){
			if (ans == 1){
				abs->m_Size = 0; //ֱ������ ���
				cout << "ͨѶ¼�����" << endl;
			}
				cout << "��ȡ����ղ�����" << endl;
			break;
		}
		cout<<"�����������������룡" << endl;
	}
	system("pause");
	system("cls");
}
int main() {
	struct AddressBooks abs;  // ͨѶ¼����
	abs.m_Size = 0;

	int select = 0;
	while (true){
		mainMenu(); //���˵�

		cin >> select;
		switch (select){
		case 1://�����ϵ��
			addPerson(&abs);
			break;
		case 2://��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3://ɾ����ϵ��
			deletePerson(&abs);
		//{
		//	cout<<"��������Ҫɾ�������������" << endl;
		//	string name;
		//	cin >> name;
		//	if ( isExist(&abs,name) == -1){
		//		cout<<"���޴���" << endl;
		//	}
		//	else{
		//		cout << "�Ѳ鵽,�±�Ϊ��" << isExist(&abs, name) << endl;
		//	}
		//}// ��װ��ֹ����
			//isExist(&abs, name);
			break;
		case 4://������ϵ��
			findPerson(&abs);
			break;
		case 5://�޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6://�����ϵ��
			clearPerson(&abs);
			break;
		case 0://�˳�ͨѶ¼
			cout<<"��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
		default:
			cout<<"��������ȷ������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	return 0;
}