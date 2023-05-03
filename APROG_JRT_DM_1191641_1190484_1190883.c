#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define NUMERO_LIVROS 100
//#define DADOS_LIVROS 7

// Estrutura com os tipos de dados que cada livro ir� ter
typedef struct livraria
{
    char nome[100];
    char autor[100];
    char editora[100];
    char formato[100];
    char categoria[100];
    int isbn;
    int ano;
    int vendidos;
    float preco;
    float desconto;
} livraria, temp;


// Verifica se o utilizador introduziu alguma character numa variavel que so aceita numeros
void aceitarNumeros(int *opcao){
  while(*opcao == 0){
    printf("O valor que introduziu nao e valido. Tente novamente!\n");
      while(getchar() != '\n');
      scanf("%d",opcao); // se opcao for um numero scanf("%d",opcao)  retorna 1 caso contrario retorna 0, e volta a entrar no loop while
  }
}

// Permite o utilizador inserir, de um vez, mais do que um livro na fun��o inserirLivros //
int contadorLivros()
{

    int cnt;

    printf("Quantos livros quer inserir?\n");
    scanf("%d", &cnt);
    aceitarNumeros(&cnt);

    return cnt;

}

// Insere livros
void inserirLivros(livraria l[], int cnt, int livrosAtuais)
{

    int opcao, opcao2;
    char tmp; // variavel para limpar buffer

    printf("\nLivros atualmente na biblioteca %d\n", livrosAtuais);

    for(int i=livrosAtuais; i<cnt+livrosAtuais; i++)
    {
        printf("\nNome livro?\n");
        scanf("%[^\n]",  l[i].nome); //%[^\n] aceita espacos para a variavel

        printf("\nAutor?\n");
        scanf("%c %[^\n]", &tmp, l[i].autor);

        do
        {
            while(getchar() != '\n'); // ignora inputs depois de introduzir um espa�o
            printf("\nISBN?\n");
            scanf("%d", &l[i].isbn);

            if(l[i].isbn < 10000 ||l[i].isbn > 99999) printf("O valor ISBN esta errado. Introduza um numero maior que 10000 e menor que 99999");
        }while(l[i].isbn < 10000 || l[i].isbn > 99999);  // Impede tambem o uso de caracteres pelo utilizador

        printf("\nEditora?\n");
        scanf("%c %[^\n]", &tmp,l[i].editora);

        do
        {
            opcao = 0;
            printf("\nFormato do livro?\n");
            printf("1 - PDF \n2 - EPUB\n3 - MOBI\n4 - AZW e AZW3\n5 - Outro\n\n");
            scanf("%d", &opcao);

            if(opcao == 0)   // Evita o loop nas letras
            {
                aceitarNumeros(&opcao);
                while(getchar() != '\n');
            }
            else while(getchar() != '\n');

            switch(opcao)
            {
            case 1:
                strcpy(l[i].formato,"PDF");
                break;

            case 2:
                strcpy(l[i].formato,"EPUB");
                break;

            case 3:
                strcpy(l[i].formato,"MOBI");
                break;

            case 4:
                strcpy(l[i].formato,"AZW e AZW3");
                break;

            case 5:
                strcpy(l[i].formato,"Outro");
                break;

            default:
                printf("\nOpcao introduzida nao foi a correta, tente outra vez\n");
                break;
            }
        }while(opcao>5 || opcao <=0);


        do
        {
            opcao2 = 0; //reset da posição para garantir que o valor inicial é sempre zero e não algum input antigo
            printf("\nCategoria?\n");
            printf("1 - Arte \n2 - Autoajuda\n3 - Banda Desenhada\n4 - Ciencias Exatas e Naturais\n5 - Ciencias Sociais e Humanas\n6 - Desporto e Lazer\n7 - Dicionarios e Enciclopedias\n8 - Direito\n9 - Economia\n10 - Financas e Contabilidade\n11 - Engenharia\n12 - Ensino e Educacao\n13 - Erotismo e Sexualidade\n14 - Gastronomia e Vinhos\n15 - Gestao\n16 - Guias e Roteiros\n17 - Historia\n18 - Infantojuvenil\n19 - Informática\n20 - Literatura\n21 - Medicina e Saúde\n22 - Plano Nacional de Leitura\n23 - Politica\n24 - Religiao e Moral\n25 - Vida Pratica\n\n");
            scanf("%d", &opcao2);

            if(opcao2 == 0)   // Evita o loop nas letras
            {
                aceitarNumeros(&opcao2);
                while(getchar() != '\n');
            }
            else while(getchar() != '\n');

            switch(opcao2)
            {

            case 1:
                strcpy(l[i].categoria,"Arte");
                break;
            case 2:
                strcpy(l[i].categoria,"Autoajuda");
                break;
            case 3:
                strcpy(l[i].categoria,"Banda Desenhada");
                break;
            case 4:
                strcpy(l[i].categoria,"Ciencias Exatas e Naturais");
                break;
            case 5:
                strcpy(l[i].categoria,"Ciencias Sociais e Humanas");
                break;
            case 6:
                strcpy(l[i].categoria,"Desporto e Lazer");
                break;
            case 7:
                strcpy(l[i].categoria,"Dicionarios e Enciclopedias");
                break;
            case 8:
                strcpy(l[i].categoria,"Direito");
                break;
            case 9:
                strcpy(l[i].categoria,"Economia");
                break;
            case 10:
                strcpy(l[i].categoria,"Financas e Contabilidade");
                break;
            case 11:
                strcpy(l[i].categoria,"Engenharia");
                break;
            case 12:
                strcpy(l[i].categoria,"Ensino e Educacao");
                break;
            case 13:
                strcpy(l[i].categoria,"Erotismo e Sexualidade");
                break;
            case 14:
                strcpy(l[i].categoria,"Gastronomia e Vinhos");
                break;
            case 15:
                strcpy(l[i].categoria,"Gestao");
                break;
            case 16:
                strcpy(l[i].categoria,"Guias e Roteiros");
                break;
            case 17:
                strcpy(l[i].categoria,"Historia");
                break;
            case 18:
                strcpy(l[i].categoria,"Infantojuvenil");
                break;
            case 19:
                strcpy(l[i].categoria,"Informatica");
                break;
            case 20:
                strcpy(l[i].categoria,"Literatura");
                break;
            case 21:
                strcpy(l[i].categoria,"Medicina e Saude");
                break;
            case 22:
                strcpy(l[i].categoria,"Plano Nacional de Leitura");
                break;
            case 23:
                strcpy(l[i].categoria,"Politica");
                break;
            case 24:
                strcpy(l[i].categoria,"Religiao Moral");
                break;
            case 25:
                strcpy(l[i].categoria,"Vida Pratica");
                break;
            default:
                printf("\nOpcao introduzida nao foi a correta, tente outra vez\n");
                break;
            }
        }while(opcao2 > 25 || opcao2 <=0);

        do
        {
            printf("\nPreco do livro?\n");
            scanf("%f", &l[i].preco);

            if(l[i].preco <= 0.00) printf("\nO valor que introduziu esta errado. Tente novamente!\n");
            while(getchar() != '\n'); // ignora inputs depois de introduzir um espa�o
        }while(l[i].preco <= 0.00);  // Impede tambem o uso de caracteres pelo utilizador

        do
        {
            printf("\nAno?\n");
            scanf("%d", &l[i].ano);
            if(l[i].ano <1487 || l[i].ano > 2021) printf("\nO ano esta errado. Introduza um ano entre 1487 e 2021!\n");
            while(getchar() != '\n'); // ignora inputs depois de introduzir um espa�o
        }while(l[i].ano < 1487 || l[i].ano >2021);  //1487 foi o ano em que o primeiro livro, em Portugal, foi imprimido

        do
        {
            printf("\nUnidades vendidas?\n");
            scanf("%d", &l[i].vendidos);
            if(l[i].vendidos <=0){
              printf("\n O valor introduzio esta errado. Tente novamente!\n");
              while(getchar() != '\n'); // ignora inputs depois de introduzir um espa�o
            } //como é o último dado a ser inserido, só limpo o buffer caso o valor esteja errado, se estiver correto o buffer é limpo a seguir
        }while(l[i].vendidos <= 0);  // Impede tambem o uso de caracteres pelo utilizador

        while(getchar() != '\n'); //limpa buffer depois de inserir Unidades Vendidas
    }
}

// Verifica se ja foram inseridos livros pelo utilizador
int verificarBiblioteca(int livrosAtuais)
{

    if (livrosAtuais == 0)
    {
        printf("\nIntroduza primeiro um livro!\n");
        return 0;
    }
    else
        return 1;
}

// Atualiza, um por um, os dados do livro escolhido pelo utilizador
void atualizarLivros(livraria l[], int livrosAtuais)
{

    int posicao, opcao;

    do
    {
        printf("\nQual dos livros deseja alterar?\n");
        for(int i=0; i<livrosAtuais; i++)
        {
            printf("%d - %s\n",i+1, l[i].nome); // mostra todos os livros inseridos na biblioteca
        }
        scanf("%d", &posicao); // O utilizador escolhe a posicao do livro que pretende mudar os seus dados

        if(posicao>livrosAtuais || posicao <= 0)
        {
            printf("\nEsse livro nao existe! Tente novamente\n");
            while(getchar() != '\n');
            posicao = 0;
        }
        else while(getchar() != '\n');
    }while(posicao>livrosAtuais || posicao <= 0);  // Impede tambem o uso de caracteres pelo utilizador


    do
    {
        opcao = 0; //set de opção a zero para garantir que no loop opção começa sempre a zero

        printf("Qual o dado do livro que quer alterar?\n");
        printf("1 -> Autor - %s\n", l[posicao-1].autor);
        printf("2 -> ISBN - %d\n", l[posicao-1].isbn);
        printf("3 -> Editora - %s\n", l[posicao-1].editora);
        printf("4 -> Formato - %s\n", l[posicao-1].formato);
        printf("5 -> Categoria - %s\n", l[posicao-1].categoria);
        printf("6 -> Preco - %.2f\n", l[posicao-1].preco);
        printf("7 -> Ano - %d\n", l[posicao-1].ano);
        printf("8 -> Unidades vendidas - %d\n", l[posicao-1].vendidos);
        printf("9 -> Sair\n");

        scanf("%d", &opcao);

        if(opcao == 0)   // Evita o loop nas letras
        {
            aceitarNumeros(&opcao);
            while(getchar() != '\n');
        }
        else while(getchar() != '\n');

        switch(opcao)
        {
        case 1:
            printf("\nAutor?\n");
            scanf("%[^\n]", l[posicao-1].autor);
            break;

        case 2:
            do
            {
              l[posicao-1].isbn = 0.0; //fazer set a 0 garante que em caso de o utilizador inserir uma letra, o valor vai ficar a zero garantindo que o user tem de introduzir um valor válido para sair do ciclo

                printf("\nISBN?\n");
                scanf("%d", &l[posicao-1].isbn);

                if(l[posicao-1].isbn < 10000 ||l[posicao-1].isbn > 99999) printf("O valor ISBN esta errado. Introduza um numero maior que 10000 e menor que 99999");
                while(getchar() != '\n'); // ignora inputs depois de introduzir um espa�o

            }while(l[posicao-1].isbn < 10000 || l[posicao-1].isbn > 99999);
            break;

        case 3:
            printf("\nEditora?\n");
            scanf("%[^\n]", l[posicao-1].editora);
            break;

        case 4:
            do
            {
                opcao = 0; //reset da opção para limpar o valor que o utilizador inserir para chegar a este case
                printf("\nFormato do livro?\n");
                printf("1 - PDF \n2 - EPUB\n3 - MOBI\n4 - AZW e AZW3\n5 - Outro\n\n");
                scanf("%d", &opcao);

                if(opcao == 0)   // Evita o loop nas letras
                {
                    aceitarNumeros(&opcao);
                    while(getchar() != '\n');
                }
                else while(getchar() != '\n');

                switch(opcao)
                {
                case 1:
                    strcpy(l[posicao-1].formato,"PDF");
                    break;

                case 2:
                    strcpy(l[posicao-1].formato,"EPUB");
                    break;

                case 3:
                    strcpy(l[posicao-1].formato,"MOBI");
                    break;

                case 4:
                    strcpy(l[posicao-1].formato,"AZW e AZW3");
                    break;

                case 5:
                    strcpy(l[posicao-1].formato,"Outro");
                    break;

                default:
                    printf("\nOpcao introduzida nao foi a correta, tente outra vez\n");
                    break;
                }
            }while(opcao>5 || opcao <=0);
            break;

        case 5:

          do{

            opcao = 0; //reset da opção para limpar o valor que o utilizador inserir para chegar a este case
            printf("\nCategoria?\n");
            printf("1 - Arte \n2 - Autoajuda\n3 - Banda Desenhada\n4 - Ciencias Exatas e Naturais\n5 - Ciencias Sociais e Humanas\n6 - Desporto e Lazer\n7 - Dicionarios e Enciclopedias\n8 - Direito\n9 - Economia\n10 - Financas e Contabilidade\n11 - Engenharia\n12 - Ensino e Educacao\n13 - Erotismo e Sexualidade\n14 - Gastronomia e Vinhos\n15 - Gestao\n16 - Guias e Roteiros\n17 - Historia\n18 - Infantojuvenil\n19 - Informática\n20 - Literatura\n21 - Medicina e Saúde\n22 - Plano Nacional de Leitura\n23 - Politica\n24 - Religiao e Moral\n25 - Vida Pratica\n\n");
            scanf("%d", &opcao);

            if(opcao == 0)   // Evita o loop nas letras
            {
                aceitarNumeros(&opcao);
                while(getchar() != '\n');
            }
            else while(getchar() != '\n');

            switch(opcao)
            {

              case 1:
                  strcpy(l[posicao-1].categoria,"Arte");
                  break;
              case 2:
                  strcpy(l[posicao-1].categoria,"Autoajuda");
                  break;
              case 3:
                  strcpy(l[posicao-1].categoria,"Banda Desenhada");
                  break;
              case 4:
                  strcpy(l[posicao-1].categoria,"Ciencias Exatas e Naturais");
                  break;
              case 5:
                  strcpy(l[posicao-1].categoria,"Ciencias Sociais e Humanas");
                  break;
              case 6:
                  strcpy(l[posicao-1].categoria,"Desporto e Lazer");
                  break;
              case 7:
                  strcpy(l[posicao-1].categoria,"Dicionarios e Enciclopedias");
                  break;
              case 8:
                  strcpy(l[posicao-1].categoria,"Direito");
                  break;
              case 9:
                  strcpy(l[posicao-1].categoria,"Economia");
                  break;
              case 10:
                  strcpy(l[posicao-1].categoria,"Financas e Contabilidade");
                  break;
              case 11:
                  strcpy(l[posicao-1].categoria,"Engenharia");
                  break;
              case 12:
                  strcpy(l[posicao-1].categoria,"Ensino e Educacao");
                  break;
              case 13:
                  strcpy(l[posicao-1].categoria,"Erotismo e Sexualidade");
                  break;
              case 14:
                  strcpy(l[posicao-1].categoria,"Gastronomia e Vinhos");
                  break;
              case 15:
                  strcpy(l[posicao-1].categoria,"Gestao");
                  break;
              case 16:
                  strcpy(l[posicao-1].categoria,"Guias e Roteiros");
                  break;
              case 17:
                  strcpy(l[posicao-1].categoria,"Historia");
                  break;
              case 18:
                  strcpy(l[posicao-1].categoria,"Infantojuvenil");
                  break;
              case 19:
                  strcpy(l[posicao-1].categoria,"Informatica");
                  break;
              case 20:
                  strcpy(l[posicao-1].categoria,"Literatura");
                  break;
              case 21:
                  strcpy(l[posicao-1].categoria,"Medicina e Saude");
                  break;
              case 22:
                  strcpy(l[posicao-1].categoria,"Plano Nacional de Leitura");
                  break;
              case 23:
                  strcpy(l[posicao-1].categoria,"Politica");
                  break;
              case 24:
                  strcpy(l[posicao-1].categoria,"Religiao Moral");
                  break;
              case 25:
                  strcpy(l[posicao-1].categoria,"Vida Pratica");
                  break;
              default:
                  printf("\nOpcao introduzida nao foi a correta, tente outra vez\n");
                  break;
            }
        }while(opcao > 25 || opcao <= 0);
            break;

        case 6:
            do
            {
                l[posicao-1].preco = 0.00; //fazer set a 0 garante que em caso de o utilizador inserir uma letra, o valor vai ficar a zero garantindo que o user tem de introduzir um valor válido para sair do ciclo

                printf("\nPreco do livro?\n");
                scanf("%f", &l[posicao-1].preco);


                if(l[posicao-1].preco <= 0.00) printf("\nO valor que introduziu esta errado. Tente novamente!\n");
                while(getchar() != '\n'); // ignora inputs depois de introduzir um espa�o

            }while(l[posicao-1].preco <= 0.00);
            break;

        case 7:
            do
            {
                l[posicao-1].ano = 0; //fazer set a 0 garante que em caso de o utilizador inserir uma letra, o valor vai ficar a zero garantindo que o user tem de introduzir um valor válido para sair do ciclo

                printf("\nAno?\n");
                scanf("%d", &l[posicao-1].ano);

                if(l[posicao-1].ano <1487 || l[posicao-1].ano > 2021) printf("\nO ano esta errado. Introduza um ano entre 1487 e 2021!\n");
                while(getchar() != '\n'); // ignora inputs depois de introduzir um espa�o

            }while(l[posicao-1].ano < 1487 || l[posicao-1].ano >2021);  //1487 foi o ano em que o primeiro livro, em Portugal, foi imprimido
            break;


        case 8:
            do
            {
                l[posicao-1].vendidos = 0; //fazer set a 0 garante que em caso de o utilizador inserir uma letra, o valor vai ficar a zero garantindo que o user tem de introduzir um valor válido para sair do ciclo


                printf("\nUnidades vendidas?\n");
                scanf("%d", &l[posicao-1].vendidos);

                if(l[posicao-1].vendidos <=0) printf("\n O valor introduzio esta errado. Tente novamente!\n");
                while(getchar() != '\n'); // ignora inputs depois de introduzir um espa�o

            }while(l[posicao-1].vendidos <= 0);
            break;

        case 9:
            break;

        default:
            printf("\nOpcao introduzida nao foi a correta, tente outra vez\n");
            break;
        }
    }
    while(opcao!=9);
}


// Remove um livro, bem como todos os seus dados, da biblioteca
void removerLivros(livraria l[], int *livrosAtuais)
{

    int posicao, i;

    do
    {
        printf("\nQual dos livros deseja remover\n");
        for(int i=0; i<*livrosAtuais; i++)
        {
            printf("%d - %s\n",i+1, l[i].nome); // mostra todos os livros inseridos na biblioteca
        }
        scanf("%d", &posicao); // O utilizador escolhe a posicao do livro que pretende retirar

        if(posicao> *livrosAtuais || posicao <= 0)
        {
            printf("\nEsse livro nao existe! Tente novamente\n");
            while(getchar() != '\n');
            posicao = 0;
        }
        else while(getchar() != '\n');

    }while(posicao > *livrosAtuais || posicao<=0);  // garante que o utilizador nao introduz caracteres

    for(i=posicao-1; i<*livrosAtuais-1; i++) l[i]=l[i+1]; // Remove o livro da posicao escolhida e poe os restantes livros uma posicao para tras

}

// Mostra todos os livros entre os anos 2020 e 2021
void listaNovidades(livraria l[], int livrosAtuais)
{

    int verificar=0;

    printf("\nNovidades\n");

    for(int i=0; i<livrosAtuais; i++)
    {
        if(l[i].ano == 2020 || l[i].ano == 2021)
        {
            printf("%s -> lancamento no ano %d\n",l[i].nome, l[i].ano);
            verificar+=1; // Utilizado para saber se existem livros entre 2020 e 2021
        }
    }

    if(verificar==0) // Caso nao existam livros entres esses anos faz o print da mensagem abaixo
        printf("\nNao existem novidades de momento\n");

}

// Permite o utilizador introduzir uma promo��o no pre�o do livro
void inserirPromo(livraria l[], int livrosAtuais)
{

    int posicao;
    float desconto;
    float promo = 0.00;

    do
    {
        //while(getchar() != '\n');
        printf("\nQual � a percentagem da promocao deseja inserir?\n");
        scanf("%f", &promo); // O valor que ser� transformado em decimal para calcular o desconto

        if(promo<=0 || promo>100)
        {
            printf("\nO valor que inseriu nao esta correto! Tente novamente e insira um numero entre 0 e 100\n");
            while(getchar() != '\n');
            promo = 0;
        }
        else while(getchar() != '\n');
    }while(promo<=0 || promo>100);

    do
    {
        printf("\nQual dos livros deseja inserir uma promocao?\n");
        for(int i=0; i<livrosAtuais; i++)
        {
            printf("%d - %s -> preco %.2f\n",i+1, l[i].nome, l[i].preco); // mostra todos os livros inseridos na biblioteca bem como o seu pre�o
        }
        scanf("%d", &posicao);

        if(posicao>livrosAtuais || posicao <= 0)
        {
            printf("\nEsse livro nao existe! Tente novamente\n");
            while(getchar() != '\n');
            posicao = 0;
        }
        else while(getchar() != '\n');
    }while(posicao>livrosAtuais || posicao<=0);

    if(l[posicao-1].desconto!=0)  //Verifica se j� existe uma promocao no livro que o utilizador escolheu
    {
        printf("\nJa existe uma promocao nesse livro. Utilize a opcao atualizar promo!\n");
        return;
    }

    l[posicao-1].desconto = l[posicao-1].preco - (l[posicao-1].preco * (promo * 0.01)); //Calcula o pre�o final, ja com desconto, do livro

    printf("\nO livro %s tem o preco final de %.2f\n", l[posicao-1].nome, l[posicao-1].desconto);
}


// Permite modificar a promo��o anteriormente escolhida pelo utilizador
void atualizarPromo(livraria l[], int livrosAtuais)
{

    int posicao;
    float desconto;
    float promo = 0.0;

    do
    {
        printf("\nQual a promocao que deseja alterar?\n");
        for(int i=0; i<livrosAtuais; i++)
        {
            printf("%d - %s -> preco %.2f\n",i+1, l[i].nome, l[i].preco); // mostra todos os livros inseridos na biblioteca bem como o seu pre�o
        }
        scanf("%d", &posicao);
        if(posicao>livrosAtuais || posicao <= 0)
        {
            printf("\nEsse livro nao existe! Tente novamente\n");
            while(getchar() != '\n');
            posicao = 0;
        }
        else while(getchar() != '\n');
    }while(posicao>livrosAtuais || posicao<=0);

    if(l[posicao-1].desconto==0)  //Verifica se o livro nao tem uma promocao
    {
        printf("\nO livro escolhido nao tem promocao. Utilize a opcao inserir promo!\n");
        return;
    }

    do
    {
        printf("\nQual � a percentagem da promocao deseja inserir?\n");
        scanf("%f", &promo); // O valor que ser transformado em decimal para calcular o desconto
        if(promo<=0 || promo>100)
        {
            printf("\nO valor que inseriu nao esta correto! Tente novamente e insira um numero entre 0 e 100\n");
            while(getchar() != '\n');
            promo = 0;
        }
    }while(promo<=0 || promo>100);

    l[posicao-1].desconto = l[posicao-1].preco - (l[posicao-1].preco * (promo * 0.01));


    printf("\nO livro %s tem o preco final de %.2f\n", l[posicao-1].nome, l[posicao-1].desconto);

}

// Remove uma promocapo anteriormente introduzida pelo utilizador
void removerPromo(livraria l[], int livrosAtuais)
{

    int posicao;
    float desconto, promo;

    do
    {
        printf("\nQual a promocao que deseja remover?\n");
        for(int i=0; i<livrosAtuais; i++)
        {
            printf("%d - %s -> preco %.2f\n",i+1, l[i].nome, l[i].desconto);
        }
        scanf("%d", &posicao);
        if(posicao>livrosAtuais || posicao <= 0)
        {
            printf("\nEsse livro nao existe! Tente novamente\n");
            while(getchar() != '\n');
            posicao = 0;
        }
    }while(posicao>livrosAtuais || posicao<=0);

    l[posicao-1].desconto = 0.00;
}

// Mostra todos os livros que tenham promocoes inseridas
void listaPromocoes(livraria l[], int livrosAtuais)
{

    int verificar=0;

    printf("\nPromocoes\n");

    for(int i=0; i<livrosAtuais; i++)
    {
        if(l[i].desconto==0) printf(" ");

        else
        {
            printf("%s -> preco com promocao %.2f\n",l[i].nome, l[i].desconto);
            verificar+=1;
        }
    }

    if(verificar==0) // Caso nao existam livros com promocoes
        printf("\nNao existem promocoes de momento\n");

}


void listagens(livraria l[], livraria temp, int livrosAtuais){

    int opcao;
    int minimo;


     do{
            opcao = 0;

            printf("\nEscolha uma das opções\n1 - Autores\n2 - Categorias\n3 - Ano\n4 - Formato\n5 - Unidades Vendidas\n");

            scanf("%d", &opcao);

            if(opcao == 0){ // Evita o loop nas letras{
              aceitarNumeros(&opcao);
              while(getchar() != '\n');
            }
            else while(getchar() != '\n'); // garante que sempre que o valor seja valido, limpa tudo o que tem no buffer depois de um espaco

        switch(opcao){

          case 1:
          for(int i=0; i<livrosAtuais - 1; i++){
              minimo = i; // marca o elemento minimo da livraria

              for(int j = i + 1; j < livrosAtuais; j++){
                if( strcmp(l[j].autor, l[minimo].autor)<0 ) minimo = j; // verifica se o elemento a seguir ao minimo atual é menor, se for o minimo passa a ser essa posição
              }
              if(minimo != i){
                temp = l[minimo];

                l[minimo] = l[i];

                l[i] = temp;
              }
          }
          for(int i=0; i<livrosAtuais; i++) printf("\n%s - %s", l[i].nome, l[i].autor);

          break;

          case 2:
          for(int i=0; i<livrosAtuais - 1; i++){
              minimo = i; // marca o elemento minimo da livraria

              for(int j = i + 1; j < livrosAtuais; j++) if( strcmp(l[j].categoria, l[minimo].categoria)<0 ) minimo = j; // verifica se o elemento a seguir ao minimo atual é menor, se for o minimo passa a ser essa posição

              if(minimo != i){
                temp = l[minimo];

                l[minimo] = l[i];

                l[i] = temp;
              }
          }
          for(int i=0; i<livrosAtuais; i++) printf("\n%s - %s", l[i].nome, l[i].categoria);
              break;

          case 3:
              for(int i=0; i<livrosAtuais - 1; i++){
                  minimo = i; // marca o elemento minimo da livraria

                  for(int j = i + 1; j < livrosAtuais; j++) if(l[j].ano<l[minimo].ano) minimo = j; // verifica se o elemento a seguir ao minimo atual é menor, se for o minimo passa a ser essa posição

                  if(minimo != i){
                    temp = l[minimo];

                    l[minimo] = l[i];

                    l[i] = temp;
                  }

              }
              for(int i=0; i<livrosAtuais; i++) printf("\n%s - %d", l[i].nome, l[i].ano);

              break;

          case 4:
          for(int i=0; i<livrosAtuais - 1; i++){
              minimo = i; // marca o elemento minimo da livraria

              for(int j = i + 1; j < livrosAtuais; j++) if( strcmp(l[j].formato, l[minimo].formato)<0 ) minimo = j; // verifica se o elemento a seguir ao minimo atual é menor, se for o minimo passa a ser essa posição

              if(minimo != i){
                temp = l[minimo];

                l[minimo] = l[i];

                l[i] = temp;
              }
          }
          for(int i=0; i<livrosAtuais; i++) printf("\n%s - %s", l[i].nome, l[i].formato);
              break;

          case 5:
              for(int i=0; i<livrosAtuais - 1; i++){

                  minimo = i; // marca o elemento minimo da livraria
                  for(int j = i + 1; j < livrosAtuais; j++) if(l[j].vendidos<l[minimo].vendidos) minimo = j; // verifica se o elemento a seguir ao minimo atual é menor, se for o minimo passa a ser essa posição

                  if(minimo != i){ //se o minimo tiver mudado, dentro do if a estrutura é reordenada
                    temp = l[minimo];

                    l[minimo] = l[i];

                    l[i] = temp;
                  }

              }
              for(int i=0; i<livrosAtuais; i++) printf("\n%s - %d", l[i].nome, l[i].vendidos); //impressão estrutura ordenada
              break;

          default:
              printf("\nOpcao introduzia nao foi a correta! Tente outra vez\n\n");
              break;
          }
        }while(opcao>5 || opcao<=0);
}

int main(){
    livraria livro[NUMERO_LIVROS];
    livraria temp;
    int opcao, contador; //Opcaoo -> o numero que o utilizador era usa para escolher
    int livrosAtuais = 0; //Numero de livros inseridos na biblioteca
    int existeLivros; //Para usar no verificar se foram introduzidos livros na biblioteca


    do
    {
        printf("\nEscolha uma das opcoes para os livros\n\n");
        printf("1 - Inserir livro\n2 - Atualizar livro\n3 - Remover livro\n4 - Lista Novidades\n5 - Inserir Promocao\n6 - Atualizar Promocao\n7 - Remover Promocao\n8 - Lista Promocoes\n9 - Listagem de livros\n10 - Sair\n\n");
        scanf("%d", &opcao);

        if(opcao == 0) // Evita o loop nas letras
        {
            aceitarNumeros(&opcao);
            while(getchar() != '\n');
        }
        else while(getchar() != '\n'); // garante que sempre que o valor seja valido, limpa tudo o que tem no buffer depois de um espaco

        switch(opcao)
        {
        case 1:
            contador = contadorLivros();
            while(getchar() != '\n'); // ignora inputs depois de introduzir um espa�o
            inserirLivros(livro, contador, livrosAtuais);
            (livrosAtuais == 0) ? (livrosAtuais = contador ) : (livrosAtuais = livrosAtuais + contador ); /*if (livrosAtuais == 0) livrosAtuais=contador; else livrosAtuais = livrosAtuais + contador;*/
            break;

        case 2:
            if(verificarBiblioteca(livrosAtuais) == 0)
                break;
            atualizarLivros(livro, livrosAtuais);
            break;

        case 3:
            if(verificarBiblioteca(livrosAtuais) == 0)
                break;
            removerLivros(livro, &livrosAtuais);
            livrosAtuais--;
            break;

        case 4:
            if(verificarBiblioteca(livrosAtuais) == 0)
                break;
            listaNovidades(livro, livrosAtuais);
            break;

        case 5:
            if(verificarBiblioteca(livrosAtuais) == 0)
                break;
            inserirPromo(livro, livrosAtuais);
            break;

        case 6:
            if(verificarBiblioteca(livrosAtuais) == 0)
                break;
            atualizarPromo(livro, livrosAtuais);
            break;

        case 7:
            if(verificarBiblioteca(livrosAtuais) == 0)
                break;
            removerPromo(livro, livrosAtuais);
            break;

        case 8:
            if(verificarBiblioteca(livrosAtuais) == 0)
                break;
            listaPromocoes(livro, livrosAtuais);
            break;

        case 9:
            if(verificarBiblioteca(livrosAtuais) == 0)
                break;
            listagens(livro, temp, livrosAtuais);
            break;

        case 10:
            exit(1);

        default:
            printf("\nOpcao introduzia nao foi a correta! Tente outra vez\n\n");
            break;
        }
        opcao = 0;
    }while(opcao!=10);

    return 0;

}
