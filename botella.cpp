#include "botella.h"
#include <QDebug>

Botella::Botella()
{  botellaChica=355;
   botellaGrande=1000;
   numeroBotellas=0;
}

Botella::~Botella()
{


}

Botella::llenadoBotella(int op)
{   if(op==0){
       do{  botellaChica=0;
           for(size_t i{0}; i<=botellaChica; i++){
               if(botellaChica<355){
                   botellaChica=botellaChica+1;
               }
               else if(botellaChica==355){
                   numeroBotellas=numeroBotellas+1;
                   botellaChica=0;
               }
            }
       }while(true);
    }
   else if(op==1){

   }

   else if(op==2){

   }
 return(botellaChica,botellaGrande,numeroBotellas);
}
