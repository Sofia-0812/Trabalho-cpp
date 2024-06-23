#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

#define MAX 10

class Quadrado
{
    private:
        float lado;
        char cor[30];

//para cada atributo tem que ter o set e o get

    public:
        void setLado(float lado)
        {
            this -> lado = lado;
        }

        float getLado()
        {
            return this -> lado;
        }

        void setCor(char *cor)
        {
            strcpy(this -> cor, cor); //string copy: copia a segunda string na primeira, ou seja, a primeira recebe o que ta na segunda
        }

        char* getCor()
        {
            return this -> cor; //esse cor eh o atributo, por isso, nao precisa de *
        }

        float perimetro()
        {
            return getLado() * 4;
        }

        float area()
        {
            return pow(getLado(), 2); //return this-> lado * lado; pow - primeiro eh a base, segundo eh expoente
        }

        void leia()
        {
            float LADO;
            printf("\n Lado: ");
            scanf("%f", &LADO);

            char COR[30];
            fflush(stdin);
            printf("\n Cor: ");
            fgets(COR, 30, stdin);
            fflush(stdin);
            this -> setLado(LADO);
            this -> setCor(COR);
        }

        void escreva()
        {
            printf("\n %.2f", getLado());
            printf("\n %s", getCor());
        }
}; //Fim Quadrado

void inserir(Quadrado* quadrados[MAX], int i)
{
    quadrados[i] ->leia();
}

void listar(Quadrado* quadrados[MAX], int i)
{
    for(int j = 0; j < i; j++)
    {
        quadrados[j] -> escreva();
        printf("\n Perimetro %f", quadrados[j]->perimetro());  //retorna e escreve o perimetro do quadrado guardado na posicao j
        printf("\n Area %f", quadrados[j]->area());
    }
}


int main()
{
    /*Quadrado q1;
    q1.setLado(7);
    q1.setCor("azul");
    q1.escreva();

    Quadrado *q2;
    q2 = new Quadrado;
    q2->setLado(9);
    q2->setCor("verde");
    q2->escreva();

    Quadrado q3;
    q3.leia();
    q3.escreva();

    Quadrado *q4;
    q4 = new Quadrado;
    q4 -> leia();
    q4 -> escreva();*/

    Quadrado* quadrados[MAX];

    int i = 0;
    int opcao;

    do{
        printf("\n 0 - sair");
        printf("\n 1 - inserir");
        printf("\n 2 - listar\n\n");

        fflush(stdin);
        scanf("%i", &opcao);
        fflush(stdin);

        switch(opcao)
        {
            case 0: printf("\n Saindo do programa!");
                    break;
            case 1: inserir(quadrados, i);
                    i++;
                    break;
            case 2: listar(quadrados, i);
                    break;
        }
    }while(opcao != 0);


    return 0;
}

//instancia de uma classe = objeto