#pragma once
#include <iostream>
#include <fstream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;
#define FILENAME "empFile.txt"

class WorkManager {
public:
	WorkManager();

	// 菜单功能
	void Show_Menu();

	// 退出功能
	void ExitSystem();

	// 记录职工人数
	int m_EmpNum;
	
	// 职工数组指针
	Worker** m_EmpArray;

	// 判断文件是否为空
	bool m_FileIsEmpty;

	// 统计文件中人数
	int get_EmpNum();

	// 初始化员工
	void init_Emp();

	// 显示职工
	void Show_Emp();

	// 添加职工
	void Add_Emp();

	// 判断职工是否存在
	int IsExist(int id);

	// 删除职工
	void Del_Emp();

	// 修改职工
	void Mod_Emp();

	// 查找职工
	void Find_Emp();

	// 员工排序
	void Sort_Emp();

	// 清空
	void Clean_Emp();

	// 保存文件
	void save();

	~WorkManager();
};
