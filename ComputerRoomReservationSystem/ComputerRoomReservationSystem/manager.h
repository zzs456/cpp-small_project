#pragma once
#include <iostream>
#include "identity.h"
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "computerRoom.h"
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class Manager :public Identity {
public:
	// 无参构造
	Manager();
	// 有参构造
	Manager(string name, string pwd);
	// 菜单界面
	virtual void openMenu();
	// 添加账号
	void addPerson();
	// 查看账号
	void showPerson();
	// 查看机房信息
	void showComputer();
	// 清空预约记录
	void cleanFile();
	// 初始化容器
	void initVector();
	// 学生容器
	vector<Student> vStu;
	// 教师容器
	vector<Teacher> vTea;
	// 机房容器
	vector<ComputerRoom> vCom;
	// 检测重复
	bool checkRepeat(int id, int type);
};