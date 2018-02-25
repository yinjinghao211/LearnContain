#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	char word;
	int weight;
	struct node *left,*right;
}huffnode;

huffnode * printhuffmantree(huffnode ** f,int n)
{
	int loop,i,k1,k2;
	huffnode *pa;
	for(loop=1;loop<n;loop++)
	{
		for(k1=0;k1<n && f[k1];k1++);
		for(k2=k1+1;k2<n && f[k2];k2++);
		for(i=k2;i<n;i++)
		{
			if(f[i])
			{
				if(f[i]->weight<f[k1]->weight)
				{
					k2=k1;
					k1=i;
				}
				else if(f[i]->weight<f[k2]->weight)
					k2=i;
			}
		}
		pa=(huffnode *)malloc(sizeof(huffnode));
		pa->word='X';
		pa->weight=f[k1]->weight+f[k2]->weight;
		pa->left=f[k1];
		pa->right=f[k2];
		f[k1]=pa;
		f[k2]=NULL;
		
	}
	return pa;
}

void main()
{
	huffnode * root;
	huffnode ** f;
	int i,n,w;
	char ch;
	//����ɭ��
	printf("������Ҷ�Ӹ���\n");
	scanf("%d",&n);
	f=(huffnode **)malloc(n*sizeof(huffnode *));
	for(i=0;i<n;i++)
	{
		printf("�������ַ�:\n");
		f[i]=(huffnode *)malloc(sizeof(huffnode));
		f[i]->left=f[i]->right=NULL;
		printf("������Ȩֵ:\n");
		fflush(stdin);//ˢ��
		scanf("%c",&ch);
		scanf("%d",&w);
		f[i]->word=ch;
		f[i]->weight=w;
	}
	
	//����huffman��
	root=printhuffmantree(f,n);
	//���huffmantree
}