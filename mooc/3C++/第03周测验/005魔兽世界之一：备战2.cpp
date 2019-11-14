#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
using namespace std;

const int WARRIOR_NUM=5;

class Camp;
class Warrior {
	private:
		Camp *pc; //司令部
		int kind; //武士的种类编号 0 dragon 1 ninja 2 iceman 3 lion 4 wolf
		int no; //武士实例的编号 从0开始递增
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
		int total; //武士总数
		int health; //生命值
		int color; //0-red, 1-blue
		int id;//当前要制造的武士是制造序列中的第几个
		int warrior[WARRIOR_NUM];//存放每种武士的数量
		Warrior *pWarrior[1000];

	public:
		friend class Warrior;
		static int Seq[2][WARRIOR_NUM]; //武士的制作顺序序列

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
			if( cnt>=WARRIOR_NUM) {//停止
				cout.fill('0');
				string cl=getColor();
				cout<<setw(3)<<time<<" "<<cl<<" headquarter stops making warriors"<<endl;
				return false;
			} else { //制作士兵
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
int Camp::Seq[2][WARRIOR_NUM] = { { 2,3,4,1,0 },{3,0,1,2,4} }; //两个司令部武士的制作顺序序列

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
