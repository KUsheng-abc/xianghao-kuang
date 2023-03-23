#include "iostream"
#define MAX 100
//using namespace std;

typedef struct shuju{
	std::string xingming;
	std::string xingbie;
}shuzu;

typedef struct jiedian{
	jiedian* next;
	shuju data;	
}*jiedian1;

typedef struct {
	jiedian1 front;
	jiedian1 rear;
}duilie;

int main() {
	duilie nan = { NULL };
	duilie nv = { NULL };
	
	std::string jieshou1 = "0";
	std::string jieshou2 = "0";
	jiedian1 L;
	int nanpanduan = 0;
	int nvpanduan = 0;
	int lunshu = 0;
	std::cout << "������е��������" << std::endl;
	std::cin >> lunshu;
	for (int i = 0; i < lunshu; i++) {
		shuzu zu[MAX] = {"0"};
		std::cout << "�����" << i + 1 << "�ֵ�������Ϣ" << std::endl;
		//������������	o
		for (int i = 0; i < 100; i++) {
			std::cout << "�����" << i + 1 << "�����ߵ�����" << std::endl;
			std::cin >> jieshou1;
			if (jieshou1 == "0") {
				break;
			}
			zu[i].xingming = jieshou1;
			std::cout << "�����" << i + 1 << "�����ߵ��Ա�" << std::endl;
			std::cin >> jieshou2;
			if (jieshou2 == "0") {
				break;
			}
			zu[i].xingbie = jieshou2;
		}
		//�����߰��Ա�ֶ���
		for (int i = 0; i < 100; i++) {
			if (zu[i].xingming.empty() || zu[i].xingbie.empty()) {
				break;
			}
			//std::cout << zu[i].xingming << zu[i].xingbie << std::endl;
			if (zu[i].xingbie == "��" && nanpanduan == 0) {
				L = new jiedian;
				L->data = zu[i];
				L->next = NULL;
				nan.front = L;
				nan.rear = L;
				nanpanduan++;
			}
			else if (zu[i].xingbie == "��" && nanpanduan != 0) {
				L = new jiedian;
				L->data = zu[i];
				L->next = NULL;
				nan.front->next = L;
				nan.front = L;
				nanpanduan++;
			}
			else if (zu[i].xingbie == "Ů" && nvpanduan == 0) {
				L = new jiedian;
				L->data = zu[i];
				L->next = NULL;
				nv.front = L;
				nv.rear = L;
				nvpanduan++;
			}
			else  if (zu[i].xingbie == "Ů" && nvpanduan != 0) {
				L = new jiedian;
				L->data = zu[i];
				L->next = NULL;
				nv.front->next = L;
				nv.front = L;
				nvpanduan++;
			}
		}
		//����Ůһ�����
		while (nan.rear && nv.rear) {
			jiedian* r = NULL;
			jiedian* t = NULL;
			r = nan.rear;
			t = nv.rear;
			std::cout << "��Ů�������" << std::endl;
			std::cout << "�У�" << nan.rear->data.xingming <<"Ů��" << nv.rear->data.xingming << std::endl;
			nan.rear = nan.rear->next;
			nv.rear = nv.rear->next;
			delete(r);
			delete(t);
			nanpanduan--;
			nvpanduan--;
		}
		//��ʣ����Ա�����ִ�ӡ����
		if (nan.rear == NULL && nv.rear == NULL) {
			std::cout << "û��ʣ����Ա" << std::endl;
		}
		else {
			std::cout << "���ʣ����Ա����" << std::endl;
			if (nan.rear == NULL) {
				std::cout << "Ů��" << std::endl;
				jiedian* p;
				p = nv.rear;
				while (p) {
					std::cout << p->data.xingming << std::endl;
					p = p->next;
				}
			}
			else if (nv.rear == NULL) {
				std::cout << "�У�" << std::endl;
				jiedian* p;
				p = nan.rear;
				while (p) {
					std::cout << p->data.xingming << std::endl;
					p = p->next;
				}
			}
		}
		std::cout << "��" << i + 1 << "��������";
	}
	return 0;
}