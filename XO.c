#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
struct node
{
	int data;//shomareh khoneh bazi shodeh ro negah midareh
	node *next;//esharegar be node badi
}*first1,*first2;//first1 baraye player1 va first2 baraye player2
char s[3][3];//character khone ha ro zakhireh mikoneh
char file_directory[]="save.txt";// default directory baraye file bazi
int count;//shomarandeh baraye taeen nobat
int win()
{//moshakhas konandeh barandeh
	int i,j,n;
	if(s[0][0]==s[0][1]&&s[0][1]==s[0][2]&&s[0][2]!=0)
		return s[0][0];
	else if(s[1][0]==s[1][1]&&s[1][1]==s[1][2]&&s[1][2]!=0)
		return s[1][0];
	else if(s[2][0]==s[2][1]&&s[2][1]==s[2][2]&&s[2][2]!=0)
		return s[2][0];
	else if(s[0][0]==s[1][0]&&s[1][0]==s[2][0]&&s[2][0]!=0)
		return s[0][0];
	else if(s[0][1]==s[1][1]&&s[1][1]==s[2][1]&&s[2][1]!=0)
		return s[0][1];
	else if(s[0][2]==s[1][2]&&s[1][2]==s[2][2]&&s[2][2]!=0)
		return s[0][2];
	else if(s[0][0]==s[1][1]&&s[1][1]==s[2][2]&&s[2][2]!=0)
		return s[0][0];
	else if(s[0][2]==s[1][1]&&s[1][1]==s[2][0]&&s[2][0]!=0)
		return s[0][2];
	for(i=0,n=0;i<3;i++)//moshakhas konandeh mosavi bodan bazi
		for(j=0;j<3;j++)
			if(s[i][j]==0)
				n++;
	if(n==0)
		return 1;
	else
		return 0;
}
void draw_table(int n)
{//rasme mize bazi player1 O    player2 X
	node *p1,*p2;//baraye chape har harekat az ro ye list peyvandi
	if(n==1)
		printf("back to menu:press any key\n\n");
	else
		printf("back to menu:press A\n\n");
	printf("         |         |\n");
	printf("    %c    |    %c    |    %c\n",s[0][0],s[0][1],s[0][2]);
	printf("_________|_________|_________\n");
	printf("         |         |\n");
	printf("    %c    |    %c    |    %c\n",s[1][0],s[1][1],s[1][2]);
	printf("_________|_________|_________\n");
	printf("         |         |\n");
	printf("    %c    |    %c    |    %c\n",s[2][0],s[2][1],s[2][2]);
	printf("         |         |\n");
	for(p1=first1,p2=first2;p1!=0;p1=p1->next)
    {//chape har harekat dar zir
		printf("%dO	",p1->data);
		if(p2!=0)
		{
			printf("%dX	",p2->data);
			p2=p2->next;
		}
	}
	printf("\n");
	if(n==1)
	{//chap barande ya mosavi
		char c=win();
		if(c=='O')
			printf("**********player 1 won**********");
		else if(c=='X')
			printf("**********player 2 won**********");
		else
			printf("----------draw----------");
	}
	else
	{//chap nobat
		if(count%2==0)
			printf("player 1\n");
		else
			printf("player 2\n");
	}
}
void fill_s(int n,char c)
{//in tabe araye s ro tebghe bazi player meghdar mideh
	switch(n)
	{
		case 1:
			s[0][0]=c;
			break;
		case 2:
			s[0][1]=c;
			break;
		case 3:
			s[0][2]=c;
			break;
		case 4:
			s[1][0]=c;
			break;
		case 5:
			s[1][1]=c;
			break;
		case 6:
			s[1][2]=c;
			break;
		case 7:
			s[2][0]=c;
			break;
		case 8:
			s[2][1]=c;
			break;
		case 9:
			s[2][2]=c;
			break;
	}
}
node *cnode(int move)
{//yek node misazeh
	node *n=(node*)malloc(sizeof(node));
	n->data=move;
	n->next=0;
	return n;
}
node *addnode(node *first,node *add)
{//node jadid ro be entahaye list ezafe mikone
	if(first==0)
		return add;
	node *p;
	for(p=first;p->next!=0;p=p->next);
	p->next=add;
	return first;
}
int is_empty(int n)
{//age khoneh n khali bood return 1 else return 0
	switch(n){
		case 1:
			if(s[0][0]==0)
				return 1;
			else
				return 0;
		case 2:
			if(s[0][1]==0)
				return 1;
			else
				return 0;
		case 3:
			if(s[0][2]==0)
				return 1;
			else
				return 0;
		case 4:
			if(s[1][0]==0)
				return 1;
			else
				return 0;
		case 5:
			if(s[1][1]==0)
				return 1;
			else
				return 0;
		case 6:
			if(s[1][2]==0)
				return 1;
			else
				return 0;
		case 7:
			if(s[2][0]==0)
				return 1;
			else
				return 0;
		case 8:
			if(s[2][1]==0)
				return 1;
			else
				return 0;
		case 9:
			if(s[2][2]==0)
				return 1;
			else
				return 0;
	}
}
int play_player1(int n)
{//baraye player1 bazi mikone
	char c='O';
	int move;//khone ee ke bayad entekhab beshe
	while(1)
    {
		if(n==0)
			move=getch()-48;
		else
			move=n;
		if(!is_empty(move))//jologiri az bazi kardaneh yek khoneh bishtar az yek bar
			continue;
		if(move=='a'-48)//baraye bargasht be menu
			return 0;
		first1=addnode(first1,cnode(move));
		fill_s(move,c);
		break;
	}
	return 1;
}
int play_player2(int n)
{//mesle play_player1()
	char c='X';
	int move;
	if(n==0)
		move=getch()-48;
	else
		move=n;
	if(move=='a'-48)
		return 0;
	first2=addnode(first2,cnode(move));
	fill_s(move,c);
	return 1;
}
void save()
{//zakhire kardane etelaat bazi to file save.txt
	FILE *f=fopen(file_directory,"w");
	node *p;
	fprintf(f,"%d\n",count);//zakhireh nobat
	for(p=first1;p!=0;p=p->next)
		fprintf(f,"%dO ",p->data);
	for(p=first2;p!=0;p=p->next)
		fprintf(f,"%dX ",p->data);
	fclose(f);
}
void remove_list(node *first)
{//baraye halat restart bazi
	if(first==0)
		return;
	node *p,*cp;
	while(first->next!=0)
    {//ba hazf kardane node ha list ro hazf mikoneh
		for(p=first;p->next!=0;cp=p,p=p->next);
		free(p);
		cp->next=0;
	}
	free(first);
}
void load()
{//baraye halat edame bazi
	FILE *f=fopen(file_directory,"r");//file save.txt ro baraye khondane etelaat baz mikoneh
	if(!f)
		return;
	if(first1==0&&first2==0)
    {//khondane etelaat az file
		int n;
		char c;
		fscanf(f,"%d\n",&count);
		while(!feof(f))
		{
			fscanf(f,"%d%c ",&n,&c);
			if(c=='O')
				play_player1(n);
			else if(c=='X')
				play_player2(n);
			fill_s(n,c);
		}
	}
	fclose(f);
}
void restart()
{//restart kardaneh bazi
	count=0;
	remove(file_directory);//hazfe file
	int i;
	for(i=1;i<10;i++)//khali kardane miz bazi
		fill_s(i,0);
	remove_list(first1);
	remove_list(first2);
	first1=first2=0;
}
int attack()
{//talash system baray bord
//dar har radif ya soton ya ghotr agar faght yek khaneh khali az X bod on ro por mikoneh
	int i;
	if(s[0][0]==s[1][1]&&s[0][0]=='X'&&s[2][2]==0)
    {
		play_player2(9);
		return 1;
	}
	else if(s[2][2]==s[1][1]&&s[2][2]=='X'&&s[0][0]==0)
	{
		play_player2(1);
		return 1;
	}
	else if(s[0][2]==s[1][1]&&s[0][2]=='X'&&s[2][0]==0)
	{
		play_player2(7);
		return 1;
	}
	else if(s[2][0]==s[1][1]&&s[2][0]=='X'&&s[0][2]==0)
	{
		play_player2(3);
		return 1;
	}
	for(i=0;i<3;i++)
		if(s[i][0]==s[i][1]&&s[i][0]=='X'||s[i][0]==s[i][2]&&s[i][0]=='X'||s[i][1]==s[i][2]&&s[i][1]=='X')
		{
			if(s[i][0]==0)
			{
				play_player2((3*i)+1);
				return 1;
			}
			else if(s[i][1]==0)
			{
				play_player2((3*i)+2);
				return 1;
			}
			else if(s[i][2]==0)
			{
				play_player2((3*i)+3);
				return 1;
			}
		}
	for(i=0;i<3;i++)
		if(s[0][i]==s[1][i]&&s[0][i]=='X'||s[0][i]==s[2][i]&&s[0][i]=='X'||s[1][i]==s[2][i]&&s[1][i]=='X')
		{
			if(s[0][i]==0)
			{
				play_player2(i+1);
				return 1;
			}
			else if(s[1][i]==0)
			{
				play_player2(i+4);
				return 1;
			}
			else if(s[2][i]==0)
			{
				play_player2(i+7);
				return 1;
			}
		}
	return 0;
}
int defense()
{//talash system baraye nabakhtan
//dar har radif ya soton ya ghotr agar faghat yek khone khali az O bod on ro ba X por mikoneh ta joloye bakht ro begireh
	int rand1,i;
	if(s[1][1]!=0)
    {//age player1 ba bazi kardane yeki az gooshe ha barande bshe in tabe jolosho migire
		if(s[0][0]==s[1][1]&&s[2][2]==0)
		{
			play_player2(9);
			return 1;
		}
		else if(s[2][2]==s[1][1]&&s[0][0]==0)
		{
			play_player2(1);
			return 1;
		}
		else if(s[0][2]==s[1][1]&&s[2][0]==0)
		{
			play_player2(7);
			return 1;
		}
		else if(s[2][0]==s[1][1]&&s[0][2]==0)
		{
			play_player2(3);
			return 1;
		}
		if(count==1)
		{//age bar avalesh bod palyer2 random yeki az goshe haro bazi mikoneh
			rand1=rand()%4;
			switch(rand1)
			{
				case 0:
					play_player2(1);
					return 1;
				case 1:
					play_player2(3);
					return 1;
				case 2:
					play_player2(7);
					return 1;
				case 3:
					play_player2(9);
					return 1;
			}
		}
	}
	else if(s[1][1]==0)
	{//age vasat khali bod vasat bazi mikoneh
		play_player2(5);
		return 1;
	}
	for(i=0;i<3;i++)//bazi kardane dar radif ha baraye jologiri az bakht
		if(s[i][0]==s[i][1]&&s[i][0]=='O'||s[i][0]==s[i][2]&&s[i][0]=='O'||s[i][1]==s[i][2]&&s[i][1]=='O')
		{
			if(s[i][0]==0)
			{
				play_player2((3*i)+1);
				return 1;
			}
			else if(s[i][1]==0)
			{
				play_player2((3*i)+2);
				return 1;
			}
			else if(s[i][2]==0)
			{
				play_player2((3*i)+3);
				return 1;
			}
		}
	for(i=0;i<3;i++)//bazi kardan dar soton ha baraye jologiri az bakht
		if(s[0][i]==s[1][i]&&s[0][i]=='O'||s[0][i]==s[2][i]&&s[0][i]=='O'||s[1][i]==s[2][i]&&s[1][i]=='O')
		{
			if(s[0][i]==0)
			{
				play_player2(i+1);
				return 1;
			}
			else if(s[1][i]==0)
			{
				play_player2(i+4);
				return 1;
			}
			else if(s[2][i]==0)
			{
				play_player2(i+7);
				return 1;
			}
		}
	return 0;
}
int level()
{//taeen konandeh sath bazi
	int n;
	printf("1.easy\n2.medium\n3.impossible\n");
	n=getch()-48;
	system("cls");
	return n;
}
void impossible()
{//halati ke system hargez nabazd
	if(!attack())
		if(!defense())
        {
			if(s[1][1]=='O')
			{
				if(s[0][0]==0)
					play_player2(1);
				else if(s[0][2]==0)
					play_player2(3);
				else if(s[2][0]==0)
					play_player2(7);
				else if(s[2][2]==0)
					play_player2(9);
			}
			else
			{
				if(s[0][1]==0)
					play_player2(2);
				else if(s[1][0]==0)
					play_player2(4);
				else if(s[1][2]==0)
					play_player2(6);
				else if(s[2][1]==0)
					play_player2(8);
			}
		}
}
void medium()
{//halat motevaset
	if(count==1)
    {//age player2 harekate avalesh bod bad bazi koneh
		if(s[1][1]=='O')
			play_player2(2);
		else if(s[1][1]==0)
		{
			if(s[0][1]==0)
				play_player2(2);
			else if(s[1][0]==0)
				play_player2(4);
			else if(s[1][2]==0)
				play_player2(6);
			else if(s[2][1]==0)
				play_player2(8);
		}
	}
	else
		impossible();//chon harekat aval ro bad bazi kardeh badi haro impossible bazi mikoneh
}
void easy()
{//halate asan
	if(s[0][0]==0)
		play_player2(1);
	else if(s[0][1]==0)
		play_player2(2);
	else if(s[0][2]==0)
		play_player2(3);
	else if(s[1][0]==0)
		play_player2(4);
	else if(s[1][1]==0)
		play_player2(5);
	else if(s[1][2]==0)
		play_player2(6);
	else if(s[2][0]==0)
		play_player2(7);
	else if(s[2][1]==0)
		play_player2(8);
	else if(s[2][2]==0)
		play_player2(9);
}
void play_system(int l)
{
	switch(l)
	{
		case 1:
			easy();
			break;
		case 2:
			medium();
			break;
		case 3:
			impossible();
			break;
	}
}
void play_players(int m)
{//control konandeh bazi
	int menu,n,l;
	printf("1.countinue\n2.restart\n");
	n=getch()-48;
	if(n==1&&count==0)
		load();
	else if(n==2)
		restart();
	system("cls");
	if(m==1)
		l=level();
	draw_table(0);
	while(win()==0)
    {
		if(count%2==0)
			menu=play_player1(0);
		else
		{
			if(m==2)
				menu=play_player2(0);
			else if(m==1)
				play_system(l);
		}
		system("cls");
		if(menu==0)
		{
			save();
			return;
		}
		count++;
		draw_table(0);
	}
	system("cls");
	draw_table(1);
	save();
	getch();
	system("cls");
}
void play()
{//bazi tak nafare bashe ya 2 nafare
	printf("1.one player\n2.two player\n");
	int n;
	n=getch()-48;
	system("cls");
	switch(n)
	{
		case 1:
			play_players(1);
			break;
		case 2:
			play_players(2);
			break;
	}
}
void color()
{//taghir range safhe
	printf("0.black\n1.blue\n2.green\n3.aqua\n4.red\n5.purple\n6.yellow\n7.white\n");
	int n;
	n=getch()-48;
	system("cls");
	switch(n)
	{
		case 0:
			system("color 07");
			break;
		case 1:
			system("color 17");
			break;
		case 2:
			system("color 27");
			break;
		case 3:
			system("color 37");
			break;
		case 4:
			system("color 47");
			break;
		case 5:
			system("color 57");
			break;
		case 6:
			system("color 67");
			break;
		case 7:
			system("color 70");
			break;
	}
}
void settings()
{
	printf("1.color\n2.change file directory\n");
	int n;
	n=getch()-48;
	system("cls");
	switch(n)
	{
		case 1:
			color();
			break;
		case 2:
			gets(file_directory);//gereftaneh directory jadid
			system("cls");
			break;
	}
}
void about()
{
    printf("name: farhad nasri\n");
    printf("student id: 961113001\n");
    printf("email: farhadnasri999@gmail.com\n");
    printf("telegram id: @farhadnasri");
    getch();
    system("cls");
}
int main()
{
	srand(time(0));
	int n;
	for(;;)
    {
		printf("1.paly\n2.settings\n3.about\n4.exit\n");
		n=getch()-48;
		system("cls");
		switch(n)
		{
			case 1:
				play();
				break;
			case 2:
				settings();
				break;
			case 3:
				about();
				break;
			case 4:
				exit(0);
				break;
		}
	}
}
