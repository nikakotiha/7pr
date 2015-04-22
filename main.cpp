




//#include "stdlib.h"
//#include <math.h>
//#include "locale"

//#include "vld.h"

typedef
	struct ListItem * PtrListItem;
struct ListItem
{
	int Z;
	PtrListItem n;
};


void ShowList(PtrListItem List)
{
	if (List!=NULL)
		printf("%c",'|');
	while (List!=NULL)
	{
		printf("%d %c",List->Z,'|');
		List=List->n;
	}
}

bool Checkdelete(double Number,int asd)
{


	return (int)Number==asd;
}


bool CheckDigitNumber(int Number)
{
	int n= 0;
	while (Number!=0)
	{
		Number/=10;
		n+=1;
	}

	if (n==2)
		return true;
	else
		return false;
}

bool CheckZz(int Z)
{
	return (Z>0);
}

bool Checkmod5(int Z)
{
	return (Z % 5==0);
}

int ProcessingList(PtrListItem *List)
{
	PtrListItem FirstEl=*List;
	PtrListItem CurrentEl=*List;
	PtrListItem Del=NULL;


	int MaxTwo_Digit=0;
	int asd=1;


	while (CurrentEl!=NULL)
	{
		if (Checkdelete(CurrentEl->Z,asd))
		{
			if (Checkmod5(CurrentEl->Z))
			{
				MaxTwo_Digit+=CurrentEl->Z;
				asd+=1;
			}

			Del=FirstEl;
			FirstEl=FirstEl->n;
			free(Del);

			CurrentEl=FirstEl;
		}
		else
			if (CurrentEl->n!=NULL)

				if (Checkdelete(CurrentEl->n->Z,asd))
				{

					if (Checkmod5(CurrentEl->Z))
					{
						MaxTwo_Digit+=CurrentEl->Z;
						asd+=1;
					}
					Del=CurrentEl->n;



					CurrentEl->n=Del->n;

					free(Del);
				}

				else
				{

					if (Checkmod5(CurrentEl->Z)) {
						MaxTwo_Digit+=CurrentEl->Z;
						asd+=1;
					}


					if (CheckZz(CurrentEl->Z))
					{
					PtrListItem Copy=CurrentEl->n;
					CurrentEl->n=(struct ListItem *)malloc(sizeof(ListItem));
					CurrentEl->n->Z=(CurrentEl->Z/10);
					CurrentEl=CurrentEl->n;
					CurrentEl->n=Copy;

					CurrentEl=CurrentEl->n;
					Copy=NULL;
					}
					else
						CurrentEl=CurrentEl->n;

				}
			else
			{
				if (Checkmod5(CurrentEl->Z))
				{
						MaxTwo_Digit+=CurrentEl->Z;
						asd+=1;
				}

				if (CheckZz(CurrentEl->Z))
				{
				PtrListItem Copy=CurrentEl->n;
				CurrentEl->n=(struct ListItem *)malloc(sizeof(ListItem));
				CurrentEl->n->Z=(CurrentEl->Z/10);
				CurrentEl=CurrentEl->n;
				CurrentEl->n=Copy;

				CurrentEl=CurrentEl->n;
				Copy=NULL;
				}
				else
				CurrentEl=CurrentEl->n;
			}
	}



	*List=FirstEl;

	FirstEl=NULL;
	CurrentEl=NULL;
	Del=NULL;

	return MaxTwo_Digit;
}

PtrListItem CreateList()
{
	PtrListItem FirstEl=NULL;
	PtrListItem NFirstEl=NULL;
	bool Compl=false;
	while (!Compl)
	{
		//NFirstEl= FirstEl;
		if (FirstEl==NULL)
		{
			FirstEl=(struct ListItem *)malloc(sizeof(ListItem));
			FirstEl->n=NULL;
			NFirstEl=FirstEl;

		}
		else
		{
			NFirstEl->n=(struct ListItem *)malloc(sizeof(ListItem));
			NFirstEl=NFirstEl->n;
			NFirstEl->n=NULL;

		}

		int p;
		int c;

		scanf("%d",&p);

		printf("%s","Çàêîí÷èòü ââîä?(1,0)");
		scanf("%d",&c);
		Compl=c;

		NFirstEl->Z=p;
	}
	NFirstEl=NULL;
	return FirstEl;
}


void FreeList(PtrListItem List)
{
	PtrListItem Del;
	while (List!=NULL)
	{
		Del=List;
		List=List->n;
		free(Del);
	}
}

int main()
{

	setlocale( LC_ALL,"Russian" );

	PtrListItem List=NULL;
	List=CreateList();

	printf("%s","Èñõîäíûé ñïèñîê:\n");
	ShowList(List);
	printf("%s","\n_____________________________________\n");

	int El=ProcessingList(&List);

	printf("Îáðàáîòàííûé ñïèñîê:\n");
	ShowList(List);
	printf("%s","\n");
	printf("%s","Ñóììà ýëåìåíòîâ, êðàòíûõ 5:");
	//if (El!=-100)
	printf("%d",El,"\n");
	//else
	//	printf("%s","Íå íàéäåí");
	printf("%s","\n_____________________________________");

	FreeList(List);

	getchar();
	getchar();


	return 0;
}
