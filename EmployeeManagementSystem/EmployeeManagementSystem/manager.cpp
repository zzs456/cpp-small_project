#include "manager.h"

Manager::Manager(int id, string name, int deptId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = deptId;
}
// ��ʾ������Ϣ
void Manager::showInfo() {
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ������ϰ彻�������񣬲��·������Ա��" << endl;
}

// ��ȡ��λ����
string Manager::getDeptName() {
	return string("����");
}