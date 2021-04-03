 #include <stdio.h>
 #include <mpi.h>
 #include <stdlib.h>
 #include <time.h>


 int main() {

int process_0,process_1;
int score1=0;
int score2=0;
int i = 1;
int ROCK = 1;
int PAPER = 2;
int SCISSORS =3;        

MPI_Init(NULL, NULL);
int world_rank;
MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);





do{
              if(world_rank != 0) {
                     //1
                     srand(time(NULL)+rand()%99);
                     process_1 = rand()%3+1;
                     MPI_Send(&process_1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
                     MPI_Recv(&score1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD,MPI_STATUS_IGNORE); 
                     MPI_Recv(&score2, 1, MPI_INT, 0, 0, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
                          
  
                     } 
              else {
                     //0
                     srand(time(NULL)+rand()%100);
                     process_0 = rand()%3+1;
                     MPI_Recv(&process_1, 1, MPI_INT, 1, 0, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
                            
                     
                     
                          if(process_0==ROCK){
                                 if(process_1==ROCK){
                                        printf("Turn %d , Process-0 : ROCK  , Process-1 : ROCK\n",i);
                                        printf("Draw , Score : %d - %d\n\n",score1,score2);
                                        printf("--\n");
                                 }
                                else if(process_1==PAPER){
                                        printf("Turn %d , Process-0 : ROCK  , Process-1 : PAPER\n",i);
                                        score2++;
                                        printf("Process 1 win , Score : %d - %d\n\n",score1,score2);
                                        printf("--\n");
                                 }
                                 else if(process_1==SCISSORS){
                                        printf("Turn %d , Process-0 : ROCK  , Process-1 : SCISSORS\n",i);
                                        score1++;
                                        printf("Process 0 win , Score : %d - %d\n\n",score1,score2);
                                        printf("--\n");
                                 }
                          }
                         else if(process_0==PAPER){
                                 if(process_1==ROCK){
                                        printf("Turn %d , Process-0 : PAPER  , Process-1 : ROCK\n",i);
                                        score1++;
                                        printf("Process 0 win , Score : %d - %d\n\n",score1,score2);
                                        printf("--\n");
                                 }
                                else if(process_1==PAPER){
                                        printf("Turn %d , Process-0 : PAPER  , Process-1 : PAPER\n",i);
                                        printf("DRAW , Score : %d - %d\n\n",score1,score2);
                                        printf("--\n");
                                 }
                                 else if(process_1==SCISSORS){
                                        printf("Turn %d , Process-0 : PAPER  , Process-1 : SCISSORS\n",i);
                                        score2++;
                                        printf("Process 1 win , Score : %d - %d\n\n",score1,score2);
                                        printf("--\n");
                                 }
                          }

                         else if(process_0==SCISSORS){
                                 if(process_1==ROCK){
                                        printf("Turn %d , Process-0 : SCISSORS  , Process-1 : ROCK\n",i);
                                        score2++;
                                        printf("Process 1 win , Score : %d - %d\n\n",score1,score2);
                                        printf("--\n");
                                 }
                                else if(process_1==PAPER){
                                        printf("Turn %d , Process-0 : SCISSORS  , Process-1 : PAPER\n",i);
                                        score1++;
                                        printf("Process 0 win , Score : %d - %d\n\n",score1,score2);
                                        printf("--\n");
                                 }
                                 else if(process_1==SCISSORS){
                                        printf("Turn %d , Process-0 : SCISSORS  , Process-1 : SCISSORS\n",i);
                                        printf("DRAW, Score : %d - %d\n\n",score1,score2);
                                        printf("--\n");
                                 }
                          }
                     

                     MPI_Send(&score1, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
                     MPI_Send(&score2, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);


                     if(score1==5){
                            printf("Process 0 WIN !!\n");
                            printf("--\n");
                            
                     }

                     
                     if(score2==5){
                            printf("Process 1 WIN !!\n");
                            printf("--\n");
                            
                     }
                         
                 }
              
             i++;
             
            

              
}while((score1!=5)&&(score2!=5)); 
       



MPI_Finalize();

return 0;

}


