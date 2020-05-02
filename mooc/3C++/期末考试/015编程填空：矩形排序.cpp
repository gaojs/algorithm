#include <iostream>
#include <set>
using namespace std;

// 在此处补充你的代码
class Rectangle
{
public:
    int a,b,area,premiere;
    
    Rectangle(int c,int d)
    {
        a = c;
        b = d;
        area = a*b;
        premiere = (a+b)*2;
    }
    
    friend bool operator < (const Rectangle& a1, const Rectangle& a2)
    {
        if(a1.area>a2.area)
        {
            return true;
		}
        else if(a1.area == a2.area)
        {
            if(a1.premiere>a2.premiere)
	        {
	            return true;
			}
            else
	        {
	            return false;
			}
        }
        return false;
    }
    
    friend ostream & operator<<(ostream &o, const Rectangle& a1)
    {
        o << a1.area << " "<<a1.premiere;
        return o;
    }
};

struct Comp
{
    bool operator()(const Rectangle& a1, const Rectangle& a2)
    {
        if(a1.premiere<a2.premiere)
        {
            return true;
		}
        else if(a1.premiere == a2.premiere)
        {
            if(a1.area < a2.area)
                return true;
            else
                return false;
        }
        else
            return false;
    }
};
// 在此处补充你的代码

int main() 
{
    multiset<Rectangle> m1;
    multiset<Rectangle, Comp> m2;
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        m1.insert(Rectangle(a, b));
        m2.insert(Rectangle(a, b));
    }
    for (multiset<Rectangle>::iterator it = m1.begin(); it != m1.end(); it++) 
	{
        cout << *it << endl;
    }
    cout << endl;
    for (multiset<Rectangle>::iterator it = m2.begin(); it != m2.end(); it++) 
	{
        cout << *it << endl;
    }
	return 0;
}
