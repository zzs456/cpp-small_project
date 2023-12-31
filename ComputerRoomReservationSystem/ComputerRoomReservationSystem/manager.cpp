#include "manager.h"

// 无参构造
Manager::Manager() {

}

// 有参构造
Manager::Manager(string name, string pwd) {
	this->m_Name = name;
	this->m_Pwd = pwd;
	this->initVector();
	// 初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE,ios::in);
	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum) {
		vCom.push_back(com);
	}
	ifs.close();
}

// 菜单界面
void Manager::openMenu() {
	cout << "欢迎管理员 " + this->m_Name << " 登录！" << endl;
	cout << "\t\t ---------------------- \n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      1.添加账号      |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      2.查看账号      |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      3.查看机房      |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      4.清空预约      |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      0.注销登录      |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t ---------------------- \n";
	cout << "请输入您的选择：" << endl;
}

// 添加账号
void Manager::addPerson() {
	cout << "请输入添加账号的类型：" << endl;
	cout << "1.添加学生" << endl;
	cout << "2.添加教师" << endl;
	string fileName;	// 操作文件名
	string tip;
	string errorTip;
	ofstream ofs;
	int select = 0;
	cin >> select;
	if (select == 1) {
		fileName = STUDENT_FILE;
		tip = "请输入学号：";
		errorTip = "学号重复，请重新输入：";
	}
	else {
		fileName = TEACHER_FILE;
		tip = "请输入职工编号：";
		errorTip = "职工编号重复，请重新输入：";
	}
	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	while (true) {
		cin >> id;
		bool ret = this->checkRepeat(id,select);
		if (ret) {
			cout << errorTip << endl;
		}
		else {
			break;
		}
	}
	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;

	// 向文件中添加数据
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功！" << endl;
	system("pause");
	system("cls");
	ofs.close() ;
	this->initVector();
}

// 学生信息
void printStudent(Student& s) {
	cout << "学号：" << s.m_Id << " 姓名：" << s.m_Name << endl;
}

// 教师信息
void printTeacher(Teacher& t) {
	cout << "职工编号：" << t.m_Id << " 姓名：" << t.m_Name << endl;
}

// 查看账号
void Manager::showPerson() {
	cout << "请选择查看内容：" << endl;
	cout << "1.查看所有学生" << endl;
	cout << "2.查看所有教师" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		cout << "所有学生信息如下：" << endl;
		for_each(vStu.begin(),vStu.end(),printStudent);
	}
	else {
		cout << "所有教师信息如下：" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}

// 查看机房信息
void Manager::showComputer() {
	cout << "机房信息如下：" << endl;
	for (auto it = vCom.begin(); it != vCom.end();it ++) {
		cout << "机房编号：" << it->m_ComId << " 机房最大容量：" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

// 清空预约记录
void Manager::cleanFile() {
	ofstream ofs(ORDER_FILE,ios::trunc);
	ofs.close();
	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}

// 初始化容器
void Manager::initVector() {
	ifstream ifs;
	vStu.clear();
	vTea.clear();
	ifs.open(STUDENT_FILE,ios::in);
	if (!ifs.is_open()) {
		
	}
	else {
		Student s;
		while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd) {
			vStu.push_back(s);
		}
	}
	ifs.close();
	ifs.open(TEACHER_FILE,ios::in);
	if (!ifs.is_open()) {
		return;
	}
	else {
		Teacher t;
		while (ifs >> t.m_Id && ifs >> t.m_Name && ifs >> t.m_Pwd) {
			vTea.push_back(t);
		}
	}
	ifs.close();
}

// 检测重复
bool Manager::checkRepeat(int id, int type) {
	if (type == 1) {
		for (auto it = vStu.begin(); it != vStu.end();it ++) {
			if (id == it->m_Id) {
				return true;
			}
		}
	}
	else {
		for (auto it = vTea.begin(); it != vTea.end(); it++) {
			if (id == it->m_Id) {
				return true;
			}
		}
	}
	return false;
}