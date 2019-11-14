#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;


const int WEAPON_NUM=3;
class CWeapon { //武器
	public:
		CWeapon() {
		}
		virtual string getName() {
			return "weapon";
		}
};
 
class CSword:public CWeapon {
	public:
		virtual string getName() {
			return "sword";
		}
};

class CBomb:public CWeapon {
	public:
		virtual string getName() {
			return "bomb";
		}
};

class CArrow:public CWeapon {
	public:
		virtual string getName() {
			return "arrow";
		}
};

const int SOLDIER_NUM=5;
class CSoldier { //武士
	public:
		int no; //编号
		int life; //生命值
		int attack; //攻击力

		CSoldier(int no) {
			this->no=no;
			this->attack=0;
		}
		virtual ~CSoldier() {
		}

		virtual string getName() {
			return "soldier";
		}
		
		virtual void printWeapon(){
		}

		int getNo() {
			return no;
		}
		int getLife() {
			return life;
		}
};

class CDragon:public CSoldier {
	public:
		static int origin_life;
		float morale; //士气
		CWeapon *pw; //武器

		CDragon(int no, float morale):CSoldier(no) {
			this->life=this->origin_life;
			this->morale = morale;
			switch(no%3) {
				case 0:
					pw= new CSword();
					break;
				case 1:
					pw= new CBomb();
					break;
				case 2:
					pw= new CArrow();
					break;
			}
		}
		~CDragon() {
			if(pw) delete pw;
		}
		void printWeapon(){
			cout<<"It has a "<<pw->getName();
			cout<<",and it's morale is ";
			cout<<fixed<<setprecision(2)<<morale<<endl;
		}
		string getName() {
			return "dragon";
		}
};
int CDragon::origin_life=0;

class CNinja:public CSoldier {
	public:
		static int origin_life;
		CWeapon *pw1,*pw2;

		CNinja(int no):CSoldier(no) {
			this->life=this->origin_life;
			switch(no%3) {
				case 0:
					pw1= new CSword();
					pw2= new CBomb();
					break;
				case 1:
					pw1= new CBomb();
					pw2= new CArrow();
					break;
				case 2:
					pw1= new CArrow();
					pw2= new CSword();
					break;
			}
		}
		~CNinja() {
			if(pw1)delete pw1;
			if(pw2)delete pw2;
		}
		void printWeapon(){
			cout<<"It has a "<<pw1->getName();
			cout<<" and a "<<pw2->getName()<<endl;
		}
		string getName() {
			return "ninja";
		}
};
int CNinja::origin_life=0;

class CIceman:public CSoldier {
	public:
		static int origin_life;
		CWeapon *pw; //武器

		CIceman(int no):CSoldier(no) {
			this->life=this->origin_life;
			switch(no%3) {
				case 0:
					pw= new CSword();
					break;
				case 1:
					pw= new CBomb();
					break;
				case 2:
					pw= new CArrow();
					break;
			}
		}
		~CIceman() {
			if(pw) delete pw;
		}
		void printWeapon(){
			cout<<"It has a "<<pw->getName()<<endl;
		}
		string getName() {
			return "iceman";
		}
};
int CIceman::origin_life=0;

class CLion:public CSoldier {
	public:
		static int origin_life;
		int loyalty; //忠诚度

		CLion(int no, int loyalty):CSoldier(no) {
			this->life=this->origin_life;
			this->loyalty=loyalty;
		}
		void printWeapon(){
			cout<<"It's loyalty is "<<loyalty<<endl;
		}
		string getName() {
			return "lion";
		}
};
int CLion::origin_life=0;

class CWolf:public CSoldier {
	public:
		static int origin_life;
		CWolf(int no):CSoldier(no) {
			this->life=this->origin_life;
		}
		string getName() {
			return "wolf";
		}
};
int CWolf::origin_life=0;

class CHeadQuarter { //司令部
	public:
		vector<CSoldier*> list; //soldier_list
		int dragon,ninja,iceman,lion,wolf;
		int index; //生成序号
		int life; //生命元。
		int no; //战士编号

		CHeadQuarter(int l):life(l),no(0) {
			dragon=ninja=iceman=lion=wolf=0;
			index=0;
		}

		~CHeadQuarter() {
			for (vector<CSoldier*>::iterator it=list.begin();
			        it!=list.end(); it=list.erase(it)) {
				delete *it;
			}
		}

		void Print(CSoldier*ps, int count, string type, int next_index) {
			cout<<ps->getName()<<" "<<ps->getNo()<<" born with strength "<<ps->getLife();
			cout<<","<<count<<" "<<ps->getName()<<" in "<<type<<" headquarter"<<endl;
			ps->printWeapon();
			index=(next_index)%SOLDIER_NUM;
			list.push_back(ps);
		}

		virtual CSoldier* Create(int time) =0;
};

class CRedHeadQuarter:public CHeadQuarter { //红司令部
	public:
		CRedHeadQuarter(int life):CHeadQuarter(life) {
			list.clear();
		}

		void Print(CSoldier*ps, int count, int next_index)	{
			CHeadQuarter::Print(ps,count,"red",next_index);
		}

		//CIceman, CLion, CWolf, CNinja, CDragon
		CSoldier* Create(int time) {
			CSoldier*ps=NULL;

			cout.fill('0');
			cout<<setw(3)<<time<<" red ";
			for(int i=0; i<SOLDIER_NUM; i++) {
				switch((index+i)% SOLDIER_NUM) {
					case 0:
						if(life>=CIceman::origin_life) {
							life-= CIceman::origin_life;
							ps = new CIceman(++no);
							Print(ps, ++iceman,1);
							return ps;
						}
					case 1:
						if(life>=CLion::origin_life) {
							life-= CLion::origin_life;
							ps =  new CLion(++no,life);
							Print(ps, ++lion,2);
							return ps;
						}
					case 2:
						if(life>=CWolf::origin_life) {
							life-= CWolf::origin_life;
							ps = new CWolf(++no);
							Print(ps, ++wolf,3);
							return ps;
						}
					case 3:
						if(life>=CNinja::origin_life) {
							life-= CNinja::origin_life;
							ps = new CNinja(++no);
							Print(ps, ++ninja,4);
							return ps;
						}
					case 4:
						if(life>=CDragon::origin_life) {
							life-= CDragon::origin_life;
							float morale=(float)life/CDragon::origin_life;
							ps = new CDragon(++no, morale);
							Print(ps, ++dragon,5);
							return ps;
						}
				}
			}
			cout<<"headquarter stops making warriors"<<endl;
			return NULL;
		}
};

class CBlueHeadQuarter:public CHeadQuarter { //蓝司令部
	public:
		CBlueHeadQuarter(int life):CHeadQuarter(life) {
		}

		void Print(CSoldier*ps, int count, int next_index) {
			CHeadQuarter::Print(ps,count,"blue",next_index);
		}


		//CLion, CDragon, CNinja, CIceman, CWolf
		CSoldier* Create(int time) {
			CSoldier*ps=NULL;

			cout.fill('0');
			cout<<setw(3)<<time<<" blue ";
			for(int i=0; i<SOLDIER_NUM; i++) {
				switch((index+i)% SOLDIER_NUM) {
					case 0:
						if(life>=CLion::origin_life) {
							life-= CLion::origin_life;
							ps= new CLion(++no,life);
							Print(ps, ++lion,1);
							return ps;
						}
					case 1:
						if(life>=CDragon::origin_life) {
							life-= CDragon::origin_life;
							float morale=(float)life/CDragon::origin_life;
							ps= new CDragon(++no,morale);
							Print(ps, ++dragon,2);
							return ps;
						}
					case 2:
						if(life>=CNinja::origin_life) {
							life-= CNinja::origin_life;
							ps= new CNinja(++no);
							Print(ps, ++ninja,3);
							return ps;
						}
					case 3:
						if(life>=CIceman::origin_life) {
							life-= CIceman::origin_life;
							ps= new CIceman(++no);
							Print(ps, ++iceman,4);
							return ps;
						}
					case 4:
						if(life>=CWolf::origin_life) {
							life-= CWolf::origin_life;
							ps= new CWolf(++no);
							Print(ps, ++wolf,5);
							return ps;
						}
				}
			}
			cout<<"headquarter stops making warriors"<<endl;
			return NULL;
		}
};

int main() {
	int n,m,dragon,ninja,iceman,lion,wolf;

	cin>>n;

	for(int i=0; i<n; i++) {
		cout<<"Case:"<<(i+1)<<endl;

		cin>>m;
		cin>>dragon>>ninja>>iceman>>lion>>wolf;
		CDragon::origin_life=dragon;
		CNinja::origin_life=ninja;
		CIceman::origin_life=iceman;
		CLion::origin_life=lion;
		CWolf::origin_life=wolf;

		CRedHeadQuarter *pRed=new CRedHeadQuarter(m);
		CBlueHeadQuarter *pBlue=new CBlueHeadQuarter(m);

		bool red=true, blue=true;
		for(int time=0; red||blue; time++) {
			if(pRed!=NULL && red) {
				CSoldier *ps=pRed->Create(time);
				if(!ps) {
					red=false;
				}
			}
			if(pBlue!=NULL && blue) {
				CSoldier *ps=pBlue->Create(time);
				if(!ps) {
					blue=false;
				}
			}
		}
		delete pRed;
		delete pBlue;
	}
}
