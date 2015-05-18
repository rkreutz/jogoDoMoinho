#include <stdio.h>
#include <stdlib.h>

void escrevertab(char mat[7][7]);
void executatab(char moinho[7][7]);
void vertrinca(char t[7][7],int linha, int coluna,char peca,int *remove);

main()
{
   char moinho[7][7];
   int i, linha, coluna, verificar=0,fim=0,x=0,y=0,remove=0;
   int l,c;
   int repW=12,repB=12;//numero de pecas sobrando para reposicao.
   int tabW=0,tabB=0;//numero de pecas no tabuleiro.
   //iniciar a matriz do jogo
   executatab(moinho);

   //iniciar "colocar peças no tabuleiro
   while(fim!=1)
   {
     system("cls");
     escrevertab(moinho);
     do
     {
        if(repW==0)
        {
           while(x!=1)
           {
              printf("Informe a linha de origem de sua peca: ");
              scanf("%d",&linha);
              printf("Informe a coluna de origem de sua peca: ");
              scanf("%d",&coluna);
              if(moinho[linha][coluna]=='W')
              {
                  moinho[linha][coluna]='#';
                  x=1;
              }
              else
                  printf("Local de origem invalido\n");
           }
           x=0;
        }
        else
            printf("Ainda possui %d pecas para por\n",repW);
        printf("Jogador 1, por gentileza, informe a linha da sua jogada: ");
        scanf("%d",&linha);
        printf("Agora, por favor informe a coluna da sua jogada: ");
        scanf("%d",&coluna);
        if (moinho[linha][coluna]=='#')
        { 
            printf("Dale\n");
            verificar=1;
            if(repW>0)
            { 
                repW-=1;
                tabW+=1;
            }
        }
        else
            printf("Local inproprio\n");
     }while (verificar!=1);
     moinho[linha][coluna]='W';
     vertrinca(moinho,linha,coluna,'W',&remove);
     system("cls");
     escrevertab(moinho);
     while(remove!=0)
     {
         printf("Remova uma peça do adversário: ");
         scanf("%d",&l);
         scanf("%d",&c);
         if(moinho[l][c]=='B')
         {
            moinho[l][c]='#';
            remove--;
            tabB--;
         }
         else 
            printf("\nPosicao invalida\n\n");
         if(tabB==0&&repB==0)
         {
            fim=1;
            remove=0;
            printf("Fim de jogo: Jogador 1 venceu.\n");
         }
     }

     
     if(fim!=1)
     {
        system("cls");//limpa a tela
        escrevertab(moinho);
        do
        {
           if(repB==0)
           {
              while(y!=1)
              {
                 printf("Informe a linha de origem de sua peca: ");
                 scanf("%d",&linha);
                 printf("Informe a coluna de origem de sua peca: ");
                 scanf("%d",&coluna);
                 //stdin(fflush);//esvazia o buffer
                 if(moinho[linha][coluna]=='B')
                 {
                     moinho[linha][coluna]='#';
                     y=1;
                 }
                 else
                     printf("Local de origem invalido\n");
              }
              y=0;
           }
           else
               printf("Ainda possui %d pecas para por\n",repB);
           printf("Jogador 2, por gentileza, informe a linha da sua jogada: ");
           scanf("%d",&linha);
           printf("Agora, por favor informe a coluna da sua jogada: ");
           scanf("%d",&coluna);
           if (moinho[linha][coluna]=='#')
           { 
               printf("Dale\n");
               verificar=0;
               if(repB>0)
               { 
                   repB-=1;
                   tabB+=1;
               }
           }
           else
               printf("Local inproprio\n");
        }while (verificar!=0);
        moinho[linha][coluna]='B';
        system("cls");
        escrevertab(moinho);
        vertrinca(moinho,linha,coluna,'B',&remove);
        while(remove>0)
        {
            printf("Remova uma peça do adversário: ");
            scanf("%d",&l);
            scanf("%d",&c);
            if(moinho[l][c]=='W')
            {
               moinho[l][c]='#';
               remove--;
               tabW--;
            }
            else 
               printf("\nPosicao invalida\n\n");
            if(tabW==0&&repW==0)
            {
               fim=1;
               remove=0;
               printf("Fim de jogo: Jogador 2 venceu.\n");
            }
        }
        
     }
   }
   system("cls");
   escrevertab(moinho);
   system("PAUSE");
}


void vertrinca(char t[7][7],int linha, int coluna,char peca,int *remove)
{
   int x,y;
   int contH=0;
   int contV=0;//conta quantos estao lado a lado.
   //horizontal
   for(x=coluna;x>=0;x--){
       if(t[linha][x]==peca)
          contH+=1;
       else if(t[linha][x]!='_')
          x=-1;
       else if(linha==3)
          x=-1;}
   for(x=(coluna+1);x<7;x++){
       if(t[linha][x]==peca)
          contH+=1;
       else if(t[linha][x]!='_')
          x=8;
       else if(linha==3)
          x=8;}
   if(contH==3)
      *remove=*remove+1;
   //vertical
   for(y=linha;y>=0;y--){
       if(t[y][coluna]==peca)
          contV+=1;
       else if(t[y][coluna]!='_')
          y=-1;
       else if(coluna==3)
          y=-1;}
   for(y=(linha+1);y<7;y++){
       if(t[y][coluna]==peca)
          contV+=1;
       else if(t[y][coluna]!='_')
          y=8;
       else if(coluna==3)
          y=8;}
   if(contV==3)
      *remove=*remove+1;
}

void escrevertab(char mat[7][7]){

int l, c;
for (l=0; l<7; l++) {
for (c=0; c<7; c++) {
printf("\t%c", mat[l][c]);
}
printf("\n");

}
}

void executatab(char moinho[7][7]){
   int linha,coluna;
   for (linha=0;linha<7;linha++){
      if (linha==0 || linha==3 || linha==6){
         moinho[linha][0]='#';
         moinho[linha][6]='#';
      }
      else {
         moinho[linha][0]='_';
         moinho[linha][6]='_';
      }
   
      if (linha==1 || linha==3 || linha==5){
         moinho[linha][1]='#';
         moinho[linha][5]='#';
      }
      else {
         moinho[linha][1]='_';
         moinho[linha][5]='_';
      }
   
      if (linha==2 || linha==3 || linha==4){
         moinho[linha][2]='#';
         moinho[linha][4]='#';
      }
      else {
         moinho[linha][2]='_';
         moinho[linha][4]='_';
      }

      if (linha!=3){
         moinho[linha][3]='#';
      }
      else
         moinho[linha][3]='_';
   
   }
}
