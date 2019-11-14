#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

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

		virtual string getName() {
			return "soldier";
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
		CDragon(int no):CSoldier(no) {
			this->life=this->origin_life;
		}
		string getName() {
			return "dragon";
		}
};
int CDragon::origin_life=0;

class CNinja:public CSoldier {
	public:
		static int origin_life;
		CNinja(int no):CSoldier(no) {
			this->life=this->origin_life;
		}
		string getName() {
			return "ninja";
		}
};
int CNinja::origin_life=0;

class CIceman:public CSoldier {
	public:
		static int origin_life;
		CIceman(int no):CSoldier(no) {
			this->life=this->origin_life;
		}
		string getName() {
			return "iceman";
		}
};
int CIceman::origin_life=0;

class CLion:public CSoldier {
	public:
		static int origin_life;
		CLion(int no):CSoldier(no) {
			this->life=this->origin_life;
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
							ps =  new CLion(++no);
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
							ps = new CDragon(++no);
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
							ps= new CLion(++no);
							Print(ps, ++lion,1);
							return ps;
						}
					case 1:
						if(life>=CDragon::origin_life) {
							life-= CDragon::origin_life;
							ps= new CDragon(++no);
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
//	freopen("F:\\in.txt","r",stdin);
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
