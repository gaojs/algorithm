#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
using namespace std;

const int WARRIOR_NUM=5;

class Camp;
class Warrior {
	private:
		Camp *pc; //˾�
		int kind; //��ʿ�������� 0 dragon 1 ninja 2 iceman 3 lion 4 wolf
		int no; //��ʿʵ���ı�� ��0��ʼ����
	public:
		static string name[WARRIOR_NUM];
		static int health[WARRIOR_NUM];

		Warrior(Camp *pCamp,int no_,int kind_) {
			pc=pCamp;
			no=no_;
			kind= kind_;
		}
		void Print(int time);
};
 
class Camp {
	private:
		int total; //��ʿ����
		int health; //����ֵ
		int color; //0-red, 1-blue
		int id;//��ǰҪ�������ʿ�����������еĵڼ���
		int warrior[WARRIOR_NUM];//���ÿ����ʿ������
		Warrior *pWarrior[1000];

	public:
		friend class Warrior;
		static int Seq[2][WARRIOR_NUM]; //��ʿ������˳������

		void Init(int color_,int health_) {
			color=color_;
			health=health_;
			total=0;
			id=0;
			memset(warrior, 0, sizeof(warrior));
		}

		~Camp() {
			for(int i=0; i<total; i++) {
				delete pWarrior[i];
			}
		}

		string getColor() {
			if(color) return "blue";
			else return "red";
		}

		bool Produce(int time) {
			int cnt=0;
			for(cnt=0; cnt<WARRIOR_NUM; cnt++) {
				if(Warrior::health[Seq[color][id]]<=health) {
					break;
				}
				id=(id+1)%WARRIOR_NUM;
			};
			if( cnt>=WARRIOR_NUM) {//ֹͣ
				cout.fill('0');
				string cl=getColor();
				cout<<setw(3)<<time<<" "<<cl<<" headquarter stops making warriors"<<endl;
				return false;
			} else { //����ʿ��
				int kind=Seq[color][id];
				warrior[kind]++;
				health-=Warrior::health[kind];
				pWarrior[total]=new Warrior(this,total+1,kind);
				pWarrior[total]->Print(time);
				id=(id+1)%WARRIOR_NUM;
				total++;
				return true;
			}
		}
};

void Warrior::Print(int time) {
	cout.fill('0');
	string color=pc->getColor();
	cout<<setw(3)<<time<<" "<<color<<" "<<name[kind]<<" "<<no;
	cout<<" born with strength "<<health[kind]<<","<<pc->warrior[kind];
	cout<<" "<<name[kind]<<" in "<<color<<" headquarter"<<endl;
}

int Warrior::health[WARRIOR_NUM]= { 0};
string Warrior::name[WARRIOR_NUM]= { "dragon","ninja","iceman","lion","wolf" };
int Camp::Seq[2][WARRIOR_NUM] = { { 2,3,4,1,0 },{3,0,1,2,4} }; //����˾���ʿ������˳������

int main() {
//	freopen("F:\\in.txt","r",stdin);
	int n,m;

	Camp Red,Blue;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cout<<"Case:"<<i<<endl;
		cin>>m;
		for(int i=0; i<WARRIOR_NUM; i++) {
			cin>>Warrior::health[i];
		}
		Red.Init(0,m);
		Blue.Init(1,m);
		bool red=true, blue=true;
		for(int time=0; red||blue; time++) {
			if(red) red=Red.Produce(time);
			if(blue) blue=Blue.Produce(time);
		}
	}
	return 0;
}
