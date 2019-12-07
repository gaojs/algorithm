//构造二叉树 3-20-7
//构造二叉树 \9 \15
//preorder=[3,9,20,15,7]
//inorder=[9,3,15,20,7] 
#include <iostream>
using namespace std;

struct BinTree
{
	int node; //节点信息 
	
	BinTree *left;
	BinTree *right;
	
	BinTree()
	{
		node=-1; //无效值 
		left=NULL;
		right=NULL;
	}
};

BinTree* create(int *pre, int *in, int n)
{//构造二叉树 
	if(n>0)
	{
		//int pre[]={3, 9, 20,15,7}; n=5
		//int in[]={[9, 3, 15,20,7}; m=1
		int t = pre[0], m=0;		
		for(m=0; m<n; m++)
		{
			if(t==in[m])
			{
				break;
			}
		}
		
		//cout<<pre[0]<<" ";
		BinTree* pBinTree = new BinTree;
		pBinTree->node=pre[0];
		
		pBinTree->left=create(pre+1, in, m);	
		pBinTree->right=create(pre+m+1, in+m+1, n-m-1);
		return pBinTree;
	} 
	return NULL; 
}

void post(const BinTree* pBinTree) 
{//后序遍历 
	if(pBinTree!=NULL)
	{
		post(pBinTree->left);
		post(pBinTree->right);
		cout<<pBinTree->node<<" ";
	}
} 

void destroy(BinTree*& pBinTree) 
{//销毁二叉树 //后序遍历 
	if(pBinTree!=NULL)
	{
		destroy(pBinTree->left);
		destroy(pBinTree->right);
		cout<<pBinTree->node<<" ";
		delete pBinTree; 
		pBinTree=NULL;
	}
} 

int main()
{
	int pre[]={3,9,20,15,7}; //先序遍历 
	int in[]={9,3,15,20,7};	//中序遍历 
	int n=sizeof(pre)/sizeof(pre[0]);
	BinTree *pBinTree=create(pre, in, n);
	cout<<"pre order: "; 
	for(int i=0;i<n;i++) cout<<pre[i]<<" ";
	cout<<endl<<"in order: "; 
	for(int i=0;i<n;i++) cout<<in[i]<<" ";
	cout<<endl<<"post order: "; 
	post(pBinTree);
	cout<<endl<<"destroy: "; 
	destroy(pBinTree); 
	return 0;
}

