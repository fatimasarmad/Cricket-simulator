/* Name: FATIMA SARMAD
roll no: 21i-1139
section:E*/
#include<iostream>
#include<windows.h>
#include<iomanip>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<fstream>
#include<string.h>
using namespace std;
int turns()
{
    int toss;       //this function returns the toss as 0 or 1 whichever team wins the toss bats first
    toss=rand()%2;
    return toss;	
}
void batting(string bat[],int balls_A[],int score[],int c_b[],int stats[][11])
{
    //displaying the batting score card c_b is the array of current batsmen
    cout<<"\n\nBATSMAN\t\t\tSCORE\t\t\tBalls\t\t\tSIXES\t\t\tFOURS\t\t\tDOTS"<<endl;
    cout<<bat[c_b[0]]<<"\t\t\t"<<score[c_b[0]]<<"\t\t\t"<<balls_A[c_b[0]]<<"\t\t\t"<<stats[0][c_b[0]]<<"\t\t\t"<<stats[1][c_b[0]]<<"\t\t\t"<<stats[2][c_b[0]]<<endl;
    cout<<bat[c_b[1]]<<"\t\t\t"<<score[c_b[1]]<<"\t\t\t"<<balls_A[c_b[1]]<<"\t\t\t"<<stats[0][c_b[1]]<<"\t\t\t"<<stats[1][c_b[1]]<<"\t\t\t"<<stats[2][c_b[1]]<<endl;
}
void bowling(string bowl[],int balls_B[],int score[],int *c_c,int b_wickets[])
{
    //displaying the bowling scored card c_c is the current bowler
    cout<<"BOWLERS\t\t\tSCORE\t\t\tBALLS\t\t\tWICKETS"<<endl;
    cout<<bowl[*c_c]<<"\t\t\t"<<score[*c_c]<<"\t\t\t"<<balls_B[*c_c]<<"\t\t\t"<<b_wickets[*c_c]<<endl;
}
void showrunrate(int *total,int *overs)
{
    //displaying the runrate on the batting score card
    if(*overs==0)
    {
        cout<<"THE CURRENT RUNRATE OF THE TEAM IS 0.0"<<endl<<endl<<endl;
    }
    else if(*overs!=0)
        cout<<"THE CURRENT RUNRATE OF THE TEAM IS "<<(float)((*total)/(*overs))<<endl<<endl<<endl;
}
void showtotal(int *total,int spb,int *wickets)
{
    //this adds up the total
    //sending as pointer so that the total is updated in main too
    *total+=spb;
    cout<<"THE CURRENT SCORE OF THE TEAM IS "<<*total<<"/"<<*wickets<<endl<<endl;
}
void showovers(int *overs,int *balls,int *c_c)
{
    // if balls %6==0 over will be incremented and balls refreshed
    if(*balls%6==0)
    {
        *balls=0;
        *overs+=1;
        bool a=(*c_c<10);
        if(a)
        {
            (*c_c)++;
            cout<<"\nNEW BALLER\n";
        }
        else
            (*c_c)=5;
    }
    cout<<endl<<"CURRENT BOWLER: "<<*c_c+1<<endl;
    cout<<"THE CURRENT OVERS THAT HAVE BEEN BOWLED IN THE INNINGS ARE: "<<*overs<<"."<<*balls<<endl;
}
void showfall(int fall[])
{
    //this shows the fall of wickets in an innings 
    cout<<endl<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<i+1<<"\t";
    }
    cout<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<fall[i]<<"\t";
    }
}
void full_scoreboard(string bat[],int balls_A[],int score[],string ball[],int b_balls_B[],int b_score_B[],int b_wickets[],int stats[][11],int fall[])
{
    //both bowling and batting functions are called here
    cout<<"BATSMAN\t\t\tSCORE\t\t\tBalls\t\t\tSIXES\t\t\tFOURS\t\t\tDOTS"<<endl;
    for(int i=0;i<11;i++)
    {
        cout<<bat[i]<<"\t\t\t"<<score[i]<<"\t\t\t"<<balls_A[i]<<"\t\t\t"<<stats[0][i]<<"\t\t\t"<<stats[1][i]<<"\t\t\t"<<stats[2][i]<<endl;
    }
    cout<<endl<<endl<<"BOWLING STATISTICS:"<<endl<<endl;
    cout<<"BOWLER\t\t\tRUNS\t\t\tBALLS\t\t\tWICKETS"<<endl;
    for(int i=5;i<11;i++)
    {
        cout<<ball[i]<<"\t\t\t"<<b_score_B[i]<<"\t\t\t"<<b_balls_B[i]<<"\t\t\t"<<b_wickets[i]<<endl;
    }
    showfall(fall);
}
void showsummary(string teamA[],int score_A[],string teamB[],int score_B[],int total_A,int total_B,int wickets_A,int wickets_B,int b_score_A[],int b_score_B[],int b_wickets_A[],int b_wickets_B[])
{
    cout<<"BATTING STATS\n\n";
    cout<<"TEAM A\t\t\t\t\t\tTEAM B\n";
    for(int i=0;i<11;i++)
    {
        cout<<teamA[i]<<"\t\t"<<score_A[i]<<"\t\t\t\t"<<teamB[i]<<"\t\t"<<score_B[i]<<"\n";
    }
    cout<<endl<<endl;
    cout<<"BOWLING STATS\n\n";
    for(int i=5;i<11;i++)
    {
        cout<<teamA[i]<<"\t\t"<<b_wickets_A[i]<<"\t\t\t\t"<<teamB[i]<<"\t\t"<<b_wickets_B[i]<<"\n";
    }
    cout<<endl<<endl;
    cout<<"TOTAL OF TEAM A: "<<total_A<<"/"<<wickets_A<<endl;
    cout<<"TOTAL OF TEAM B: "<<total_B<<"/"<<wickets_B<<endl;


}
void scorecard(string bat[],string bowl[],int balls_A[],int balls_B[],int score[],int b_score_B[] ,int c_b[],int *c_c,int *wickets,int *balls,int *overs,int spb,int *total_A,int b_wickets[],int stats[][11])
{ 
    //this shows the small scorecard of the current batsman and bowler only along with total, overs and runrte
    cout<<"********************************************************************"<<endl;   
    batting(bat,balls_A,score,c_b,stats);
    showtotal(total_A,spb,wickets);
    showovers(overs,balls,c_c);
    showrunrate(total_A,overs);
    bowling(bowl,balls_B,b_score_B, c_c,b_wickets);
    cout<<"********************************************************************"<<endl;   

}
bool probable(int current)
{
    //if batsman is from first 5 probaility of scoring is 90%
    //if batsman is not from first 5 probaility of scoring is 50%
    if(current<5)
    {
        bool a=(rand() % 100) < 90;
        return a;
    }
    if(current>=5)
    {
        bool a=(rand() % 100) < 50;
        return a;
    }
}
void innings_1(string teamA[],string teamB[],int n,int strike,int balls_A[],int c_b[],int score_A[],int *wickets_A,int c_c,int b_score_B[],int b_balls_B[],int *balls,int *overs,int *total_A,int stats[][11],int b_wickets[])
{
    
    //this is the code for first innings 
    //first and second innings have different functions as the total of A matters in second innings only
    int scoreperball;
    int fall[11]={0,0,0,0,0,0,0,0,0,0,0};
    for(int i=0;i<n*6;i++)
    {
        //calling the probability function
        bool probability=probable(c_b[0]);
        cout<<endl<<"NEXT BALL WILL BE BOWLED WHEN YOU PRESS ENTER! (ENTER S FOR FULL SCOREBOARD)"<<endl;
        char a;
        a=getchar();
        if(a=='\n')
        {
            system("CLS");
            //strike 0 is c_b[0]
            if(strike==0)
            {
                bool probability=probable(c_b[0]);
                if(probability)
                {
                    scoreperball=rand()%7;
                }
                else
                    scoreperball=-1;
            }
            //strike 1 is c_b[1]

            if(strike==1)
            {
                bool probability=probable(c_b[1]);
                if(probability)
                {
                    scoreperball=rand()%7;
                }
                else
                    scoreperball=-1;
            }
            
            cout<<"THIS BALL HAS GONE FOR A "<<scoreperball<<endl<<endl;
            if(strike==0 && scoreperball!=-1)
            {
                    //these are to increment the stats which stores sixes,fours and maidens in 0,1,2 respectively
                if(scoreperball==6)
                    stats[0][c_b[0]]++;
                if(scoreperball==4)
                    stats[1][c_b[0]]++;
                if(scoreperball==0)
                    stats[2][c_b[0]]++;
                balls_A[c_b[0]]++;  //incrementing balls faced by batsman
                score_A[c_b[0]]+=scoreperball;  //incrementing batsman score
            }   
            else if(strike==1 && scoreperball!=-1)
            {
                //same as above for other batsman   
                if(scoreperball==6)
                    stats[0][c_b[1]]++;
                if(scoreperball==4)
                    stats[1][c_b[1]]++;
                if(scoreperball==0)
                    stats[2][c_b[1]]++;
                balls_A[c_b[1]]++;
                score_A[c_b[1]]+=scoreperball;
            }
            //rotating the strike
            if(scoreperball==1||scoreperball==3||scoreperball==5)
            {
                strike=!strike;
            }
            //conditions for out
            if(scoreperball==-1 )
            {
                fall[(*wickets_A)]=*total_A;        //storingfall of wicket
                (*wickets_A)++;     //incrementing wickets
                b_wickets[c_c]++;   //bwoler stats update
                if(strike%2==0)
                {
                    while(balls_A[c_b[0]]!=0)
                    {
                        c_b[0]+=1;
                    }
                }
                else 
                {
                    while(balls_A[c_b[1]]!=0)
                    {
                        c_b[1]+=1;
                    }
                    
                }
                scoreperball++;
            }
            //incrementing bowler score and balls
            b_score_B[c_c]+=scoreperball;
            b_balls_B[c_c]+=1;
            (*balls)++;
            if(*wickets_A==10)
            {
                cout<<endl<<"ALL OUT!!!"<<endl;
                _getch();
                full_scoreboard(teamA,balls_A,score_A,teamB,b_balls_B,b_score_B,b_wickets,stats,fall);
                break;
            }
            scorecard(teamA,teamB,balls_A,b_balls_B,score_A,b_score_B,c_b,&c_c,wickets_A,balls,overs,scoreperball,total_A,b_wickets,stats);
        }
        if(a=='S' || a=='s')
        {
            full_scoreboard(teamA,balls_A,score_A,teamB,b_balls_B,b_score_B,b_wickets,stats,fall);
            _getch();
        }
    }		
}
void innings_2(string teamA[],string teamB[],int n,int strike,int balls_A[],int c_b[],int score_A[],int *wickets_A,int c_c,int b_score_B[],int b_balls_B[],int *balls,int *overs,int *total_A,int stats[][11],int b_wickets[],int total1)
{
   
    //all comments shall be same as for innings one
    int scoreperball;
    int fall[11]={0,0,0,0,0,0,0,0,0,0,0};
    for(int i=0;i<n*6;i++)
    {
        cout<<endl<<"NEXT BALL WILL BE BOWLED WHEN YOU PRESS ENTER! (ENTER S FOR FULL SCOREBOARD)"<<endl;
        char a;
        a=getchar();
        if(a=='\n')
        {
            system("CLS");
            cout<<"TOTAL OF INNINGS 1 is: "<<total1<<endl;
            if(strike==0)
            {
                bool probability=probable(c_b[0]);
                if(probability)
                {
                    scoreperball=rand()%7;
                }
                else
                    scoreperball=-1;
            }
            if(strike==1)
            {
                bool probability=probable(c_b[1]);
                if(probability)
                {
                    scoreperball=rand()%7;
                }
                else
                    scoreperball=-1;
            }
            cout<<"THIS BALL HAS GONE FOR A "<<scoreperball<<endl<<endl;
            if(strike==0 && scoreperball!=-1)
            {
                if(scoreperball==6)
                    stats[0][c_b[0]]++;
                if(scoreperball==4)
                    stats[1][c_b[0]]++;
                if(scoreperball==0)
                    stats[2][c_b[0]]++;
                balls_A[c_b[0]]++;
                score_A[c_b[0]]+=scoreperball;
            }   
            else if(strike==1 && scoreperball!=-1)
            {
                if(scoreperball==6)
                    stats[0][c_b[1]]++;
                if(scoreperball==4)
                    stats[1][c_b[1]]++;
                if(scoreperball==0)
                    stats[2][c_b[1]]++;
                balls_A[c_b[1]]++;
                score_A[c_b[1]]+=scoreperball;
            }
            if(scoreperball==1||scoreperball==3||scoreperball==5)
            {
                strike=!strike;
            }
            
            if(scoreperball==-1 )
            {
                fall[(*wickets_A)]=*total_A;
                (*wickets_A)++;
                b_wickets[c_c]++;
                if(strike%2==0)
                {
                    while(balls_A[c_b[0]]!=0)
                    {
                        c_b[0]+=1;
                    }
                }
                else 
                {
                    while(balls_A[c_b[1]]!=0)
                    {
                        c_b[1]+=1;
                    }
                    
                }
                scoreperball++;
            }
            b_score_B[c_c]+=scoreperball;
            b_balls_B[c_c]+=1;
            (*balls)++;
            //these scenarios are for if total crossed, if all out, if alls overs bowled
            if(*total_A>total1)
            {
                cout<<endl<<"THE TEAM BATTING SECOND HAS WON THE MATCH"<<endl;
                _getch();
                full_scoreboard(teamA,balls_A,score_A,teamB,b_balls_B,b_score_B,b_wickets,stats,fall);
                break;
            }
            if(i==(n*6)-1)
            {
                cout<<endl<<"THE TEAM BATTING SECOND HAS LOST THE MATCH"<<endl;
                _getch();
                full_scoreboard(teamA,balls_A,score_A,teamB,b_balls_B,b_score_B,b_wickets,stats,fall);
                break;
            }
            if(*wickets_A==10)
            {
                cout<<endl<<"ALL OUT TEAM BATTING SECOND HAS LOST THE MATCH!!!"<<endl;
                _getch();
                full_scoreboard(teamA,balls_A,score_A,teamB,b_balls_B,b_score_B,b_wickets,stats,fall);
                break;
            }
            scorecard(teamA,teamB,balls_A,b_balls_B,score_A,b_score_B,c_b,&c_c,wickets_A,balls,overs,scoreperball,total_A,b_wickets,stats);
        }
        if(a=='S' || a=='s')
        {
            full_scoreboard(teamA,balls_A,score_A,teamB,b_balls_B,b_score_B,b_wickets,stats,fall);
            _getch();
        }
    }		
}
int main()
{
    string teamA[11]={"fatima","Anum","Aiyza","Sohaib","mujtaba","Sarmad","Aisha","Aamir","Ali","Ahmad","Abdul"};//names of players team 1
    string teamB[11]={"Wasim","Shaheen","Babar","Umar","Sanga","Bopara","Rizwan","Mark","Azan","Afridi","Yousuf"};  //names of players team 2
    int score_A[11]={0,0,0,0,0,0,0,0,0,0,0};    //score storage of team A
    int b_score_A[11]={0,0,0,0,0,0,0,0,0,0,0};          //bowling score storage of team A
    int b_balls_A[11]={0,0,0,0,0,0,0,0,0,0,0};          //bowling score storage of team A
    int balls_A[11]={0,0,0,0,0,0,0,0,0,0,0};//balls of faced by batsmen A
    int stats_A[3][11];                 //boundary stats for team A
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<11;j++)
            stats_A[i][j]=0;
    }
    int *b_wickets_A=new int [11];      //use of dynamic memory to store wicket stat of team A
    for(int i=0;i<11;i++)
    {
        b_wickets_A[i]=0;
    }
    int total_A=0;      //batting total of team A
    int overs=0;    //displaying overs team A
    int balls=0;    //displaying balls team A
    int wickets_A=0;

    int c_b[2]={0,1};    //current batsman
    int c_c=5;          //current bowler

    int score_B[11]={0,0,0,0,0,0,0,0,0,0,0};    //score storage of team B
    int b_balls_B[11]={0,0,0,0,0,0,0,0,0,0,0};          //bowling score storage of team A
    int b_score_B[11]={0,0,0,0,0,0,0,0,0,0,0};//bscore given by bowlers team B
    int balls_B[11]={0,0,0,0,0,0,0,0,0,0,0};//balls of faced by batsmen B
    int stats_B[3][11];                 //boundary stats for team B
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<11;j++)
            stats_B[i][j]=0;
    }
    int b_wickets_B[11]={0,0,0,0,0,0,0,0,0,0,0};                //wickets stats for team B
    int total_B=0;      //batting total of team B
    int overs_B=0;    //displaying overs team A
    int ballsB=0;    //displaying balls team A
    int wickets_B=0;
    int toss;
    
    srand(time(0));


    /* this section is for opening the overs file and
        reading the number of overs to be bowled*/
    int n=2;
    string s = "";
    fstream file("overs.txt");//file reading for overs
    getline(file, s);
    n = stoi(s);
    file.close();
    cout<<endl<<"THE NUMBER OF OVERS IN THE GAME ARE: "<<n;
    _getch();
    system("CLS");
    toss=turns();	
    balls_A[1]=1;
    balls_B[1]=1;
    balls++;
    total_A++;
    total_B++;
    ballsB++;
    score_A[1]++;
    score_B[1]++;
    toss=0;
    int strike=0;       //strike is used to define the current batsman facing the ball
    if(toss==0)
    {   
        cout<<"Team A has won the toss"<<endl;
        innings_1(teamA,teamB,n,strike,balls_A,c_b,score_A,&wickets_A,c_c,b_score_B,b_balls_B,&balls,&overs,&total_A,stats_A,b_wickets_B);
        cout<<endl<<"THE TOTAL OF INNINGS A IS: "<<total_A<<endl;       //this shows total of team A
        c_c=5;
        c_b[0]=0;
        c_b[1]=1;
        balls=0;
        overs=0;
        innings_2(teamB,teamA,n,strike,balls_B,c_b,score_B,&wickets_B,c_c,b_score_A,b_balls_A,&balls,&overs,&total_B,stats_B,b_wickets_A,total_A);
        cout<<endl<<endl<<"PRESS ENTER TO VIEW THE MATCH SUMMARY!"<<endl<<endl;
        _getch();
        system("CLS");
        if(total_B>total_A)     //if team B wins then batsman of the match will be from team B
        {
            string name;
            int bat=score_B[0];
            for(int i=0;i<11;i++)
            {
                if(bat<=score_B[i])
                {
                    name=teamB[i];
                    bat=score_B[i];
                }
            }
            cout<<endl<<"THE BATSMAN OF THE MATCH IS "<<name<<" for scoring "<<bat<<" runs"<<endl;
            string name_1;
            int ball=b_wickets_B[0];
            for(int i=0;i<11;i++)           //if team B wins then bowler of the match will be from team B
            {
                if(ball<=b_wickets_B[i])
                {
                    name_1=teamB[i];
                    ball=b_wickets_B[i];
                }
            }
            //these are just simple programs for maximum weickets and score
            cout<<endl<<"THE BOWLER OF THE MATCH IS "<<name_1<<" for taking "<<ball<<" wickets"<<endl;
        }
        if(total_B<total_A)         //if team A wins then batsman of the match will be from team B
        {
            string name;
            int bat=score_A[0];
            for(int i=0;i<11;i++)
            {
                if(bat<=score_A[i])
                {
                    name=teamA[i];
                    bat=score_A[i];
                }
            }
            cout<<endl<<"THE BATSMAN OF THE MATCH IS "<<name<<" for scoring "<<bat<<" runs"<<endl;
            string name_1;
            int ball=b_wickets_A[0];
            for(int i=0;i<11;i++)       //if team A wins then bowler of the match will be from team A
            {
                if(ball<=b_wickets_A[i])
                {
                    name_1=teamA[i];
                    ball=b_wickets_A[i];
                }
            }
            cout<<endl<<"THE BOWLER OF THE MATCH IS "<<name_1<<" for taking "<<ball<<" wickets"<<endl;
        }
            //these are just simple programs for maximum weickets and score

        showsummary(teamA,score_A,teamB,score_B,total_A,total_B,wickets_A,wickets_B,b_score_A,b_score_B,b_wickets_A,b_wickets_B);
        
    }
     //this function is same as above with same comments but different arrays
    //therefore no commenting has been done 
    
    if(toss==1)
    {
        cout<<"Team B has won the toss"<<endl;
        innings_1(teamB,teamA,n,strike,balls_B,c_b,score_B,&wickets_B,c_c,b_score_A,b_balls_A,&balls,&overs,&total_B,stats_B,b_wickets_A);
        cout<<endl<<"THE TOTAL OF INNINGS A IS: "<<total_B<<endl;
        c_c=5;
        c_b[0]=0;
        c_b[1]=1;
        balls=0;
        overs=0;
        innings_2(teamA,teamB,n,strike,balls_A,c_b,score_A,&wickets_A,c_c,b_score_B,b_balls_B,&balls,&overs,&total_A,stats_A,b_wickets_B,total_B);
        
        cout<<endl<<endl<<"PRESS ENTER TO VIEW THE MATCH SUMMARY!"<<endl<<endl;
        _getch();
        system("CLS");
        if(total_B>total_A)
        {
            string name;
            int bat=score_B[0];
            for(int i=0;i<11;i++)
            {
                if(bat<=score_B[i])
                {
                    name=teamB[i];
                    bat=score_B[i];
                }
            }
            cout<<endl<<"THE BATSMAN OF THE MATCH IS "<<name<<" for scoring "<<bat<<" runs"<<endl;
            string name_1;
            int ball=b_wickets_B[0];
            for(int i=0;i<11;i++)
            {
                if(ball<=b_wickets_B[i])
                {
                    name_1=teamB[i];
                    ball=b_wickets_B[i];
                }
            }
            cout<<endl<<"THE BOWLER OF THE MATCH IS "<<name_1<<" for taking "<<ball<<" wickets"<<endl;
        }
        if(total_B<total_A)
        {
            string name;
            int bat=score_A[0];
            for(int i=0;i<11;i++)
            {
                if(bat<=score_A[i])
                {
                    name=teamA[i];
                    bat=score_A[i];
                }
            }
            cout<<endl<<"THE BATSMAN OF THE MATCH IS "<<name<<" for scoring "<<bat<<" runs"<<endl;
            string name_1;
            int ball=b_wickets_A[0];
            for(int i=0;i<11;i++)
            {
                if(ball<=b_wickets_A[i])
                {
                    name_1=teamA[i];
                    ball=b_wickets_A[i];
                }
            }
            cout<<endl<<"THE BOWLER OF THE MATCH IS "<<name_1<<" for taking "<<ball<<" wickets"<<endl;
        }
        showsummary(teamA,score_A,teamB,score_B,total_A,total_B,wickets_A,wickets_B,b_score_A,b_score_B,b_wickets_A,b_wickets_B);
    }

    delete [] b_wickets_A;  //deleting dynamic array
}
