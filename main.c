#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 100

struct atendimento {
    char avaria[50];
    int balcaor;
    int balcaoe;
    char observacoes[100];
    char equipamento[50];
    char condicoes[50];
    float valorpagar;
};

struct atendimento atendimentos[MAX];

struct tm *data_hora_atual;

void tempo() {
    time_t segundos;
    time(&segundos);
    data_hora_atual = localtime(&segundos);
    printf("\nHora ........: %d:%d:%d\n", data_hora_atual->tm_hour, data_hora_atual->tm_min, data_hora_atual->tm_sec);
    printf("Data ........: %d/%d/%d\n\n", data_hora_atual->tm_mday, data_hora_atual->tm_mon + 1, data_hora_atual->tm_year + 1900);
}

void ticketdereparacao(int *cont1) {
    printf("Ticket de Reparacao\n");
    printf("Senha numero: %d\n", *cont1);
    tempo();
    printf("Prima qualquer tecla para voltar ao menu.\n");
    // getch();  // Comentei essa linha, pois o getch não é uma função padrão em C
    system("cls");
}

void ticketdeentrega(int *cont2) {
    printf("Ticket de Entrega\n");
    printf("Senha numero: %d\n", *cont2);
    tempo();
    printf("Prima qualquer tecla para voltar ao menu.\n");
    // getch();  // Comentei essa linha, pois o getch não é uma função padrão em C
    system("cls");
}

void acessofuncionario() {
    int a = 0, i = 0;
    char uname[10], c = ' ';
    char pword[10];
    char user[10] = "user";
    char pass[10] = "pass";
    do {
        printf(" \n\n                  USERNAME:-");
        scanf("%s", uname);
        printf(" \n\n                  PASSWORD:-");
        while (i < 10) {
            pword[i] = getchar();
            c = pword[i];
            if (c == '\n') break;
            else printf("*");
            i++;
        }
        pword[i] = '\0';

        i = 0;

        if ((strcmp(uname, "jm1190691") == 0 && strcmp(pword, "pass2") == 0) || (strcmp(uname, "ls1190819") == 0 && strcmp(pword, "pass1") == 0)) {
            break;
        } else {
            printf("\n        Incorreto");
            a++;
            // getch();  // Comentei essa linha, pois o getch não é uma função padrão em C
        }
    } while (a <= 2);
    if (a > 2) {
        printf("\n Desculpe mas foram inseridos dados incorretos demasiadas vezes! ");
        // getch();  // Comentei essa linha, pois o getch não é uma função padrão em C
        system("cls");
        // mainmenu();  // Evite chamar mainmenu() dentro de uma função, isso pode causar problemas de recursão
    }
}

void atendimento1(int *cont1, int *cont3) {
    system("cls");
    int a;
    acessofuncionario();
    system("cls");
    tempo();
    if (*cont3 <= *cont1) {
        printf("Senha numero: %d\n", *cont3);
        printf("O cliente esta presente? \n");
        printf("1- Sim                       2- Nao\n");
        scanf("%d", &a);
        switch (a) {
            case 1:
                do {
                    system("cls");
                    printf("Balcao: \n");
                    scanf("%d", &atendimentos[*cont3].balcaor);
                } while (atendimentos[*cont3].balcaor > 3 || atendimentos[*cont3].balcaor < 1);
                printf("Equipamento para reparacao: \n");
                fflush(stdin);
                scanf("%49s", atendimentos[*cont3].equipamento);
                printf("Avaria principal identificada: \n");
                fflush(stdin);
                scanf("%49s", atendimentos[*cont3].avaria);
                printf("Observacoes: \n");
                fflush(stdin);
                scanf("%99s", atendimentos[*cont3].observacoes);
                break;
            case 2:
                system("cls");
                break;
        }
    } else {
        *cont3 = *cont3 - 1;
        printf("Ainda nao foram retiradas senhas de Reparacao");
        printf("\n\n\n");
        printf("Prima qualquer tecla para voltar ao menu.");
        // getch();  // Comentei essa linha, pois o getch não é uma função padrão em C
        system("cls");
    }
    system("cls");
}

void atendimento2(int *cont2, int *cont4) {
    system("cls");
    int a;
    acessofuncionario();
    system("cls");
    tempo();
    if (*cont4 <= *cont2) {
        printf("Senha numero: %d\n", *cont4);
        printf("O cliente esta presente? \n");
        printf("1- Sim                       2- Nao\n");
        scanf("%d", &a);
        switch (a) {
            case 1:
                do {
                    system("cls");
                    printf("Balcao: \n");
                    scanf("%d", &atendimentos[*cont4].balcaoe);
                } while (atendimentos[*cont4].balcaoe > 4 || atendimentos[*cont4].balcaoe < 1);
                printf("Condicoes da mercadoria: \n");
                fflush(stdin);
                scanf("%49s", atendimentos[*cont4].condicoes);
                do {
                    printf("Valor a pagar: \n");
                    scanf("%f", &atendimentos[*cont4].valorpagar);
                } while (atendimentos[*cont4].valorpagar < 0);
                break;
            case 2:
                system("cls");
                break;
        }
    } else {
        *cont4 = *cont4 - 1;
        printf("Ainda nao foram retiradas senhas de Entrega");
        printf("\n\n\n");
        printf("Prima qualquer tecla para voltar ao menu.");
        // getch();  // Comentei essa linha, pois o getch não é uma função padrão em C
        system("cls");
    }
    system("cls");
}

void senhasatrasadas(int *cont3, int *cont4) {
    system("cls");
    int a = 0, e = 0, r = 0;
    acessofuncionario();
    system("cls");
    tempo();
    if (*cont3 != 0 || *cont4 != 0) {
        printf("1- Ticket de Reparacao \n");
        printf("2- Ticket de Entrega \n");
        scanf("%d", &a);
        switch (a) {
            case 1:
                printf("Qual o numero do ticket?\n");
                scanf("%d", &r);
                if (r > *cont3 - 3 && r < *cont3) {
                    do {
                        system("cls");
                        printf("Balcao: \n");
                        scanf("%d", &atendimentos[r].balcaor);
                    } while (atendimentos[r].balcaor > 3 || atendimentos[r].balcaor < 1);
                    printf("Equipamento para reparacao: \n");
                    fflush(stdin);
                    scanf("%49s", atendimentos[r].equipamento);
                    printf("Avaria principal identificada: \n");
                    fflush(stdin);
                    scanf("%49s", atendimentos[r].avaria);
                    printf("Observacoes: \n");
                    fflush(stdin);
                    scanf("%99s", atendimentos[r].observacoes);
                    system("cls");
                } else {
                    printf("Perdeu a sua vez. A tolerancia sao 3 tickets. A contagem ja vai no numero %d.\n", *cont3);
                    printf("Prima qualquer tecla para voltar ao menu.\n");
                    // getch();  // Comentei essa linha, pois o getch não é uma função padrão em C
                    system("cls");
                }
                break;
            case 2:
                printf("Qual o numero do ticket?\n");
                scanf("%d", &e);
                if (e > *cont4 - 3 && e < *cont4) {
                    do {
                        system("cls");
                        printf("Balcao: \n");
                        scanf("%d", &atendimentos[e].balcaoe);
                    } while (atendimentos[e].balcaoe > 4 || atendimentos[e].balcaoe < 1);
                    printf("Condicoes da mercadoria: \n");
                    fflush(stdin);
                    scanf("%49s", atendimentos[e].condicoes);
                    do {
                        printf("Valor a pagar: \n");
                        scanf("%f", &atendimentos[e].valorpagar);
                    } while (atendimentos[e].valorpagar < 0);
                    system("cls");
                } else {
                    printf("Perdeu a sua vez. A tolerancia sao 3 tickets. A contagem ja vai no numero %d.\n", *cont4);
                    printf("Prima qualquer tecla para voltar ao menu.\n");
                    // getch();  // Comentei essa linha, pois o getch não é uma função padrão em C
                    system("cls");
                }

                break;
        }
    } else {
        printf("Ainda nao foram retirados tickets.\n");
        printf("Prima qualquer tecla para voltar ao menu.\n");
        // getch();  // Comentei essa linha, pois o getch não é uma função padrão em C
        system("cls");
    }
}

void quanttickets(int *cont3, int *cont4) {
    system("cls");
    int total = 0;
    time_t segundos;
    time(&segundos);
    data_hora_atual = localtime(&segundos);
    printf("\nData ........: %d/%d/%d\n\n", data_hora_atual->tm_mday, data_hora_atual->tm_mon + 1,
           data_hora_atual->tm_year + 1900);
    total = *cont3 + *cont4;
    printf("Tickets atendidos: %d\n", total);
    printf("Prima qualquer tecla para voltar ao menu dos mapas.\n");
    // getch();  // Comentei essa linha, pois o getch não é uma função padrão em C
    system("cls");
}

void balcoesprod(int *cont3, int *cont4) {
    system("cls");
    int i = 0, j = 0, cl1 = 0, cl2 = 0, cl3 = 0, cl4 = 0, maior = 0, menor = 0;
    time_t segundos;
    time(&segundos);
    data_hora_atual = localtime(&segundos);
    printf("\nData ........: %d/%d/%d\n\n", data_hora_atual->tm_mday, data_hora_atual->tm_mon + 1,
           data_hora_atual->tm_year + 1900);
    if (*cont3 != 0) {
        for (i = 1; i <= *cont3; i++) {
            switch (atendimentos[i].balcaor) {
                case 1:
                    cl1++;
                    break;
                case 2:
                    cl2++;
                    break;
                case 3:
                    cl3++;
                    break;
            }
        }
    } else {
        printf("Ainda nenhum Ticket de reparacao foi atendido.\n");
    }
    if (*cont4 != 0) {
        for (j = 1; j <= *cont4; j++) {
            switch (atendimentos[j].balcaoe) {
                case 1:
                    cl1++;
                    break;
                case 2:
                    cl2++;
                    break;
                case 3:
                    cl3++;
                    break;
                case 4:
                    cl4++;
                    break;
            }
        }
    } else {
        printf("Ainda nenhum Ticket de entrega foi atendido.\n");
    }

    if (cl1 > cl2 && cl1 > cl3 && cl1 > cl4) {
        printf("O balcao mais produtivo e o 1.\n");
    }

    if (cl2 > cl1 && cl2 > cl3 && cl2 > cl4) {
        printf("O balcao mais produtivo e o 2.\n");
    }

    if (cl3 > cl1 && cl3 > cl2 && cl3 > cl4) {
        printf("O balcao mais produtivo e o 3.\n");
    }

    if (cl4 > cl1 && cl4 > cl2 && cl4 > cl3) {
        printf("O balcao mais produtivo e o 4.\n");
    }

    if (cl1 < cl2 && cl1 < cl3 && cl1 < cl4) {
        printf("O balcao menos produtivo e o 1.\n");
    }

    if (cl2 < cl1 && cl2 < cl3 && cl2 < cl4) {
        printf("O balcao menos produtivo e o 2.\n");
    }

    if (cl3 < cl1 && cl3 < cl2 && cl3 < cl4) {
        printf("O balcao menos produtivo e o 3.\n");
    }

    if (cl4 < cl1 && cl4 < cl2 && cl4 < cl3) {
        printf("O balcao menos produtivo e o 4.\n");
    }
    printf("Prima qualquer tecla para voltar ao menu dos mapas.\n");
    // getch();  // Comentei essa linha, pois o getch não é uma função padrão em C
    system("cls");
}

void receita(int *cont4) {
    system("cls");
    int j = 0;
    float total = 0;
    time_t segundos;
    time(&segundos);
    data_hora_atual = localtime(&segundos);
    printf("\nData ........: %d/%d/%d\n\n", data_hora_atual->tm_mday, data_hora_atual->tm_mon + 1,
           data_hora_atual->tm_year + 1900);
    if (*cont4 != 0) {
        for (j = 1; j <= *cont4; j++) {
            total = total + atendimentos[j].valorpagar;
        }
        printf("Receita total: %.2f\n", total);
    } else {
        printf("Nao foram atendidos tickets de Entrega\n");
    }
    printf("Prima qualquer tecla para voltar ao menu dos mapas.\n");
    // getch();  // Comentei essa linha, pois o getch não é uma função padrão em C
    system("cls");
}

void mostrartickets(int *cont3, int *cont4) {
    system("cls");
    int i = 0, j = 0;
    time_t segundos;
    time(&segundos);
    data_hora_atual = localtime(&segundos);
    printf("\nData ........: %d/%d/%d\n\n", data_hora_atual->tm_mday, data_hora_atual->tm_mon + 1,
           data_hora_atual->tm_year + 1900);
    printf("\n\nTickets de Reparacao\n\n");
    if (*cont3 != 0) {
        for (i = 1; i <= *cont3; i++) {
            printf("Ticket numero: %d\n", i);
            printf("Balcao: %d\n", atendimentos[i].balcaor);
            printf("Equipamento para reparacao: %s\n", atendimentos[i].equipamento);
            printf("Avaria principal identificada: %s\n", atendimentos[i].avaria);
            printf("Observacoes: %s\n", atendimentos[i].observacoes);
            printf("\n\n");
        }
    } else {
        printf("Ainda nenhum Ticket de reparacao foi atendido.\n");
    }

    printf("\n\nTickets de Entrega\n\n");
    if (*cont4 != 0) {
        for (j = 1; j <= *cont4; j++) {
            printf("Ticket numero: %d\n", j);
            printf("Balcao: %d \n", atendimentos[j].balcaoe);
            printf("Condicoes da mercadoria: %s\n", atendimentos[j].condicoes);
            printf("Valor a pagar: %f\n", atendimentos[j].valorpagar);
            printf("\n\n");
        }
    } else {
        printf("Ainda nenhum Ticket de entrega foi atendido.\n");
    }
    printf("Prima qualquer tecla para voltar ao menu dos mapas.\n");
    // getch();  // Comentei essa linha, pois o getch não é uma função padrão em C
    system("cls");
}

void menumapas(int *cont1, int *cont2, int *cont3, int *cont4) {
    system("cls");
    int n2;
    do {
        printf("                    Menu Mapas\n");
        printf("1- Quantidade de tickets atendidos por data\n");
        printf("2- Medias de tempo de espera entre atendimentos por data\n");
        printf("3- Balcao mais e menos produtivo por data\n");
        printf("4- Receita de produtos entregues por data\n");
        printf("5- Informacao de cada ticket\n");
        printf("6- Voltar ao menu principal\n");
        scanf("%d", &n2);
        switch (n2) {
            case 1:
                quanttickets(&*cont3, &*cont4);
                break;
            case 2:
                system("cls");
                printf("Opcao indisponivel.\n");
                printf("Prima qualquer tecla para voltar ao menu dos mapas.\n");
                // getch();  // Comentei essa linha, pois o getch não é uma função padrão em C
                system("cls");
                break;
            case 3:
                balcoesprod(&*cont3, &*cont4);
                break;
            case 4:
                receita(&*cont4);
                break;
            case 5:
                mostrartickets(&*cont3, &*cont4);
                break;
        }
    } while (n2 != 6);
    system("cls");
}

int mainmenu() {
    int n, cont1 = 0, cont2 = 0, cont3 = 0, cont4 = 0;
    do {
        printf("                                   MENU:\n");
        printf("||=======================================================================||\n");
        printf("||            1- Ticket de Reparacao                                     ||\n");
        printf("||            2- Ticket de Entrega                                       ||\n");
        printf("||            3- Atendimento Reparacao ( exclusivo funcionarios)         ||\n");
        printf("||            4- Atendimento Entrega ( exclusivo funcionarios)           ||\n");
        printf("||            5- Atendimento de senhas atrasadas (exclusivo funcionarios)||\n");
        printf("||            6- Mapas                                                   ||\n");
        printf("||            7- Sair 	                                                 ||\n");
        printf("||=======================================================================||\n");
        printf("  Insira a sua escolha: ");
        scanf("%d", &n);
        printf("\n\n\n\n");
        switch (n) {
            case 1:
                cont1++;
                ticketdereparacao(&cont1);
                break;
            case 2:
                cont2++;
                ticketdeentrega(&cont2);
                break;
            case 3:
                cont3++;
                atendimento1(&cont1, &cont3);
                break;
            case 4:
                cont4++;
                atendimento2(&cont2, &cont4);
                break;
            case 5:
                senhasatrasadas(&cont3, &cont4);
                break;
            case 6:
                menumapas(&cont1, &cont2, &cont3, &cont4);
                break;
        }
    } while (n != 7);
    return 0;
}

int main() {
    mainmenu();
    return 0;
}
