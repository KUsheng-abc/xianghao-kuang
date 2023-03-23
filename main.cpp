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
	std::cout << "输入进行的舞会轮数" << std::endl;
	std::cin >> lunshu;
	for (int i = 0; i < lunshu; i++) {
		shuzu zu[MAX] = {"0"};
		std::cout << "输入第" << i + 1 << "轮的舞者信息" << std::endl;
		//输入舞者数据	o
		for (int i = 0; i < 100; i++) {
			std::cout << "输入第" << i + 1 << "个舞者的姓名" << std::endl;
			std::cin >> jieshou1;
			if (jieshou1 == "0") {
				break;
			}
			zu[i].xingming = jieshou1;
			std::cout << "输入第" << i + 1 << "个舞者的性别" << std::endl;
			std::cin >> jieshou2;
			if (jieshou2 == "0") {
				break;
			}
			zu[i].xingbie = jieshou2;
		}
		//将舞者按性别分队列
		for (int i = 0; i < 100; i++) {
			if (zu[i].xingming.empty() || zu[i].xingbie.empty()) {
				break;
			}
			//std::cout << zu[i].xingming << zu[i].xingbie << std::endl;
			if (zu[i].xingbie == "男" && nanpanduan == 0) {
				L = new jiedian;
				L->data = zu[i];
				L->next = NULL;
				nan.front = L;
				nan.rear = L;
				nanpanduan++;
			}
			else if (zu[i].xingbie == "男" && nanpanduan != 0) {
				L = new jiedian;
				L->data = zu[i];
				L->next = NULL;
				nan.front->next = L;
				nan.front = L;
				nanpanduan++;
			}
			else if (zu[i].xingbie == "女" && nvpanduan == 0) {
				L = new jiedian;
				L->data = zu[i];
				L->next = NULL;
				nv.front = L;
				nv.rear = L;
				nvpanduan++;
			}
			else  if (zu[i].xingbie == "女" && nvpanduan != 0) {
				L = new jiedian;
				L->data = zu[i];
				L->next = NULL;
				nv.front->next = L;
				nv.front = L;
				nvpanduan++;
			}
		}
		//将男女一次配对
		while (nan.rear && nv.rear) {
			jiedian* r = NULL;
			jiedian* t = NULL;
			r = nan.rear;
			t = nv.rear;
			std::cout << "男女配对名字" << std::endl;
			std::cout << "男：" << nan.rear->data.xingming <<"女：" << nv.rear->data.xingming << std::endl;
			nan.rear = nan.rear->next;
			nv.rear = nv.rear->next;
			delete(r);
			delete(t);
			nanpanduan--;
			nvpanduan--;
		}
		//将剩余人员的名字打印出来
		if (nan.rear == NULL && nv.rear == NULL) {
			std::cout << "没有剩余人员" << std::endl;
		}
		else {
			std::cout << "输出剩余人员姓名" << std::endl;
			if (nan.rear == NULL) {
				std::cout << "女：" << std::endl;
				jiedian* p;
				p = nv.rear;
				while (p) {
					std::cout << p->data.xingming << std::endl;
					p = p->next;
				}
			}
			else if (nv.rear == NULL) {
				std::cout << "男：" << std::endl;
				jiedian* p;
				p = nan.rear;
				while (p) {
					std::cout << p->data.xingming << std::endl;
					p = p->next;
				}
			}
		}
		std::cout << "第" << i + 1 << "轮舞会结束";
	}
	return 0;
}